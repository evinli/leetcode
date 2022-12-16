// Whichever height (front vs. back) is smaller, we won’t consider it again, because, this height could
// only be the answer only if the other height is larger than it and at maximum width.
class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int front = 0;
        int back = height.length - 1;

        while (front != back) {
            maxArea = Math.max(maxArea, Math.min(height[back], height[front]) * (back - front));

            if (height[front] < height[back]) {
                front++;
            }
            else {
                back--;
            }
        }

        return maxArea;
    }
}