#include "tree/treeQuiz.h"
#include "queue/queueQuiz.h"

int main() {
    LinkedQueue *queue = initLinkedQueue();
    build4LinkedQueueInHead(queue);
    print4LinkedQueue(queue);

    pop4LinkedQueue(queue);
    push4LinkedQueue(queue, 'x');
    pop4LinkedQueue(queue);
    push4LinkedQueue(queue, 'y');
    pop4LinkedQueue(queue);
    pop4LinkedQueue(queue);

    print4LinkedQueue(queue);
    return 0;
}
