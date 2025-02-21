#ifndef MIDDLE_LINKED_LIST_H_
#define MIDDLE_LINKED_LIST_H_

/**
 * @file middle_linked_list.h
 * @brief Defines a solution to find the middle node of a singly linked list.
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;        ///< Value of the node.
    ListNode* next; ///< Pointer to the next node.

    /**
     * @brief Default constructor initializes value to 0 and next to nullptr.
     */
    ListNode() : val(0), next(nullptr) {}

    /**
     * @brief Constructor that initializes node with a given value.
     * @param x Value to initialize the node with.
     */
    ListNode(int x) : val(x), next(nullptr) {}

    /**
     * @brief Constructor that initializes node with a given value and next pointer.
     * @param x Value to initialize the node with.
     * @param next Pointer to the next node in the list.
     */
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * @class Solution
 * @brief Provides methods to determine the middle node of a linked list.
 */
class Solution {
public:
    /**
     * @brief Computes the length of a linked list.
     * @param head Pointer to the head of the linked list.
     * @return The length of the linked list.
     */
    int lengthOfLL(ListNode* head) {
        int cnt = 0;
        ListNode* mover = head;
        while (mover != nullptr) {
            mover = mover->next;
            cnt += 1;
        }
        return cnt;
    }

    /**
     * @brief Finds the middle node of a linked list.
     * @param head Pointer to the head of the linked list.
     * @return Pointer to the middle node of the linked list.
     */
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        int cnt = lengthOfLL(head);
        cnt = cnt / 2; // Middle index for zero-based indexing.
        ListNode* temp = head;
        while (cnt--) {
            temp = temp->next;
        }
        return temp;
    }
};

#endif  // MIDDLE_LINKED_LIST_H_
