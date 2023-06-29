//
// Created by Administrator on 2023/6/28.
//

#include "queueQuiz.h"

void test4Queue() {
    LinkedQueue queue;
    LinkedQueueP node1 = malloc(sizeof(LinkedQueueNode));
    node1->data = 10;
    LinkedQueueP node2 = malloc(sizeof(LinkedQueueNode));
    node2->data = 20;

    node1->next = node2;
    node2->next = null;

    queue.head = node1;
    queue.tail = node2;

    printf("%d %d", queue.head->data, queue.tail->data);
}

void build4LinkedQueueInHead(LinkedQueue *queue) {
    printf("头插法进行链式队列的创建\n");
    QueueNode *queueNode = malloc(sizeof(QueueNode));
    printf("请输入节点值: ");
    scanf("%c", queueNode);

    while (*queueNode != 'q') {
        LinkedQueueP temp = malloc(sizeof(LinkedQueueNode));
        temp->data = *queueNode;
        if (queue->head == null) {
            queue->head = temp;
            temp->next = null;
            queue->tail = queue->head;
        } else{
            temp->next = queue->head;
            queue->head = temp;
        }
        printf("请输入节点值: ");
        scanf("%c", queueNode);
    }
}

LinkedQueue initLinkedQueue() {
    LinkedQueue *queue = malloc(sizeof(LinkedQueue));
    queue->head = null, queue->tail = null;
    return *queue;
}