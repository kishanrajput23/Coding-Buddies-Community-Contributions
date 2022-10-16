import java.util.*;

public class fourSum {
    public List<List<Integer>> fourSumLC(int[] nums, int target) {
        ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();

        if (nums == null || nums.length == 0)
            return result;

        int l = nums.length;

        Arrays.sort(nums);

        for (int i = 0; i < l; i++) {

            int target_3 = target - nums[i];

            for (int j = i + 1; j < l; j++) {

                int target_2 = target_3 - nums[j];

                int front = j + 1;
                int back = l - 1;

                while(front < back) {

                    int two_sum = nums[front] + nums[back];

                    if (two_sum < target_2) front++;

                    else if (two_sum > target_2) back--;

                    else {

                        List<Integer> quad = new ArrayList<>();
                        quad.add(nums[i]);
                        quad.add(nums[j]);
                        quad.add(nums[front]);
                        quad.add(nums[back]);
                        result.add(quad);

                        while (front < back && nums[front] == quad.get(2)) ++front;

                        while (front < back && nums[back] == quad.get(3)) --back;
                    }
                }
                while(j + 1 < l && nums[j + 1] == nums[j]) ++j;
            }
            while (i + 1 < l && nums[i + 1] == nums[i]) ++i;
        }
        return result;
    }
}