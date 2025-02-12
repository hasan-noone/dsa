#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false -1
/**
 * Structure representing a node in the singly linked list.
 */
struct Node {
    int val;          // Value stored in the node
    struct Node *next; // Pointer to the next node in the list
};
/**
 * Checks presence of the element in linked list.
 *
 * @param head pointer to the head of the linked list.
 * @return 1-> if element is present -1 -> if element is not present.
 * This function iterates through out the list and check if the target Node presence.
 * */ 
int checkPresence(struct Node* head,int target){
    if(head == NULL) return false;
    //mover iterater to traverse into the list
    struct Node* mover = head;
    while(mover != NULL)
    {
        if(mover->val == target){
            return true;
        }
        mover = mover->next;
    }
    return false;
}
/**
 * Calculates the length of the linked list.
 *
 * @param head Pointer to the head of the linked list
 * @return Number of nodes in the linked list
 *
 * This function iterates through the entire list and counts the number of nodes.
 * It is used to determine valid positions for insertion and deletion.
 */
int lengthOfLL(struct Node* head) {
    int count = 0;
    struct Node* mover = head;
    while (mover != NULL) {
        mover = mover->next;
        count++;
    }
    return count;
}

/**
 * Creates a new node with the given value.
 *
 * @param data Value to be stored in the new node
 * @return Pointer to the newly created node, or NULL if memory allocation fails
 *
 * This function dynamically allocates memory for a new node.
 * If memory allocation fails, it prints an error message and returns NULL.
 */
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * Inserts a new node at the kth position in the linked list.
 *
 * @param head Pointer to the head of the list
 * @param element Value to be inserted
 * @param k Position where the new node should be inserted (0-based index)
 * @return Updated head pointer of the list
 *
 * Edge cases handled:
 * - If `k` is negative or greater than the length of the list, insertion is ignored.
 * - If inserting at position `0`, the new node becomes the new head.
 * - If inserting in the middle or end, the function properly updates the links.
 */
struct Node *insertNode(struct Node *head, int element, int k) {
    int size = lengthOfLL(head);  // Compute size only when needed

    // Handle invalid positions
    if (k < 0 || k > size) return head;

    // Special case: inserting at head (k = 0)
    if (k == 0) {
        struct Node *newHead = createNode(element);
        if (newHead == NULL) return head;  // Handle memory allocation failure
        newHead->next = head;
        return newHead;
    }

    // Traverse to the node before the insertion point
    struct Node *current = head;
    for (int i = 0; i < k - 1; i++) {
        current = current->next;
    }

    // Create and insert new node
    struct Node *newNode = createNode(element);
    if (newNode == NULL) return head;  // Handle memory allocation failure

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

/**
 * Deletes a node at the kth position in the linked list.
 *
 * @param head Pointer to the head of the list
 * @param k Position of the node to be deleted (0-based index)
 * @return Updated head pointer of the list
 *
 * Edge cases handled:
 * - If the list is empty (`head == NULL`), deletion is ignored.
 * - If `k` is negative or greater than or equal to the list length, deletion is ignored.
 * - If deleting the head node, the head is updated to the next node.
 * - If deleting from the middle or end, links are updated properly.
 */
struct Node *deleteNode(struct Node *head, int k) {
    int size = lengthOfLL(head);  // Compute size only when needed

    // Handle invalid positions
    if (head == NULL || k < 0 || k >= size) return head;

    struct Node *temp = head;

    // Special case: deleting the head node
    if (k == 0) {
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse to the node before the one to be deleted
    struct Node *prev = NULL;
    for (int i = 0; i < k; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

/**
 * Prints the linked list in a readable format.
 *
 * @param head Pointer to the head of the linked list
 *
 * The function iterates through the list and prints each node's value,
 * followed by an arrow (`->`), until reaching the end (`NULL`).
 */
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * Driver function to test linked list operations.
 */
int main() {
    struct Node *head = NULL;

    // Insert some nodes
    head = insertNode(head, 10, 0); // Insert 10 at position 0
    head = insertNode(head, 20, 1); // Insert 20 at position 1
    head = insertNode(head, 30, 1); // Insert 30 at position 1 (between 10 and 20)
    head = insertNode(head, 40, 3); // Insert 40 at position 3

    printf("Linked List after insertions: ");
    printList(head);

    // Delete a node
    head = deleteNode(head, 1); // Delete node at position 1

    printf("Linked List after deletion: ");
    printList(head);

    return 0;
}
