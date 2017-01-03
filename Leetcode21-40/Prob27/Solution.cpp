class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int leftIdx=0;
        int rightIdx=nums.size()-1; 
        while(leftIdx< nums.size() && nums[leftIdx]!=val ) leftIdx++; // left is first element equals to val
        while(rightIdx>=0 &&nums[rightIdx]==val) rightIdx--; // right is last non-val element
        
        while(leftIdx<rightIdx && leftIdx<nums.size() && rightIdx>=0)  {       
        
            nums[leftIdx]=nums[rightIdx];
            nums[rightIdx]=val;
            leftIdx++;
            rightIdx--;        
                    
            while(leftIdx< nums.size() && nums[leftIdx]!=val ) leftIdx++;   // left is first element equals to val
            while(rightIdx>=0 &&nums[rightIdx]==val) rightIdx--; // right is last non-val element            
        }
        
        while(rightIdx>=0 &&nums[rightIdx]==val) rightIdx--; // right is last non-val element        
        
        return rightIdx+1;
    }
};
