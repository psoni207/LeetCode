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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *next = head->next->next;
        
        //Second node
        ListNode *curr = head->next;
        
        //Change head
        head->next->next = head;
        
        //Recursive call to swap others
        head->next = swapPairs(next);
        
        return curr;
        
    }
};