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
        scanf("%c", queueNode);
    }
}

LinkedQueue* initLinkedQueue() {
    printf("初始化队列\n");
    LinkedQueue *queue = malloc(sizeof(LinkedQueue));
    queue->head = null, queue->tail = null;
    return queue;
}

LinkedQueueP pop4LinkedQueue(LinkedQueue *queue) {
    printf("出一个节点: ");
    LinkedQueueP res = null;
    if (isLinkedQueueInit(queue) || isLinkedQueueEmpty(queue)) return res;
    if (queue->head == queue->tail) {
        //节点只有一个的情况
        res = queue->head;
        queue->head = null, queue->tail = null;
    } else {
        //多个节点
        res = queue->head;
        queue->head = queue->head->next;
    }
    if (res != null) printf("%c\n", res->data);
    return res;
}

void print4LinkedQueue(LinkedQueue *queue) {
    printf("遍历链式队列: ");
    //如果队列不为空
    if (!isLinkedQueueInit(queue) && !isLinkedQueueEmpty(queue)) {
        LinkedQueueNode *temp = queue->head;
        while (temp != null){
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

boolean push4LinkedQueue(LinkedQueue *queue, QueueNode node) {
    printf("入一个节点: ");
    if (isLinkedQueueInit(queue)) return false;
    printf("%c\n", node);
    LinkedQueueP temp = malloc(sizeof(LinkedQueue));
    temp->data = node, temp->next = null;

    if (queue->tail == null) {
        queue->head = temp;
        queue->tail = queue->head;
    } else {
        queue->tail->next = temp;
        queue->tail = temp;
    }
    return true;
}

boolean isLinkedQueueEmpty(LinkedQueue *queue) {
    boolean isEmpty = queue->tail == null && queue->head == null;
    if (isEmpty) printf("队列为空！\n");
    return isEmpty;
}

boolean isLinkedQueueInit(LinkedQueue *queue) {
    boolean isInit = queue == null;
    if (isInit) printf("队列未初始化！\n");
    return isInit;
}

