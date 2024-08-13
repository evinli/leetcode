import org.junit.jupiter.api.Test;
import org.problems.LongestRepeatingCharReplacement;
import org.problems.ThreeSum;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class TestLongestRepeatingCharReplacement {

    @Test
    public void testLongestRCP() {
        LongestRepeatingCharReplacement lrcp = new LongestRepeatingCharReplacement();

        String test = "ABAB";
        int k = 2;
        int expected = 4;
        int result = lrcp.characterReplacement(test, k);

        assertEquals(expected, result);
    }
}