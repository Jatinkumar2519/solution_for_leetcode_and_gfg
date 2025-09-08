class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        function<bool(int)> ok = [&](int num) -> bool{
            while(num > 0){
                if(num % 10 == 0) return false;
                num /= 10;
            }
            return true;
        };
        for(int i = 1;i < n;i++){
            int num1 = i;
            int num2 = n - i;
            if(ok(num1) && ok(num2)) return {num1,num2};
        }
        return {};
    }
};