class Solution {
public:
    struct Node {
        Node* child[2];
        Node() { child[0] = child[1] = nullptr; }
    };
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Node* root = new Node();
        function<void(int)> insert = [&](int num) -> void {
            Node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = ((num & (1 << i)) > 0) ? 1 : 0;
                if (temp->child[bit] == nullptr) {
                    temp->child[bit] = new Node();
                }
                temp = temp->child[bit];
            }
        };
        function<int(int)> search = [&](int num) -> int {
            int sum = 0;
            Node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = ((num & (1 << i)) > 0) ? 1 : 0;
                if (bit == 1) {
                    if (temp->child[0]) {
                        sum = (sum | (1 << i));
                        temp = temp->child[0];
                    } else {
                        temp = temp->child[1];
                    }
                } else {
                    if (temp->child[1]) {
                        sum = (sum | (1 << i));
                        temp = temp->child[1];
                    } else {
                        temp = temp->child[0];
                    }
                }
            }
            return sum;
        };
        int maxval = 0;
        insert(nums[0]);
        for (int i = 1;i < n;i++) {
            maxval = max(maxval, search(nums[i]));
            insert(nums[i]);
        }
        return maxval;
    }
};