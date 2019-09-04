//https://leetcode.com/problems/jump-game/
//https://1ilsang.blog.me/221629368021

/**
 * @param {number[]} nums
 * @return {boolean}
 */
const canJump = (nums) => {
    let step = 1;
    for(let i = nums.length - 2; i >= 0; i--) {
        if(nums[i] >= step) step = 1;
        else step++;
    }
    return step === 1;
};
