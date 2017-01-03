class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        if(candidates.size()==0 || target<candidates[0]) return result;
        
        bool hasResult=combinationSum(candidates,target,0,candidates.size()-1,result);
        
        return result;
        
    }
    
    bool combinationSum(vector<int>& candidates, int target, int leftIdx, int rightIdx, vector<vector<int> >& result) {
        // cout<<"target: "<<target<<" leftIdx: "<<leftIdx<<" rightIdx "<<rightIdx<<endl;
        // case 1: only one number 
        if(leftIdx==rightIdx){
          if(target==candidates[leftIdx])   {
              vector<int> temp={target};
              result.push_back(temp );
              return true;
          }
          else{
            return false;
          }
        }
    
        if(candidates[leftIdx]>target)  return false;
        
        // [leftIdx] = target
        if(target==candidates[leftIdx]){
            vector<int> temp={target};
            result.push_back(temp);
            return true;            
        }
        
        // [leftIdx] < target        
        bool flag1=false;
        int newTarget=target-candidates[leftIdx];       
        int currentSize=result.size();
        if(leftIdx+1<=rightIdx){
            flag1=combinationSum(candidates, newTarget, leftIdx+1,  rightIdx, result);
        }
        if(flag1){
            for(int i=currentSize;i<result.size();i++)
                result[i].push_back(candidates[leftIdx]);  
        }
        
        // without element at leftIdx
        bool flag2=false;
        while(leftIdx+1<=rightIdx && candidates[leftIdx+1]==candidates[leftIdx]) leftIdx++;
        
        if(leftIdx+1<=rightIdx){
            flag2=combinationSum(candidates, target, leftIdx+1,  rightIdx, result);
        }
        
        return (flag1 || flag2);

        
    }    
};
