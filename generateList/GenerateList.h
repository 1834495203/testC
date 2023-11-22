//
// Created by asus on 2023/10/21.
//

#ifndef TESTC_GENERATELIST_H
#define TESTC_GENERATELIST_H

#include "../base/base.h"

typedef int AutoType;

typedef enum {ATOM, LIST} ElemTag;

//广义表
typedef struct GLNode {
    ElemTag tag;
    union {
        AutoType atom;
        struct {
            struct GLNode *hp, *tp;
        } ptr;
    };
}GLNode, *GList;

#endif //TESTC_GENERATELIST_H
