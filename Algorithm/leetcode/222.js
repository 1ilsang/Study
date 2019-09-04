//https://leetcode.com/problems/count-complete-tree-nodes/
//https://1ilsang.blog.me/221620693044

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
const countNodes = function(root) {
    if(root === null) return 0;
    return go(root);
};

const go = (node) => {
    let ret = 1;
    if(node.left !== null) ret += go(node.left);
    if(node.right !== null) ret += go(node.right);
    return ret;
}
