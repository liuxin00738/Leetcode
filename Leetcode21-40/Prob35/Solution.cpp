class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0 || target<=nums[0]) return 0;
        if(target>nums[nums.size()-1])  return nums.size();
        
        // nums.size()>=2
        return binarySearch( nums,  target, 0, nums.size()-1);
    }
    
    // return a index which is smaller or equal to target, 
    // but the number after it is bigger than 
    // must satisfy [leftIdx <= target <= rightIdx]
    int binarySearch(vector<int>& nums, int target, int leftIdx, int rightIdx) {
       if(leftIdx+1==rightIdx){
           if(nums[leftIdx]==target)    return leftIdx;
           if(nums[rightIdx]==target)   return rightIdx;
           return rightIdx;
       }
       
       int middleIdx=leftIdx+(rightIdx-leftIdx)/2;
       if(nums[middleIdx]>target)
           return binarySearch( nums, target, leftIdx, middleIdx);
       
       return binarySearch( nums, target, middleIdx, rightIdx);
    }
};
