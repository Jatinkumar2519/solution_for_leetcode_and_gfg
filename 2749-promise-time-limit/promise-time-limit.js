/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {
        const res = fn(...args)
        let timer = new Promise((_,reject)=>{
            setTimeout(()=>{
                reject("Time Limit Exceeded")
            },t)
        })

        return Promise.race([res,timer])
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */