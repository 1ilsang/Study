//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//https://1ilsang.blog.me/221629329706

/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
const kthSmallest = (matrix, k) => [].concat(...matrix).sort((a, b) => a - b)[k - 1];
