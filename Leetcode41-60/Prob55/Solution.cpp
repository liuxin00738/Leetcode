class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        vector<bool> reachable(nums.size(), false);
        //reachable[0]=true;
        
        int maxDist=0;
        for(int i=0;i<nums.size();i++){
             
            if(maxDist>=i){
                reachable[i]=true;
                maxDist=max(maxDist, nums[i]+i);
            }
            if(maxDist>=(nums.size()-1)){
                reachable[nums.size()-1]=true;
                break;
            }
        }
        return reachable[nums.size()-1];
    }
};
