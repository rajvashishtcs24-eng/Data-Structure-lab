#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

////////////////////////////////////////////////////
// STACK IMPLEMENTATION USING SINGLY LINKED LIST
////////////////////////////////////////////////////

// Push (Insert at beginning)
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    return top;
}

// Pop (Delete from beginning)
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("STACK UNDERFLOW!\n");
        return NULL;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

// Display Stack
void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////
// QUEUE IMPLEMENTATION USING SINGLY LINKED LIST
////////////////////////////////////////////////////

// Enqueue (Insert at end)
struct Node* enqueue(struct Node* front, int value) {
    struct Node* newNode = createNode(value);

    if (front == NULL)
        return newNode;

    struct Node* temp = front;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return front;
}

// Dequeue (Delete from beginning)
struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("QUEUE UNDERFLOW!\n");
        return NULL;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    free(temp);
    return front;
}

// Display Queue
void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////
// MAIN MENU
////////////////////////////////////////////////////

int main() {
    struct Node *stackTop = NULL;
    struct Node *queueFront = NULL;
    int choice, value;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. PUSH (Stack)\n");
        printf("2. POP (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. ENQUEUE (Queue)\n");
        printf("5. DEQUEUE (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                stackTop = push(stackTop, value);
                break;

            case 2:
                stackTop = pop(stackTop);
                break;

            case 3:
                displayStack(stackTop);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                queueFront = enqueue(queueFront, value);
                break;

            case 5:
                queueFront = dequeue(queueFront);
                break;

            case 6:
                displayQueue(queueFront);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
