class Solution {
public:
    int maxOperations(string s) {
        int i = 0;
        int one = 0;
        int count = 0;
        int n = s.length();
        while(i < n){
            if(s[i] == '1'){ 
                one++;i++;
            }
            else{
                while(i < n && s[i] == '0'){
                    i++;
                }
                count += one;
            }
        }
        return count;
    }
};