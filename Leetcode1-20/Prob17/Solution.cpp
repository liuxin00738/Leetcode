class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.find('0')!=string::npos || digits.find('1')!=string::npos) return result;
        
        // repeat call the function.
        for(int i=0;i<digits.size();i++){
            string digit2str;
            letterDictionary(digits[i],digit2str);
            combinationhelper(result, digit2str);        
        }
        return result;
        
    }
    void combinationhelper(vector<string>& result, const string& input){
        int resultSize=result.size();
        
        // if first time, just put each char into the vector
        if(resultSize==0){
            for(int i=0;i<input.size();i++){
                string tempStr;
                tempStr+=input[i];
                result.push_back(tempStr);            
            }
            return;
        }
        
        // other times, copy the previous result n-1 times and append a new char.
        for(int i=0;i<input.size()-1;i++){
            for(int j=0;j<resultSize;j++){
                result.push_back(result[j]);
            }       
        }
        for(int i=0;i<input.size();i++){
            for(int j=0;j<resultSize;j++){
                result[j+i*resultSize]+=input[i];
            }       
        }
              
    }
    void letterDictionary(const char c, string& output){
        static unordered_map<char, string> letterDic;
        if(letterDic.size()==0){
            letterDic['2']="abc";
            letterDic['3']="def";
            letterDic['4']="ghi";
            letterDic['5']="jkl";
            letterDic['6']="mno";
            letterDic['7']="pqrs";
            letterDic['8']="tuv";
            letterDic['9']="wxyz";        
        }
        output=letterDic[c];        
    
    }
    
};