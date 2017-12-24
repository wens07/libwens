//
// Copyright (c) 2016. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang 
// Contact info: qiangweng.site/wens.wq@gmail.com
// Date: 2016/5/20
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//

#include "SocketUtil.h"

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <boost/implicit_cast.hpp>

using namespace wens;

const struct sockaddr* socketaddr_cast(const struct sockaddr_in *addr)
{
    return static_cast<const struct sockaddr*>(boost::implicit_cast<const void*>(addr));
}

const struct sockaddr* socketaddr_cast(const struct sockaddr_in6 *addr)
{
    return static_cast<const struct sockaddr*>(boost::implicit_cast<const void*>(addr));
}

const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr *addr)
{
    return static_cast<const struct sockaddr_in*>(boost::implicit_cast<const void*>(addr));
}

const struct sockaddr_in6* sockaddr_in6_cast(cosnt struct sockaddr *addr)
{
    return static_cast<const struct sockaddr_in6*>(boost::implicit_cast<const void*>(addr));
}


int createNonblockingOrDie(sa_family_t family)
{
    int sockfd = ::socket(family, SOCK_STREAM|SOCK_ NONBLOCK|SOCK_CLOEXEC, IPPROTO_TCP);
    if (sockfd < 0)
        perror("create socket failed");

    return sockfd;

}

void bindOrDie(int sockfd, const struct sockaddr *addr)
{
    int ret = ::bind(sockfd, addr, sizeof(struct sockaddr_in6));

    if (ret < 0)
        perror("bind failed!");
}

void listenOrDie(int sockfd, const struct sockaddr *addr)
{
    int ret = ::listen(fd, SOMAXCONN);

    if (ret < 0)
        perror("listen failed!");

}

int accept(int sockfd, const struct sockaddr_in6 *addr)
{
    socklen_t addrlen = static_cast<socklen_t>(sizeof(addr));

    int connfd = ::accept(sockfd, socketaddr_cast(addr), &addrlen);
    if (connfd < 0)
    {
        int savederrno = errno;
        perror("accept failed!");
    }

    return connfd;

}

int connect(int sockfd, const struct sockaddr *addr)
{
    return  ::connect(sockfd, addr, static_cast<socklen_t>(sizeof(struct sockaddr_in6)));
}

ssize_t read(int sockfd, void *buf, size_t count)
{
    return ::read(sockfd, buf, count);
}

ssize_t write(int sockfd, const void *buf, size_t count)
{
    return ::write(sockfd, buf, count);
}

void close(int sockfd)
{
    if (::close(sockfd) < 0)
        perror("close error!");
}

void shutdownWrite(int sockfd)
{
    if (::shutdown(sockfd, SHUT_WR) < 0)
        perror("shutdown write error!");
}

void toIpPort(char *buf, size_t size, const struct sockaddr* addr)
{
    toIp(buf, size, addr);
    size_t  end = ::strlen(buf);

    const struct  sockaddr_in *addr4 = sockaddr_in_cast(addr);
    uint16_t port = net::sockets::networkToHost16(addr4->sin_port);

    assert(size > end);

}




