class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n + 1);

        int res = 0;
        vector<int> result(n);
        for(int i = 0;i < n;i++){
            if(++count[A[i]] == 2) res++;
            if(++count[B[i]] == 2) res++;

            result[i] = res;
        }

        return result;
    }
};