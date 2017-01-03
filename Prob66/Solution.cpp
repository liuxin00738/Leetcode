class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> resultStack;
        int advanceBit=0+1;
        for(int i=digits.size()-1;i>=0;i--){
            int sumDigit=advanceBit+digits[i];
            advanceBit=sumDigit/10;
            //cout<<sumDigit-10*advanceBit<<endl;
            resultStack.push(sumDigit-10*advanceBit);
        }
        if(advanceBit!=0)
            resultStack.push(advanceBit);
        
        vector<int> result;
        while(resultStack.size()!=0){
            result.push_back(resultStack.top());
            resultStack.pop();
        }
        return result;
    }
};
