/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSpecial = function(mat) {
    let n = mat.length
    let m = mat[0].length

    var count = 0;
    for(let i = 0;i < n;i++){
        for(let j = 0;j < m;j++){
            if(mat[i][j] == 1){
                let flag = true;
                for(let k = 0;k < n;k++){
                    if(k == i) continue;
                    if(mat[k][j] == 1){
                        flag = false;
                        break;
                    }
                }
                for(let k = 0;k < m;k++){
                    if(k == j) continue;
                    if(mat[i][k] == 1){
                        flag = false;
                        break;
                    }
                }
                count += flag;
            }
        }
    }
    return count;
};