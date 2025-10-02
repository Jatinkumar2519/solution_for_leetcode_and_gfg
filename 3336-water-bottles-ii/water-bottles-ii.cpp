class Solution {
public:
    int maxBottlesDrunk(int bt, int ex) {
        int drink = 0;
        while(bt > 0){
            if(bt >= ex){
                drink += ex;
                bt = bt - ex + 1;
                ex++;
            }
            else{
                drink += bt;
                bt = 0;
            }
        }
        return drink;
    }
};