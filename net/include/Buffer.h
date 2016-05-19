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

#ifndef WENSLIB_BUFFER_H
#define WENSLIB_BUFFER_H

#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>

#include <vector>
#include <string>
#include <algorithm>


namespace wens
{
    namespace net
    {
        /**
         *  A buffer class modeled after org.jboss.netty.buffer.ChannelBuffer
         *  @code
         *   +-------------------+------------------+------------------+
         *   | prependable bytes |  readable bytes  |  writable bytes  |
         *   |                   |     (CONTENT)    |                  |
         *   +-------------------+------------------+------------------+
         *   |                   |                  |                  |
         *   0      <=      readerIndex   <=   writerIndex    <=     size
         *   @endcode
         */
        class Buffer
        {
        private:
            std::vector<char> buffer_;
            size_t readerIndex_;
            size_t writerIndex_;

            static const char kCRLF[];

        public:
            static const size_t kCheapPrepend = 8;
            static const size_t kInitialSize = 1024;

            /**
             * constructor
             */
            explicit Buffer(size_t initialSize = kInitialSize): buffer_(kCheapPrepend + initialSize),
                                                                 readerIndex_(kCheapPrepend),
                                                                 writerIndex_(kCheapPrepend)
            {
                assert(readableBytes() == 0);
                assert(writableBytes() == initialSize);
                assert(prependableBytes() == kCheapPrepend);

            }

            /**
             *   implicit copy-ctor, move-ctor, dtor and assignment are fine
             *   NOTE: implicit move-ctor is added in g++ 4.6
             */

            void swap(Buffer &rhs)
            {
                buffer_.swap(rhs.buffer_);
                std::swap(readerIndex_, rhs.readerIndex_);
                std::swap(writerIndex_, rhs.writerIndex_);

            }

            size_t readableBytes() const
            {
                return writerIndex_ - readerIndex_;
            }

            size_t writableBytes() const
            {
                return buffer_.size() - writerIndex_;
            }

            size_t prependableBytes() const
            {
                return readerIndex_;
            }

            const char* peek() const
            {
                return  begin() + readerIndex_;
            }

            const char* findCRLF() const
            {
                const char *crlf = std::search(peek(), beginWrite(), kCRLF, kCRLF + 2);
                return crlf == beginWrite()? nullptr : crlf;
            }

            const char* findCRLF(const char *start) const
            {
                assert(peek() <= start);
                assert(start <= beginWrite());

                const char *crlf = std::search(start, beginWrite(), kCRLF, kCRLF + 2);
                return crlf == beginWrite()? nullptr : crlf;
            }

            const char* findEOL() const
            {
                const void *eol = memchr(peek(), '\n', readableBytes());
                return static_cast<const char*>(eol);
            }

            const char* findEOL(const char *start) const
            {
                assert(peek() <= start);
                assert(start <= beginWrite());

                const void *eol = memchr(start, '\n', beginWrite() - start);
                return static_cast<const char*>(eol);

            }

            void reset()
            {
                readerIndex_ = kCheapPrepend;
                writerIndex_ = kCheapPrepend;
            }

            /**
             *  retrieve function returns void to prevent following situation:
             *
             *  ep: string mystr(retrieve(readableBytes()), readableBytes())
             *  the evaluation of two functions are unspecified
             */
            void retrieve(size_t len)
            {
                assert(len <= readableBytes());
                if (len <= readableBytes())
                    readerIndex_ += len;
                else
                    reset();
            }

            void retrieveUntil(const char* end)
            {
                assert(peek() <= end);
                assert(end <= beginWrite());

                retrieve(end - peek());
            }

            std::string retrieveAsString(size_t len)
            {
                assert(len >= readableBytes());

                std::string result(peek(), len);
                retrieve(len);

                return  result;
            }

            std::string retrieveAllString()
            {
                return retrieveAsString(readableBytes());
            }

            void ensureWritableBytes(size_t len)
            {
                if (writableBytes() < len)
                    makeSpace(len);

                assert(writableBytes() >= len);

            }

            void append(const char *str, size_t len)
            {
                ensureWritableBytes(len);
                std::copy(str, str + len, beginWrite());
            }

            void append(const void *str, size_t len)
            {
                append(static_cast<const char*>(str), len);
            }

            void doWritten(size_t len)
            {
                assert(writableBytes() >= len);
                writerIndex_ += len;
            }

            void undoWritten(size_t len)
            {
                assert(readableBytes() >= len);
                writerIndex_ -= len;
            }

//            ssize_t readFD(int fd, int *errno);

        private:
            char* begin()
            {
                return &*buffer_.begin();
            }
            const char* begin() const
            {
                return &*buffer_.begin();
            }

            //have function peek()
          /*  char* beginRead() {return begin() + readerIndex_;}
            const char* beginRead() { return  begin() + readerIndex_;}*/

            char* beginWrite() { return begin() + writerIndex_;}
            const char* beginWrite() const {return begin() + writerIndex_;}

            void makeSpace(size_t len)
            {
                //if there is no space, then resize buffer_
                if (writableBytes() + prependableBytes() < len + kCheapPrepend) {
                    buffer_.resize(writerIndex_ + len);
                }
                else // get space in prependableBytes() ---> (readerIndex_ - kCheapPrepend)
                {
                    assert(kCheapPrepend < prependableBytes());

                    size_t  readable = readableBytes();

                    std::copy(begin() + readerIndex_, begin() + writerIndex_, begin() + kCheapPrepend);
                    readerIndex_ = kCheapPrepend;
                    writerIndex_ = readerIndex_ + readable;
                    assert(readable == readableBytes());

                }

            }



        };

    }
}



#endif //WENSLIB_BUFFER_H
