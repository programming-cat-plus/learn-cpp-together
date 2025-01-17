#include <barrier>
#include <syncstream>
#include <iostream>
#include <chrono>
#include <array>
#include <thread>
#include <random>

class Participant{
public:
    std::string name;
    Participant(std::string name) : name(name) {}
    template <typename BarrierType>
    void run(BarrierType &finish)
    {
        std::mt19937 eng{std::random_device{}()};
        std::uniform_int_distribution<unsigned int> uniform_dist{1000, 2000};
        for (int i = 0; i < 5; i++)
        {
            auto rnd = uniform_dist(eng);
            std::this_thread::sleep_for(std::chrono::milliseconds(rnd));
            alive = rnd % 3;
            if (alive)
            {
                finish.arrive_and_wait();
            }
            else
            {
                finish.arrive_and_drop();
                break;
            }
        }
    }
    bool is_alive() const{ return alive;}
private:
    bool alive = true;
};

int main()
{
    std::vector<Participant> participants = {Participant{"张三"},Participant{"李四"},Participant{"王五"},Participant{"赵六"},Participant{"钱七"},};
    const int participant_count = participants.size();
    int round = 0;

    auto on_complete = [&participants, &round](){
        round++;
        std::cout << "第" << round << "轮幸存者：" << std::endl;
        int count = 0;
            for (auto &p : participants)
            {
                if (p.is_alive())
                {
                    std::cout << p.name << " ";
                    count++;
                }
            }
            if(count==0)
                std::cout<< "无";
            std::cout << std::endl;
 
    };

    std::barrier finish(participant_count, on_complete);
    std::vector<std::thread> threads;
    for (auto &p : participants)
        threads.emplace_back([&p, &finish](){ p.run(finish); });
    
    for (auto &thread : threads)
        thread.join();
    
    return 0;
}