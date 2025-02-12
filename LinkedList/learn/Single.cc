#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Bunch of todos
// - Implement an array based conversion->LL. [-]
// - able to traverse, get size, check if an element is present or not. [-]
// - able to delete a node/element from the list. [-]
// - able to add elements into the list. [-]

struct Node {
    int data;
    Node *next;
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

/**
 * @brief Converts an array to a linked list.
 * @param nums A vector of integers to be converted into a linked list.
 * @return The head of the newly created linked list.
 */
Node *convertArrayToLinkedList(vector<int> &nums) {
    if (nums.empty()) return nullptr;  // Handle empty array case

    Node *head = new Node(nums[0]);  // Create the first node
    Node *mover = head;              // Pointer to track the last node

    int i = 1;
    while (i < nums.size()) {
        mover->next = new Node(nums[i]);  // Create a new node and link it
        mover = mover->next;              // Move to the new node
        i += 1;                           // Increment index
    }
    return head;  // Return the head of the linked list
}

/**
 * @brief Checks if a target element is present in the linked list.
 * @param head The head of the linked list.
 * @param target The element to search for.
 * @return True if the element is found, false otherwise.
 */
bool checkPresence(Node *head, int target) {
    Node *mover = head;
    while (mover != nullptr) {
        if (mover->data == target) return true;
        mover = mover->next;
    }
    return false;
}

/**
 * @brief Prints the elements of the linked list.
 * @param head The head of the linked list.
 */
void printLL(Node *head) {
    Node *mover = head;
    while (mover != nullptr) {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

/**
 * @brief Calculates the length of the linked list.
 * @param head The head of the linked list.
 * @return The number of nodes in the linked list.
 */
int lengthOfLL(Node *head) {
    if (head == nullptr) return 0;
    int cnt = 0;
    Node *mover = head;
    while (mover != nullptr) {
        cnt += 1;
        mover = mover->next;
    }
    return cnt;
}

/**
 * @brief Deletes a node at a specific position in the linked list.
 * @param head The head of the linked list.
 * @param pos The position of the node to delete (0-based index).
 * @return The head of the modified linked list.
 */
Node *deleteNode(Node *head, int pos) {
    if (head == nullptr) return nullptr;  // Edge case: empty list

    // Delete the head node
    if (pos == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Traverse to the node just before the deletion position
    int cnt = 0;
    Node *mover = head;
    while (mover != nullptr && cnt < pos - 1) {
        mover = mover->next;
        cnt += 1;
    }

    // Check if the position is valid
    if (mover == nullptr || mover->next == nullptr) return head;

    // Delete the node
    Node *temp = mover->next;
    mover->next = temp->next;
    delete temp;
    return head;
}

/**
 * @brief Inserts a new node with a given element at a specific position.
 * @param head The head of the linked list.
 * @param pos The position at which to insert the new node (0-based index).
 * @param element The element to insert.
 * @return The head of the modified linked list.
 */
Node *insertNode(Node *head, int pos, int element) {
    if (head == nullptr) return nullptr;  // Edge case: empty list

    // Insert at the head node
    if (pos == 0) {
        Node *newHead = new Node(element);
        newHead->next = head;
        return newHead;
    }

    // Traverse to the node just before the insertion position
    Node *mover = head;
    int cnt = 0;
    while (mover != nullptr && cnt < pos - 1) {
        mover = mover->next;
        cnt++;
    }

    // Check if the position is valid
    if (mover == nullptr) return head;

    // Insert the new node
    Node *newNode = new Node(element);
    newNode->next = mover->next;
    mover->next = newNode;
    return head;
}

/**
 * @brief Main function to demonstrate linked list operations.
 */
int main() {
    Node *head = nullptr;
    vector<int> nums;
    int choice, element, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Convert array to linked list\n";
        cout << "2. Print linked list\n";
        cout << "3. Check if an element is present\n";
        cout << "4. Get length of linked list\n";
        cout << "5. Delete a node\n";
        cout << "6. Insert a node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the number of elements: ";
                int n;
                cin >> n;
                nums.clear();
                cout << "Enter the elements: ";
                for (int i = 0; i < n; i++) {
                    int val;
                    cin >> val;
                    nums.push_back(val);
                }
                head = convertArrayToLinkedList(nums);
                cout << "Linked list created.\n";
                break;
            }
            case 2: {
                cout << "Linked list: ";
                printLL(head);
                break;
            }
            case 3: {
                cout << "Enter the element to search: ";
                cin >> element;
                if (checkPresence(head, element)) {
                    cout << "Element is present.\n";
                } else {
                    cout << "Element is not present.\n";
                }
                break;
            }
            case 4: {
                cout << "Length of linked list: " << lengthOfLL(head) << endl;
                break;
            }
            case 5: {
                cout << "Enter the position to delete: ";
                cin >> pos;
                head = deleteNode(head, pos);
                cout << "Node deleted.\n";
                break;
            }
            case 6: {
                cout << "Enter the position to insert: ";
                cin >> pos;
                cout << "Enter the element to insert: ";
                cin >> element;
                head = insertNode(head, pos, element);
                cout << "Node inserted.\n";
                break;
            }
            case 7: {
                cout << "Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}
