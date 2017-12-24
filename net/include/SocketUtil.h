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

#ifndef WENSLIB_SOCKETUTIL_H
#define WENSLIB_SOCKETUTIL_H

#include <stdint.h>
#include <endian.h>

#include <netinet/in.h>
#include <sys/types.h>

namespace wens
{
    namespace net
    {
        namespace sockets
        {

#if defined(__clang__) || __GNUC_MINOR__ >= 6
#pragma GCC diagnostic push
#endif
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wold-style-cast"
            /**
             * folling functions were added to glibc in version 2.9. eg: htobe64/be64toh etc.
             */
            inline uint64_t hostToNetwork64(uint64_t host64)
            {
//                return htobe64();
            }

            inline uint32_t hostToNetwork32(uint32_t host32)
            {
//                return htobe32();
            }

            inline uint16_t  hostToNetwork16(uint16_t host16)
            {
//                return htobe16();
            }

            inline uint64_t networkToHost64(uint64_t net64)
            {
//                return be64toh();
            }

            inline uint32_t networkToHost32(uint32_t net32)
            {
//                return be32toh();
            }

            inline uint16_t  networkToHost16(uint16_t net16)
            {
//                return be16toh();
            }

#if defined(__clang__) || __GUNC_MINOR__ >= 6
#pragma GCC diagnostic pop
#else
#pragma GCC diagnostic warning "-Wconversion"
#pragma GCC diagnostic warning "-Wold-style-cast"
#endif


            /**
             * create a non-blocking socket file descriptor,
             * abort if any error happen
             *
             */
            int createNoBlockingOrDie(sa_family_t family);

            int connect(int sockfd, const struct sockaddr *addr);

            void bindOrDie(int sockfd, const struct sockaddr *addr);
            void listenOrDie(int sockfd);

            int accept(int sockfd, struct sockaddr_in6 *addr);

            ssize_t read(int sockfd, void *buf, size_t count);
            ssize_t write(int sockfd, void *buf, size_t count);

            void close(int sockfd);
            void shutdownWrite(int sockfd);

            void toIpPort(char *buf, size_t size, const struct sockaddr *addr);
            void toIp(char *buf, size_t size, const struct sockaddr *addr);

            void fromIpPort(const char *ip, uint16_t port, struct sockaddr_in *addr);
            void fromIpPort(const char *ip, uint16_t port, struct sockaddr_in6 *addr);

            int getSocketError(int sockfd);

            const struct sockaddr* sockaddr_cast(const struct sockaddr_in *addr);
            const struct sockaddr* sockaddr_cast(const struct sockaddr_in6 *addr);

            const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr);
            const struct sockaddr_in6* sockaddr_in6_cast(const struct sockaddr* addr);

            struct sockaddr_in6 getLocalAddr(int sockfd);
            struct sockaddr_in6 getPeerAddr(int sockfd);

            bool  isSelfConnect(int sockfd);

        }
    }
}

#endif //WENSLIB_SOCKETUTIL_H
