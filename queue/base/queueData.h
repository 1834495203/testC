//
// Created by asus on 2023/6/29.
//

#ifndef TESTC_QUEUEDATA_H
#define TESTC_QUEUEDATA_H

//队列节点类型的定义
typedef char QueueNode;

//顺序表队列的长度
#define MAX (1 << 3)

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

//顺序表队列
typedef struct OrderedQueueStruct {
    QueueNode data[MAX];
    int head, tail, size;
}OrderedQueue, *OrderedQueueP;

#endif //TESTC_QUEUEDATA_H
