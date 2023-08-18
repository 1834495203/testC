//
// Created by asus on 2023/7/14.
//

#include "listSolution.h"

void reverseLinkedList(LinkedList list) {
    if (list == null || list->next == null) return;
    LinkedListNode *next = list->next;
    LinkedListNode *move = list->next->next;

    while (move != null) {
        list->next = move;
        
    }
}
