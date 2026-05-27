// Time Complexity: O(4^(n*n))
// Space Complexity: O(n*n)
class Solution {
  public:
    void solve(vector<vector<int>>& maze,string temp,vector<vector<bool>>&visited,int i,int j,vector<string>&ans){
        if(i<0||j<0||i>=maze.size()||j>=maze.size()||maze[i][j]==0||visited[i][j]==1)    
            return;
        
        if(i==maze.size()-1&&j==maze.size()-1){
            ans.push_back(temp);
            return;
        }
        
        visited[i][j]=1;
        solve(maze, temp + 'D', visited, i + 1, j, ans);
        solve(maze, temp + 'L', visited, i, j - 1, ans);
        solve(maze, temp + 'R', visited, i, j + 1, ans);
        solve(maze, temp + 'U', visited, i - 1, j, ans);

        visited[i][j] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n=maze.size();
        vector<string> ans;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        solve(maze,"",visited,0,0,ans);
        return ans;
    }
};
