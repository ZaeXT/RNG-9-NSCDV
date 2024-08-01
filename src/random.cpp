#include <random>

/*
生成1~37 - 1（学号）返回
*/
int gen_rnd(int gen_min, int gen_max) {
    std::random_device rnd;
    std::mt19937 mt_rnd(rnd());
    std::uniform_int_distribution<int> distribution(gen_min, gen_max);
    return distribution(mt_rnd);
}