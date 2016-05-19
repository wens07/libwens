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

#include "Timer.h"

using namespace wens;
using namespace wens::net;

void Timer::restart(Timestamp now)
{
    if (repeat_)
    {
        expiration_ = addTime(now, interval_);
    }
    else
    {
        expiration_ = Timestamp::invalid();
    }
}