class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        if(s.size()==0) return result;
        result=method2(s);
        return result;
    }
    
    // find left and right odd or even string, max length
    string method2(string& s){
        int maxLength=1;
        string result=s.substr(0,1);
        vector<int> resultIdx={0,0};
        
        // odd string, 
        for(int i=1;i<s.size()-1;i++){
            int leftIdx=i-1;
            int rightIdx=i+1;
            
            // left and right idx must be within range
            // also the begin and end char is the same
            while(leftIdx>=0 && rightIdx<s.size() && s[leftIdx]==s[rightIdx]){
                if( (rightIdx-leftIdx+1)>maxLength ){
                    maxLength=rightIdx-leftIdx+1;
                    result=s.substr(leftIdx, maxLength);
                    resultIdx={leftIdx,rightIdx};
                }
                leftIdx--;
                rightIdx++;
            }        
        }

        // even string 
        for(int i=1;i<s.size();i++){
            int leftIdx=i-1;
            int rightIdx=i;
            
            // left and right idx must be within range
            // also the begin and end char is the same
            while(leftIdx>=0 && rightIdx<s.size() && s[leftIdx]==s[rightIdx]){
                if( (rightIdx-leftIdx+1)>maxLength ){
                    maxLength=rightIdx-leftIdx+1;
                    result=s.substr(leftIdx, maxLength);
                    resultIdx={leftIdx,rightIdx};
                }
                leftIdx--;
                rightIdx++;
            }        
        }
        return result;
    
    }
    
    
    // dynamic programming method
    // create a n by n matrix, record if substr(i,j) is palindrome
    // return the longest palindrome
    string method1(string& s){
        int maxLength=1;
        string result=s.substr(0,1);
        vector<int> resultIdx={0,0};
        vector< vector<bool> > p(s.size(), vector<bool>(s.size(), false) ); 
        p[0][0]=true;
        for(int i=1;i<s.size();i++){
            p[i][i]=true;
            p[i][i-1]=true; // initialize for dynamic programming
        }
        
        // do a dynamic programming
        for(int i=s.size()-2;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                // if the inner part is a palindrome and the new chars are the same                
                p[i][j]=p[i+1][j-1] && (s[i]==s[j]);
                if(p[i][j] && (j-i+1)>maxLength){
                    maxLength=j-i+1;
                    resultIdx={i,j};
                }
            }  
        }
        result=s.substr(resultIdx[0], resultIdx[1]-resultIdx[0]+1);
        return result;
    
    }
};