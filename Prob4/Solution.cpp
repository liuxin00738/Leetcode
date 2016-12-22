class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /// case when both arrays are empty
        if(nums1.size()==0 && nums2.size()==0) return 0;
 
        /// elements within [nums1LeftIdx, nums1RightIdx) are kept
        int nums1LeftIdx=0;
        int nums2LeftIdx=0;
        int nums1RightIdx=nums1.size();
        int nums2RightIdx=nums2.size();
        
        double result=findMedianSortedArray(nums1, nums2, nums1LeftIdx, nums1RightIdx, nums2LeftIdx, nums2RightIdx);
        return result;    
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2 
           , int& nums1LeftIdx, int& nums1RightIdx 
           , int& nums2LeftIdx, int& nums2RightIdx) {
        
        static int totalNums=nums1.size()+nums2.size();
        static int halfOfTotalNums= (totalNums%2==0)? (totalNums/2-1) : (totalNums/2);
        
        // if has not removed enough elements, do recursive call
        if((nums1LeftIdx +nums2LeftIdx) < halfOfTotalNums ) < halfOfTotalNums  ){
            // get the middle number of the two arrays
            int nums1MiddleIdx=(nums1LeftIdx +nums1RightIdx) /2;
            int nums1Middle=nums1[nums1MiddleIdx];
            
            int nums2MiddleIdx=(nums2LeftIdx +nums2RightIdx) /2;
            int nums2Middle=nums1[nums2MiddleIdx];
            
            // if nums2.middle is bigger
            if(nums2Middle >= nums1Middle){                
                // if has odd elements,  add extra 1
                // if has even elements, do not add 1        
                nums2RightIdx=( (nums2RightIdx-nums2LeftIdx)%2 ==0)? nums2MiddleIdx : (nums2MiddleIdx+1);                                  
                nums1LeftIdx= nums1MiddleIdx;                 
            }
            // if nums1.middle is smaller
            else{
                nums1RightIdx=( (nums1RightIdx-nums1LeftIdx)%2 ==0)? nums1MiddleIdx : (nums1MiddleIdx+1);                                  
                nums2LeftIdx= nums2MiddleIdx;              
            } 
            // do recursive call
            findMedianSortedArray(nums1, nums2, nums1LeftIdx, nums1RightIdx, nums2LeftIdx, nums2RightIdx);        
        }
        
        // if has removed enough elements, return result
        else
        {
            double result=0;
            int  numCount=0;
            for(int i=nums1LeftIdx; i< nums1RightIdx;i++){
                result+=nums1[nums1LeftIdx];
                numCount++;
            }
            for(int i=nums2LeftIdx; i< nums2RightIdx;i++){
                result+=nums2[nums2LeftIdx];
                numCount++;
            }      
        
        }
            
        
    }
    
};
