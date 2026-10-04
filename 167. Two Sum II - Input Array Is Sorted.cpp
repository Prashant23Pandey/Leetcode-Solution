class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        // Iterate through each element as the first number
        for (int i = 0; i < n - 1; ++i) {
            // Calculate the complement needed to reach the target
            int complement = target - numbers[i];

            // Binary search template to find first index where numbers[mid] >= complement
            int left = i + 1;
            int right = n - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] >= complement) {
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Check if the complement exists at the found position
            if (firstTrueIndex != -1 && numbers[firstTrueIndex] == complement) {
                // Return 1-indexed positions as required by the problem
                return {i + 1, firstTrueIndex + 1};
            }
        }

        // Problem guarantees exactly one solution exists
        return {};
    }
};
