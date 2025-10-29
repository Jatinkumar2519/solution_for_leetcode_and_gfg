class Solution {
public:
    int smallestNumber(int n) {
        int num = 0;
        int i = 0;
        while(num < n){
            num |= (1 << i);
            i++;
        }
        return  num;
    }
};