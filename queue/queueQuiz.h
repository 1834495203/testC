//
// Created by Administrator on 2023/6/28.
//

#ifndef TESTC_QUEUEQUIZ_H
#define TESTC_QUEUEQUIZ_H

#include "../base/base.h"

typedef int Node;

//链式队列节点
typedef struct LinkedQueueNodeStruct {
    Node data;
    struct LinkedQueueNodeStruct *next;
}LinkedQueueNode, *LinkedQueue;

typedef struct LinkedQueueStruct {
    LinkedQueue head;
    LinkedQueue tail;
}Queue;

void test4Queue();

#endif //TESTC_QUEUEQUIZ_H
