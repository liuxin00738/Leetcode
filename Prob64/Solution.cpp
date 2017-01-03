class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m=grid.size();
        int n=grid[0].size();
        if(n==0) return 0;
        
        vector<vector<int>> cost=grid;
        
        for(int i=1;i<m;i++)
            cost[i][0]=cost[i-1][0]+cost[i][0];
            
        for(int i=1;i<n;i++)
            cost[0][i]=cost[0][i-1]+cost[0][i];
            
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                cost[i][j]=min(cost[i][j-1], cost[i-1][j])+cost[i][j];
                
        return cost[m-1][n-1];        
    }
};
