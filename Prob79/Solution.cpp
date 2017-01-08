class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        if(board.size()==0) return false;
        if(board[0].size()==0) return false;
        
        bool result=false;                
        vector<vector<bool>> boardVisited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i< board.size();i++){
            for(int j=0;j<board[0].size();j++){
                result= result || exist(board, boardVisited, word, i, j, word.size());
                if(result) return true;
            }
        }
        
        return result;
        
    }
    
    // check if part of the word exist in the board
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& boardVisited, 
              string& word, int i, int j, int wordLength) {
        // if successfuly reach the end, return true
        if(wordLength==0)
            return true; 
             
        bool result=false;
        char curChar=word[word.length()-wordLength];
          
        if(curChar==board[i][j] && boardVisited[i][j]==false){
            if(wordLength==1) return true;
            
            boardVisited[i][j]=true;
            // check top
            if(i>0)
                result=result || exist(board, boardVisited, word, i-1, j, wordLength-1);
                
            // check bottom
            if(i<board.size()-1 && !result)
                result=result || exist(board, boardVisited, word, i+1, j, wordLength-1);
                
            //  check left
            if(j>0 && !result)
                result=result || exist(board, boardVisited, word, i, j-1, wordLength-1);
                
            //check right
            if(j<board[0].size()-1 && !result)
                result=result || exist(board, boardVisited, word, i, j+1, wordLength-1);
            
            boardVisited[i][j]=false;    
        }
        
        return result;
    }
};