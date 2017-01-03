class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        if(candidates.size()==0 || target<candidates[0]) return result;
        
        bool hasResult=combinationSum(candidates,target,0,candidates.size()-1,result);
        
        return result;
        
    }
    
    // 
    bool combinationSum(vector<int>& candidates, int target, int leftIdx, int rightIdx, vector<vector<int> >& result) {
        //cout<<"target: "<<target<<" leftIdx: "<<leftIdx<<" rightIdx "<<rightIdx<<endl;
        // case 1: only one number 
        if(leftIdx==rightIdx){
          if(target==candidates[leftIdx])   {
              vector<int> temp={target};
              result.push_back(temp );
              return true;
          }
          else{
            if(target%candidates[leftIdx]!=0) return false;
            vector<int> temp(target/candidates[leftIdx], candidates[leftIdx]);
            result.push_back(temp);
            return true;
          }
        }
        
    
        if(target<candidates[leftIdx])  return false;
        // with element at leftIdx
        bool flag1=false;
        int newTarget=target-candidates[leftIdx];
        if(newTarget==0){
            vector<int> temp={target};
            result.push_back(temp);
            flag1=true;            
        }
        else{
            int currentSize=result.size();
            flag1=combinationSum(candidates, newTarget, leftIdx,  rightIdx, result);
            // if has find solution with leftIdx
            if(flag1){
                for(int i=currentSize;i<result.size();i++)
                    result[i].push_back(candidates[leftIdx]);
            }
        }
        
        // without element at leftIdx
        bool flag2=false;
        if(leftIdx+1<=rightIdx){
            flag2=combinationSum(candidates, target, leftIdx+1,  rightIdx, result);
        }
        
        return (flag1 || flag2);

        
    }    
};
