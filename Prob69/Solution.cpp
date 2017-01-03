class Solution {
public: 
    int mySqrt(int x) {
        if(x<0)  return 0;
        if(x==0) return 0;
        if(x==1) return 1;
        
        return helper(x, 0, x);
    }
    
    int helper(int x, int left, int right){
        int result=0;
        if(left==right){
            return left;
        }
        if(left==right-1){
            result= left;
            return result;
        }
         
        long int middle= (left+right)/2;
        double squareMiddle=middle;
        squareMiddle=squareMiddle*squareMiddle;
        //cout<<squareMiddle<<endl;
        if(squareMiddle > x)
            return helper(x, left, middle);
        else
            return helper(x, middle, right);
        
    }
};
