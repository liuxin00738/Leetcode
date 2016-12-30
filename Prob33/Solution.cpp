class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        
        int leftIdx=0; 
        int rightIdx=nums.size()-1;
        return searchHelper(nums, target, leftIdx, rightIdx);
    }
    
    int searchHelper(vector<int>& nums, int target, int leftIdx, int rightIdx) {
        // boarder case, only has one or two element
        if(leftIdx==rightIdx || leftIdx==rightIdx-1){
            if(nums[leftIdx]==target) 
                return leftIdx;
            if(nums[rightIdx]==target) 
                return rightIdx;
            return -1;
        }  
        
        int middleIdx=leftIdx+(rightIdx-leftIdx)/2;
        // if is a ordered array
        if(nums[leftIdx] < nums[rightIdx]){
            if(nums[middleIdx]<target)
                return searchHelper( nums, target, middleIdx, rightIdx);
            if(nums[middleIdx]>target)
                return searchHelper( nums, target, leftIdx, middleIdx);
            return middleIdx;
        }
        // if is a rotated array
        else{ 
            // middle is before the pivot
            if(nums[middleIdx]>nums[leftIdx]){
                if(nums[leftIdx]>target)
                    return searchHelper( nums, target, middleIdx, rightIdx);
                else
                    return max(searchHelper( nums, target, leftIdx, middleIdx),
                               searchHelper( nums, target, middleIdx+1, rightIdx) );
            }
            // middle is after pivot
            else{
                if(nums[leftIdx]<target)
                    return searchHelper( nums, target, leftIdx, middleIdx);
                else
                    return max( searchHelper( nums, target, leftIdx, middleIdx),
                                searchHelper( nums, target, middleIdx+1, rightIdx));               
                
            }
            
        }
    
    }
};
