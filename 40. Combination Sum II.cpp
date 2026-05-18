// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result,
               vector<int>& temp, int sum, int i) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (i >= candidates.size() || sum > target) {
            return;
        }
        for (int index = i; index < candidates.size(); index++) {
            if (candidates[index] > target)
                break; // sorted
            if (index > i && candidates[index] == candidates[index - 1])
                continue;
            temp.push_back(candidates[index]);
            solve(candidates, target, result, temp, sum + candidates[index],
                  index + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(candidates, target, result, temp, 0, 0);
        return result;
    }
};
