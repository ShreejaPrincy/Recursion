// Time Complexity: O(2^n * n)
// Space Complexity: O(n)
class Solution {
public:
    void solve(vector<int>& nums,
               vector<vector<int>>& result,
               vector<int>& temp,
               int i) {

        if(i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // skip
        solve(nums, result, temp, i + 1);

        // take
        temp.push_back(nums[i]);

        solve(nums, result, temp, i + 1);

        // backtrack
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> temp;

        solve(nums, result, temp, 0);

        return result;
    }
};
