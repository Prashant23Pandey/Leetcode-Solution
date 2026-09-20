class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize: maxProd tracks maximum product ending at current position
        // minProd tracks minimum product ending at current position (for handling negative numbers)
        // result stores the global maximum product found so far
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
      
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // Store previous values before updating
            int prevMax = maxProd;
            int prevMin = minProd;
          
            // Update maximum product ending at current position
            // Consider three cases:
            // 1. Start fresh with current number alone
            // 2. Extend previous maximum product
            // 3. Extend previous minimum product (useful when current number is negative)
            maxProd = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
          
            // Update minimum product ending at current position
            // Similar logic but taking minimum to handle negative products
            minProd = min({nums[i], prevMax * nums[i], prevMin * nums[i]});
          
            // Update global maximum result
            result = max(result, maxProd);
        }
      
        return result;
    }
};
