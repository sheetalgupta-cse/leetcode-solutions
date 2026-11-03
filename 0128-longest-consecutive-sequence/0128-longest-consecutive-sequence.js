/**
 * @param {number[]} nums
 * @return {number}
 */

var longestConsecutive = function(nums) {
    let set = new Set(nums);
    let longest = 0;
    for (let num of set) {
        if (!set.has(num - 1)) {
            let count = 1;
            let current = num;
            while (set.has(current + 1)) {
                current++;
                count++;
            }
            longest = Math.max(longest, count);
        }
    }
    return longest;
};
