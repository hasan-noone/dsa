#include <iostream>

using namespace std;
static int sizeLL = 0;
class Node{
public:
    int val;
    Node *prev;
    Node *next;
    // constructor
    Node(int data) : val(data),prev(nullptr), next(nullptr) {} 
};
//bunch of todos :
/**
 * Insertion at kth node [-]
 * deletion at kth node [-]
 * print all nodes [-]
 * free node [-]
*/

/**
 * This function is used to insert element at a given position
 * 
 * @param : Node head -> the first element
 *          int k -> is the position to enter
 *          int ele -> the element we want to insert. 
 * @return : return's head node after insertion of elements, wether at beginning/end or k.
 */
Node* insertKthPosition(Node *head,int k,int ele){
    Node *newNode = new Node(ele);

    // Simple case: list is empty, just create the first node
    if(head == nullptr && sizeLL == 0){
        sizeLL += 1;
        return newNode;
    }

    if(k < 0 || k >= sizeLL){
        //by default will add into the end.
        // Allow k == sizeLL to insert at the end properly
        Node *mover = head;
        while(mover->next != nullptr){
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
    while(i < (k - 1) && mover->next != nullptr){
        mover = mover->next;
        i += 1;
    }
    newNode->next = mover->next;
    newNode->prev = mover;
    
    if (mover->next != nullptr) {
        //this is to connect the node of newNode right side, if only its not a nullptr, cause if its a nullptr then newNode's by default have nullptr.
        mover->next->prev = newNode;
    }
    mover->next = newNode;
    sizeLL += 1;
    return head;
}


/**
 * This function deletes the k-th node from a doubly linked list.
 *
 * @param head : Pointer to the head of the doubly linked list.
 * @param k    : The zero-based index of the node to be deleted.
 *
 * @return     : Pointer to the updated head of the linked list.
 */
Node* deleteKthNode(Node* head, int k) {
    // If the list is empty, return nullptr as there is nothing to delete.
    if (head == nullptr) {
        return nullptr;
    }
    
    // Check if k is out of bounds.
    if (k >= sizeLL) {  
        printf("Invalid position, try again.\n");
        return head;
    }

    // Deleting the head node (first node).
    if (k == 0) {
        Node* newHead = head->next; // Update the head to the next node.
        if (newHead != nullptr) {
            newHead->prev = nullptr; // Unlink the old head from the new head.
        }
        free(head); // Free memory of the old head node.
        sizeLL--;   // Decrement the size of the list.
        return newHead; // Return the updated head.
    }

    // Deleting the last node (tail).
    if (k == sizeLL - 1) {
        Node* mover = head;
        while (mover->next) {  // Move to the last node.
            mover = mover->next;
        }
        mover->prev->next = nullptr; // Unlink the last node from the list.
        free(mover); // Free memory of the last node.
        sizeLL--; // Decrement the size of the list.
        return head; // Return the unchanged head.
    }

    // Deleting a middle node (any node that is not head or tail).
    Node* mover = head;
    for (int i = 0; i < k; i++) {
        mover = mover->next; // Move to the k-th node.
    }

    // Update pointers to unlink the k-th node.
    mover->prev->next = mover->next; 
    if (mover->next) { // Check to avoid dereferencing nullptr.
        mover->next->prev = mover->prev;
    }
    
    free(mover); // Free memory of the deleted node.
    sizeLL--; // Decrement the size of the list.

    return head; // Return the head of the updated list.
}
/**
 * This function is use to print DLL
 * @param : Node *head -> the head Node to get reference of other Node's.
 * 
 * @return : Nothing is returned as it is a void function.
 */
void printDoublyLL(Node* head) {
    if (head == nullptr) {
        cout << "NULL\n";
        return;
    }

    Node* mover = head;
    Node* tail = nullptr;

    // Print forward traversal with arrows
    cout << "NULL ↔ ";
    while (mover != nullptr) {
        cout << mover->val;
        tail = mover; // Track the last node

        if (mover->next != nullptr)
            cout << " ↔ ";
        
        mover = mover->next;
    }
    cout << " ↔ NULL\n";
}

/**
 * This function is used to free the memory before exiting from the program.
 * @param : Node* head -> This is the head Node which we will use to traverse in the LL. 
 * 
 * @return : Returns nothing, as it is use to free the memory. 
 */
void freeLL(Node* head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    head = nullptr;
    sizeLL = 0;
}

/**
 * Function to display the menu for the user
 */
void displayMenu() {
    cout << "\n---------- Doubly Linked List Operations ----------\n";
    cout << "1. Insert element at specified position\n";
    cout << "2. Delete element at specified position\n";
    cout << "3. Print doubly linked list\n";
    cout << "4. Get size of linked list\n";
    cout << "5. Exit program\n";
    cout << "---------------------------------------------------\n";
    cout << "Enter your choice (1-5): ";
}

int main(){
    Node* head = nullptr;
    int choice, position, element;
    bool running = true;

    while(running) {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: // Insert element
                cout << "Enter the element to insert: ";
                cin >> element;
                
                if (head == nullptr) {
                    // If list is empty, just insert at the beginning
                    head = insertKthPosition(head, 0, element);
                    cout << "Element " << element << " inserted as the first node.\n";
                } else {
                    cout << "Enter the position (0-indexed, -1 for end): ";
                    cin >> position;
                    
                    if (position == -1) {
                        position = sizeLL; // Insert at the end
                    }
                    
                    head = insertKthPosition(head, position, element);
                    cout << "Element " << element << " inserted successfully.\n";
                }
                break;
                
            case 2: // Delete element
                if (head == nullptr) {
                    cout << "List is empty, nothing to delete.\n";
                    break;
                }
                
                cout << "Enter the position to delete (0-" << sizeLL-1 << "): ";
                cin >> position;
                
                if (position < 0 || position >= sizeLL) {
                    cout << "Invalid position! Valid range is 0-" << sizeLL-1 << ".\n";
                } else {
                    head = deleteKthNode(head, position);
                    cout << "Element at position " << position << " deleted successfully.\n";
                }
                break;
                
            case 3: // Print list
                cout << "Current list: ";
                printDoublyLL(head);
                break;
                
            case 4: // Get size
                cout << "Current size of linked list: " << sizeLL << endl;
                break;
                
            case 5: // Exit
                cout << "Exiting program. Freeing memory...\n";
                freeLL(head);
                running = false;
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}