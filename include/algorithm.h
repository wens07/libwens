//
//  algorithm.h
//  libwens
//
//  Created by wengqiang on 31/12/15.
//  Copyright (c) 2015 wengqiang. All rights reserved.
//

#ifndef libwens_algorithm_h
#define libwens_algorithm_h

#include "macros.h"
#include <iostream>

_LIBWENS_START

/**
 *  swap two value
 *
 *  @param src
 *  @param dst
 */
template <class type>
void swap(type *src, type *dst)
{
    type temp = *src;
    
    *src = *dst;
    *dst = temp;
}


/**
 *  permutation of a array element
 *
 *  @param str
 *  @param start
 *  @param end
 */
template <class type>
void permutation(type *arr, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; ++i)
        {
            std::cout<<arr[i];
        }
        
        std::cout<<std::endl;
    }
    else
    {
        for (int i = start; i <= end; ++i)
        {
            swap<type>((arr + start), (arr + i));
            permutation(arr, start + 1, end);
            swap<type>((arr + start), (arr + i));
        }
    }
}

void sieve_sundaram(int32_t n);
_LIBWENS_END

#endif


