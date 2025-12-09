#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create a doubly linked list (insert at end)
struct Node* createList(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// b) Insert a new node to the LEFT of the node with specific value
struct Node* insertLeft(struct Node* head, int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }

    struct Node* newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;  // Inserted at beginning

    temp->prev = newNode;

    return head;
}

// c) Delete node based on a specific value
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;   // Deleted first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d deleted.\n", value);

    return head;
}

// d) Display contents of the list
void display(struct Node* head) {
    struct Node* temp = head;

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create (Insert at end)\n");
        printf("2. Insert to the LEFT of a value\n");
        printf("3. Delete a node by value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                head = createList(head, value);
                break;

            case 2:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                head = insertLeft(head, target, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}
