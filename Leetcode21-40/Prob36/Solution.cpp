class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> rowChecked(9, false);
        vector<bool> columnChecked(9,false);
        vector<bool> cubicChecked(9,false);
        
        bool isValid;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(rowChecked[i]==false){
                    isValid=checkRow(board, i);
                    rowChecked[i]=true;
                    if(!isValid) return false;
                }
                if(columnChecked[j]==false){
                    isValid=checkColumn(board, j);
                    columnChecked[j]=true;
                    if(!isValid) return false;
                }
                int cubicIdx=i/3*3+j/3;
                if(cubicChecked[cubicIdx]==false){
                    isValid=checkCubic(board, i,j);
                    cubicChecked[cubicIdx]=true;
                    if(!isValid) return false;
                }
            }  
        }
        return true;
 
    }
    
    bool checkRow(vector<vector<char>>& board, int rowIdx){
        vector<bool> numberAppeared(9,false);
        for(int i=0;i<board.size();i++){
            if(board[rowIdx][i]=='.')   continue;
            int number=board[rowIdx][i]-'1';
            if(numberAppeared[number])  return false;
            numberAppeared[number]=true;        
        }
        return true;    
    }
    bool checkColumn(vector<vector<char>>& board, int colIdx){
        vector<bool> numberAppeared(9,false);
        for(int i=0;i<board.size();i++){
            if(board[i][colIdx]=='.')   continue;
            int number=board[i][colIdx]-'1';
            if(numberAppeared[number])  return false;
            numberAppeared[number]=true;        
        }
        return true;    
    }
    
    bool checkCubic(vector<vector<char>>& board, int colIdx, int rowIdx){
        vector<bool> numberAppeared(9,false);
        int cubicRow=(rowIdx/3)*3;
        int cubicCol=(colIdx/3)*3;
        for(int i=cubicRow;i<cubicRow+3;i++){
            for(int j=cubicCol;j<cubicCol+3;j++){
                if(board[i][j]=='.')   continue;
                int number=board[i][j]-'1';
                if(numberAppeared[number])  return false;
                numberAppeared[number]=true;                
            }                
        }
        return true;    
    }
};
