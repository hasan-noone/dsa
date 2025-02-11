#include <iostream>
#include <vector>

using namespace std;

// Bunch of todos
// - Implement an array based conversion->LL. [-]
// - able to traverse, get size, check if an element is present or not. []
// - able to delete a node/element from the list. []
// - able to add elements into the list. []

struct Node {
    int data;
    Node *next;
    //constructor
    Node(int val){
        data = val;
        next = nullptr;
    }
};

// convert array to LinkedList
/**
 * @brief : Will take a vector and convert each element to Linked list Node
 * @param : vector of int type
 * @return : will return the head of the Linkedlist
 */
Node *convertArrayToLinkedList(vector<int> &nums) {
    if (nums.empty()) return nullptr; // Handle empty array case

    Node *head = new Node(nums[0]); // Create the first node
    Node *mover = head; // Pointer to track the last node

    int i = 1;
    while (i < nums.size()) {
        mover->next = new Node(nums[i]); // Create a new node and link it
        mover = mover->next; // Move to the new node
        i += 1; // Increment index
    }
    return head; // Return the head of the linked list
}
int main() {
    
    return 0; 
}
