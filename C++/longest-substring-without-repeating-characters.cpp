// Time: O(n)
// Space: 
// Notes:
    // Sliding window technique

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxLength = 0;
        unordered_map<char, int> umap;

        for(int i = 0; i < s.length(); i++) {
            if (umap.count(s[i])) { // count returns 1 if key exists, 0 elsewise
                start = max(start, umap[s[i]] + 1); // in case new start appears before an old start (would reinclude duplicates)
            }
            
            umap[s[i]] = i;
            
            maxLength = max(maxLength, i - start + 1);            
        }
        return maxLength;
    }
};