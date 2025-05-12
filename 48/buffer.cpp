/*
*  循环缓冲区
* 实现读写线程示例，其中一个线程写入共享缓冲区，另一个线程从中读取
* 该版本使用信号量来确保读取器只读取有效数据，而写入器不会覆盖未读取的数据。
*
*/
#include <mutex>
#include <thread>
#include <iostream>
#include <string.h>
#include <syncstream>
#include <array>
#include "random_range.h"
#include <semaphore>

template <size_t BuffSize = 6>
class RWBuffer
{
public:
  RWBuffer(){buff.fill(' ');};

  char prepareData(){
    std::this_thread::sleep_for(std::chrono::milliseconds(rgen()));//模拟生成数据消耗的时间
    return chargen();
  }

  void processData(char ch){
    std::this_thread::sleep_for(std::chrono::milliseconds(rgen2()));//模拟处理数据消耗的时间
  }

  void printBuffer(std::osyncstream& out){
    //std::osyncstream out(std::cout);
    out << "BUFFER: |";
    for (auto c : buff)
      out << c << "|";
    out << std::endl;
  }

  void writeToBuffer(size_t iterations)
  {
    std::osyncstream(std::cout) << "写线程就绪.\n";
    for (size_t i = 0; i < iterations * buff.size(); i++)
    {
      char ch = prepareData();
      sem_writer.acquire();
      
      buff[i % buff.size()] = ch;

      std::osyncstream out(std::cout) ;
      out << "写线程: 写入字符 '"<< ch << "'.\t\t";
      printBuffer(out);

      // Signal that there is content to read
      sem_reader.release();
    }
  }

  void readFromBuffer(size_t iterations)
  {
    std::osyncstream(std::cout) << "读线程就绪.\n";
    for (size_t i = 0; i < iterations * buff.size(); i++)
    {
      sem_reader.acquire();
      auto idx = i % buff.size();

      char ch = buff[idx];
      processData(ch); 
      buff[idx] = ' ';

      std::osyncstream out(std::cout);
      out << "读线程: 读取数据 '" << ch << "'.\t\t";
      printBuffer(out);
      sem_writer.release();
    }
  }

private:
  Random rgen{500, 1000};
  Random rgen2{800, 1500};
  Random chargen{'A', 'Z'};
  std::array<char, BuffSize> buff;
  std::counting_semaphore<BuffSize> sem_reader{0};
  std::counting_semaphore<BuffSize> sem_writer{BuffSize};
};

// 读/写循环次数.
static const unsigned int kNumIterations = 3;
int main(int argc, const char *argv[])
{
  // Create an empty buffer
  RWBuffer rwbuffer;
  std::thread writer(&RWBuffer<>::writeToBuffer, &rwbuffer, kNumIterations);
  std::thread reader(&RWBuffer<>::readFromBuffer, &rwbuffer, kNumIterations);
  writer.join();
  reader.join();
  return 0;
}