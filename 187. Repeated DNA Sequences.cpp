class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Hash map to store frequency of each 10-letter substring
        unordered_map<string, int> substringFrequency;
      
        // Result vector to store repeated DNA sequences
        vector<string> result;
      
        // Calculate the number of possible 10-letter substrings
        int numSubstrings = s.size() - 10 + 1;
      
        // Iterate through all possible starting positions for 10-letter substrings
        for (int i = 0; i < numSubstrings; ++i) {
            // Extract the current 10-letter substring
            string currentSubstring = s.substr(i, 10);
          
            // Increment the frequency count for this substring
            substringFrequency[currentSubstring]++;
          
            // If this substring appears exactly twice, add it to the result
            // (This ensures each repeated sequence is added only once)
            if (substringFrequency[currentSubstring] == 2) {
                result.emplace_back(currentSubstring);
            }
        }
      
        return result;
    }
};
