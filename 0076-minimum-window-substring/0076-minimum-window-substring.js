/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    if (s.length < t.length) return "";
    let map = new Map();
    for (let char of t) {
        map.set(char, (map.get(char) || 0) + 1);
    }
    let left = 0;
    let right = 0;
    let required = t.length;
    let minLength = Infinity;
    let start = 0;
    while (right < s.length) {
        let char = s[right];
        if (map.has(char)) {
            if (map.get(char) > 0) {
                required--;
            }
            map.set(char, map.get(char) - 1);
        }
        while (required === 0) {
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }
            let leftChar = s[left];
            if (map.has(leftChar)) {
                map.set(leftChar, map.get(leftChar) + 1);
                if (map.get(leftChar) > 0) {
                    required++;
                }
            }

            left++;
        }
        right++;
    }
    return minLength === Infinity
        ? ""
        : s.substring(start, start + minLength);
};