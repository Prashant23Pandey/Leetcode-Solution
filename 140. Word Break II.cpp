#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * Trie (Prefix Tree) data structure for efficient word storage and retrieval
 */
class Trie {
private:
    // Array to store 26 child nodes (for lowercase letters a-z)
    Trie* children[26];
    // Flag to mark if current node represents end of a word
    bool isEndOfWord;
  
public:
    /**
     * Constructor initializes the Trie node
     */
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
  
    /**
     * Destructor to free allocated memory
     */
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }
  
    /**
     * Inserts a word into the Trie
     * @param word The word to be inserted
     */
    void insert(string word) {
        Trie* currentNode = this;
      
        // Traverse through each character in the word
        for (char character : word) {
            // Convert character to index (0-25)
            int index = character - 'a';
          
            // Create new node if path doesn't exist
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new Trie();
            }
          
            // Move to the child node
            currentNode = currentNode->children[index];
        }
      
        // Mark the end of the word
        currentNode->isEndOfWord = true;
    }
  
    /**
     * Searches for a complete word in the Trie
     * @param word The word to search for
     * @return true if the word exists in the Trie, false otherwise
     */
    bool search(string word) {
        Trie* currentNode = this;
      
        // Traverse through each character in the word
        for (char character : word) {
            // Convert character to index (0-25)
            int index = character - 'a';
          
            // Return false if path doesn't exist
            if (currentNode->children[index] == nullptr) {
                return false;
            }
          
            // Move to the child node
            currentNode = currentNode->children[index];
        }
      
        // Check if current node marks the end of a word
        return currentNode->isEndOfWord;
    }
};

/**
 * Solution class for Word Break II problem
 * Given a string and a dictionary of words, returns all possible sentences
 * that can be formed by breaking the string using dictionary words
 */
class Solution {
private:
    Trie* trie;
  
    /**
     * Recursive DFS helper method to find all valid word combinations
     * @param remainingString The remaining substring to process
     * @return List of all possible word combinations for the remaining string
     */
    vector<vector<string>> dfs(string remainingString) {
        vector<vector<string>> result;
      
        // Base case: empty string means we've successfully broken the entire string
        if (remainingString.empty()) {
            result.push_back(vector<string>());
            return result;
        }
      
        // Try all possible prefixes starting from index 1
        for (int endIndex = 1; endIndex <= remainingString.length(); endIndex++) {
            string prefix = remainingString.substr(0, endIndex);
          
            // If prefix exists in dictionary, recursively process the remaining string
            if (trie->search(prefix)) {
                string suffix = remainingString.substr(endIndex);
                vector<vector<string>> suffixCombinations = dfs(suffix);
              
                // Add current prefix to each valid combination from suffix
                for (vector<string>& combination : suffixCombinations) {
                    // Insert prefix at the beginning of the combination
                    combination.insert(combination.begin(), prefix);
                    result.push_back(combination);
                }
            }
        }
      
        return result;
    }
  
public:
    /**
     * Main method to break the string into valid sentences using dictionary words
     * @param s The input string to break
     * @param wordDict List of valid dictionary words
     * @return List of all possible valid sentences
     */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Initialize Trie and insert all dictionary words
        trie = new Trie();
        for (const string& word : wordDict) {
            trie->insert(word);
        }
      
        // Get all possible word combinations using DFS
        vector<vector<string>> wordCombinations = dfs(s);
      
        // Convert list of word lists to list of sentences (space-separated)
        vector<string> result;
        for (const vector<string>& words : wordCombinations) {
            string sentence = "";
            for (int i = 0; i < words.size(); i++) {
                if (i > 0) {
                    sentence += " ";
                }
                sentence += words[i];
            }
            result.push_back(sentence);
        }
      
        // Clean up allocated memory
        delete trie;
      
        return result;
    }
};
