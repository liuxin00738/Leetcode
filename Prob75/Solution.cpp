class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> red;
        vector<int> white;
        vector<int> blue;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)  red.push_back(nums[i]);
            if(nums[i]==1)  white.push_back(nums[i]);
            if(nums[i]==2)  blue.push_back(nums[i]);
        }
        
        for(int i=0;i<nums.size();i++){
            if(i<red.size())    
                nums[i]=red[i];
            if(i>=red.size() && i < red.size()+white.size() )    
                nums[i]=white[i-red.size()];
            if(i>=red.size()+white.size())    
                nums[i]=blue[i-red.size()-white.size()];   
        }
        
        return;
        
    }
};