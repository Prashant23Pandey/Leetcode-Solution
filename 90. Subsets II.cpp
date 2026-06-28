class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> currentSubset;
        int n = nums.size();
        function<void(int)> backtrack = [&](int index) {
            if (index >= n) {
                result.push_back(currentSubset);
                return;
            }
            currentSubset.push_back(nums[index]);
            backtrack(index + 1);
            currentSubset.pop_back();
            while (index + 1 < n && nums[index + 1] == nums[index]) {
                index++;
            }
            backtrack(index + 1);
        };
        backtrack(0);
        return result;
    }
};