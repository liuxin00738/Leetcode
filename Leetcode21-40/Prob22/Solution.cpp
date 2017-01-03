class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result={""};
        if(n==0) return result;
        
        // keep record of how much leftParUsed
        string temp="(";
        result[0]=temp;
        vector<int> leftParUsed={1};
        for(int i=2;i<n*2+1; i++){
            insertKthPar(n,leftParUsed, result, i);        
        }
        return result;
        
    }
    
    // insert one left or right parenthesis
    // if has two choices, copy one new choice to the end
    void insertKthPar(const int& n, vector<int>& leftParUsed, vector<string>& result, int k){
        int resultSize=result.size();
        for(int i=0;i<resultSize;i++){
            // if has left par remains, and can also insert a right par
            int rightParUsed=k-1-leftParUsed[i];
            if(leftParUsed[i]<n && rightParUsed<leftParUsed[i]){
                // make a copy, add with right parenthesis
                result.push_back(result[i]+')');
                leftParUsed.push_back(leftParUsed[i]);
                // add a left par
                result[i]+='(';
                leftParUsed[i]++;
             }
            // can only insert left
            else if(leftParUsed[i]<n && rightParUsed==leftParUsed[i]){
                // add a left par
                result[i]+='(';
                leftParUsed[i]++; 
            }
            // can only insert right
            else if(leftParUsed[i]==n){
                result[i]+=')';
             }        
        }
    
    }
};
