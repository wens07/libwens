//
// Copyright (c) 2016. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang (wens at qiangweng dot site)
// Date: 2016/4/11
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//

#ifndef WENSLIB_CALLBACK_H
#define WENSLIB_CALLBACK_H

#include <functional>
#include "config.h"

namespace wens
{
    namespace net
    {
        typedef  std::function<void()> TimerCallback;
    }
}

#endif //WENSLIB_CALLBACK_H
