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
        int m = 0;
        ListNode* list = head;
        
        while(list){
            m += 1;
            list = list->next;
        }
        
        if(m == n){
            head = head->next;
            return head;
        }
        
        int len = m - n;
        int i = 1;
        list = head;
        while(i < len){
            list=list->next;
            i += 1;
        }
        
        list->next = list->next->next;
        return head;
    }
};