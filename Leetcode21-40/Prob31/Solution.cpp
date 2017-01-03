class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        // check from backward to find the first decrease index
        int breakIdx=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<=nums[i-1]) continue;
            breakIdx=i;
            break;
        }
        
        // if this is already the largetst number
        if(breakIdx==-1){
            //sort(nums.begin(), nums.end());
            mysort(nums, 0, nums.size()-1);
            return;
        }
        
        // find the smallest number that are bigger than nums[breakIdx-1] 
        int minIdx=breakIdx;
        int minElem=nums[breakIdx];
        for(int i=nums.size()-1;i>=breakIdx;i--){
            if(nums[i]> nums[breakIdx-1] && nums[i]< minElem)  {
                minElem=nums[i];
                minIdx=i;
            }
        }        
        // swap number, do a sort
        nums[minIdx]=nums[breakIdx-1];
        nums[breakIdx-1]=minElem;
        //sort(nums.begin()+breakIdx, nums.end());
        mysort(nums, breakIdx, nums.size()-1);
        return;
        
    }
    
    // inplace sort of nums[leftIdx, rightIdx]
    void mysort(vector<int>& nums, int leftIdx, int rightIdx){
        // build heap, insert one by one
        for(int i=leftIdx+1;i<=rightIdx;i++){
            insertHeap( nums, leftIdx, i);
        }
        
        // extract one by one
        for(int i=rightIdx;i>leftIdx;i--){
            extracttMaxOfHeap(nums,leftIdx,i);
        }
        
    }

private:

    // insert rightIdx into heap, bubble up, [leftIdx, rightIdx]
    void insertHeap(vector<int>& nums, int leftIdx, int rightIdx){
        if(leftIdx==rightIdx)   return;
        int relIdx=rightIdx-leftIdx;
        while(relIdx!=0){
            int parentIdx=leftIdx+(relIdx-1)/2;
            int childIdx=leftIdx+relIdx;
            // swap if parent is small than child
            if(nums[parentIdx]< nums[childIdx]){
                //int temp=nums[childIdx];
                //nums[childIdx]=nums[parentIdx];
                //nums[parentIdx]=temp;
                swap(nums[parentIdx], nums[childIdx]);
                relIdx=parentIdx-leftIdx;
            }
            else{
                break;
            }
        }
    }
    
    // put the largest element of the heap (from [leftIdx, rightIdx]) to rightIdx
    // do a bubble down of the new element at leftIdx
    void extracttMaxOfHeap(vector<int>& nums, int leftIdx, int rightIdx){
        if(leftIdx==rightIdx)   return;
        swap(nums[leftIdx], nums[rightIdx]);
        
        int relIdx=0;
        while( (2*relIdx+1+leftIdx) < rightIdx){
            int parentIdx=leftIdx+relIdx;
            int childIdx1=leftIdx+relIdx*2+1;
            int childIdx2=leftIdx+relIdx*2+2 < rightIdx? leftIdx+relIdx*2+2: childIdx1;
            
            int bigChildIdx= nums[childIdx1]>nums[childIdx2]? childIdx1:childIdx2;
            // compare parent and child
            if(nums[parentIdx]< nums[bigChildIdx])    {
                swap(nums[parentIdx], nums[bigChildIdx]);
                relIdx=bigChildIdx-leftIdx;
            }
            else{
                break;
            }
        }
    }    
    
};