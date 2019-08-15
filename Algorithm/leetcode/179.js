//https://leetcode.com/problems/largest-number/
//https://1ilsang.blog.me/221617691763

/**
 * @param {number[]} nums
 * @return {string}
 */
const largestNumber = function(nums) {
    return nums
            .sort((a, b) => `${b}${a}` - `${a}${b}`)
            .reduce((a, b) => (b || a  ? a + b : a), '') || '0';
};
