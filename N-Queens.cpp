class Solution {
public:
    bool isValid(vector<string> &board,int row, int col){
        //look for up 
        for(int i = row ;i>=0;i--){
            if(board[i][col] == 'Q') return false;
        }
        //look for left diagonal 
        for(int i = row , j= col ;i >=0 && j >=0 ;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        //look fo right diagonal
        for(int i = row, j = col; i>=0 && j < board.size();i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board,int row,vector<vector<string>> &result){
        if(row >= board.size()){
            result.push_back(board);
            return ;
        }
        for(int i = 0; i < board.size();i++){
            if(isValid(board,row,i)){
                board[row][i] = 'Q';
                solve(board,row+1,result);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0) return {};
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        solve(board,0,result);
        return result;
    }
};
