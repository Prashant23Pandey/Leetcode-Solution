/**
 * Converts a column number to its corresponding Excel column title
 * @param columnNumber - The column number to convert (1-indexed)
 * @returns The Excel column title as a string (e.g., 1 -> "A", 27 -> "AA")
 */
string convertToTitle(int columnNumber) {
    // String to store the result
    string result = "";
  
    // Continue until all digits are processed
    while (columnNumber > 0) {
        // Adjust to 0-indexed (A=0, B=1, ..., Z=25)
        columnNumber--;
      
        // Get the remainder which represents the current character
        int remainder = columnNumber % 26;
      
        // Convert number to corresponding letter (0->A, 1->B, ..., 25->Z)
        // 'A' + remainder gives us the correct character
        char current_character = 'A' + remainder;
      
        // Add character to the beginning of the result string
        result = current_character + result;
      
        // Move to the next digit position
        columnNumber = columnNumber / 26;
    }
  
    // Return the final string
    return result;
}
