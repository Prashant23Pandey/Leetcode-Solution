class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        int dp[sLen + 1][pLen + 1];
        memset(dp, -1, sizeof(dp));
        function<bool(int, int)> dfs = [&](int sIdx, int pIdx) -> bool {
            if (sIdx >= sLen) {
                return pIdx >= pLen || (p[pIdx] == '*' && dfs(sIdx, pIdx + 1));
            }
            if (pIdx >= pLen) {
                return false;
            }
            if (dp[sIdx][pIdx] != -1) {
                return dp[sIdx][pIdx] == 1;
            }
            if (p[pIdx] == '*') {
                dp[sIdx][pIdx] = (dfs(sIdx + 1, pIdx) || dfs(sIdx, pIdx + 1)) ? 1 : 0;
            } else {
                dp[sIdx][pIdx] = ((p[pIdx] == '?' || s[sIdx] == p[pIdx]) && 
                                  dfs(sIdx + 1, pIdx + 1)) ? 1 : 0;
            }         
            return dp[sIdx][pIdx] == 1;
        };
        return dfs(0, 0);
    }
};