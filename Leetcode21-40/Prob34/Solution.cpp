class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result={-1,-1};
        if(nums.size()==0) return result;
        int leftIdx=0;
        int rightIdx=nums.size()-1;
 
        result[0]=leftSearch(nums, target, leftIdx, rightIdx);
        //cout<<result[0]<<endl;
        result[1]=rightSearch(nums, target, leftIdx, rightIdx);
        
        return result;        
    }
    
    // search the left most target in the range [leftIdx, rightIdx]
    int leftSearch(vector<int>& nums, int target, int leftIdx, int rightIdx) {
        // boarder case: only one or two elements
        if(leftIdx==rightIdx || leftIdx+1==rightIdx){
            if(nums[leftIdx]==target) return leftIdx;
            if(nums[rightIdx]==target) return rightIdx;
            return -1;
        }
        
        // at least three elements  
        int middleIdx=leftIdx+(rightIdx-leftIdx)/2;
        if(nums[middleIdx]<target)
            return leftSearch( nums, target, middleIdx, rightIdx);
        
        return leftSearch( nums, target, leftIdx, middleIdx);     
        
    }
    
    // search the right most target in the range [leftIdx, rightIdx]
    int rightSearch(vector<int>& nums, int target, int leftIdx, int rightIdx) {
        // boarder case: only one or two elements
        if(leftIdx==rightIdx || leftIdx+1==rightIdx){
            if(nums[rightIdx]==target) return rightIdx;
            if(nums[leftIdx]==target) return leftIdx;
            return -1;
        }
        
        // at least three elements
        int middleIdx=leftIdx+(rightIdx-leftIdx)/2;
        if(nums[middleIdx]>target)
            return rightSearch( nums, target, leftIdx, middleIdx);
        
        return rightSearch( nums, target, middleIdx, rightIdx);     
        
    }
};
