class Solution {
public:
    vector<vector<int>>  generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if(n==0) return matrix;
        int num=1;
        for(int i=0;i<(n+1)/2 ;i++){
            moveRight(matrix, num, i);
            moveDown(matrix, num, i);
            moveLeft(matrix, num, i);
            moveUp(matrix, num, i);
        }
        return matrix;
    }
    
    void moveRight(vector<vector<int>>& matrix, int& num, int rotateCount ){
        //cout<<"move right"<<endl;
        if(2*rotateCount>=matrix.size()) return;
        for(int i=rotateCount;i<matrix[0].size()-rotateCount;i++){
            matrix[rotateCount][i]=num;
            num++;
            //result.push_back(matrix[rotateCount][i]);
            //cout<<" "<<matrix[rotateCount][i];
        }
        //cout<<endl;
        return;
    }
    
    void moveDown(vector<vector<int>>& matrix, int& num, int rotateCount ){
        //cout<<"move down"<<endl;
        if(2*rotateCount >= matrix[0].size()) return;
        int colIdx=matrix[0].size()-1-rotateCount;
        for(int i=rotateCount+1;i<matrix.size()-rotateCount;i++){
            //result.push_back(matrix[i][colIdx]);
            matrix[i][colIdx]=num;
            num++;            
            //cout<<" "<<matrix[i][colIdx];
        }
        //cout<<endl;
        return;
    }  

    void moveLeft(vector<vector<int>>& matrix, int& num, int rotateCount ){
        //cout<<"move left"<<endl;
        if(rotateCount*2+1 >= matrix.size()) return;
        int colIdx=matrix[0].size()-2-rotateCount;
        int rowIdx=matrix.size()-1-rotateCount;
        for(int i=colIdx;i>=rotateCount;i--){
            //result.push_back(matrix[rowIdx][i]);
            matrix[rowIdx][i]=num;
            num++;            
            //cout<<" "<<matrix[rowIdx][i];
        }
        //cout<<endl;
        return;
    }
    
    void moveUp(vector<vector<int>>& matrix, int& num, int rotateCount ){
        //cout<<"move up"<<endl;
        if((rotateCount*2+1)>=matrix[0].size()) return;
        int rowIdx=matrix.size()-2-rotateCount;
        for(int i=rowIdx;i>rotateCount;i--){
            //result.push_back(matrix[i][rotateCount]);
            matrix[i][rotateCount]=num;
            num++;            
            //cout<<" "<<matrix[i][rotateCount];
        }
        //cout<<endl;
        return;
    }     
    
    
};
