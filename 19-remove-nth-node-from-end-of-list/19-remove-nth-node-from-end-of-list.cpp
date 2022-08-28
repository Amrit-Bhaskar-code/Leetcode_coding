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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp = head;
        while(n--)
        {
            temp = temp->next;
        }
        if(temp==NULL) return head->next;
        ListNode* temp_2 = head; 
        ListNode* prev = NULL;
        while(temp!=NULL)
        {
            temp = temp->next;
            prev = temp_2;
            temp_2 = temp_2->next;
        }
        prev->next = prev->next->next;
        return head;
        
    }
};