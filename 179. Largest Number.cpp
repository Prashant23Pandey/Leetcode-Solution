class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings for custom comparison
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
      
        // Sort strings based on which concatenation produces a larger number
        // For example: "3" and "30" -> "330" > "303", so "3" comes before "30"
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
      
        // Handle edge case: if the largest number is "0", all numbers must be 0
        if (numStrings[0] == "0") {
            return "0";
        }
      
        // Concatenate all sorted strings to form the largest number
        string result;
        for (const string& numStr : numStrings) {
            result += numStr;
        }
      
        return result;
    }
};
