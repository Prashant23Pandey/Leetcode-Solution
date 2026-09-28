using pii = pair<int, int>;

class Solution {
public:
    const int INF = 0x3f3f3f3f;
  
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
      
        // Edge case: less than 2 elements
        if (n < 2) {
            return 0;
        }
      
        // Find minimum and maximum values in the array
        int minValue = INF;
        int maxValue = -INF;
        for (int value : nums) {
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
      
        // Calculate bucket size using pigeonhole principle
        // The maximum gap must be at least (maxValue - minValue) / (n - 1)
        int bucketSize = max(1, (maxValue - minValue) / (n - 1));
        int bucketCount = (maxValue - minValue) / bucketSize + 1;
      
        // Initialize buckets: each bucket stores (min, max) values
        vector<pii> buckets(bucketCount, {INF, -INF});
      
        // Distribute numbers into buckets
        for (int value : nums) {
            int bucketIndex = (value - minValue) / bucketSize;
            buckets[bucketIndex].first = min(buckets[bucketIndex].first, value);
            buckets[bucketIndex].second = max(buckets[bucketIndex].second, value);
        }
      
        // Find maximum gap by comparing adjacent non-empty buckets
        int maxGap = 0;
        int previousMax = INF;
      
        for (auto [currentMin, currentMax] : buckets) {
            // Skip empty buckets
            if (currentMin > currentMax) {
                continue;
            }
          
            // Calculate gap between current bucket's min and previous bucket's max
            maxGap = max(maxGap, currentMin - previousMax);
            previousMax = currentMax;
        }
      
        return maxGap;
    }
};
