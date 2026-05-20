// Time Complexity: O(4^n)
// Space Complexity: O(n)
class Solution {
public:
    void solve(string digits,vector<string>&arr,vector<string>&result,string temp,int index){
        
        if(index>=digits.size()){
            result.push_back(temp);
            return;
        }
        int i=digits[index]-'0';
        for(int j=0 ;j<arr[i].size();j++){
            solve(digits,arr,result,temp+arr[i][j],index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>arr={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        solve(digits,arr,result,"",0);
        return result;
    }
};
