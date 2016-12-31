class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        if(num1.size()==0 || num2.size()==0)
            return result;
        stack<char> multiplyStack;
        
        if(num1=="0" || num2=="0") {
            result="0";
            return result;
        }
        for(int i=num1.size()-1;i>=0;i--){
            if(num1[i]=='0') continue;
            // do the multiplication of nums1[i] to nums2
            int advanceBit=0;
            for(int j=num2.size()-1;j>=0;j--){
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                int multiply= a*b+advanceBit;
                advanceBit=multiply/10;                
                multiplyStack.push(multiply%10+'0');            
            }          
            if(advanceBit){
                multiplyStack.push(advanceBit+'0');
            }
            
            // convert to string
            string multiplyStr="";
            while(multiplyStack.size()!=0){
                multiplyStr+=multiplyStack.top();
                multiplyStack.pop();                
            }
            // add zeros to the end
            for(int k=0;k<num1.size()-i-1 && multiplyStr[0]!='0';k++){
                multiplyStr+='0';    
            }
            
            cout<<"multiply result: "<<multiplyStr<<endl;
            // add the result
            addition(result, multiplyStr);
            cout<<"add result: "<< result <<endl;
            
        }
        return result;
    }
    
    // add the two numbers, the result is saved in num1
    void addition(string& num1, string& num2) {
        if(num1.size()==0){
            num1=num2;
            return;
        }
        
        // add two numbers
        stack<char> resultStack;
        int minSize=min(num1.size(), num2.size());
        int maxSize=max(num1.size(), num2.size());
        int advanceBit=0;
        for(int i=0;i<maxSize;i++){
            int num1Digit=(num1.size()-i-1)>=num1.size()? 0: num1[num1.size()-i-1]-'0';
            int num2Digit=(num2.size()-i-1)>=num2.size()? 0: num2[num2.size()-i-1]-'0';
            int addDigit=num1Digit+num2Digit+advanceBit;
            advanceBit=addDigit/10;
            resultStack.push(addDigit%10+'0');        
        }
        if(advanceBit){
            resultStack.push(advanceBit+'0');
        }
        
        // put result into num1
        int idx=0;
        while(resultStack.size()!=0){
            if(idx<num1.size())
                num1[idx]=resultStack.top();
            else
                num1+=resultStack.top();
            
            idx++;
            resultStack.pop();
        }
        

        return;
    }
    
};
