//
// Created by wengqiang on 11/4/16.
//

#ifndef WENSLIB_CALLBACK_H
#define WENSLIB_CALLBACK_H

#include <functional>
#include "../config.h"

namespace wens
{
    namespace net
    {
        typedef  std::function<void()> TimerCallback;
    }
}

#endif //WENSLIB_CALLBACK_H
