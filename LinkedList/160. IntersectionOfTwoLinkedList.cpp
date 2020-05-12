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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        long long m,n;
        m = n = 0;
        ListNode* list1=headA,*list2=headB;
        
        while(list1){
            m += 1;
            list1 = list1->next;
        }
        
        while(list2){
            n += 1;
            list2 = list2->next;
        }
        
        list1=headA;
        list2=headB;
        
        long long seek;
        if(m > n){
            seek = m - n;
            while(seek){
                list1=list1->next;
                seek -= 1;
            }
        }else{
            seek = n - m;
            while(seek){
                list2=list2->next;
                seek -= 1;
            }
        }
        
        while(list1 != list2){
            list1 = list1->next;
            list2 = list2->next;
        }
        
        return list1;
        
    }
};