class Solution {
public:
    string getPermutation(int n, int k) {
        string result="";
        vector<int> permutation(n+1,1);
        for(int i=1;i<=n;i++)
                permutation[i]=permutation[i-1]*i;
        if(k>permutation[n]) return result;
        
        set<int> remainNum;
        for(int i=1;i<=n;i++)
            remainNum.insert(i);
            
            
        getKPermutation(k,remainNum, result, permutation);
 
        return result;
        
        
    }
    
    void getKPermutation(int k, set<int>& remainNum, string& curResult, vector<int>& permutation){
        // permutation stores 1! 2! 3! n!, used to speed up the search of kth number
        //cout<<"k is "<<k<<endl;
        int remainNumSize=remainNum.size();
        if(remainNumSize==0) return;
        
        // inert the ratio's smallest number in the remaining set
        int ratio=  (k-1)/permutation[remainNumSize-1];
        auto iter=remainNum.begin();
        for(int i=0;i<ratio;i++)
            iter++;
        curResult+=*iter+'0';
        remainNum.erase(iter);

        int newK=k-ratio*permutation[remainNumSize-1];
        getKPermutation(newK, remainNum, curResult, permutation);
        return;
    }
    
    
};
