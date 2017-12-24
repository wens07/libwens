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

#ifndef WENSLIB_INETADDRESS_H
#define WENSLIB_INETADDRESS_H

#include "copyable.h"

#include <sys/socket.h>
#include <netinet/in.h>

#include <string>

namespace  wens
{
    namespace net
    {
        namespace sockets
        {
            const struct sockaddr* sockaddr_cast(const struct sockaddr_in6* addr);
        }
        class InetAddress : public wens::copyable
        {
        private:
            union
            {
                struct sockaddr_in addr_;
                struct sockaddr_in6 addr6_;
            };

        public:
            /**
             * construct an endpoint with given port number.
             *
             * Mostly used in TcpServer listening.
             */
            explicit InetAddress(uint16_t port = 0, bool lookbackOnly = false, bool ipv6 = false);

            /**
             * construct an endpoint with ip and port
             */
            InetAddress(std::string &ip, uint16_t port, bool ipv6 = false);

            /**
             * construct an endpoint with struct @c sockaddr_in
             *
             * Mostly used when accepting new connections
             */
            explicit InetAddress(const struct sockaddr_in &addr) : addr_(addr)
            {}

            explicit InetAddress(const struct sockaddr_in6 &addr6) : addr6_(addr6)
            {}

            /**
             *  default copy ctor/assignment is ok
             */



            sa_family_t family() const { return addr_.sin_family; }

            std::string toIp() const;
            std::string toIpPort() const;
            uint16_t toPort() const;

            const struct sockaddr* getSockAddr() const { return sockets::sockaddr_cast(&addr6_); }
            void setSockAddrInet6(const struct sockaddr_in6 &addr) { addr6_ = addr; }

            uint32_t  ipNetEndian() const;
            uint32_t  portNetEndian() const { return addr_.sin_port; }

            /**
             * change hostname to Ip address
             */
            static bool resolve(std::string &hostname, InetAddress *result);






        };
    }

}


#endif //WENSLIB_INETADDRESS_H
