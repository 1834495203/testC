//
// Created by asus on 2023/10/2.
//

#ifndef TESTC_STACKDATA_H
#define TESTC_STACKDATA_H

#include "../base/base.h"
#include "../tree/base/treeData.h"

typedef TreeNode ElemType4Stack;

//带头节点的链栈
typedef struct Stack {
    ElemType4Stack *data;
    struct Stack *next;
}LinkedStack;

/**
 * 初始化栈
 * @return 栈
 */
LinkedStack *initLinkedStack();

/**
 * 向链栈中插入数据
 * @param stack 链栈
 * @param data 数据
 */
void push4LinkedStack(LinkedStack *stack, ElemType4Stack *data);

/**
 * 出栈
 * @param stack 链栈
 * @return 数据
 */
ElemType4Stack *pop4LinkedStack(LinkedStack *stack);

/**
 * 链栈是否为空
 * @param stack 链栈
 * @return
 */
int isLinkedStackEmpty(LinkedStack *stack);

/**
 * 求链栈长度
 * @param stack 链栈
 * @return 长度
 */
int getLinkedStackSize(LinkedStack *stack);

#endif //TESTC_STACKDATA_H
