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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *list1 = l1, *list2 = l2;
         ListNode *result = new ListNode(0);
         ListNode *curr = result;
            int carry = 0;
        
            while(list1 || list2 || carry)
            {
                int num = 0;   
                if(list1) 
                {
                    num += list1->val;
                    list1 = list1->next;
                }
                if(list2)
                {
                    num += list2->val;
                    list2 = list2->next;
                }
                if(carry)
                    num += carry;
                
                carry = num/10;
                num %= 10;
                
                curr->next = new ListNode(num);
                curr = curr->next;     
            }
            delete list1,list2,curr;
        
            return result->next;
        
        
    }
};