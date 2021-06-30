class Node{
public:  
  int key;
  int value;
  Node* next = NULL;
  Node* prev = NULL;
   
  Node( int a, int b)
  {
      key= a;
      value = b;
  }
   
};


class LRUCache {
public:
   
    int cap;
    int ll_cap=0;
    unordered_map< int, Node*> m1;
    Node* head = NULL;
    Node* tail = NULL;
   
    LRUCache(int capacity) {
        cap =capacity;
    }
   
    int get(int key) {
       
        int retval= -1;
        //exists in ll
        if( m1.find(key) != m1.end())
        {
         
            Node* curr = m1[key];
            retval = curr->value;
           
            //reorder nodes
            if ( curr == head)
            {
               
            }
            else if ( curr == tail)
            {
                // cout<<"i am here"<<endl;
                //delete from tail
                if( tail->prev == NULL)
                {
                    // cout<<"so\n";
                    tail =NULL;
                    head =NULL;
                }
                else
                {
                    tail->prev->next = NULL;
                    tail = tail->prev;
                    // cout<<"pop "<<tail->key<<" "<<head->key<<endl;
                }
               
                //insert at head
                 if(head == NULL && tail ==NULL)
                {
                    head= curr;
                    tail = curr;
                }
                else
                {  
                    curr->next = head;
                    curr->prev = NULL; //changed
                    curr->next->prev = curr; //changed
                    head = curr;
                }
               
            }
            else
            {
                // cout<<"i am here too";
              curr->prev->next = curr->next;
              curr->next->prev= curr->prev;
               
              //insert at head
                curr->next = head;
                curr->prev = NULL;
                head->prev = curr;
                head = curr;
               
            }
           
           
        }
        // not exist in ll -> retval will be -1
//           cout<<"get head:::"<< head->key<<" "<<head->value<< endl;
//             cout<<"get tail:::"<< tail->key<<" "<<tail->value<< endl;
        
//         cout<<"get head_next "<<head->next->key<<" "<<head->next->value<<endl;
        return retval;
    }
   
    void put(int key, int value) {
       
        //exists in ll
        if( m1.find(key) != m1.end())
        {
            Node* curr = m1[key];
            curr->value= value;
           
            // cout<<"hhh "<<head->key<<" "<<head->value<<endl;
            
            //reorder nodes
            if ( curr == head)
            {
               // printf("head\n");
            }
            else if ( curr == tail)
            {
               // printf("tail\n");
                //delete from tail
                if( tail->prev == NULL)
                {
                    tail =NULL;
                    head =NULL;
                }
                else
                {
                    tail->prev->next = NULL;
                    tail = tail->prev;
                }
               
                //insert at head
                 if(head == NULL && tail ==NULL)
                {
                    head= curr;
                    tail = curr;
                }
                else
                {  
                    curr->next = head;
                    head->prev = curr;//changed
                    head = curr;
                }
               
            }
            else
            {
            // cout<<"debug "<<key<<" "<<value<<" "<<curr->prev->key<<" "<<curr->prev->value<<" "<<curr->next->key<<" "<<curr->next->value<<endl;
              curr->prev->next = curr->next;
              curr->next->prev= curr->prev;
               
              //insert at head
                curr->next = head;
                curr->prev = NULL;
                head->prev = curr;
                head = curr;
               
            }
           // cout<<"if head:cout::"<< head->key<<" "<<head->value<< endl;
           //  cout<<"if tail:::"<< tail->key<<" "<<tail->value<< endl;
           
           
        }
        // not exists in ll, add into ll
        else
        {
            ll_cap += 1;
            Node* curr= new Node(key, value);
            m1[key] = curr;
           
         
           
            //ok to add
            if( ll_cap <= cap)
            {
                if(head == NULL && tail ==NULL)
                {
                    head= curr;
                    tail = curr;
                }
                else
                {
                    //insert at head
                    curr->next = head;
                    head->prev = curr;
                    head = curr;
                   
                }
            }
           
            else
            // delete lru and then ok to add
            {
                // cout<<"hiii "<< ll_cap<<endl;
                //delete from tail
               
                if( tail->prev == NULL)
                {
                    m1.erase(tail->key);//changed
                    // cout<<"deleting "<< tail->key<<" "<<endl;
                    tail =NULL;
                    head =NULL;
                }
                else
                {
                    m1.erase(tail->key);//changed
                    // cout<<"deleting "<< tail->key<<" "<<endl;
                    tail->prev->next = NULL;
                    tail = tail->prev;
                    ll_cap -= 1;                  
                }
               
                //insert at head
                 if(head == NULL && tail ==NULL)
                {
                    head= curr;
                    tail = curr;
                }
                else
                {  
                    curr->next = head;
                    head->prev = curr;
                    head = curr;
                }
               
            }
            //  cout<<"head:cout::"<< head->key<<" "<<head->value<< endl;
            // cout<<"tail:::"<< tail->key<<" "<<tail->value<< endl;
           
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */