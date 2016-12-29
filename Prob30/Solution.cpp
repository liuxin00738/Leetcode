class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.size()==0)     return result;
        int wordSize=words[0].size();
        int combinationSize=wordSize*words.size();
        if(s.size()<combinationSize)   return result;
        
        // create a map which keep tracking the appearance of words
        unordered_map<string, int>   wordDic;        
        for(int i=0;i<words.size();i++){
            if(wordDic.find(words[i]) == wordDic.end()) {
                wordDic.insert({words[i],1});
                continue;
            }
            else{
                wordDic[words[i]]++;
            }
            //cout<<words[i]<<" "<<wordDic[words[i]]<<endl;
        }

        for(int i=0;i<s.size();i++){
            //cout<<i<<" "<<endl;
            if(s.size()-i < combinationSize) break;
            unordered_map<string, int> localDic=wordDic;
            for(int j=0;j<words.size();j++){
                string temp=s.substr(i+j*wordSize, wordSize );
                if(localDic.find(temp)==localDic.end()) break; 
                localDic[temp]--;
                if(localDic[temp]==0)   
                    localDic.erase(temp);
            }
            if(localDic.size()==0)  result.push_back(i);        
        }
        
        return result;
    }
};
