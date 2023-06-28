//
// Created by Administrator on 2023/6/28.
//

#ifndef TESTC_TREEQUIZ_H
#define TESTC_TREEQUIZ_H

#include "stdlib.h"
#include "stdio.h"
#define null ((void *)0)

typedef int Node;

//二叉树
typedef struct TreeStruct{
    Node data;
    struct TreeStruct *leftNode;
    struct TreeStruct *rightNode;
}TreeNode, *Tree;

//构造
int build(Tree head);

#endif //TESTC_TREEQUIZ_H
