class Solution {
public:
    int romanToInt(string s) {
        int result=0;        
        // at least two char
        for(int i=0;i<s.size()-1;i++){
            char curChar=s[i];
            char nxtChar=s[i+1];// bug
            if(romanDict(curChar) >= romanDict(nxtChar) ){
                result+=romanDict(curChar);
            }
            else{
                result-=romanDict(curChar);
            }          
        }
        result+=romanDict(s[s.size()-1]);        
        return result;
        
    }
    
    int romanDict(const char& c){
        static unordered_map<char, int> romanChart;
        // only initilize once
        if(romanChart.size()==0){
            romanChart['I']=1;
            romanChart['V']=5;
            romanChart['X']=10;
            romanChart['L']=50;
            romanChart['C']=100;
            romanChart['D']=500;
            romanChart['M']=1000;
        }
        return romanChart[c];  
    }    
};
