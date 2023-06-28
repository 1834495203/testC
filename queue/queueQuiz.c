//
// Created by Administrator on 2023/6/28.
//

#include "queueQuiz.h"

void test4Queue() {
    Queue queue;
    LinkedQueue node1 = malloc(sizeof(LinkedQueueNode));
    node1->data = 10;
    LinkedQueue node2 = malloc(sizeof(LinkedQueueNode));
    node2->data = 20;

    node1->next = node2;
    node2->next = null;

    queue.head = node1;
    queue.tail = node2;

    printf("%d %d", queue.head->data, queue.tail->data);
}