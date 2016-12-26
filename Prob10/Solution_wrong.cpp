class Solution {
public:
    // find s in p
    bool isMatch(string s, string p) {
        if(s.size()==0 || p.size()==0)  return true;
        // if there is a *, call a special helper function
        if( p.find('*')!=string::npos){
            return isMatch_WithStar(s,p);
        }
        // if string has no *        
        return isMatch_NoStar(s, p);        
    }
    
    bool isMatch_WithStar(string& s, string& p){
        // find possible starting position
        vector<size_t> possibleStartPos;
        findPossibleStartPos(s, p, possibleStartPos);
        
        // check for each possible match until find a match
        for(int i=0;i<possibleStartPos.size();i++){
            bool findMatch=true;
            int  pIdx=possibleStartPos[i];
            for(int sIdx=0;sIdx<s.size() && pIdx<p.size();){                
                // if is a star
                if(p[pIdx] =='*'){
                    if(compareChar(s[sIdx],p[pIdx-1])){
                        sIdx++;
                        continue;                
                    }
                    else{
                        pIdx++;
                        continue;
                    }
                    
                }   
                // if not star, continue regular comparing
                if(!compareChar(s[sIdx], p[pIdx])){
                    findMatch=false;
                    break; // break inner loop if find one mismatch
                }
                sIdx++;pIdx++;                
                
            }
            
            if(findMatch) return true;        
        }
        return false;
    }
    
    // check if the two are matches when there is no star
    bool isMatch_NoStar(string& s, string& p){
        // without star, then s must be shorter than p
        if(s.size() != p.size()) return false;      
        // find possible starting position
        vector<size_t> possibleStartPos;
        findPossibleStartPos(s, p, possibleStartPos);
        
        // check for each possible match until find a match
        for(int i=0;i<possibleStartPos.size();i++){
            bool findMatch=true;            
            for(int j=0;j<s.size();j++){
                if(!compareChar(s[j], p[j+possibleStartPos[i]])){
                    findMatch=false;
                    break; // break inner loop if find one mismatch
                }
            }
            if(findMatch) return true;        
        }
        return false;
    
    }
    // find all the possible beginning positions
    void findPossibleStartPos(const string& s, const string& p, vector<size_t>& possibleStartPos){
        
        if(s[0]=='.'){
            for(int i=0;i< p.size()-s.size()+1;i++)
                possibleStartPos.push_back(i);
        }
        else{
            for(int i=0;i<p.size();){
                size_t nextMatch=findChar(s[0], p, i);
                if(nextMatch!=string::npos ){
                    possibleStartPos.push_back(nextMatch);
                    i=nextMatch+1;
                }
                else{
                    break;
                }
            }
        }      
    }
    
    // find first appearance of c in string p from leftIdx
    // handle . and *
    size_t findChar(const char c, const string& p, const int leftIdx){
        size_t firstChar=p.find(c  , leftIdx);
        size_t firstDot =p.find('.', leftIdx);
        size_t firstStar=p.find('*', leftIdx);
        // check if the star is a possible beginning by checking the char before it 
        if(firstStar!=string::npos && !compareChar(c, p[firstStar-1]) ) firstStar=string::npos;
        
        size_t result=string::npos;
        if(firstChar!=string::npos) result=firstChar;
        if(firstDot !=string::npos) result= (result==string::npos)? firstDot : min(firstDot , result);
        if(firstStar!=string::npos) result= (result==string::npos)? firstStar: min(firstStar, result);

        return result;
    }
    
    // compare if two chars are the same
    bool compareChar(const char c1, const char c2){
        if(c1==c2 || c1=='.' || c2=='.')    return true;
        return false;
    }   
    
    
};
