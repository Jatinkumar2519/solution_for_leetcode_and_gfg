class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count = 1;
        int num = 1 % k;
        vector<bool> visit(k,false);
        while(num != 0){
            if(visit[num]) return -1;
            visit[num] = true;
            num = num * 10 + 1;
            num = num % k;
            count++;
        }
        return count;
    }
};