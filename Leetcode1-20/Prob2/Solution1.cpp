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

	ListNode* result (new ListNode(0));
        ListNode* Root=result;
	int overflow=0;
	
        while(l1 != nullptr || l2 != nullptr){
		    int Sum=0;
		    Sum+=overflow;
		    if(l1  != nullptr) Sum+=l1->val;
		    if(l2  != nullptr) Sum+=l2->val;

		    overflow= (Sum>9)? 1 : 0;
		    Sum= (Sum>9)? (Sum-10) : Sum;
		
		    ListNode* tempPtr =new ListNode(Sum);
		    result->next=tempPtr;	
		    result=result->next;
		    if(l1 != nullptr) l1=l1->next;
		    if(l2 != nullptr) l2=l2->next;
	
	} 
	/// deal with case when need to have one more bit
        if(overflow==1){
		ListNode* tempPtr =new ListNode(overflow);
		result->next=tempPtr;
	}
	return Root->next;

    }
    
};
