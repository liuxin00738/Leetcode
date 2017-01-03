class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        trans(matrix);
        for(int i=0;i<matrix.size()/2;i++)
            swapCol(matrix, i,matrix.size()-1-i);
        
        return;
    }
    
    void trans(vector<vector<int>>& matrix){
        for(int i=0;i<matrix[0].size();i++) 
            for(int j=0;j<i;j++)
                swap(matrix[i][j], matrix[j][i]);
     
        return;   
    }
    // swap column i and column j
    void swapCol(vector<vector<int>>& matrix, int col1, int col2){
        for(int i=0;i<matrix[0].size();i++) 
            swap(matrix[col1][i], matrix[col2][j]);     
        return;   
    }
};

