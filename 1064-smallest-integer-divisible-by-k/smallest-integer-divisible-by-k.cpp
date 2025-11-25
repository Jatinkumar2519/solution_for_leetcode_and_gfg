class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> set;
        int num = 1 % k;
        int count = 1;
        while(num != 0){
            if(set.find(num) != set.end()) return -1;
            set.insert(num);
            num = num * 10 + 1;
            num = num % k;
            count++;
        }
        return count;
    }
};