class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
      
        // Initialize arrays to track candy count from left and right perspectives
        // Each child starts with at least 1 candy
        vector<int> leftToRight(n, 1);
        vector<int> rightToLeft(n, 1);
      
        // First pass: left to right
        // If current child has higher rating than previous child,
        // give them one more candy than the previous child
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }
      
        // Second pass: right to left
        // If current child has higher rating than next child,
        // give them one more candy than the next child
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }
      
        // Calculate total candies needed
        // Take maximum of left and right requirements for each child
        // to satisfy both neighboring constraints
        int totalCandies = 0;
        for (int i = 0; i < n; ++i) {
            totalCandies += max(leftToRight[i], rightToLeft[i]);
        }
      
        return totalCandies;
    }
};
