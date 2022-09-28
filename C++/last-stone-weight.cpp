class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // base case
        if (stones.empty()) return 0;
        if (stones.size() == 1) return stones[0];

        // recursive step
        int maxOne[2] = {stones[0], 0}; // weight, stone ID
        int maxTwo[2] = {stones[1], 1};
        for (int i = 1; i < stones.size(); i++) {
            if (stones[i] > maxOne[0]) {
                maxTwo[0] = maxOne[0];
                maxTwo[1] = maxOne[1];
                maxOne[0] = stones[i];
                maxOne[1] = i;
            }
            else if (stones[i] > maxTwo[0]) {
                maxTwo[0] = stones[i];
                maxTwo[1] = i;
            }
        }

        if (maxOne[0] == maxTwo[0]) {
            // two cases so that the ID for the 2nd stone decrements when the 1st stone is removed
            if (maxTwo[1] > maxOne[1]) {
                stones.erase(stones.begin() + maxOne[1]);
                maxTwo[1]--;
                stones.erase(stones.begin() + maxTwo[1]);
            }
            else {
                stones.erase(stones.begin() + maxTwo[1]);
                maxOne[1]--;
                stones.erase(stones.begin() + maxOne[1]);
            }
            return lastStoneWeight(stones);
        }

        stones[maxOne[1]] = maxOne[0] - maxTwo[0];
        stones.erase(stones.begin() + maxTwo[1]);
        return lastStoneWeight(stones);
    }
};


// optimized soln using priority queues
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p_queue;

        for (int i = 0; i < stones.size(); i++) {
            p_queue.push(stones[i]);
        }

        while (p_queue.size() > 1) {
            int maxOne = p_queue.top();
            p_queue.pop();
            int maxTwo = p_queue.top();
            p_queue.pop();

            if (maxOne != maxTwo) p_queue.push(maxOne - maxTwo);
        }

        if (p_queue.size() == 1) return p_queue.top();
        return 0;
    }
};


