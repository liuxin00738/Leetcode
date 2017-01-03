class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0) return 0;
        int length=0;
        bool findWord=false;
        for(int i=s.size()-1;i>=0;i--){
            if(!findWord && s[i]!=' ')
                findWord=true;
            
            if(findWord &&s[i]!=' ')
                length++;
            
            if(findWord && s[i]==' ')    
                break;
            
        }
        return length;
        
    }
};
