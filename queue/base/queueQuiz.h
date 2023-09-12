//
// Created by Administrator on 2023/6/28.
//

#ifndef TESTC_QUEUEQUIZ_H
#define TESTC_QUEUEQUIZ_H

#include "../../base/base.h"
#include "queueData.h"

void test4Queue();

/**
 * 初始化链式队列
 * @return 链式队列
 */
LinkedQueue* initLinkedQueue();

/**
 * 链式队列头插法
 * @param queue 链式队列指针 指向头节点
 */
void build4LinkedQueueInHead(LinkedQueue *queue);

/**
 * 出一个节点链式队列
 * @param queue 链式队列
 * @return 出队列的节点
 */
LinkedQueueP pop4LinkedQueue(LinkedQueue *queue);

/**
 * 入一个节点链式队列
 * @param queue 链式队列
 * @param node  入队列的节点
 * @return 是否插入成功
 */
boolean push4LinkedQueue(LinkedQueue *queue, QueueNode node);

/**
 * 遍历链式队列
 * @param queue 队列
 */
void print4LinkedQueue(LinkedQueue *queue);

/**
 * 判断链式队列是否为空
 * @param queue 队列
 * @return 判断
 */
boolean isLinkedQueueEmpty(LinkedQueue *queue);

/**
 * 判断链式队列是否初始化
 * @param queue
 * @return 判断
 */
boolean isLinkedQueueInit(LinkedQueue *queue);

/**
 * 创建循序队列
 * @param arr 数组元素
 * @param len 长度
 * @return 循环队列
 */
OrderedQueue *orderedQueueInit(const QueueNode *arr, int len);

/**
 * 向循环队列插入元素
 * @param queue 队列
 * @param data 数据
 * @return 是否插入成功
 */
int push4OrderQueue(OrderedQueue *queue, QueueNode data);

/**
 * 从队列中取出一个元素
 * @param queue 队列
 * @param data 取出的数据
 * @return 是否成功取出
 */
int pop4OrderQueue(OrderedQueue *queue, QueueNode *data);

#endif //TESTC_QUEUEQUIZ_H