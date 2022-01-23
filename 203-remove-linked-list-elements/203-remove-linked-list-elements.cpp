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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res;
        
        while(head!=NULL && head->val==val)
        {
            head = head->next;
        }
        if(head==NULL)
            return NULL;
        res = head;
        ListNode *temp=head;
        if(temp->next==NULL)
        {
            return res;
        }
        ListNode* prev = temp;
        temp = temp->next;
        // cout<<temp->val<<" "<<prev->val<<endl;
        while(temp!=NULL)
        {
            if(temp->val == val)
            {
                prev->next = temp->next;
            }
            else
                prev = temp;
            temp = temp->next;
        }
        return res;
    }
};