/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.nums = nums
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    let sum = 0;
    this.nums.forEach((num)=>{
        sum += num
    })

    return sum
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    let sum = '['
    this.nums.forEach((num)=>{
        sum += num.toString() + ','
    })

    if(sum.length > 1){
        sum = sum.slice(0,-1)
    }

    sum += ']'
    return sum
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */