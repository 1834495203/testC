//
// Created by asus on 2023/7/21.
//

#ifndef TESTC_TREEDATA_H
#define TESTC_TREEDATA_H

#include "../../base/base.h"

typedef int Node;

//二叉树
typedef struct TreeStruct {
    Node data;
    struct TreeStruct *lchild, *rchild;
}TreeNode, *Tree;

//线索二叉树
typedef struct ThreadNode {
    Node data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;                     // 0为孩子节点，1为前驱或后继
}ThreadNode, *ThreadTree;

#endif //TESTC_TREEDATA_H
