#include <algorithm>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /// case when both arrays are empty
        if(nums1.size()==0 && nums2.size()==0) return 0;
        if(nums1.size()==0) {
            return nums2.size()%2==1? nums2[nums2.size()/2]: (nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2.0;
        }
        
        if(nums2.size()==0) {
            return nums1.size()%2==1? nums1[nums1.size()/2]: (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
        }
        
        int totalNums=nums1.size()+nums2.size();
        /// elements within [nums1LeftIdx, nums1RightIdx) are kept
        int nums1LeftIdx=0;
        int nums2LeftIdx=0;        
        
        if (totalNums%2 == 1)
            return findKth(nums1, nums2, nums1LeftIdx, nums2LeftIdx, totalNums/2+1);

        int leftMiddle=findKth(nums1, nums2, nums1LeftIdx, nums2LeftIdx, totalNums/2+1);
        int rightMiddle=findKth(nums1, nums2, nums1LeftIdx, nums2LeftIdx, totalNums/2);
        
        return  (leftMiddle+rightMiddle)/2.0;      
    }

    int findKth(vector<int>& nums1, vector<int>& nums2 
           , int nums1LeftIdx, int nums2LeftIdx, int k) {
        
        //cout<< nums1LeftIdx<<" "<<nums2LeftIdx<<" "<<k<<endl;
        if(nums1LeftIdx==nums1.size())
            return nums2[nums2LeftIdx+k-1];
        
        if(nums2LeftIdx==nums2.size())
            return nums1[nums1LeftIdx+k-1];        
        
        if(k==1)
            return min(nums1[nums1LeftIdx], nums2[nums2LeftIdx]);       
        int maxStep=min(nums1.size()-nums1LeftIdx, nums2.size()-nums2LeftIdx) ;
        int step=min(k/2, maxStep);
        //cout<<"step "<<step<<endl;

        int nums1Value=nums1[nums1LeftIdx+step-1]; 
        int nums2Value=nums2[nums2LeftIdx+step-1];        
        
        if(nums1Value<nums2Value){
            nums1LeftIdx=nums1LeftIdx+step;
            //cout<< "left idx is updated to "<<nums1LeftIdx<<endl;
            return findKth(nums1, nums2, nums1LeftIdx, nums2LeftIdx, k-step);
        }
        else{
            nums2LeftIdx=nums2LeftIdx+step;
            return findKth(nums1, nums2, nums1LeftIdx, nums2LeftIdx, k-step);
        }    
    }
    
};
