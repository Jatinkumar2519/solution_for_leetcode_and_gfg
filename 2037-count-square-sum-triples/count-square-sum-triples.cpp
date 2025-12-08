class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int num1 = 1;num1 <= n;num1++){
            for(int num2 = 1;num2 <= n;num2++){
                int sum = (num1 * num1) + (num2 * num2);
                int num = sqrt(sum);
                if(num * num == sum){
                    count += (num <= n);
                }
            }
        }
        return count;
    }
};