class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int num = n + 1;num < INT_MAX;num++){
            int freq[10] = {0};
            int temp = num;
            while(temp > 0){
                freq[temp % 10]++;
                temp /= 10;
            }
            bool flag = true;
            for(int i = 0;i < 10;i++){
                if(freq[i] > 0 && freq[i] != i){
                    flag = false;
                    break;
                }
            }
            if(flag) return num;
        }
        return -1;
    }
};