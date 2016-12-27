class Solution {
public:
    string intToRoman(int num) {
        string result;
        int input=num;
        int power=1000;
        for(int i=0;i<4;i++){
            int digit=input/power;            
            result+=romanHelper(digit, power); 
            input=input-power*digit;
            power=power/10;
        }
        return result;
    }
    
    string romanHelper(int num, int power){
        vector< vector<char> > romanChart={{'I','V','X'},{'X','L','C'},{'C','D','M'},{'M','V','X'}};
        string digitResult;
        int powerIdx=0;
        
        if(power==1000) powerIdx=3;        
        if(power==100)  powerIdx=2;
        if(power==10)   powerIdx=1;
        if(power==1)    powerIdx=0;
    
        if(num==4){
            digitResult+= romanChart[powerIdx][0];
            digitResult+= romanChart[powerIdx][1];
        }
        else if (num==9){
            digitResult+= romanChart[powerIdx][0];
            digitResult+= romanChart[powerIdx][2];        
        }
        else if( num>0 && num<4){
            for(int i=0;i< num;i++)
                digitResult+= romanChart[powerIdx][0];               
        }
        else if( num>4 && num<9){
            digitResult+= romanChart[powerIdx][1];
            for(int i=0;i< num-5;i++)
                digitResult+= romanChart[powerIdx][0];            
        }

        return digitResult;
    }
};
