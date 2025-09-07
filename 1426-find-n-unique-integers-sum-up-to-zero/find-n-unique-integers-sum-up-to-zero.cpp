class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int num = 1;
        int left = n/2 - 1;
        int right = n/2 + 1;
        if(n % 2 != 0){
            left = n/2 - 1;
            right = n/2 + 1;
            result[n/2] = 0;
        }
        else{
            left = n/2;
            right = n/2 - 1;
        }
        while(left >= 0 && right < n){
            result[left--] = -num;
            result[right++] = num;
            num++;
        }
        return result;
    }
};