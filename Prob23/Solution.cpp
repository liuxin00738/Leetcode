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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeHelper(lists, lists.size());        
        
    }
    // recursive call to do the merge
    ListNode* mergeHelper(vector<ListNode*>& lists, int size){
        if(size==1) return lists[0];
        
        // merge each two of the list
        for(int i=0;i+1 < size;i=i+2){
            lists[i/2]=mergeTwo(lists[i], lists[i+1]);        
        }
        // attach the last list
        if(size%2==1) lists[size/2]=lists[size-1];
        
        int newSize= size%2==0? size/2: size/2+1;
        return mergeHelper(lists, newSize);   
        
    }
    // merge two
    ListNode* mergeTwo(ListNode* left, ListNode* right){
        if(left==NULL)  return right;
        if(right==NULL) return left;
        
        ListNode    root(0);
        ListNode*   rootPtr=&root;
        
        // compare the two to merge
        while(left!=NULL && right!=NULL){
            // left is smaller
            if(left->val <= right->val){
                rootPtr->next=left;
                left=left->next;
                rootPtr=rootPtr->next;
            }
            // right is smaller
            else
            {
                rootPtr->next=right;
                right=right->next;
                rootPtr=rootPtr->next;
            }
        }
        
        // attach the non-empty list to rootPtr
        if(left==NULL)  rootPtr->next=right;
        if(right==NULL) rootPtr->next=left;
        //rootPtr=root.next;
        //while(rootPtr!=NULL) {
        //    cout<<rootPtr->val <<" ";
        //    rootPtr=rootPtr->next;
        //}
        //cout<<endl;
        return root.next;
    }
};
