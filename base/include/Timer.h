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

#ifndef WENSLIB_TIMER_H
#define WENSLIB_TIMER_H

#include <sys/time.h>
#include <boost/noncopyable.hpp>
#include "CallBack.h"
#include "Timestamp.h"

using namespace wens;
using namespace wens::net;

namespace wens
{
    class Timer : boost::noncopyable
    {
    public:
        Timer()
        {

        }

    private:
        const TimerCallback callback_;
        Timestamp expiration_;
        const double interval_;
        const  bool repeat_;
        const int64_t  sequence_;




    };

}




#endif //WENSLIB_TIMER_H
