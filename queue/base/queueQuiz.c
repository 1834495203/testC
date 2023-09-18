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
    printf("ͷ�巨������ʽ���еĴ���\n");
    QueueNode *queueNode = malloc(sizeof(QueueNode));
    printf("������ڵ�ֵ: ");
    scanf_s("%d", queueNode);

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
        scanf_s("%d", queueNode);
    }
}

LinkedQueue* initLinkedQueue() {
    printf("��ʼ������\n");
    LinkedQueue *queue = malloc(sizeof(LinkedQueue));
    queue->head = null, queue->tail = null;
    return queue;
}

LinkedQueueP pop4LinkedQueue(LinkedQueue *queue) {
    printf("��һ���ڵ�: ");
    LinkedQueueP res = null;
    if (isLinkedQueueInit(queue) || isLinkedQueueEmpty(queue)) return res;
    if (queue->head == queue->tail) {
        //�ڵ�ֻ��һ�������
        res = queue->head;
        queue->head = null, queue->tail = null;
    } else {
        //����ڵ�
        res = queue->head;
        queue->head = queue->head->next;
    }
    if (res != null) printf("%c\n", res->data);
    return res;
}

void print4LinkedQueue(LinkedQueue *queue) {
    printf("������ʽ����: ");
    //������в�Ϊ��
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
    printf("��һ���ڵ�: ");
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
    if (isEmpty) printf("����Ϊ�գ�\n");
    return isEmpty;
}

boolean isLinkedQueueInit(LinkedQueue *queue) {
    boolean isInit = queue == null;
    if (isInit) printf("����δ��ʼ����\n");
    return isInit;
}

//�����ʼ��ʱ���е�β��ָ��������������е�Ԫ��
OrderedQueue *orderedQueueInit(const QueueNode *arr, int len) {
    if (len == 0 || len > MAX) return null;
    OrderedQueue *queue = malloc(sizeof(OrderedQueue));
    queue->head = -1;
    queue->tail = -1;
    queue->size = 0;
    for (int i = 0; i < len; ++i) {
        queue->data[++queue->tail] = arr[i];
        if (queue->head == -1) queue->head = 0;
        queue->size++;
    }
    return queue;
}

int push4OrderQueue(OrderedQueue *queue, QueueNode data) {
    if (queue == null) return -1;
    int index = (queue->tail + 1) % MAX;
    if (index == queue->head) return -1;
    else queue->tail = index;
    queue->data[queue->tail] = data;
    queue->size++;
    return 1;
}

int pop4OrderQueue(OrderedQueue *queue, QueueNode *data) {
    if (null == queue || -1 == queue->head) return -1;
    int index = (queue->head + 1) % MAX;
    *data = queue->data[queue->head];
    if (index == queue->tail) return -1;
    else queue->head = index;
    queue->size--;
    return 1;
}
