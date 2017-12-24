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


//     /* Structure describing an Internet socket address.  */
//     struct sockaddr_in {
//         sa_family_t    sin_family; /* address family: AF_INET */
//         uint16_t       sin_port;   /* port in network byte order */
//         struct in_addr sin_addr;   /* internet address */
//     };

//     /* Internet address. */
//     typedef uint32_t in_addr_t;
//     struct in_addr {
//         in_addr_t       s_addr;     /* address in network byte order */
//     };

//     struct sockaddr_in6 {
//         sa_family_t     sin6_family;   /* address family: AF_INET6 */
//         uint16_t        sin6_port;     /* port in network byte order */
//         uint32_t        sin6_flowinfo; /* IPv6 flow information */
//         struct in6_addr sin6_addr;     /* IPv6 address */
//         uint32_t        sin6_scope_id; /* IPv6 scope-id */
//     };


#include "InetAddress.h"

#include <string.h>

using namespace wens;
using namespace wens::net;

static_assert(sizeof(InetAddress) == sizeof(struct sockaddr_in6), "sizeof InetAddress not equal sockaddr_in6");
static_assert(offsetof(sockaddr_in, sin_family) == 0);
static_assert(offsetof(sockaddr_in6, sin6_family) == 0);
static_assert(offsetof(sockaddr_in, sin_port) == 2);
static_assert(offsetof(sockaddr_in6, sin6_port) == 2);

InetAddress::InetAddress(uint16_t port, bool lookbackOnly, bool ipv6)
{
    if (ipv6)
    {
        memset(&addr6_, 0, sizeof(addr6_));
        addr6_.sin6_family = AF_INET6;

        in6_addr ip = lookbackOnly ? in6addr_loopback : in6addr_any;

        addr6_.sin6_addr = ip;
        addr6_.sin6_port = sockets::hostToNetwork16(port);

    }
    else
    {
        memset(&addr_, 0, sizeof(addr_));
        addr_.sin_family = AF_INET;

        in_addr ip = lookbackOnly ? INADDR_LOOPBACK: INADDR_ANY;

        addr_.sin_addr = ip;
        addr_.sin_port = sockets::hostToNetwork16(port);
    }

}




