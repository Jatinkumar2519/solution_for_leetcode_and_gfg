class Solution {
public:
    int countPairs(vector<int>& arr, int low, int high) {
        struct Node {
            int count;
            vector<Node*> child;

            Node() {
                count = 0;
                child = vector<Node*>(2);
            }
        };

        Node* root = new Node();
        int maxLen = log2(20000) + 1;

        auto insert = [&](int num) -> void {
            Node* temp = root;
            for (int i = maxLen; i >= 0; i--) {

                int bit = ((num & (1 << i)) > 0);

                if (temp->child[bit] == nullptr) {
                    temp->child[bit] = new Node();
                }

                temp = temp->child[bit];
                temp->count++;
            }
        };

        auto check = [&](int num, int limit) -> int {
            Node* temp = root;
            int curr = 0, count = 0;

            for (int i = maxLen; i >= 0; i--) {

                if (!temp)
                    break;

                int bit = (num & (1 << i)) > 0;
                int limBit = (limit & (1 << i)) > 0;

                if (limBit) {
                    if(temp->child[bit]){
                        count += temp->child[bit]->count;
                    }

                    temp = temp->child[1 - bit];
                } else {

                    temp = temp->child[bit];
                }
            }

            if (temp)
                count += temp->count;

            return count;
        };

        int n = arr.size();

        insert(arr[0]);
        int count1 = 0;

        for (int i = 1; i < n; i++) {

            count1 += check(arr[i], low - 1);
            insert(arr[i]);
        }

        root = new Node();

        insert(arr[0]);
        int count2 = 0;

        for (int i = 1; i < n; i++) {

            count2 += check(arr[i], high);
            insert(arr[i]);
        }

        return (count2 - count1);
    }
};