class Solution {
public:
    string addBinary(string a, string b) {
        int aSize=a.size();
        int bSize=b.size();
        
        if(aSize==0 || bSize==0)
            return aSize==0? b: a;
        
        stack<char> resultStack;
        int advanceBit=0;
        while(aSize>0 || bSize>0 || advanceBit!=0){
            int aBit= aSize>0? a[aSize-1]-'0': 0;
            int bBit= bSize>0? b[bSize-1]-'0': 0;
            int sumBit=aBit+bBit+advanceBit;
            
            advanceBit=sumBit/2;
            resultStack.push(sumBit-2*advanceBit+'0');
            aSize--;
            bSize--;
        }    
        
        string result="";
        while(resultStack.size()!=0){
            result+=resultStack.top();
            resultStack.pop();
        }
        return result;
    }
};
