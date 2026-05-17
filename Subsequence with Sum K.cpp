// Time Complexity: O(2^n)
// Space Complexity: O(n) due to recursion stack
//method 1 using recursion (tle)
class Solution {
  public:
    bool solve(vector<int>& arr, int target, int i, int sum){

        if(i>=arr.size()){
            if(sum==target) return true;
            else    return false;
        }
        
        //take
        bool take= solve(arr,target,i+1,sum+arr[i]);
        //skip
        bool skip= solve(arr,target,i+1,sum);
        
        return take||skip;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return solve(arr,k,0,0);
    }
};
