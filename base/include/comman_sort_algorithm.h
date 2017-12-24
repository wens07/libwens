
// 
// Copyright (c) 2017. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang (wens at qiangweng dot site)
// Date: 26/9/17
// 
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//

#ifndef WENSLIB_COMMAN_SORT_ALGORITHM_H
#define WENSLIB_COMMAN_SORT_ALGORITHM_H

#include <algorithm>

template <typename T>
void bubble_sort(T* a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j]) std::swap(a[i], a[j]);
        }
    }

}


#endif //WENSLIB_COMMAN_SORT_ALGORITHM_H


