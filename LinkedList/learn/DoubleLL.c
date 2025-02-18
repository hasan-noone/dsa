#include <stdio.h>
#include <stdlib.h>

static int sizeLL = 0;

// Node structure for doubly linked list
typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the k-th position
Node* insertKthPosition(Node* head, int k, int ele) {
    Node* newNode = createNode(ele);

    // Simple case: list is empty, just create the first node
    if (head == NULL && sizeLL == 0) {
        sizeLL += 1;
        return newNode;
    }

    if (k < 0 || k >= sizeLL) {
        // By default, add to the end
        Node* mover = head;
        while (mover->next != NULL) {
            mover = mover->next;
        }
        mover->next = newNode;
        newNode->prev = mover;
        sizeLL += 1;
        return head;
    }

    // If inserting at the head
    if (k == 0) {
        newNode->next = head;
        head->prev = newNode;
        sizeLL += 1;
        return newNode;
    }

    Node* mover = head;
    int i = 0;
    while (i < (k - 1) && mover->next != NULL) {
        mover = mover->next;
        i += 1;
    }
    newNode->next = mover->next;
    newNode->prev = mover;

    if (mover->next != NULL) {
        mover->next->prev = newNode;
    }
    mover->next = newNode;
    sizeLL += 1;
    return head;
}

// Function to delete the k-th node
Node* deleteKthNode(Node* head, int k) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Check if k is out of bounds
    if (k >= sizeLL) {
        printf("Invalid position, try again.\n");
        return head;
    }

    // Deleting the head node (first node)
    if (k == 0) {
        Node* newHead = head->next;
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        free(head);
        sizeLL--;
        return newHead;
    }

    // Deleting the last node (tail)
    if (k == sizeLL - 1) {
        Node* mover = head;
        while (mover->next) {
            mover = mover->next;
        }
        mover->prev->next = NULL;
        free(mover);
        sizeLL--;
        return head;
    }

    // Deleting a middle node
    Node* mover = head;
    for (int i = 0; i < k; i++) {
        mover = mover->next;
    }

    mover->prev->next = mover->next;
    if (mover->next) {
        mover->next->prev = mover->prev;
    }

    free(mover);
    sizeLL--;
    return head;
}

// Function to print the doubly linked list
void printDoublyLL(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    Node* mover = head;
    Node* tail = NULL;

    // Print forward traversal with arrows
    printf("NULL ↔ ");
    while (mover != NULL) {
        printf("%d", mover->val);
        tail = mover; // Track the last node

        if (mover->next != NULL)
            printf(" ↔ ");

        mover = mover->next;
    }
    printf(" ↔ NULL\n");
}

// Function to free the memory of the linked list
void freeLL(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;
    sizeLL = 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n---------- Doubly Linked List Operations ----------\n");
    printf("1. Insert element at specified position\n");
    printf("2. Delete element at specified position\n");
    printf("3. Print doubly linked list\n");
    printf("4. Get size of linked list\n");
    printf("5. Exit program\n");
    printf("---------------------------------------------------\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    Node* head = NULL;
    int choice, position, element;
    int running = 1;

    while (running) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert element
                printf("Enter the element to insert: ");
                scanf("%d", &element);

                if (head == NULL) {
                    // If list is empty, just insert at the beginning
                    head = insertKthPosition(head, 0, element);
                    printf("Element %d inserted as the first node.\n", element);
                } else {
                    printf("Enter the position (0-indexed, -1 for end): ");
                    scanf("%d", &position);

                    if (position == -1) {
                        position = sizeLL; // Insert at the end
                    }

                    head = insertKthPosition(head, position, element);
                    printf("Element %d inserted successfully.\n", element);
                }
                break;

            case 2: // Delete element
                if (head == NULL) {
                    printf("List is empty, nothing to delete.\n");
                    break;
                }

                printf("Enter the position to delete (0-%d): ", sizeLL - 1);
                scanf("%d", &position);

                if (position < 0 || position >= sizeLL) {
                    printf("Invalid position! Valid range is 0-%d.\n", sizeLL - 1);
                } else {
                    head = deleteKthNode(head, position);
                    printf("Element at position %d deleted successfully.\n", position);
                }
                break;

            case 3: // Print list
                printf("Current list: ");
                printDoublyLL(head);
                break;

            case 4: // Get size
                printf("Current size of linked list: %d\n", sizeLL);
                break;

            case 5: // Exit
                printf("Exiting program. Freeing memory...\n");
                freeLL(head);
                running = 0;
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
