class Solution {
public:
    int titleToNumber(string columnTitle) {
        // Initialize result to store the column number
        int result = 0;
      
        // Iterate through each character in the column title
        for (char& ch : columnTitle) {
            // Convert from base-26 system to decimal
            // Multiply previous result by 26 (shift left in base-26)
            // Add current character's value (A=1, B=2, ..., Z=26)
            result = result * 26 + (ch - 'A' + 1);
        }
      
        // Return the final column number
        return result;
    }
};
