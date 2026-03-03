class Solution {
public:
    string invert(string str){
        for(int i = 0; i < str.length();i++){
            if(str[i] == '0'){
                str[i] = '1';
            }
            else{
                str[i] = '0';
            }
        }
        return str;
    }
    char findKthBit(int n, int k) {
        string str = "0";
        while(n--){
            string temp = invert(str);
            reverse(temp.begin(),temp.end());
            str = str + '1' + temp;
        }
        return str[k-1];
    }
};