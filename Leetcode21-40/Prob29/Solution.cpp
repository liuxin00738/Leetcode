class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX; 
        
        long int longDividend=dividend;
        long int longDivisor=divisor;
        long int absDividend=abs(longDividend);
        long int absDivisor=abs(longDivisor); 
        //cout<<absDividend<<endl;
        if(absDividend<  absDivisor) return 0;
        
        map<long int, long int> multiMap;        
        long int temp=absDivisor;
        long int tempSol=1;
        while( temp <= absDividend ){
            multiMap.insert(std::pair<long int, long int>(temp, tempSol));
            temp=temp*2;
            tempSol=tempSol*2;
        }        
        
        long int result=0;  
        while(absDividend>=absDivisor){
            map<long int,long int>::iterator itlow=multiMap.upper_bound(absDividend);
            itlow--;
            result+= itlow->second;
            absDividend-=itlow->first;        
            //cout<<absDividend<<endl;
        }
        if( (dividend>=0 && divisor<0 ) || (dividend<0 && divisor>=0) ) result=-result;

        if(result>INT_MAX)  return INT_MAX;
        if(result<INT_MIN)  return INT_MIN;
        
        return result;
    }
};
