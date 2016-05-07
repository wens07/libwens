//
// Created by wengqiang on 13/4/16.
// 
// Copyright (c) 2016. All rights reserved.
//

#include "EventLoop.h"
#include <sys/signal.h>
#include <sys/socket.h>

namespace
{
    __thread EventLoop *p_loopInThisThread = NULL;
    const int kPollTimeMs = 10000;

   class IgnoreSigPipe
   {
   public:
       IgnoreSigPipe()
       {
           ::signal(SIGPIPE, SIG_IGN);
           //LOG_TRACE << "Ignore SIGPIPE";
       }
   };

    IgnoreSigPipe initObj;

}

EventLoop* EventLoop::getEventLoopOfCurrentThread()
{
    return  p_loopInThisThread;
}

EventLoop::EventLoop()
    : looping_(false),
      quit_(false),
      eventHandling_(false),
      callingPendingFunctors_(false),
      iteration_(0),
      threadId_(std::this_thread::get_id()),
      poller_(),
      timerQueue_(new TimerQueue),
      currentActiveChannel_(NULL)
{
    LOG_DEBUG << "EventLoop created " << this << " in thread " << threadId_;
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, wakeupFd_) < 0)
    {
        LOG_SYSFATAL << "Failed in socketpair";
    }
    wakeupChannel_.reset(new Channel(this, wakeupFd_[0]));

}


