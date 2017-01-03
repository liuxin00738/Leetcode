class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int duplicateCount=0;
        int curNum=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(curNum==nums[i]) {
                duplicateCount++;
                continue;
            }
            if(duplicateCount!=0){
                nums[i-duplicateCount]=nums[i];
            }                
            curNum=nums[i];

        }
        return nums.size()-duplicateCount;
        
        
    }
};
