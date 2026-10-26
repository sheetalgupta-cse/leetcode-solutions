/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let maxLength = 0;
    for (let i = 0; i < s.length; i++) {
        let str = "";
        for (let j = i; j < s.length; j++) {
            if (str.includes(s[j])) {
                break;
            }
            str = str + s[j];
            maxLength = Math.max(maxLength, str.length);
        }
    }
    return maxLength;
};