/******************************************************
 * 
 * condition_variable 示例
 * 会出现唤醒丢失或者虚假唤醒的例子
 * 
 ****************************************************/
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <sstream>
#include <chrono>
#include <vector>
using namespace std::chrono_literals;

struct Channel
{
  void getData()
  {
    auto tid = std::this_thread::get_id();
    std::unique_lock lck(mutex_);
    std::cout << "接收方[" << tid << "]等待数据;" << std::endl;
    condVar.wait(lck);
    std::cout << "接收方[" << tid << "]得到数据：" << sharedData << std::endl;
    sharedData.clear();
  }

  void setData()
  {
    static int id = 1;
    std::stringstream ss;
    ss << "Hello #" << id;
    {
      std::unique_lock lck(mutex_);
      sharedData = ss.str();
      std::cout << "\n发送方: 第" << id << "条数据写入完毕;" << std::endl;
      id++;
    }
    condVar.notify_one();
    std::this_thread::sleep_for(1ms);
  }

private:
  std::mutex mutex_;
  std::condition_variable condVar;
  std::string sharedData;
};

int main()
{
  Channel channel;
  std::thread write_th(Channel::setData, &channel);
  std::thread read_th(Channel::getData, &channel);

  read_th.join();
  write_th.join();
}

