class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIdx=0;
        int rightIdx=height.size()-1;
        
        int curArea=0;
        int maxArea=0;
        
        while(leftIdx<rightIdx){
            curArea=(rightIdx-leftIdx)*min(height[rightIdx],height[leftIdx]);
            maxArea=max(curArea, maxArea);
            
            if(height[rightIdx]<height[leftIdx]){
                rightIdx--;
             }
            else if(height[rightIdx]>height[leftIdx]){
                leftIdx++;
             }
            else{
                leftIdx++;
                rightIdx--;
            }
            
        }
        return maxArea;
        
        
    }
};