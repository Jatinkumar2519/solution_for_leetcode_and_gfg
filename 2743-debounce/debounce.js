/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let id = null
    return function(...args) {
        if(isNaN(id)){
            id = setTimeout(()=>{
                fn(...args)
                id = null
            },t)
        }
        else{
            clearTimeout(id)
            
            id = setTimeout(()=>{
                fn(...args)
                id = null
            },t)
        }
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */