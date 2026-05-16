// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(n) recursion stack
class Solution {
public:
    void solve(int n,vector<string>&st,string s,int open,int close){
        if(open==close && open==n){
            st.push_back(s);
            return;
        }

        if(open+1<=n){
            solve(n,st,s+'(',open+1,close);
        } 
        if(close<open){
            solve(n,st,s+')',open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve(n,result,"",0,0);
        return result;
    }
};
