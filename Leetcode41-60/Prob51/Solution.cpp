class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> unUsedCol;
        for(int i=0;i<n;i++)
            unUsedCol.push_back(true);
        vector<int> curBoard;
        vector<vector<string>> result;
        NQueen(n,unUsedCol, curBoard,result);
        return result;
    }
    
    
    // insert n elements, 
    void NQueen(int n, vector<bool>& unUsedCol, vector<int>& curBoard, vector<vector<string>> & result){
        //cout<<"n= "<<n<<endl;
        if(n==0){
            // convert the result
            convertResult(curBoard, result);
            return;
        }
        
        for(int iter=0;iter<unUsedCol.size();iter++){
            if(unUsedCol[iter]==false) continue;
            // check if there is conflict on the column
            int newCol=iter;
            bool hasConflict=false;
            for(int i=0;i<curBoard.size();i++){
                if(i-(unUsedCol.size()-n) == newCol-curBoard[i] || (i-(unUsedCol.size()-n) == curBoard[i]-newCol)){
                    hasConflict=true;
                    break;
                }
            }
            
            // if not has conflict
            if(!hasConflict){
                unUsedCol[iter]=false;
                curBoard.push_back(newCol);
                NQueen(n-1, unUsedCol, curBoard,result);
                curBoard.pop_back();
                unUsedCol[iter]=true;
            }
            
        }
        
        return;
        
    }
    
    void convertResult(vector<int>& curBoard, vector<vector<string>> & result){
        //cout<<"find one solution!"<<endl;
        string oneRow="";
        for(int i=0;i<curBoard.size();i++)
            oneRow+='.';
        vector<string> oneSolution;
        for(int i=0;i<curBoard.size();i++){
            oneSolution.push_back(oneRow);
            oneSolution[i][curBoard[i]]='Q';
        }
        //cout<<"reach here 1"<<endl;
        result.push_back(oneSolution);
        return;
    }
    
};
