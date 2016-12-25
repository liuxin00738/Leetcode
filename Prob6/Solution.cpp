class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(s.size()==0) return result;
        if(numRows==0)  return s;
        if(numRows==1)  return s;
        
        vector< vector<char> > charMtx(numRows, vector<char>() );
        for(int i=0;i<s.size();){
            for(int j=0;j<numRows && i<s.size();j++){
                charMtx[j].push_back(s[i]); 
                i++;
            }
            
            for(int j=numRows-2;j>0 && i< s.size();j--){
                charMtx[j].push_back(s[i]);            
                i++;
            } 
        }
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<charMtx[i].size();j++)
                result+=charMtx[i][j];    
        
        }
        
        return result;
    }
};