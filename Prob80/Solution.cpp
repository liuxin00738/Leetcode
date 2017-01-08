class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        
        int curElem=nums[0];
        int repeatCount=1;
        int replacePtr=-1;
        for(int i=1;i<nums.size();i++){
            // find repeat element
            if( nums[i]==curElem){
                repeatCount++;
                // if first find more than two element, record the position
                if(repeatCount>2 && replacePtr==-1){
                    replacePtr=i;
                }
            }            
            // find a new element    
            else{
                curElem=nums[i];    
                repeatCount=1;
            }
            
            // check if need to move element forward
            if(replacePtr!=-1 && repeatCount<=2){
                nums[replacePtr]=nums[i];
                replacePtr++;
            }
        }
        
        if(replacePtr==-1)
            return nums.size();
        return replacePtr;    
        
    }
};