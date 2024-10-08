/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    filteredArr = [];
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i) != 0)
            filteredArr.push(arr[i]);
    }
    return filteredArr;

};

