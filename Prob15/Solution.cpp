class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;        
        if(nums.size()<3)   return result;
        
        // build a hash table of all nums
        unordered_map<int, int> numsMap;
        for(int i=0;i<nums.size();i++){
            // if not find the element
            if(numsMap.find(nums[i]) == numsMap.end()) {
                numsMap[nums[i]]=1;
                continue;
            }
            // if already exist in the map, ++
            else{
                numsMap[nums[i]]= numsMap[nums[i]]+1;
            }
        }
        
        // build a unique vector of nums
        vector<int> uniqueNums={nums[0]};
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])  uniqueNums.push_back(nums[i]);
        }        
        
        // go through each element in nums;
        // once finished this element, erase it from set to prevent repeat
        for(int i=0;i<uniqueNums.size();i++){
            int firstElem=uniqueNums[i]; 
            numsMap[firstElem]=numsMap[firstElem]-1;
            
            //  do a two-sum-search
            vector<vector<int>> twoSumResult=twoSum(numsMap, uniqueNums, -firstElem, i);
            // combine result;
            for(int j=0;j<twoSumResult.size();j++){
                vector<int> tempVec={firstElem, twoSumResult[j][0], twoSumResult[j][1]};
                result.push_back(tempVec);            
            }
            
            // remove the element from map
            numsMap.erase(firstElem);
        }
        
        return result;
    }
    
    vector<vector<int>>  twoSum(unordered_map<int, int>& numsMap, const vector<int>& nums, int sum, int idx) {
        vector<vector<int>> result;      
        // search the first and second element
        for(int i=idx; i<nums.size();i++){
            int firstElem=nums[i];
            int secondElem=sum-firstElem;
            if(secondElem > firstElem) continue; // prevent repeat
            
            // if not find first element, or element has zero appearance, continue
            if(numsMap.find(firstElem) == numsMap.end() || numsMap.at(firstElem)==0) continue;
            
            // if find first element and the second element,  in map
            numsMap[firstElem] = numsMap[firstElem]-1;           
            if(numsMap.find(secondElem) != numsMap.end() && numsMap.at(secondElem)!=0) {
                vector<int> temp={firstElem, secondElem};
                result.push_back(temp);
            }
            // restore the map
            numsMap[firstElem] = numsMap[firstElem]+1;
  
        }

        return result;
        
    }
};