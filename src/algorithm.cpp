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

/**
 *  Prints all prime numbers smaller than n
 *
 *  @param n primes not bigger than n
 */
void sieve_eratosthenes(int32_t n)
{
    bool marked[n + 1];
    
    memset(marked, true, sizeof(marked));
    
    for (int32_t i = 2; i * i <= n; ++i)
    {
        for (int32_t j = i; j <= n; j += j)
            marked[j] = false;
    }
    
    for (int32_t i = 2; i <= n; ++i)
    {
        if (marked[i])   printf("%d ", i);

    }
}

/**
 *  Prints all prime numbers smaller than n
 *
 *  @param n primes not bigger than n
 */
void sieve_sundaram(int32_t n)
{
    // This array is used to separate numbers of the form i+j+2ij
    // from others where  1 <= i <= j
    bool marked[n];
    
    // In general Sieve of Sundaram, produces primes smaller
    // than (2*x + 2) for a number given number x.
    // Since we want primes smaller than n, we reduce n to half
    int32_t n_new = (n - 2) / 2;
    
    // Initalize all elements as not marked
    memset(marked, false, sizeof(marked));
    
    // Main logic of Sundaram.  Mark all numbers of the
    // form i + j + 2ij as true where 1 <= i <= j
    for (int32_t i = 1; i <= n_new; ++i)
    {
        for (int32_t j = i; (i + j + 2 * i * j) <= n_new; ++j)
        {
            marked[i + j + 2 * i * j] = true;
        }
    }
    
    // Since 2 is a prime number
    if (n > 2) printf("2 ");
    
    // Print other primes. Remaining primes are of the form
    // 2*i + 1 such that marked[i] is false.
    for (int32_t i = 1; i <= n_new; ++i)
    {
        if (marked[i] == false)   printf("%d ", 2 * i + 1);

    }
}

_LIBWENS_END