class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<bool> used(n,false);
        vector<int> cur;
        DFS(result, cur, k, 1, n);
        return result;
    }
    
    void DFS(vector<vector<int>>& result, vector<int>& cur, int k, int leftNum, int rightNum){
        if(k==0){
            result.push_back(cur);
            return;
        }
        
        if(leftNum<=rightNum){
            cur.push_back(leftNum);
            DFS(result, cur, k-1, leftNum+1,rightNum);
            cur.pop_back();
            
            // without leftNum
            DFS(result, cur, k, leftNum+1, rightNum);
            
        }
        return;
    }
    
};