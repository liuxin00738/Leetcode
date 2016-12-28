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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        if(head==NULL) return head;
        if(head->next==NULL) return head; // return if only one element
        
        ListNode root(0);
        root.next=head;
        ListNode* rootPtr=&root;
        
        // move right pointer         
        //int listCounter=0;  
        while(1){
            // check if has at least k nodes
            bool reachEnd=false;            
            hasKNodes(rootPtr, reachEnd, k);
            if(reachEnd)    break;
            
            // do the reverse if has k nodes
            ListNode* tailPtr=rootPtr->next;
            ListNode* right=rootPtr->next->next;
            for(int rvCounter=0;rvCounter<k-1 ;rvCounter++){
                right=reverseHelper(rootPtr, right); 
                tailPtr->next=right;
            }       
            rootPtr=tailPtr;
        }
        return root.next;       
    }
    
    
    // insert what right ptr pointed to after root, return right->next
    // say  root is 0->1->2->3, and right is 3->4->5
    // then root is 0->3->1->2->3 
    // notice this does not change the last element of root, i.e., 2 is still pointing to 3
    // return a pointer to 4
    ListNode* reverseHelper(ListNode* root, ListNode* right){ 
        ListNode* next=right->next;                
        ListNode* temp=root->next;        
        root->next=right;
        right->next=temp;        
        return next;
    }
    
    //  
    void hasKNodes(ListNode* root, bool& reachEnd, int k){ 
            // check if has at least k nodes
            for(int i=0;i<k;i++){                
                if(root->next == NULL){ 
                    reachEnd=true;
                    return;
                }
                else{
                    root=root->next;
                }
            }
            reachEnd=false;
            return;
    }    
    
};
