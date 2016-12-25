class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        bool isNegative= x<0? true:false;
        long int absx=abs(x);
        vector<int> digits;
        //cout<<absx<<endl;

        int denom=10;
        while(absx!=0){        
            digits.push_back(absx%denom);
            //cout<<absx%denom<<" ";
            absx=(absx-absx%denom)/10;            
        }
        //cout<<endl;
        
        long int result=0;
        long int power=1;
        for(int i=digits.size()-1;i>=0;i--){
            result+=digits[i]*power;
            power=power*10;
        }
        
        if(isNegative)  result=-result;
        //cout<<result<<endl;
        if(result > numeric_limits<int>::min() && result< numeric_limits<int>::max())
            return int(result);
        return 0;
    }
};