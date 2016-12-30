class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength=0;
        int preLength=0;
        unordered_map<int, int> parMap; // index --> earliest valid left index of current block
        for(int i=0;i<s.size();i++){
            parMap[i]=-1;
        }
        
        // use a stack to check for valid pairs
        stack<std::pair<char, int> > parStack; 
        for(int i=0;i<s.size();i++){
            if(s[i]== '('){
                parStack.push(pair<char, int>(s[i],i));
                continue;    
            }
            // if is a right parentheses, check if it is a pair
            else{
                // if is a match
                if(parStack.size()>0 && parStack.top().first=='('){
                    int topParIdx=parStack.top().second;
                    // check if the one in front is also a valid colsure
                    if(parMap[topParIdx-1]!=-1){
                        parMap[i]=parMap[topParIdx-1];
                    }
                    else{
                        parMap[i]=topParIdx;
                    }
                    parStack.pop();
                }
                // if not a match, push stack
                else{
                    parStack.push(pair<char, int>(s[i],i));
                }
            }            

        }
        
        // extract the reuslt
        for(int i=0;i<s.size();i++){
            if(parMap[i]!=-1){
                int tempLength=i-parMap[i]+1;
                maxLength= maxLength>tempLength? maxLength:tempLength;
            }
        }        
        return maxLength;
    }
};
