class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
            }
        }
        vector<vector<string>> result;
        vector<string> currentPartition;
        function<void(int)> backtrack = [&](int startIndex) -> void {
            if (startIndex == n) {
                result.push_back(currentPartition);
                return;
            }
            for (int endIndex = startIndex; endIndex < n; ++endIndex) {
                if (isPalindrome[startIndex][endIndex]) {
                    currentPartition.push_back(s.substr(startIndex, endIndex - startIndex + 1));
                    backtrack(endIndex + 1);
                    currentPartition.pop_back();
                }
            }
        };
        backtrack(0);
        return result;
    }
};
