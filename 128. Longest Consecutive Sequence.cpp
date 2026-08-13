class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        unordered_map<int, int> sequenceLengths;
        for (int currentNum : nums) {
            int nextNum = currentNum;
            while (numSet.count(nextNum)) {
                numSet.erase(nextNum);
                nextNum++;
            }
            int currentSequenceLength = (nextNum - currentNum);
            if (sequenceLengths.count(nextNum)) {
                currentSequenceLength += sequenceLengths[nextNum];
            }
            sequenceLengths[currentNum] = currentSequenceLength;
            maxLength = max(maxLength, sequenceLengths[currentNum]);
        }
        return maxLength;
    }
};
