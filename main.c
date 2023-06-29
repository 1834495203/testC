#include "tree/treeQuiz.h"
#include "queue/queueQuiz.h"

int main() {
    LinkedQueue queue = initLinkedQueue();
    build4LinkedQueueInHead(&queue);

    LinkedQueueP temp = queue.head;

    while (temp != null) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    return 0;
}
