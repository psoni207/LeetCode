/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow,*fast;
        slow = fast = head;
        
        ListNode* pos = NULL;
        
        if(head == NULL || head->next == NULL){
            return pos;
        }
        
        bool res = false;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                res = true;
                break;
            }
        }
        
        if(res){
            if(slow == head){
                //Check if loop starts at head
                while(slow->next != head){
                    slow = slow->next;
                }
                pos = slow->next;
            }else{
                slow = head;
                while(slow->next != fast->next){
                    slow = slow->next;
                    fast = fast->next;
                }
                pos = fast->next;
            }
        }
        
        return pos;
        
    }
};