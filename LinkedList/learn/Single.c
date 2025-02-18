#include <stdio.h>
#include <stdlib.h>

// Global variable to track the size of the linked list
static int size = 0;

// Definition of the Node structure
struct Node {
    int val;
    struct Node* next;
};

// Function to create a new node
struct Node* createNewNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Allocation failed.\n");
        return NULL;
    }
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    if (current == NULL) {
        printf("Empty");
    }
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at a specified position
struct Node* insertNode(int ele, int position, struct Node* head) {
    // Simple case: list is empty, just create the first node
    if (head == NULL) {
        head = createNewNode(ele);
        if (head != NULL) {
            size = 1;
        }
        return head;
    }
    
    // Edge case: invalid position
    if (position < 0 || position > size) {
        printf("Invalid Position entered, try again.\n");
        return head;
    }
    
    // Special case: insert at the head
    if (position == 0) {
        struct Node* newHead = createNewNode(ele);
        if (newHead == NULL) {
            return head;
        }
        newHead->next = head;
        size += 1;
        return newHead;
    }
    
    // Traverse to the node before the insert position
    struct Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    // Insert the new node
    struct Node* newNode = createNewNode(ele);
    if (newNode == NULL) {
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    size += 1;
    return head;
}

// Function to delete a node at a specified position
struct Node* deleteNode(int position, struct Node* head) {
    // Edge case: if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // Edge case: invalid position
    if (position < 0 || position > size - 1) {
        printf("Invalid position.\n");
        return head;
    }
    
    // Special case: deleting the head node
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        size -= 1;
        return head;
    }
    
    // Traverse to the node before the one to be deleted
    struct Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    // Remove the node from the list
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    size -= 1;
    return head;
}

// Function to free all memory before exiting
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function with switch case menu
int main() {
    struct Node* head = NULL;
    int choice, ele, pos;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (head == NULL) {
                    // If list is empty, directly insert the element
                    printf("Enter value to insert: ");
                    scanf("%d", &ele);
                    head = createNewNode(ele);
                    if (head != NULL) {
                        size = 1;
                        printf("Element %d inserted as first node\n", ele);
                    }
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &ele);
                    printf("Enter position to insert at (0 for beginning to %d): ", size);
                    scanf("%d", &pos);
                    head = insertNode(ele, pos, head);
                }
                break;
            
            case 2:
                if (head == NULL) {
                    printf("List is empty, nothing to delete\n");
                } else if (head->next == NULL) {
                    // If only one element exists, directly delete it
                    free(head);
                    head = NULL;
                    size = 0;
                    printf("Single element deleted, list is now empty\n");
                } else {
                    printf("Enter position to delete (0 for first element to %d): ",size);
                    scanf("%d", &pos);
                    head = deleteNode(pos, head);
                }
                break;
            
            case 3:
                printList(head);
                printf("List size: %d\n", size);
                break;
            
            case 4:
                printf("Exiting...\n");
                freeList(head);
                return 0;
            
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}