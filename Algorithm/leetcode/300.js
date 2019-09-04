//https://leetcode.com/problems/longest-increasing-subsequence/
//https://1ilsang.blog.me/221619819694

/**
 * @param {number[]} nums
 * @return {number}
 */
const lengthOfLIS = function(nums) {
    let lowerList = [];
    
    for(let i = 0; i < nums.length; i++) {
        let l = 0;
        let r = lowerList.length - 1;
        const cur = nums[i];
        
        if(r < 0 || lowerList[r] < cur) {
            lowerList.push(cur);
            continue;
        }
        
        while(l <= r) {
            let mid = (l + r) >> 1;
            if(lowerList[mid] >= cur) r = mid - 1;
            else l = mid + 1;
        }
        
        lowerList[l] = cur;
    }
    
    return lowerList.length;
};
