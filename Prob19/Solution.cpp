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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(n==0) return head;
        
        ListNode* root= new ListNode(0);
        root->next=head;
        
        ListNode* frontPtr=root;
        ListNode* backPtr =root;
        // move frontPtr by n
        for(int i=0;i<n+1;i++){
            // keep moving the ptr forward
            // if not enough element, return
            if(frontPtr!= NULL)  
                frontPtr=frontPtr->next;
            else
                return head;
        }
        // keep moving until the end of array
        while(frontPtr != NULL ){
            frontPtr=frontPtr->next;
            backPtr =backPtr->next;
        }
        
        backPtr->next=(backPtr->next)->next; 
        
        return root->next;        
    }
};