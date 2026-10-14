class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str;
        int i = 0;
        
        while(i < num){
            if(sum > 9){
                str.push_back('9');
                sum -= 9;
            }
            else{
                str.push_back('0' + sum);
                sum -= sum;
            }

            i++;
        }

        if(sum > 0) return "";
        return str;
    }
};