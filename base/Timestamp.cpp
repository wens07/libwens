//
// Copyright (c) 2016. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang 
// Contact info: qiangweng.site/wens.wq@gmail.com
// Date: 2016/5/18
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//

#include "Timestamp.h"
#include <inttypes.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

using namespace wens;

#define TIMESTAMPLEN 32
static_assert(sizeof(Timestamp) == sizeof(int64_t), "Timestamp is not 64 bits");

std::string Timestamp::toString() const
{
    char buf[TIMESTAMPLEN] = {0};
    int64_t seconds = microseconds_since_epoch_ / kMicroSecondsPerSecond;
    int64_t microseconds = microseconds_since_epoch_ % kMicroSecondsPerSecond;

    snprintf(buf, TIMESTAMPLEN - 1, "%d \t\t %d", seconds, microseconds);

    return buf;

}

std::string Timestamp::toFormattedString(bool showMicroseconds) const
{
    char buf[TIMESTAMPLEN] = {0};
    time_t seconds = static_cast<time_t>(microseconds_since_epoch_ / kMicroSecondsPerSecond);

    struct tm *tm_time = gmtime(&seconds);

    if (showMicroseconds)
    {
        int microSeconds = static_cast<int>(microseconds_since_epoch_ % kMicroSecondsPerSecond);
        snprintf(buf, TIMESTAMPLEN, "%4d%02d%02d %02d:%02d:%02d.%06d",
                tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday,
                tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec, microSeconds);
    }
    else
    {
        snprintf(buf, TIMESTAMPLEN, "%4d%02d%02d %02d:%02d:%02d",
                 tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday,
                 tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec);
    }

    return buf;
}

Timestamp Timestamp::now()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);

    int64_t seconds = tv.tv_sec;

    return Timestamp(seconds * kMicroSecondsPerSecond + tv.tv_usec);

}