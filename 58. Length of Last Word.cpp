class Solution {
public:
    int lengthOfLastWord(string s) {
        int endIndex = s.size() - 1;
        while (endIndex >= 0 && s[endIndex] == ' ') {
            --endIndex;
        }
        int startIndex = endIndex;
        while (startIndex >= 0 && s[startIndex] != ' ') {
            --startIndex;
        }
        return endIndex - startIndex;
    }
};