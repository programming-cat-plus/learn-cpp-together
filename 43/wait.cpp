#include <future>
#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include <iomanip>
std::mutex coutMutex;

void teach(std::promise<void> &&prom)
{
    std::cout << "上课\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    prom.set_value();
    std::cout << "下课\n";
}

void learn(std::shared_future<void> &&sf)
{
    sf.wait();

    const std::time_t t_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::lock_guard<std::mutex> guard(coutMutex);

    std::cout << "再见(" << std::this_thread::get_id() << ") [" <<  std::put_time(std::localtime(&t_c), "%H:%M:%S") << "]\n";
}

int main()
{
    std::promise<void> promise;
    std::shared_future<void> sfuture = promise.get_future();

    std::thread teacher = std::thread(teach, std::move(promise));
    std::vector<std::thread> students;

    for (int i = 0; i < 40; i++)
        students.push_back(std::thread(learn, sfuture));

    teacher.join();
    for (auto &s : students)
        s.join();
}
