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
        if(l1==nullptr)  return l2;
        if(l2==nullptr)  return l1;

	    std::shared_ptr<ListNode> result (new ListNode(0));
        ListNode* resultSaver=result.get();
	    int overflow=0;
	
        while(l1 != nullptr || l2 != nullptr){
		    int tempSum=0;
		    tempSum+=overflow;
		    if(l1  != nullptr) tempSum+=l1->val;
		    if(l2  != nullptr) tempSum+=l2->val;

		    overflow= (tempSum>9)? 1 : 0;
		    tempSum= (tempSum>9)? (tempSum-10) : tempSum;
		
		    std::shared_ptr<ListNode> tempPtr (new ListNode(tempSum));
		    result->next=tempPtr.get();	
		    result=result->next;
		    if(l1 != nullptr) l1=l1->next;
		    if(l2 != nullptr) l2=l2->next;
	
	    } 
	    return resultSaver->next;

    }
    
};
