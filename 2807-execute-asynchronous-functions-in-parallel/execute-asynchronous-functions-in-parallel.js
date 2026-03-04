/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve,reject)=>{
        let n = functions.length
        let res = new Array(n)

        let flag = true
        let completed = 0;
        for(let i = 0;i < n;i++){
            const promise = functions[i]()
            promise.then((val)=>{
                res[i] = val
            }).catch((val)=>{
                reject("Error")
            }).finally(()=>{
                if(n === ++completed){
                    resolve(res)
                }
            })
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */