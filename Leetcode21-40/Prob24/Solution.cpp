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
    ListNode* swapPairs(ListNode* head) {
        ListNode root(0);
        ListNode* rootPtr=&root;
        rootPtr->next=head;
        if(head==NULL) return root.next;
        
        
        ListNode* rightPtr=head->next;
        while(rootPtr!=NULL && rightPtr!=NULL){
            ListNode* tempPtr=rightPtr->next;
            rightPtr->next=rootPtr->next;
            (rootPtr->next)->next=tempPtr;
            rootPtr->next=rightPtr;
            //(rightPtr->next)->next=tempPtr;
            
            // move pointer forward two steps, check nullptr
            rootPtr=rootPtr->next->next;
            rightPtr=rightPtr->next;
            if(rightPtr->next==NULL) break;            
            rightPtr=rightPtr->next;
            if(rightPtr->next==NULL) break;            
            rightPtr=rightPtr->next;
        }        
        return root.next;
        
    }
};
