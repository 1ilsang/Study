//https://leetcode.com/problems/additive-number/
//https://1ilsang.blog.me/221624186477

/**
 * @param {string} num
 * @return {boolean}
 */
const isAdditiveNumber = (num) => {
    const len = num.length;
    
    for(let i = 1; i < len / 2; i++) {
        if(num[0] === '0' && i > 1) break;
        
        for(let j = i + 1; len - j >= Math.max(j - i, i); j++) {
            if(num[i] === '0' && j - i > 1) break;
            
            const a = num.substring(0, i);
            const b = num.substring(i, j);
            const str = num.substring(j);
            
            if(isPossible(str, a, b)) return true;
        }
    }
    
    return false;
};

const isPossible = (str, a, b) => {
    if(str === '') return true;
    
    const sum = (parseInt(a) + parseInt(b)).toString();
    if(!str.startsWith(sum)) return false;
    
    return isPossible(str.substring(sum.length), b, sum);
};
