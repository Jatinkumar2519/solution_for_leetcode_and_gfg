class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0,j = 0;
        int m = version1.length();
        int n = version2.length();
        int k;
        while(i < m && j < n){
            int num1 = 0;
            while(i < m && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            int num2 = 0;
            while(j < n && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if(num1 > num2){
                return 1;
            }
            else if(num1 < num2){
                return -1;
            }
            i++;j++;
        }
        while(i < m){
            if(version1[i] != '.' && version1[i] != '0'){
                return 1;
            }
            i++;
        }
        while(j < n){
            if(version2[j] != '.' && version2[j] != '0'){
                return -1;
            }
            j++;
        }
        return 0;
    }
};