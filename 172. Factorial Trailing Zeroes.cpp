class Solution {
public:
    int trailingZeroes(int n) {
        // Count the number of trailing zeros in n factorial
        // Trailing zeros come from factors of 10, which is 2 * 5
        // Since there are always more factors of 2 than 5 in n!,
        // we only need to count the number of factors of 5
      
        int count = 0;
      
        // Count factors of 5, 25, 125, 625, etc.
        // n/5 gives factors of 5
        // n/25 gives additional factors from numbers divisible by 25
        // n/125 gives additional factors from numbers divisible by 125, and so on
        while (n > 0) {
            n /= 5;
            count += n;
        }
      
        return count;
    }
};
