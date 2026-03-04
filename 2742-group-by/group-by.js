/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let obj = {}

    let n = this.length
    for(let i = 0;i < n;i++){
        let key = fn(this[i])
        if(key in obj){
            obj[key].push(this[i])
        }
        else{
            obj[key] = [this[i]]
        }
    }

    return obj
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */