/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
    let n = nums.length;
    if (n == 0) return init;
    
    let res = fn(init, nums[0]);
    for (let i = 1; i < n; i++) {
        res = fn(res, nums[i])
    }
    return res;
};
nums = [1, 2, 3, 4]
fn = function sum(accum, curr) { return accum + curr; }
init = 0
console.log(reduce(nums, fn, init))