class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        permute(nums, nums.size()-1, result);
        return result;
        
    }
    
    void permute(vector<int>& nums, int rightIdx, vector<vector<int>>& result){
        if(rightIdx>=nums.size()) return;
        if(rightIdx==0){
            vector<int> onePermute;            
            onePermute.push_back(nums[rightIdx]);
            result.push_back(onePermute);
            return;
        }
            
        permute(nums, rightIdx-1, result);
        // first appendix it to the end
        int newNum=nums[rightIdx];
        int resultSize=result.size();
        for(int i=0;i<resultSize;i++){
            result[i].push_back(newNum);
        }
        // insert the new number into different position
        for(int i=0;i<rightIdx;i++){
            // insert position is i
            for(int j=0;j<resultSize;j++){
                // copy the previous result many times
                result.push_back( vector<int>(rightIdx+1,0));
                int curResultSize=result.size();
                for(int k=0;k<rightIdx+1;k++){                    
                    if(k<i)
                        result[curResultSize-1][k]=result[j][k];
                    if(k==i)
                        result[curResultSize-1][k]=newNum;
                    if(k>i)
                        result[curResultSize-1][k]=result[j][k-1];                
                }                
            }       
        
        }
        return;
        
    }
};
