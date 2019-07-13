//https://leetcode.com/problems/two-sum/
//https://1ilsang.blog.me/221585059710

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        boolean flag = false;
        for(int i = 0; i < nums.length - 1; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                if(nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return ans;
    }
}
