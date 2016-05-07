//
// Created by wengqiang on 11/4/16.
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
            __sync
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
