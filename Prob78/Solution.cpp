class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // this is equivalent to find all the combinations
        vector<int> cur;
        vector<vector<int>> result; 
        
        for(int i=0;i<=nums.size();i++){
            vector<int> cur;
            findCombination(result,nums, cur, i, 0, nums.size()-1);
        }
        return result;
    } 
    
    void findCombination(vector<vector<int>>& result, vector<int>& nums, vector<int>& cur,
            int totalNumbers, int leftIdx, int rightIdx){
        if(totalNumbers==0){
            result.push_back(cur);
            return;
        }
        if(leftIdx<=rightIdx && (rightIdx-leftIdx >= totalNumbers-1)){
            // with current leftIndex
            cur.push_back(nums[leftIdx]);
            findCombination(result, nums, cur, totalNumbers-1, leftIdx+1, rightIdx);
            cur.pop_back();
            // without current leftIdx
            findCombination(result, nums, cur, totalNumbers, leftIdx+1, rightIdx);
        }
        return;
    }
    
};