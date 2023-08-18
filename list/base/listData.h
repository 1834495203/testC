//
// Created by asus on 2023/7/14.
//

#ifndef TESTC_LISTDATA_H
#define TESTC_LISTDATA_H

//队列节点类型的定义
typedef char ListNode;

//链表数据结构
typedef struct linkedList {
    ListNode data;
    struct linkedList *next;
}LinkedListNode, *LinkedList;

#endif //TESTC_LISTDATA_H
