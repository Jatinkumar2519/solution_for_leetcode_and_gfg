class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        int sum = 0;
        string str = to_string(n);
        for(int i = 0;i < str.length();i++){
            if(str[i] != '0'){
                num = num * 10 + (str[i] - '0');
            }
            sum += (str[i] - '0');
        }
        return num * sum;
    }
};