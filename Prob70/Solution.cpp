class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        
        if(n==1) return first;
        if(n==2) return second;
        vector<int> fibonachi={1,2};
        for(int i=2;i<n;i++)
            fibonachi.push_back(fibonachi[i-1]+fibonachi[i-2]);
            
        return fibonachi[n-1];    
    }
    
    
};
