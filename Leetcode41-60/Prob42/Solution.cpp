class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        
        vector<int> leftHighest(height.size(),0);
        vector<int> rightHighest(height.size(),0);
        vector<int> waters(height.size(),0);
        
        leftHighest[0]=height[0];
        rightHighest[height.size()-1]=height[height.size()-1];
        
        for(int i=1;i<height.size();i++){
            leftHighest[i]= leftHighest[i-1]> height[i]? leftHighest[i-1]: height[i];
        }
        
        for(int i=height.size()-2;i>=0;i--){
            rightHighest[i]= rightHighest[i+1]> height[i]? rightHighest[i+1]: height[i];
        }        
        
        for(int i=1;i<height.size()-1;i++){
            waters[i]=min(leftHighest[i],rightHighest[i])-height[i];
        }
        
        int result=0;
        for(int i=1;i<waters.size()-1;i++){
            result+=waters[i];
        }
        return result; 
        
    }
};