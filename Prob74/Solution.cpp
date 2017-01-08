class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize=matrix.size();
        if(rowSize==0) return false;
        int colSize=matrix[0].size();
        if(colSize==0) return false;
        
        int rowNumber=searchRow(matrix, target, 0, rowSize-1);
        bool foundElement=searchCol(matrix[rowNumber], target, 0, colSize-1);
        return foundElement;
    }
    
    // binary search of the row number
    int searchRow(vector<vector<int>>& matrix, int target, int left, int right){
        if(left==right) return left;
        if(left==right-1) {
            if(matrix[right][0]>target) return left;
            return right;
        }
        
        int middle=left+(right-left)/2;
        if(matrix[middle][0]>target)
            return searchRow(matrix, target, left, middle);
        return searchRow(matrix, target, middle, right);   
    }
    
    // binary search of the col number
    bool searchCol(vector<int>& matrix, int target, int left, int right){
        if(left==right) return matrix[left]==target;
        if(left==right-1) {
             if(matrix[left]==target || matrix[right]==target) return true;
             return false;
        }
        
        int middle=left+(right-left)/2;
        if(matrix[middle]>target)
            return searchCol(matrix, target, left, middle);
        return searchCol(matrix, target, middle, right);   
    }    
};