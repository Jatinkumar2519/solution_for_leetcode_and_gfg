class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0;
        int num = 10;

        while(n >= num){
            n -= num;
            num -= 1;
            turn = 1 - turn;
        }

        return turn;
    }
};