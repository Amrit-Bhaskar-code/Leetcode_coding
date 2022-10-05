/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *head_copy = head;
        while(head)
        {
            if(head->child)
            {
                Node * next = head->next;
                head->next = head->child;
                head->child->prev = head;
                head->child = NULL;
                Node* p  = head->next;
                while(p->next)
                {
                    p = p->next;
                }
                p->next = next;
                if(next)
                {
                    next->prev = p;
                }
            }
            head = head->next;
        }
        return head_copy;
    }
};