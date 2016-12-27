class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // find the str with minimal length
        string result;
        if(strs.size()==0) return result;
        
        // find the string with shortest length
        result=strs[0];
        for(int i=1;i<strs.size();i++){
            if(strs[i].size()< result.size())
                result=strs[i];        
        }
        
        // compare this string with everyone else
        string finalResult; 
        for(int j=0;j<result.size();j++){
            char temp=result[j];
            for(int i=0;i<strs.size();i++){
                if(temp!=strs[i][j])
                    return finalResult;
            }        
            finalResult+=temp;
        }
        
        return finalResult;
    }
    
    
};