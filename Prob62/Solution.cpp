class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n<1) return 0;
        vector<vector<int>> middleResult(m, vector<int>(n,1));
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                middleResult[i][j]=middleResult[i][j-1]+middleResult[i-1][j];
                
        return middleResult[m-1][n-1];        
        
    }
};
