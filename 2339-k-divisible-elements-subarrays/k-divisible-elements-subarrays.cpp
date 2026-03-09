class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        struct Node {
            bool isend;
            unordered_map<int, Node*> child;

            Node() { isend = false; }
        };

        Node* root = new Node();
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int odds = 0;
            Node* temp = root;
            for (int j = i; j < n; j++) {
                if (temp->child.count(nums[j]) == 0) {
                    temp->child[nums[j]] = new Node();
                }
                odds += (nums[j] % p == 0);
                temp = temp->child[nums[j]];

                if (odds > k)
                    break;
                    
                count += !temp->isend;
                temp->isend = true;
            }
        }

        return count;
    }
};