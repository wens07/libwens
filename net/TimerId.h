//
// Copyright (c) 2016. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang (wens at qiangweng dot site)
// Date: 13/4/16
// 
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//

#ifndef WENSLIB_TIMEID_H
#define WENSLIB_TIMEID_H

#include "copyable.h"
#include "Timer.h"
#include ""

namespace wens
{
    namespace net
    {
        class TimerId : public wens::copyable
        {
        public:
            TimerId() : timer_(NULL), sequence_(0)
            {
            }

            TimerId(Timer *t, int64_t seq) : timer_(t), sequence_(seq)
            {
            }


            friend class TimerQueue;

        private:
            Timer *timer_;
            int64_t  sequence_;

        };

    }
}


#endif //WENSLIB_TIMEID_H
