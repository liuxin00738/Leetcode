class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        if(s.size()==0) return result;
        result=method3(s);
        return result;
    }
    
    // manarch's method
    string method3(string& s){
        
        // preprocess s
        string sp;
        for(int i=0;i<s.size();i++){
            sp+='#';
            sp+=s[i];
        }
        sp+='#';
        
        vector<int> p(sp.size(), 0);
        p[0]=1;
        //cout<<1<<" ";
        int mx=0;  // most right edge
        int idx=0; // center of most right edge
        for(int i=1;i<sp.size();i++){
            // if mx>i, choose between the two value: right edge, or left mirror's value 
            p[i]= mx>i? min(p[2*idx-mx], mx-i) : 1;
            // keep extending to both direction
            while( i-p[i]>=0 && i+p[i]< sp.size() && sp[i+p[i]]== sp[i-p[i]] ) p[i]++;
            //cout<<p[i]<<" ";
            // update mx and idx
            if(i+p[i]-1 > mx){
                mx=i+p[i]-1;
                idx=i;
            }       
        }
        //cout<<endl;
        int maxLengthIdx=0;
        for(int i=0;i<p.size();i++)
            maxLengthIdx= p[maxLengthIdx]>p[i]? maxLengthIdx : i;
        
        string result;
        int stringLength=p[maxLengthIdx]-1;
        int centerIdx=maxLengthIdx/2;
        int leftIdx=centerIdx-stringLength/2;
        //cout<<"left is "<<leftIdx<<"length is "<< stringLength<<endl;
        result=s.substr(leftIdx, stringLength);
        
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