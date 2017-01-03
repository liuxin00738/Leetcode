class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        // build the map
        unordered_map<long int, double> middle_result;
        set<long int> twoPower;
        double powerX=x;
        middle_result.insert(pair<long int, double>(1,powerX));
        twoPower.insert(1);   
        long int longN=n;
        for(long int i=2;i<=abs(2*longN);i=i*2){
            powerX=powerX*powerX;
            //cout<<powerX<<endl;
            middle_result.insert(pair<long int,double>(i,powerX));
            twoPower.insert(i);
        }
        
        
        // when n>0        
        double result=1;
        long int powerCount=n;
        while(n>0 && powerCount>=0){
            //cout<<"count is "<<powerCount<<endl;
            if(powerCount==1)
                return result*x;
            if(powerCount==0)    
                return result;
                
            auto iter=twoPower.lower_bound(powerCount);
            // check if the element is equal or bigger than the powerCount
            if(iter!=twoPower.end()){
                if(*iter==powerCount){
                    result=result*middle_result[powerCount];
                    powerCount-=*iter;
                }
                // if the element is bigger than powerCount
                else{
                    iter--;
                    result=result*middle_result[*iter];
                    powerCount-=*iter;
                }
            }
            
        }
 
        // when n<0
        powerCount=abs(longN);
        while(n<0 && powerCount>=0){
            if(powerCount==1)
                return result/x;
            if(powerCount==0)    
                return result;
                
            auto iter=twoPower.lower_bound(powerCount);
            // check if the element is equal or bigger than the powerCount
            if(iter!=twoPower.end()){
                if(*iter==powerCount){
                    result=result/middle_result[powerCount];
                    powerCount-=*iter;
                }
                // if the element is bigger than powerCount
                else{
                    iter--;
                    result=result/middle_result[*iter];
                    powerCount-=*iter;
                }
            }
            
        }
        
        return 0;
    }
};
