class Solution {
public:
    int maximum69Number (int num) {
        string mynum = to_string(num);
        for(char& ch : mynum){
            if(ch == '6'){
                ch = '9';
                break;
            }
        }
        return stoi(mynum);
    }
};