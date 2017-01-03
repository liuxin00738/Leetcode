class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        nSum(nums, 0, target, 4, result);
        return result;
    }
    
    void nSum(vector<int>& nums, int leftIdx, int target, int n
        , vector<vector<int> >& result){
        // if don't has enough element, return
        if(n>(nums.size()-leftIdx))    return;
        
        // n==2, do a two sum
        if(n==2){
            twoSum(nums, leftIdx, target, result);
            return;
        }
        // n>2, do recursive call
        else{
            for(int i=leftIdx;i<nums.size();){
                // remove redundant element if there are same elements;
                if(i>leftIdx && nums[i]==nums[i-1] ) {
                    i++;
                    continue;
                }
                
                int resultSize=result.size();
                nSum(nums, i+1, target-nums[i], n-1, result);
                
                // append the corresponding element
                for(int j=resultSize; j<result.size();j++){
                    result[j].push_back(nums[i]);                
                }
                i++;
            }        
        }
    
    }
    
    void twoSum(vector<int>& nums, int leftIdx, int target, vector<vector<int> >& result){    
        // boarder case: not enough element
        if(leftIdx>=nums.size()-1)  return;
        
        int left=leftIdx;
        int right=nums.size()-1;
        while(left<right){            
            // find one, move edge, prevent repeat
            if(nums[left]+nums[right] == target){
                vector<int> temp={nums[left], nums[right]};
                result.push_back(temp);
                left++;right--;
                while(nums[left]==nums[left-1])  
                    left++;
                while(nums[right]==nums[right+1])  
                    right--;
            }
            // too big, move right edge
            else if(nums[left]+nums[right] > target){
                right--;
            }
            // too small, move left edge
            else{
                left++;
            }
        
        }      
        return;
    }
};