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
    private:
        ListNode* list;
        bool res = true;
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return res;
        }
        list = head;
        
        ListNode *headptr = head;
        checkPalindrome(headptr);
        
        return res;
    }
    
    void checkPalindrome(ListNode *headptr){
        if(headptr == NULL){
            return;
        }else{
            checkPalindrome(headptr->next);
            if(headptr->val == list->val){
                res &= true;
            }else{
                res &= false;
            }
            list = list->next;
        }
    }
};