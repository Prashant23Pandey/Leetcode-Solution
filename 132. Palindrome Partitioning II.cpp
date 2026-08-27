class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start + 1; end < n; ++end) {
                isPalindrome[start][end] = (s[start] == s[end]) && isPalindrome[start + 1][end - 1];
            }
        }
        vector<int> minCuts(n);
        for (int i = 0; i < n; ++i) {
            minCuts[i] = i;  // Maximum i cuts needed for string of length i+1
        }
        for (int end = 1; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                if (isPalindrome[start][end]) {
                    if (start == 0) {
                        minCuts[end] = 0;
                    } else {
                        minCuts[end] = min(minCuts[end], minCuts[start - 1] + 1);
                    }
                }
            }
        }
        return minCuts[n - 1];
    }
};
