// Time Complexity: O(2^n)
// Space Complexity: O(n) recursion stack
class Solution {
  public:
    void solve(vector<int>& arr,vector<int>&result,int i,int sum){
        if(i>=arr.size()){
            result.push_back(sum);
            return;
        }
        //skip
        solve(arr,result,i+1,sum);
        //take
        solve(arr,result,i+1,sum+arr[i]);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>result;
        solve(arr,result,0,0);
        return result;
    }
};
