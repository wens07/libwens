//
// Created by wengqiang on 12/4/16.
// 
// Copyright (c) 2016. All rights reserved.
//

#ifndef WENSLIB_TIMESTAMP_H
#define WENSLIB_TIMESTAMP_H

#include <boost/operators.hpp>
#include <string>

namespace wens
{
    class Timestamp : public  boost::less_than_comparable<Timestamp>
    {
    public:
        /**
         * construct an invalid Timestamp
         *
         */
        Timestamp() : microseconds_since_epoch_(0)
        {
        }

        /**
         * construct a Timestamp with specific time
         *
         * @param time
         */
        explicit Timestamp(int64_t time) : microseconds_since_epoch_(time)
        {
        }

        /**
         * default copy/assign/dtor a ok
         */


        void swap(Timestamp &ts)
        {
            std::swap(microseconds_since_epoch_, ts.microseconds_since_epoch_);
        }

        std::string toString() const;
        std::string toFormattedString(bool showMicroseconds = true) const;

        bool valid() const { return  microseconds_since_epoch_ > 0 ;}

        // for internal usage
        int64_t  microSecondsSinceEpoch() const { return microseconds_since_epoch_;}

        time_t  secondsSinceEpoch() { return static_cast<time_t>(microseconds_since_epoch_ / kMicroSecondsPerSecond);}

        /**
         * get timestamp
         */
        static Timestamp now();

        static Timestamp invalid() { return Timestamp();}

        static Timestamp fromUnixTime(time_t t) { return  fromUnixTime(t, 0);}


        static Timestamp fromUnixTime(time_t t, int microsecond)
        {
            return Timestamp(static_cast<int64_t>(t) * kMicroSecondsPerSecond + microsecond);
        }


        static const int kMicroSecondsPerSecond = 1000 * 1000;
    private:
        int64_t  microseconds_since_epoch_;

    };

    inline bool operator<(const Timestamp &lhs, const Timestamp &rhs)
    {
        return lhs.microseconds_since_epoch_ < rhs.microseconds_since_epoch_;
    }

    inline bool operator==(const Timestamp &lhs, const Timestamp &rhs)
    {
        return lhs.microseconds_since_epoch_ == rhs.microseconds_since_epoch_;
    }


    /**
     * get the difference of two Timestamps, result in seconds
     *
     * @param high, low
     * @return (high - low) in seconds
     * @c double has 52 precision, enough for one-microsecond resolution for next 100 years
     */
    inline double timeDifference(const Timestamp &high, const Timestamp &low)
    {
        int64_t  diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
        return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
    }

    /**
     * add @c seconds to Timestamp
     *
     * @return ts + seconds  as Timestamp
     */
    inline Timestamp addTime(const Timestamp &ts, double seconds)
    {
        int64_t  delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
        return Timestamp(ts.microSecondsSinceEpoch() + delta);
    }
}

#endif //WENSLIB_TIMESTAMP_H
