// Time Complexity: O(2^n)
// Space Complexity: O(n) recursion stack
class Solution {
public:
    void solve(int n,vector<string>&st,string s){
        if(n==0){
            st.push_back(s);
            return;
        }
        if(s.empty() || s.back()=='1'){
            solve(n-1,st,s+'1');
            solve(n-1,st,s+'0');
        }
        else if(s.back()=='0')   solve(n-1,st,s+'1');
    }
    vector<string> validStrings(int n) {
        vector<string>result;
        solve(n,result,"");
        return result;
    }
};
