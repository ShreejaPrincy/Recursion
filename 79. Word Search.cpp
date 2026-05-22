// Time Complexity: O(m * n * 4^L)
// Space Complexity: O(m * n)
//L = word.length()
class Solution {
public:
    bool chek(vector<vector<char>>& board, string &word,vector<vector<bool>>&visited,int i,int j,int k){ 

        if(k>=word.size())  return true;
        if(i<0||j<0 || i>=board.size() || j>=board[0].size())   return false;
        
        if(visited[i][j]) return false;
        if(board[i][j]!=word[k]){
            return false;
        }

        visited[i][j] = true;
        bool bottom= chek(board,word,visited,i+1,j,k+1);
        bool right= chek(board,word,visited,i,j+1,k+1);
        bool left=chek(board,word,visited,i,j-1,k+1);
        bool top= chek(board,word,visited,i-1,j,k+1);
        visited[i][j] = false;
        return (bottom||top||right||left);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                bool check=chek(board,word,visited,i,j,0);
                if(check)   return true;
            }
        }
        return false;
    }
};
