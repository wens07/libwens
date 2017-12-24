//
// Copyright (c) 2016. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang (wens at qiangweng dot site)
// Date: 2016/5/18
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//

#ifndef WENSLIB_CONFIG_H
#define WENSLIB_CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>


#define ALIGNBYTES (sizeof(uintptr_t) - 1)
#define ALIGN(p) ((uintptr_t)(p) + ALIGNBYTES) & ~(ALIGNBYTES)

#define std(flags, file) \
      {0,0,0,flags,file,{0,0},0,__sF+file,__sclose,__sread,nullptr,__swrite, \
      {(unsigned char *)(__sFext+file), 0},nullptr,0,{0},{0},{0,0},0,0}

#define ALLOC_SIZE 1024

// get from nginx
#define wens_align(d, a)     (((d) + (a - 1)) & ~(a - 1))
#define wens_align_ptr(p, a)                                                   \
    (u_char *) (((uintptr_t) (p) + ((uintptr_t) a - 1)) & ~((uintptr_t) a - 1))

namespace wens
{

    size_t align8(size_t s)
    {
        if (s & 0x7 == 0)
            return s;

        return (s >> 3 + 1) << 3;
    }
}

#endif //WENSLIB_CONFIG_H
