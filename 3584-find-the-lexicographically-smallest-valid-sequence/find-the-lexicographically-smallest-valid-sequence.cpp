class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last(m,-1);
        int j = m - 1;

        for(int i = n - 1;i >= 0;i--){
            if(j >= 0 && word1[i] == word2[j]){
                last[j] = i;
                j -= 1;
            }
        }

        vector<int> result;
        bool used = false;
        j = 0;

        for(int i = 0;i < n && j < m;i++){

            if(word1[i] == word2[j] || (!used && (j + 1 == m || i < last[j + 1]))){

                used = used || (word1[i] != word2[j]);
                result.push_back(i);
                j++;
            }
        }

        return (j == m) ? result : vector<int>();
    }
};

// if (m > n)
//     return {};

// vector<vector<bool>> check(26, vector<bool>(n));
// for (char ch = 'a'; ch <= 'z'; ch++) {

//     check[ch - 'a'][n - 1] = (ch == word1[n - 1]);
//     for (int i = n - 2; i >= 0; i--) {
//         check[ch - 'a'][i] = check[ch - 'a'][i + 1] || (ch == word1[i]);
//     }
// }

// bool used = false;
// int i = 0;
// int j = 0;

// while (i < n && j < m) {
//     if (check[word2[j] - 'a'][i]) {

//         while (i < n && word1[i] != word2[j])
//             i++;
//         result.push_back(i);
//         j++;
//     }
// }