// 44 → 32 → 13 → 10 → 1 → 1
// 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
// Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

class Solution {
public:
    // using math identity that any chain that arrives at 1 or 89 will become stuck in an endless loop
    bool isHappy(int n) {
        if (n == 1) return true;
        if (n == 89) return false;

        int sum = 0;
        while (n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        return isHappy(sum);
    }
};

class Solution {
public:
    // floyd's cycle-finding algorithm
    bool isHappy(int n) {
        int slow = n;
        int fast = getNextNum(n);

        while (fast != 1 && slow != fast) {
            slow = getNextNum(slow);
            fast = getNextNum(getNextNum(fast));
        }

        return fast == 1;
    }

    int getNextNum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};