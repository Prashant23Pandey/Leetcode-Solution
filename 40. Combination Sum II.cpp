class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> currentCombination;
        function<void(int, int)> backtrack = [&](int startIndex, int remainingTarget) {
            if (remainingTarget == 0) {
                result.emplace_back(currentCombination);
                return;
            }
            if (startIndex >= candidates.size() || remainingTarget < candidates[startIndex]) {
                return;
            }
            for (int currentIndex = startIndex; currentIndex < candidates.size(); ++currentIndex) {
                if (currentIndex > startIndex && candidates[currentIndex] == candidates[currentIndex - 1]) {
                    continue;
                }
                currentCombination.emplace_back(candidates[currentIndex]);
                backtrack(currentIndex + 1, remainingTarget - candidates[currentIndex]);
                currentCombination.pop_back();
            }
        };
        backtrack(0, target);
      
        return result;
    }
};
