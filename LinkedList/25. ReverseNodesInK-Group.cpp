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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count = 0;
        ListNode *temp = head;
        while(temp){
            count += 1;
            temp = temp->next;
        }
        
        if(count < k){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        int i = 0;
        while(curr && i < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            
            curr = next;
            i += 1;
        }
        
        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }
        
        return prev;
    }
    
};