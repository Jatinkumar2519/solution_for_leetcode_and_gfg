var TimeLimitedCache = function() {
    this.getValue = new Map()
    this.getId = new Map()
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let flag = false
    if(this.getValue.has(key)){
        const id = this.getId.get(key)
        clearTimeout(id)

        this.getValue.delete(key)
        this.getId.delete(key)

        flag = true
    }

    this.getValue.set(key,value)

    const id = setTimeout(() => {
        this.getId.delete(key)
        this.getValue.delete(key)
    },duration)

    this.getId.set(key,id)
    
    return flag;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if(this.getValue.has(key)){
        return this.getValue.get(key)
    }

    return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.getValue.size
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */