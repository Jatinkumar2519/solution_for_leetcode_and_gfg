class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int & num : nums){
            int sum = 0;
            int count = 0;
            for(int j = 1;j * j <= num;j++){
                if(num % j == 0){
                    int d1 = j;
                    int d2 = num / j;
                    if(d1 == d2){
                        sum += d1;
                        count ++;
                    }
                    else{
                        sum += d1;
                        sum += d2;
                        count += 2;
                    }
                }
                if(count > 4) break;
            }

            if(count == 4) res += sum;
        }
        return res;
    }
};