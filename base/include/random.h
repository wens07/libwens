/**
  * Author: wengqiang (email: wens.wq@gmail.com)
  * Copyright (c) 2017 . All rights reserved.
  */

#ifndef WENSLIB_RANDOM_H
#define WENSLIB_RANDOM_H

#include <random>
#include <time.h>
#include <chrono>

uint64_t  pseudo_random_int64()
{

    auto seed = static_cast<uint64_t > (std::chrono::system_clock::now().time_since_epoch().count());

    std::mt19937_64  gen(seed);
    std::uniform_int_distribution<uint64_t > distribution(0, 1000);

    return distribution(gen);
}

#endif //WENSLIB_RANDOM_H
