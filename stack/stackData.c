//
// Created by asus on 2023/10/2.
//

#include "stackData.h"

LinkedStack *initLinkedStack() {
    LinkedStack *stack = malloc(sizeof(struct Stack));
    stack->next = null;
    return stack;
}

void push4LinkedStack(LinkedStack *stack, ElemType4Stack *data) {
    if (stack == null) stack = initLinkedStack();
    LinkedStack *temp = malloc(sizeof(struct Stack));
    temp->data = data;
    temp->next = stack->next;
    stack->next = temp;
}

ElemType4Stack *pop4LinkedStack(LinkedStack *stack) {
    if (stack == null) return null;
    LinkedStack *temp = stack->next;
    if (temp != null)
        stack->next = temp->next;
    else stack->next = null;
    return &temp->data;
}

int isLinkedStackEmpty(LinkedStack *stack) {
    return stack->next == null;
}

int getLinkedStackSize(LinkedStack *stack) {
    int len = 0;
    LinkedStack *temp = stack;
    while (temp) {
        temp = temp->next;
        len++;
    }
    return len;
}
