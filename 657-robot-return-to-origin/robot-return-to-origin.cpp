class Solution {
public:
    bool judgeCircle(string moves) {
        int sum1 = 0;
        int sum2 = 0;
        for(char i : moves){
            if(i == 'U'){
                sum1++;
            }
            else if(i == 'D'){
                sum1--;
            }
            else if(i == 'L'){
                sum2++;
            }
            else{
                sum2--;
            }
        }
        return sum1 == 0 && sum2 == 0 ? true:false;
    }
};