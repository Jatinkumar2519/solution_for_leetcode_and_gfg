/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let n = arr.length
    if(n === 0){
        return []
    }
    
    let res = [];
    let nums = [];

    for(let i = 0;i < n;i++){
        if(i > 0 && i % size === 0){
            res.push(nums)
            nums = [];
        }
        nums.push(arr[i])
    }
    res.push(nums)
    return res
};
