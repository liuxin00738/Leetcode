class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> result(nums.size(),0);        
        int farest=nums[0];
        int leftIdx=1;
        int step=1;
        for(int i=1;i<nums.size() && leftIdx< nums.size();i++){
            // set all the numbers from leftIdx to farthest to step
            while(leftIdx<=farest && leftIdx<nums.size()){
                result[leftIdx]=step;
                //cout<<leftIdx<<" "<<step<<endl;
                leftIdx++;
            }
            if(nums[i]+i>farest){
                farest=nums[i]+i;
                step=result[i]+1;
            }
        }
        
        return result[nums.size()-1];
    }
};
