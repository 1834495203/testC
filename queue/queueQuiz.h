//
// Created by Administrator on 2023/6/28.
//

#ifndef TESTC_QUEUEQUIZ_H
#define TESTC_QUEUEQUIZ_H

#include "../base/base.h"

typedef char QueueNode;

//链式队列的节点
typedef struct LinkedQueueNodeStruct {
    QueueNode data;
    struct LinkedQueueNodeStruct *next;
}LinkedQueueNode, *LinkedQueueP;

//链式队列
typedef struct LinkedQueueStruct {
    LinkedQueueP head;
    LinkedQueueP tail;
}LinkedQueue;

void test4Queue();

/**
 * 初始化链式队列
 * @return 链式队列
 */
LinkedQueue initLinkedQueue();

/**
 * 链式队列头插法
 * @param queue 链式队列指针 指向头节点
 */
void build4LinkedQueueInHead(LinkedQueue *queue);

#endif //TESTC_QUEUEQUIZ_H
