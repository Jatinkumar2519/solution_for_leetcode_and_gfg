class Solution {
public:
    int maxl;

    struct Node {
        unordered_map<char, Node*> child;
        int len;
        int idx;

        Node() {
            len = INT_MAX;
            idx = INT_MAX;
        }
    };

    void update(Node* node, int len, int idx) {
        if (len < node->len) {
            node->len = len;
            node->idx = idx;
        } else if (len == node->len) {
            node->idx = min(node->idx, idx);
        }
    }

    void insert(Node* root, string& word, int idx) {

        Node* temp = root;

        update(temp, word.size(), idx);

        int len = 0;
        for (int i = word.size() - 1; i >= 0 && len < maxl; i--) {

            char ch = word[i];len++;

            if (temp->child.find(ch) == temp->child.end()) {
                temp->child[ch] = new Node();
            }

            temp = temp->child[ch];

            update(temp, word.size(), idx);
        }
    }

    int search(Node* root, string& word) {

        Node* temp = root;

        for (int i = word.size() - 1; i >= 0; i--) {

            char ch = word[i];

            if (temp->child.find(ch) == temp->child.end()) {
                break;
            }

            temp = temp->child[ch];
        }

        return temp->idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,vector<string>& wordsQuery) {

        Node* root = new Node();

        maxl = 0;
        for(auto& word : wordsQuery){
            maxl = max(maxl,(int)word.length());
        }

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(root, wordsContainer[i], i);
        }

        vector<int> ans;

        for (string& q : wordsQuery) {
            ans.push_back(search(root, q));
        }

        return ans;
    }
};