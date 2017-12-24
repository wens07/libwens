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

    private:
        const TimerCallback callback_;
        Timestamp expiration_;
        const double interval_;
        const  bool repeat_;
//        const int64_t  sequence_; //if added, should also add constructor etc.

    public:
        Timer(const TimerCallback &cb, Timestamp when, double interval): callback_(cb),
                                                                           expiration_(when),
                                                                           interval_(interval),
                                                                           repeat_(interval > 0.0)
        {
        }

#ifdef __GXX_EXPERIMENTAL_CXX0X__
        Timer(const TimerCallback &&cb, Timestamp when, double interval): callback_(cb),
                                                                         expiration_(when),
                                                                         interval_(interval),
                                                                         repeat_(interval > 0.0)
        {
        }
#endif

        void run() const
        {
            callback_();
        }

        //getter functions
        Timestamp expiration() const { return expiration_;}
        bool repeat() const { return repeat_;}
//        int64_t sequence() const { return  sequence_};

        void restart(Timestamp now);


    };

}




#endif //WENSLIB_TIMER_H
