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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(k==0) return head;
        
        ListNode root(0);
        root.next=head;
        ListNode* rootPtr=&root;
        ListNode* endPtr;
        int listLength=0;
        while(rootPtr->next!=NULL){
            listLength++;
            //cout<<listLength<<endl;
            rootPtr=rootPtr->next;
        }
        endPtr=rootPtr;
        rootPtr=&root;
        int modK=k%listLength;
        
        if(modK==0) return head;
        
        //cout<<modK<<endl;
        for(int i=0;i<listLength-modK;i++)
            rootPtr=rootPtr->next;
        
        //cout<<"1"<<endl;

        ListNode* temp=rootPtr->next;
        rootPtr->next=NULL;
        root.next=temp;
        endPtr->next=head;
        //cout<<"2"<<endl;

        return root.next;
        
        
    }
};
