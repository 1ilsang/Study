//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//https://1ilsang.blog.me/221620608519

/**
 * @param {string} digits
 * @return {string[]}
 */
const letterCombinations = function(digits) {
    const list = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
    const combo = (arr1, arr2) => arr1.reduce((res, s1) => res.concat(arr2.map(s2 => s1 + s2)), []);
    
    return digits 
        ? digits
            .split('')
            .map(n => list[n - 2].split(''))
            .reduce((res, arr) => combo(res, arr))
        : [];
};
