/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        // ListNode* next = head;
        while(head!=NULL)
        {
            ListNode* temp = new ListNode;
            temp->val = head->val;
            curr = temp;
            curr->next=prev;
            cout<<curr->val<<endl;            
            prev = curr;
            head = head->next;
            
        }
        return curr;
    }
};