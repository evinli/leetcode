package org.problems;
import java.util.*;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        // Use a set to track all triplet combinations
        Set<List<Integer>> triplets = new HashSet<>();
        // Trivial case
        if (nums.length < 3) return new ArrayList<>(triplets);
        // Sort input array on spot
        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            int target = 0 - nums[i];
            int j = i + 1;
            int k = nums.length - 1;

            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    triplets.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < target) j++;
                else k--;
            }
        }

        return new ArrayList<>(triplets);
    }
}
