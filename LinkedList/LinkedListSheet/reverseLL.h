#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        stack<int> st;
        ListNode* it = head;
        while(it != NULL){
            st.push(it->val);
            it = it->next;
        }
        ListNode* temp = head;
        while(temp != NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};
