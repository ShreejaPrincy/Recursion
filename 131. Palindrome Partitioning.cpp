// Time Complexity: O(2^n * n)
// Space Complexity: O(n)
class Solution {
public:
    bool ispalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    void solve(string s,vector<vector<string>>&result,vector<string>&temp,int index){
        if(index>=s.size()){
            result.push_back(temp);
            return;
        }
        string t="";
        for(int i=index;i<s.size();i++){
            t+=s[i];
            if(ispalindrome(t)){
                temp.push_back(t);
                solve(s,result,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        solve(s,result,temp,0);
        return result;
    }
};
