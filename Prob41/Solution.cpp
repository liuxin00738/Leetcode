class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numSize=nums.size();
        if(nums.size()==0) return 1;
        
        // put every number into its corresponding place
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i && nums[i]>=0 && nums[i]<numSize && nums[nums[i]]!=nums[i]){
                swap(nums[i], nums[nums[i]]);
            }        
        }
        
        // check if any element is not equal to i
        for(int i=1;i<nums.size();i++){
            if(i!=nums[i])
                return i;        
        }
        if(nums[0]==numSize) return numSize+1;
        return numSize;
        
    }
};

