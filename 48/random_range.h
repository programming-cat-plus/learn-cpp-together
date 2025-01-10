#include <random>
/*
  * 一个用于生成随机数的类
 */

class Random {
  private:
    std::mt19937 eng{std::random_device{}()};
    std::uniform_int_distribution<unsigned int> uniform_dist{0, UINT32_MAX};
  public:
    Random() = default;
    Random(const Random &) = delete;
    Random & operator=(const Random &) = delete;
    Random(int min,int max):uniform_dist(min,max){};
    unsigned int generate(){
        return uniform_dist(eng);
    }
    unsigned int operator()(){
      return generate();
    }
};