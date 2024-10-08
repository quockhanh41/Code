/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    var existed = new Map();
    return function (...args) {
        if (existed.has(JSON.stringify([...args])))
            return existed.get(JSON.stringify([...args]))
        let res = fn(...args);
        existed.set(JSON.stringify([...args]), res)
        return res;
    }
}



let callCount = 0;
const memoizedFn = memoize(function (a, b) {
    callCount += 1;
    return a + b;
})
memoizedFn(2, 3) // 5
memoizedFn(2, 3) // 5
console.log(callCount) // 1 
