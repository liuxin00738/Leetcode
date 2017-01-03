class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(); 
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        if(m<1 || n<1) return 0;
        vector<vector<int>> middleResult(m, vector<int>(n,1));
        
        if(obstacleGrid[0][0]==1) middleResult[0][0]=0;
        for(int i=1;i<m;i++){
            middleResult[i][0]= obstacleGrid[i][0]==1? 0: middleResult[i-1][0];    
        }
        
        for(int i=1;i<n;i++){
            middleResult[0][i]= obstacleGrid[0][i]==1? 0 :middleResult[0][i-1];    
        }        
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                middleResult[i][j]= obstacleGrid[i][j]==1? 0 : middleResult[i][j-1]+middleResult[i-1][j];
                
        return middleResult[m-1][n-1];        
        
    
        
    }
};
