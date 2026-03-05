/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let n = s.length

    let s1 = ""
    let s2 = ""
    for(let i = 0;i < n;i++){
        if(i % 2 == 0){
            s1 += '0'
            s2 += '1'
        }
        else{
            s1 += '1'
            s2 += '0'
        }
    }

    let count1 = 0;
    let count2 = 0;

    for(let i = 0;i < n;i++){
        count1 += (s1[i] != s[i]);
        count2 += (s2[i] != s[i]);
    }

    return Math.min(count1,count2)
};