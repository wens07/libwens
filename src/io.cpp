//
//  wensio.c
//  libwens
//
//  Created by wengqiang on 30/12/15.
//  Copyright (c) 2015 wengqiang. All rights reserved.
//

#include "macros.h"

_LIBWENS_START

/**
 *  read a line from input, and return the length
 *
 *  @param line   the line for input
 *  @param maxlen the max lenght of the line
 *
 *  @return the len of line
 */
int getline(char line[], int maxlen)
{
    int c, i;
    
    //read the line, store in line[]
    //because [maxlen - 1] should store '\0'
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    
    if (c == '\n')   line[i++] = '\n';
    
    line[i] = '\0';
    
    return i;
    
}

_LIBWENS_END

