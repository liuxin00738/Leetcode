class Solution {
public:
    string countAndSay(int i) {
        string result;
        if(i<=0) return result;
        
        countAndSay(i, result);
        
        return result;
        
    }
    
    void countAndSay(int i, string& result){
        string tempStr;
        if(i==1){
            result='1';
            return;
        }
        
        countAndSay(i-1, tempStr);
        //cout<<i-1<<" "<<tempStr<<endl;
        char digit=tempStr[0];
        int count=0;
        for(int i=0;i<tempStr.size();i++){
            if(digit==tempStr[i]){
                count++;
                continue;
            }
            else{
                result+=to_string(count);
                result+=digit;
                digit=tempStr[i];
                count=1;
            }
        }
        result+=to_string(count);
        result+=digit;        
        return;
    }
};
