class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        vector<int> used(nums.size(),0);
        
        permute(nums, 0, used,cur,result);
        return result;        
    }
    
    void permute(vector<int>& nums, int level, vector<int>& used
        , vector<int>& cur, vector<vector<int>>& result){
        // if reaches the bottom of leaf
        if(level==nums.size()) {
            result.push_back(cur);
            return;
        }
        
        // insert all possible combinations
        for(int i=0;i<nums.size();i++){
            if(used[i]==0){
                // think like a tree branch: each level can only has one element that is same
                if( i>0 && nums[i]==nums[i-1] && used[i-1]==0) continue;
                cur.push_back(nums[i]);
                used[i]=1;
                permute(nums, level+1, used, cur, result);
                used[i]=0;
                cur.pop_back();
            }       
        }    
    }
 
};
