class MyLinkedList {
    
    private:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}   
        };
    
        ListNode *head, *tail;
        int size;
public:
    /** Initialize your data structure here. */
    // Definition for singly-linked list.
    
    
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index >= size){
            return -1;
        }
        ListNode *temp = head;
        int  i = 0;
        while(i < index){
            temp = temp->next;
            i += 1;
        }
        
        return temp->val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        ListNode * temp = new ListNode(val);
        
        if(head != NULL){
            temp->next = head;
            head = temp;
        }
        else{
            head = temp;
            tail = head;
        }
        size += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
         ListNode * temp = new ListNode(val);
        
        if(head == NULL){
            addAtHead(val);
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
        size += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) { 
        
        if(index == 0){
            addAtHead(val);

        }else if(index == size){
            addAtTail(val);
            
        }else if(index < size){
            
            ListNode * temp = new ListNode(val);
        
            ListNode *prev,*curr;
            prev = NULL;
            curr = head;
            
            while(index){
                prev  = curr;
                curr = curr->next;
                index -= 1;
            }
            
            temp->next = curr;
            prev->next = temp;
            size += 1;
        }else{
            return;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtHead(int index){
        if(head != NULL){
            ListNode *temp;
            temp = head;
            head = head->next;
            
            if(head == NULL){
                tail = NULL;
            }
            
            size -= 1;
        }
    }
    
    
    void deleteAtIndex(int index) {
         if(index == 0){
            deleteAtHead(index);
             
        }else if(index < size){
        
            ListNode *curr;
            curr = head;
            while(index != 1){
                curr = curr->next;
                index -= 1;
            }
             
             if(curr->next->next == NULL){
                 tail = curr;
             }
             curr->next = curr->next->next;
             
             size -= 1;
            
        }else{
            return;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */