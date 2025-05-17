import java.util.*;
import java.util.stream.*;

// 최대한 많은 종류의 포켓몬 포함 n/2 선택
class Solution {
    public int solution(int[] nums) {
        int numsSize = nums.length / 2;
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        
        return Math.min(set.size(), numsSize);
    }
}
