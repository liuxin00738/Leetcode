class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(needle.size()>haystack.size()) return -1;
        
        int result=-1;
        for(int i=0;i<(haystack.size()-needle.size()+1);i++){
            result=i;
            // if find the matching first char,
            // compare the rest chars
            if(needle[0]==haystack[i]){
                // compare the rest
                for(int j=1;j<needle.size();j++){
                    if(needle[j] != haystack[i+j]) {
                        result=-1;
                        break;
                    }
                } 
                // if find a match, return
                if(result!=-1) return result;                
            }
            // not find matching first char, continue
        }
        
        return -1;        
    }
};
