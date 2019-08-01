//https://leetcode.com/problems/maximum-product-subarray/
//https://1ilsang.blog.me/221602470218

class Solution {
    public int maxProduct(int[] nums) {
        int ret = nums[0], maxNum = nums[0], minNum = nums[0];
        
        for(int i = 1; i < nums.length; i++) {
            int tmp = maxNum;
            maxNum = Math.max(Math.max(nums[i] * maxNum, nums[i] * minNum), nums[i]);
            minNum = Math.min(Math.min(nums[i] * tmp, nums[i] * minNum), nums[i]);
            ret = Math.max(ret, maxNum);
        }
        
        return ret;
    }
}
