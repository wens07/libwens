//
//  io.h
//  libwens
//
//  Created by wengqiang on 30/12/15.
//  Copyright (c) 2015 wengqiang. All rights reserved.
//

#ifndef libwens_io_h
#define libwens_io_h

#include "macros.h"

_LIBWENS_START

/**
 *  read a line from input until encounter a newline or EOF, and return the length
 * 	the line will contain the newline character
 *
 *  @param line   the line for input
 *  @param maxlen the max lenght of the line
 *
 *  @return the len of line
 */
int getline(char line[], int maxlen);

_LIBWENS_END


#endif
