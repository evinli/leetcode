// Time: O(n^(3/2)) ????
// Space: 

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> validChars; 
    
        for (int i = 0; i < s.length(); i++) {
            if (iswalnum(s[i])) validChars.push_back(tolower(s[i]));
        }
                
        int start = 0;
        int end = validChars.size() - 1;
        
        while (start <= end) {
            if (validChars[start] != validChars[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};