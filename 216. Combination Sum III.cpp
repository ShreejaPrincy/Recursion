// Time Complexity: O(2^9)
// Space Complexity: O(k)
class Solution {
public:
    void solve(int k, int n, vector<int>&arr,vector<int>&temp,vector<vector<int>>&result,int i,int sum){    
        if(temp.size()==k){
            if(sum==n){
                result.push_back(temp);
            }
            return;
        }
        if(i>=arr.size())   return;
        if(sum > n) return;
        if(temp.size() > k) return;
        //skip
        solve(k,n,arr,temp,result,i+1,sum);
        //take
        temp.push_back(arr[i]);
        solve(k,n,arr,temp,result,i+1,sum+arr[i]);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        vector<vector<int>>result;
        solve(k,n,arr,temp,result,0,0);
        return result;
    }
};
