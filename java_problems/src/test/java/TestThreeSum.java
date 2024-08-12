import org.junit.jupiter.api.Test;
import org.problems.ThreeSum;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Arrays;
import java.util.List;

public class TestThreeSum {

    @Test
    public void testFindThreeSum() {
        ThreeSum threeSum = new ThreeSum();

        int[] nums = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(-1, -1, 2),
                Arrays.asList(-1, 0, 1)
        );
        List<List<Integer>> result = threeSum.threeSum(nums);

        assertEquals(expected.size(), result.size());
        for (List<Integer> triplet : expected) {
            assertTrue(result.contains(triplet));
        }
    }
}