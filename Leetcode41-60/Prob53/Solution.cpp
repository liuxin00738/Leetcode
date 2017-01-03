class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> sums(nums.size(),0);
        sums[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]>=0) {
                sums[i]=max(nums[i], nums[i]+sums[i-1]);
                continue;
            }
            else{
                sums[i]=max(nums[i], nums[i]+sums[i-1]);
                continue;
            }
        }
        
        int result=sums[0];
        for(int i=1;i<sums.size();i++)
            if(sums[i]>=result) result=sums[i];
            
        return result;
            
        
    }
};
