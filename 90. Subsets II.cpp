// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& result, vector<int> temp,
               int index) {
        result.push_back(temp);
            
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            temp.push_back(arr[i]);
            solve(arr, result, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(nums, result, temp, 0);
        return result;
    }
};
