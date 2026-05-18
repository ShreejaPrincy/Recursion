// Time Complexity: O(2^target)
// Space Complexity: O(target)
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>&result, vector<int>&temp, int sum, int i){
        if(sum==target){
            result.push_back(temp);
            return;
        }
        if(i>=candidates.size() || sum>target){
            return ;
        }
        //skip
        solve(candidates,target,result,temp,sum,i+1);
        //take
        temp.push_back(candidates[i]);
        solve(candidates,target,result,temp,sum+candidates[i],i);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(candidates,target,result,temp,0,0);
        return result;
    }
};
