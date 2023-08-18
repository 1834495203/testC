//
// Created by asus on 2023/7/14.
//

#include "listQuiz.h"

LinkedList initLinkedListInHead() {
    printf("头插法创建链表\n");
    LinkedList list = malloc(sizeof(LinkedListNode));
    list->next = null;
    ListNode data;

    scanf("%c", &data);
    while (data != 'q') {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        temp->data = data, temp->next = null;
        if (list->next == null) list->next = temp;
        else {
            temp->next = list->next;
            list->next = temp;
        }
        scanf("%c", &data);
    }

    return list;
}

void print4LinkedList(LinkedList list) {
    if (list == null) return;
    LinkedList temp = list->next;
    while (temp != null){
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
