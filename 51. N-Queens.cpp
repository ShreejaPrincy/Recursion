// Time Complexity: O(n!)
// Space Complexity: O(n^2)
class Solution {
public:
    bool safe(int row,int col,vector<string>&board){
        int n=board.size();
    // check same column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q')
            return false;
    }

    // check upper-left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q')
            return false;
    }

    // check upper-right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q')
            return false;
    }

    return true;
    }
    void solve(int n,vector<vector<string>>&ans,vector<string>&board,int i){
        if(i == n) {
            ans.push_back(board);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(safe(i,j,board)){
                board[i][j] = 'Q';
                solve(n,ans,board,i+1);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));

        solve(n,ans,board,0);
        return ans;
    }
};
