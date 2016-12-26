class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x>=0 && x<=9)   return true;
        
        int absx=abs(x);
        int totalDigits=1;
        int power=10;
        while(absx/power){
            absx=(absx-absx%power)/power;
            totalDigits++;
        }
        //cout<<" total digits "<<totalDigits<<endl;
        absx=abs(x);
        for(int i=0;i<totalDigits/2;i++){
            if(getKthDigit(absx, i+1 ) != getKthDigit(absx, totalDigits-i))  return false;
        }
        
        return true;
        
    }
    int getKthDigit(int absx, int k){
        long int power=1;
        for(int i=1;i<k;i++){
            power=power*10;        
        }
        int result=0;        
        result=(absx/power)%10;
        //cout<<k<<" digit is "<<result<<endl;
        return result;
    }
};