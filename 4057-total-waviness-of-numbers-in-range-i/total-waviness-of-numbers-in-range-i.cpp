class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int num = num1;num <= num2;num++){
            string str = to_string(num);
            for(int i = 1;i + 1 < str.length();i++){
                if(str[i - 1] < str[i] && str[i] > str[i + 1]) count++;
                if(str[i - 1] > str[i] && str[i] < str[i + 1]) count++;
            }
        }
        return count;
    }
};