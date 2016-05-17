//
// Created by wengqiang on 13/4/16.
// 
// Copyright (c) 2016. All rights reserved.
//

#ifndef WENSLIB_EVENTLOOP_H
#define WENSLIB_EVENTLOOP_H


#include <boost/core/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/any.hpp>
#include <atomic>
#include <vector>
#include <mutex>
#include <thread>

#include "Timestamp.h"
#include "TimerId.h"


namespace wens
{
    namespace  net
    {
        class Channel;
        class Poller;
        class TimerQueue;

        /**
         * Reactor,  one eventloop per thread.
         *
         * this is an interface class, so don't expose too much details.
         */
        class EventLoop : boost::noncopyable
        {
        public:
            typedef  boost::function<void()>  Functor;

            EventLoop();
            ~EventLoop();

            /**
             * loops forever
             *
             * must called in the thread  which created the eventloop obj.
             */
            void loop();


            /**
             * quit the loop
             *
             * this is not 100% thread safe if you call through a raw pointer, better to call
             * through a shared_ptr<EventLoop> for 100% safety.
             */
            void quit();


            Timestamp pollReturnTime() const { return  poolReturnTime_; }

            int64_t iteration() const { return iteration_; }

            /**
             * run callback immediately in the loop thread.
             * it wake up the loop, then run the cb.
             *
             * if in the same loop thread, cb is run in the function.
             * it is safe to call from other threads.
             *
             * @param cb : the callback func.
             *
             */
            void runInLoop(const Functor &cb);

            /**
             * queue the cb in the loop thread.
             *
             * run after finish pooling.
             * it is safe to call from other threads.
             *
             */
            void queueInLoop(const Functor &cb);

#ifdef __GXX_EXPERIMENTAL_CXXOX__
            void runInLoop(Functor &&cb);
            void queueInLoop(Functor &&cb);
#endif

            /// timers
            /**
             * run callback at time 'ts'
             * safe to call from other threads.
             *
             * @param ts: the timestamp
             * @param cb: the callback func
             *
             * @return TimerId
             */
            TimerId  runAt(const Timestamp &ts, const TimerCallback &cb);


            /**
             * run callback after @c delay seconds
             * safe to call from  other threads.
             *
             * @param delay: the seconds
             * @param cb: the callback func
             * @return TimerId
             */
            TimerId runAfter(double delay, const TimerCallback &cb);

            /**
             * run callback every @c interval seconds
             * safe to call from other threads.
             *
             * @param interval: the seconds
             * @param cb: the callback func
             * @return TimerId
             *
             */
            TimerId runEvery(double interval, const TimerCallback &cb);

            /**
             * cancel the timer
             * safe to call from  other threads.
             */
            void cancel(TimerId timerId);

#ifdef __GXX_EXPERIMENTAL_CXX0X__
            TimerId runAt(const Timestamp &ts, const TimerCallback &&cb);
            TimerId runAfter(double delay, const TimerCallback &&cb);
            TimerId runEvery(double interval, const TimerCallback &&cb);

#endif

            /// internal usage
            void wakeup();
            void updateChannel(Channel *channel);
            void removeChannel(Channel *channel);
            bool hasChannel(Channel *channel);

            pid_t threadId() const { return threadId_; };

            bool isInLoopThread() const { return threadId_ == std::this_thread::get_id(); };


            void assertInLoopThread()
            {
                if (!isInLoopThread())
                    abortNotInLoopThread();
            }

            bool callingPendingFunctors() const { return callingPendingFunctors_; };
            bool eventHandling() const { return eventHandling_; };

            void setContext(const boost::any &context)
            {
                context_ = context;
            }

            const boost::any& getContext() const { return context_; };
            boost::any* getMutableContext() { return &context_; };

            static EventLoop* getEventLoopOfCurrentThread();

        private:
            void abortNotInLoopThread();
            void handleRead();
            void doPendingFunctors();

            void printActiveChannels() const;


            typedef std::vector<Channel> vecChannel;

            std::atomic<bool> looping_;  //whether the loop is looping
            std::atomic<bool> quit_;  //quit loop or not
            std::atomic<bool> eventHandling_;
            std::atomic<bool> callingPendingFunctors_;

            int64_t  iteration_;
            const std::thread::id  threadId_;

            Timestamp poolReturnTime_;

            boost::scoped_ptr<Poller> poller_;
            boost::scoped_ptr<TimerQueue> timerQueue_;

            int wakeupFd_[2];

            //we don't expose Channel to client
            boost::scoped_ptr<Channel> wakeupChannel_;
            boost::any context_;

            //scratch variable
            vecChannel activeChannels_;
            Channel *currentActiveChannel_;

            std::mutex mutex_;
            std::vector<Functor> pendingFunctors_; //guarded by mutex_

        };

    }
}




#endif //WENSLIB_EVENTLOOP_H
