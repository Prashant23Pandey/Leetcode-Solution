class Solution {
public:
    bool isNumber(string s) {
        int length = s.size();
        int index = 0;
        if (s[index] == '+' || s[index] == '-') {
            ++index;
        }
        if (index == length) {
            return false;
        }
        if (s[index] == '.' && (index + 1 == length || s[index + 1] == 'e' || s[index + 1] == 'E')) {
            return false;
        }
        int decimalCount = 0; 
        int exponentCount = 0; 
        for (int j = index; j < length; ++j) {
            if (s[j] == '.') {
                if (exponentCount || decimalCount) {
                    return false;
                }
                ++decimalCount;
            } 
            else if (s[j] == 'e' || s[j] == 'E') {
                if (exponentCount || j == index || j == length - 1) {
                    return false;
                }
                ++exponentCount;
                if (s[j + 1] == '+' || s[j + 1] == '-') {
                    ++j; 
                    if (j == length - 1) {
                        return false;
                    }
                }
            } 
            else if (s[j] < '0' || s[j] > '9') {
                return false;
            }
        }  
        return true;
    }
};
