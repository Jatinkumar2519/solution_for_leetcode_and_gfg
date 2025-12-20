class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int n = strs.size();
        for(int j = 0;j < strs[0].length();j++){
            bool flag = false;
            for(int i = 1;i < n;i++){
                if(strs[i - 1][j] > strs[i][j]){
                    flag = true;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};
// a b c d e f g h i j k l m n o p q r s t u v w x y z