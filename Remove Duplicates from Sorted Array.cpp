class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writeIndex = 0;
        for (int currentNum : nums) {
            if (writeIndex == 0 || currentNum != nums[writeIndex - 1]) {
                nums[writeIndex++] = currentNum;
            }
        }
        return writeIndex;
    }
};