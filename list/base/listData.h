//
// Created by asus on 2023/7/14.
//

#ifndef TESTC_LISTDATA_H
#define TESTC_LISTDATA_H

#define ORDER_LIST_MAX_LENGTH (1 << 4)

//队列节点类型的定义
typedef int ListNode;

//链表数据结构
typedef struct linkedList {
    ListNode data;
    struct linkedList *next;
}LinkedListNode, *LinkedList;

//循序表数据结构
typedef struct OrderedList {
    ListNode data[ORDER_LIST_MAX_LENGTH];
    int size;
}OrderedList;

#endif //TESTC_LISTDATA_H
