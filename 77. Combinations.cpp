class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;             
        vector<int> currentCombination;        
        function<void(int)> backtrack = [&](int currentNumber) {
            if (currentCombination.size() == k) {
                result.emplace_back(currentCombination);
                return;
            }
            if (currentNumber > n) {
                return;
            }
            currentCombination.emplace_back(currentNumber);
            backtrack(currentNumber + 1);
            currentCombination.pop_back();
            backtrack(currentNumber + 1);
        };
        backtrack(1); 
        return result;
    }
};