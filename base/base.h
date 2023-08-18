//
// Created by Administrator on 2023/6/28.
//

#ifndef TESTC_BASE_H
#define TESTC_BASE_H

#include "stdlib.h"
#include "stdio.h"

#define null ((void *) 0)

#ifndef new
#define new(type, size) malloc(sizeof(type)*(size))
#endif

#define f(p) free(p)

#define bind(x, y) x##y

#define stringify(x) #x

#define def(type, name, val) type name = val

#define true 1

#define false 0

#ifndef boolean
typedef int boolean;
#endif

typedef char* string;

#endif //TESTC_BASE_H
