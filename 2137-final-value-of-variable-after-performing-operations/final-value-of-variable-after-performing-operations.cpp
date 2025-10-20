class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int num = 0;
        for(string& i : operations){
            if(i == "++X"){
                ++num;
            }
            else if(i == "--X"){
                --num;
            }
            else if(i == "X--"){
                num--;
            }
            else{
                num++;
            }
        }
        return num;
    }
};