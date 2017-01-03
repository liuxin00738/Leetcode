class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
		vector<bool> b;//b[i]为true，表示数字‘i+1’还未使用。例如若b[0]为true,则表示数字‘1’未使用。
		b.assign(9, true);
		column_left_.assign(9,b);
		line_left_.assign(9,b);
		sub_box_left_.assign(9,b);
		int sub_box_order = 0;
		int n = 0;
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				if(board[i][j] != '.'){
					n = board[i][j] - '1';
					line_left_[i][n] = false;
					column_left_[j][n] = false;
					sub_box_order = i / 3 * 3 + j / 3;//由行号列号得到3*3表方格的编号
					sub_box_left_[sub_box_order][n] = false;
				}//if(board[i][j] != '.')
			}//for(int j = 0; j < 9; ++j)
		}//for(int i = 0; i < 9; ++i)
     
		internalSolveSudoku(board, 0, 0);

    }
private:

	bool internalSolveSudoku(vector<vector<char> > &board, int begin_row, int begin_col){
		int row = begin_row;
		int col = begin_col;
		while(row < 9){
				if('.' == board[row][col]){
					int sub_box_order = row / 3 * 3 + col / 3;
					for(int k = 0; k < 9; ++k){
						if(line_left_[row][k] && column_left_[col][k] && sub_box_left_[sub_box_order][k]){//数字‘k+1’尚未使用，即填入数字‘k+1’不会引起冲突
							board[row][col] = '1' + k;
							line_left_[row][k] = false;
							column_left_[col][k] = false;
							sub_box_left_[sub_box_order][k] = false;

							if(col < 8){
								if(internalSolveSudoku(board, row, col+1)){
									return true;
								}
							}//if(col < 8)
							else{
								if(internalSolveSudoku(board, row + 1, 0)){
									return true;
								}
							}//else
							board[row][col] = '.';
							line_left_[row][k] = true;
							column_left_[col][k] = true;
							sub_box_left_[sub_box_order][k] = true;
						}//if(line_left_[row][k] && column_left_[col][k] && sub_box_left_[sub_box_order][k])			
					}//for(int k = 1; k <=9; ++k)
					return false;
				}//if('.' == board[row][col])
				++col;
				if(col > 8){
					col = 0;
					++row;
				}
		}//while(row < 9)
		return true;
	}	

	vector<vector<bool>> line_left_;//每行剩下可以填的数字，一共9行，每行有9个bool值
	vector<vector<bool>> column_left_;//每列剩下可以填的数字，一共9列，每列有9个bool值
	vector<vector<bool>> sub_box_left_;//每个3*3的小方格可以填的数字，一共9个方格，每个方格有9个bool值
};
