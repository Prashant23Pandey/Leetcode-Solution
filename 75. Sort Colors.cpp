class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1;                
        int right = nums.size();      
        int current = 0;     
        while (current < right) {
            if (nums[current] == 0) {
                left++;
                swap(nums[left], nums[current]);
                current++;                
            } 
            else if (nums[current] == 2) {
                right--;
                swap(nums[right], nums[current]);
            } 
            else {
                current++;
            }
        }
    }
};