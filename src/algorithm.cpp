//
//  algorithm.cpp
//  libwens
//
//  Created by wengqiang on 31/12/15.
//  Copyright (c) 2015 wengqiang. All rights reserved.
//

#include "algorithm.h"
#include <string.h>


_LIBWENS_START

void sieve_sundaram(int32_t n)
{
    bool marked[n];
    
    int32_t n_new = (n - 2) / 2;
    
    memset(marked, false, sizeof(marked));
    
    for (int32_t i = 1; i <= n_new; ++i)
    {
        for (int32_t j = i; (i + j + 2 * i * j) <= n_new; ++j)
        {
            marked[i + j + 2 * i * j] = true;
        }
    }
    
    if (n > 2) printf("2 ");
    
    for (int32_t i = 1; i <= n_new; ++i)
    {
        if (marked[i] == false)   printf("%d ", 2 * i + 1);

    }
}

_LIBWENS_END