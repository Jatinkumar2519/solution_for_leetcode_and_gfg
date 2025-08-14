class Solution {
public:
    string largestGoodInteger(string num) {
        int maxn = -1;
        int n = 0;
        for(int i = 0;i < 3;i++){
            n = n * 10 + (num[i] - '0');
        }
        if(n % 111 == 0)
            maxn = n;
        for(int i = 3;i < num.size();i++){
            n = n % 100;
            n = n * 10 + (num[i] - '0');
            if(n % 111 == 0)
                maxn = max(maxn,n);
        }
        if(maxn == 0) return "000";
        return (maxn == -1) ? "" : to_string(maxn);
    }
};