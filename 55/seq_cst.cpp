#include <atomic>
#include <thread>
#include <iostream>
#include <set>
/**********************************
 * Sequntial Consistency Model示例
*********************************/
int main(void)
{
    std::set<std::pair<int,int>> results;
    for (int i = 0; i < 10000; i++)
    {
        std::atomic<int> a = 0;
        std::atomic<int> b = 0;
        int x = 0;
        int y = 0;

        std::thread th1([&]()
                        {
                            a.store(1); //
                            std::this_thread::yield();// 强制调度器切换到另一个线程，以便观察到写入操作的顺序。                     
                            x=b.load(); 
                            
                        });
        std::thread th2([&]()
                        {   
                            b.store(1);   
                            std::this_thread::yield();                     
                            y=a.load(); 
                        });

        th1.join();
        th2.join();
        results.insert(std::make_pair(x, y));
    }
    for (auto &p : results) {
        std::cout << "(x="<< p.first << ", y=" << p.second << ") \n";
    }
    return 0;
}