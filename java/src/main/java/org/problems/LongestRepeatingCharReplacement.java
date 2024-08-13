package org.problems;

public class LongestRepeatingCharReplacement {
    public int characterReplacement(String s, int k) {
        int length = s.length();
        int maxSubstring = 1;

        for (int i = 0; i < length; i++) {
            int usedK = k;
            int currSubstring = 1;

            // Check subsequence characters
            for (int j = i + 1; j < length; j++) {
                if (s.charAt(i) == s.charAt(j)) currSubstring++;
                else {
                    if (usedK > 0) {
                        usedK--;
                        currSubstring++;
                    } else break;
                }
            }

            // Check proceeding characters
            for (int m = i - 1; m >= 0; m--) {
                if (s.charAt(i) == s.charAt(m)) currSubstring++;
                else {
                    if (usedK > 0) {
                        usedK--;
                        currSubstring++;
                    } else break;
                }
            }

            if (currSubstring > maxSubstring) maxSubstring = currSubstring;
        }

        return maxSubstring;
    }
}
