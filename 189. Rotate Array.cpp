class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
      
        // Handle cases where k is greater than array size
        // After n rotations, array returns to original position
        k = k % n;
      
        // Step 1: Reverse the entire array
        // Example: [1,2,3,4,5,6,7] becomes [7,6,5,4,3,2,1]
        reverse(nums.begin(), nums.end());
      
        // Step 2: Reverse the first k elements
        // Example: k=3, [7,6,5,4,3,2,1] becomes [5,6,7,4,3,2,1]
        reverse(nums.begin(), nums.begin() + k);
      
        // Step 3: Reverse the remaining n-k elements
        // Example: [5,6,7,4,3,2,1] becomes [5,6,7,1,2,3,4]
        reverse(nums.begin() + k, nums.end());
    }
};
