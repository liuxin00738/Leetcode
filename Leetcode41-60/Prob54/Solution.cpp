class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0) return result;
        
        for(int i=0;i<(matrix.size()+1)/2 && i<(matrix[0].size()+1)/2;i++){
            moveRight(matrix, result, i);
            moveDown(matrix, result, i);
            moveLeft(matrix, result, i);
            moveUp(matrix, result, i);
        }
        return result;
    }
    
    void moveRight(vector<vector<int>>& matrix, vector<int>& result, int rotateCount ){
        //cout<<"move right"<<endl;
        //if(rotateCount>=(matrix.size()+1)/2) return;
        if(2*rotateCount>=matrix.size()) return;
        for(int i=rotateCount;i<matrix[0].size()-rotateCount;i++){
            result.push_back(matrix[rotateCount][i]);
            //cout<<" "<<matrix[rotateCount][i];
        }
        //cout<<endl;
        return;
    }
    
    void moveDown(vector<vector<int>>& matrix, vector<int>& result, int rotateCount ){
        //cout<<"move down"<<endl;
        if(2*rotateCount >= matrix[0].size()) return;
        int colIdx=matrix[0].size()-1-rotateCount;
        for(int i=rotateCount+1;i<matrix.size()-rotateCount;i++){
            result.push_back(matrix[i][colIdx]);
            //cout<<" "<<matrix[i][colIdx];
        }
        //cout<<endl;
        return;
    }  

    void moveLeft(vector<vector<int>>& matrix, vector<int>& result, int rotateCount ){
        //cout<<"move left"<<endl;
        if(rotateCount*2+1 >= matrix.size()) return;
        int colIdx=matrix[0].size()-2-rotateCount;
        int rowIdx=matrix.size()-1-rotateCount;
        for(int i=colIdx;i>=rotateCount;i--){
            result.push_back(matrix[rowIdx][i]);
            //cout<<" "<<matrix[rowIdx][i];
        }
        //cout<<endl;
        return;
    }
    
    void moveUp(vector<vector<int>>& matrix, vector<int>& result, int rotateCount ){
        //cout<<"move up"<<endl;
        if((rotateCount*2+1)>=matrix[0].size()) return;
        int rowIdx=matrix.size()-2-rotateCount;
        for(int i=rowIdx;i>rotateCount;i--){
            result.push_back(matrix[i][rotateCount]);
            //cout<<" "<<matrix[i][rotateCount];
        }
        //cout<<endl;
        return;
    }     
    
    
};
