class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size()<3) return 0;
        
        int closestSum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int leftIdx=i+1;
            int rightIdx=nums.size()-1;
            
            while(leftIdx<rightIdx){
                int sum=nums[i];                
                sum+=nums[leftIdx];
                sum+=nums[rightIdx];
                if(abs(target-sum)<abs(target-closestSum))
                    closestSum=sum;
                
                if(sum>target){
                    rightIdx--;
                }
                else if(sum<target){
                    leftIdx++;
                }
                else{
                    return sum;
                }            
            }
        }
        return closestSum;
        
    }
};
