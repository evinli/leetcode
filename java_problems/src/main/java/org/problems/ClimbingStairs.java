package org.problems;

class ClimbingStairs {
    public int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int prev1 = 1;
        int prev2 = 2;
        int ans = 0;

        for (int i = 3; i <= n; i++) {
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
}

// n = 3

// 111
// 12
// 21

// n = 4
// 1111
// 22
// 121
// 112
// 211

