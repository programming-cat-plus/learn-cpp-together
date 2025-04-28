/******************************************************
 *
 * condition_variable 示例
 * 一个写入数据的线程和多个读取数据的线程
 *  *
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
  std::mutex mutex_;
  std::condition_variable condVar;
  std::string sharedData;

  void getData()
  {
    auto tid = std::this_thread::get_id();
    std::unique_lock<std::mutex> lck(mutex_);
    std::cout << "接收方[" << tid << "]等待数据;" << std::endl;
    condVar.wait(lck, [this]{ return !sharedData.empty(); });
    if (sharedData.empty())
      std::cout << "接收方[" << tid << "] 虚假唤醒,无数据;" << sharedData << std::endl;
    else
      std::cout << "接收方[" << tid << "]得到数据：" << sharedData << std::endl;
    sharedData.clear();
  }

  void setData()
  {
    static int id = 1;
    std::stringstream ss;
    ss << "数据#" << id;
    {
      std::unique_lock<std::mutex> lck(mutex_);
      sharedData = ss.str();
      std::cout << "\n发送方: 第" << id << "条数据写入完毕;" << std::endl;
      id++;
    }
    condVar.notify_one();
    std::this_thread::sleep_for(1ms);
  }
};
int main()
{

  std::cout << std::endl;
  static const int N = 10;
  static const int N_R = 4;
  Channel channel;

  std::thread write_th([&channel]()
                       { for (int i = 0; i < N; i++)channel.setData(); });

  std::vector<std::thread> read_threads;

  for (int i = 0; i < N_R; i++)
    read_threads.emplace_back([&channel]()
                              { for (int i = 0; i < N/N_R; i++)channel.getData(); });

  for (auto &t : read_threads)
    t.join();

  write_th.join();

  std::cout << std::endl;
}