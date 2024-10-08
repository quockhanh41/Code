/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

var map = function (arr, fn) {
    for (let i = 0; i < arr.length; i++) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
};
arr = [1, 2, 3]; function plusone(n) { return n + 1; }
console.log(arr)
console.log(map(arr, plusone))
