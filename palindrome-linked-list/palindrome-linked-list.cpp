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
            // cout<<curr->val<<endl;            
            prev = curr;
            head = head->next;
            
        }
        return curr;
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        int l=0;
         ListNode *temp = head;
        if(head==NULL || head->next==NULL)
            return true;
        
        while(temp!=NULL)
        {
            l++;
            temp = temp->next;
        }
        l = l/2;
        // l = l+1;
        int temp_l = l;
        temp = head;
        while(temp_l)
        {
            temp_l--;
            temp = temp->next;
        }
        ListNode *next_half = reverseList(temp);
        
        // cout<<next_half->next->val<<endl;
        
        if(next_half==NULL && head!=NULL)
            return false;
        
        while(next_half)
        {
            if(next_half->val!=head->val)
                return false;
            
            next_half = next_half->next;
            head = head->next;
        }
        
        // cout<<temp->val<<endl;
        return true;
        
    }  
};