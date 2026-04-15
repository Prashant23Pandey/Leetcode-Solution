class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;          
        vector<int> currentPermutation(n);   
        vector<bool> visited(n, false);   
        auto generatePermutations = [&](this auto&& generatePermutations, int position) -> void {
            if (position == n) {
                result.emplace_back(currentPermutation);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    currentPermutation[position] = nums[i];
                    generatePermutations(position + 1);
                    visited[i] = false;
                }
            }
        };
        generatePermutations(0);
        return result;
    }
};