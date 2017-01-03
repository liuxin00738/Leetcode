class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_multimap<string, string> resultMap;
        vector<vector<string>> resultVec;
        vector<string> keyValues;
        
        // generate the keys
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            keyValues.push_back(temp);            
        }
        
        // insert the elements
        for(int i=0;i<strs.size();i++){
            resultMap.insert(pair<string, string>(keyValues[i], strs[i]));        
        }
        
        // put the elements into the vector
        for(int i=0;i<keyValues.size();i++){
            //cout<<"i "<<i<<endl;
            //cout<<keyValues[i]<<endl;
            auto range = resultMap.equal_range(keyValues[i]);
            if(range.first==resultMap.end())   continue;
            int count=resultVec.size();
            vector<string> temp;
            resultVec.push_back(temp);
            for(auto iter=range.first;iter!=resultMap.end() && iter!=range.second;iter++){ 
                resultVec[count].push_back(iter->second);
                //cout<<iter->second<<endl;
            }
            resultMap.erase(keyValues[i]);
        }
        
        return resultVec;
        
    }
};
