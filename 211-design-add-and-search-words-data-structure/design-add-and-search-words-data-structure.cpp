class WordDictionary {
public:
    struct Node{
        bool isend;
        Node* child[26];
        Node(){
            isend = false;
            for(int i = 0;i < 26;i++){
                child[i] = nullptr;
            }
        }
    };
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(char& ch : word){
            if(temp->child[ch - 'a'] == nullptr){
                temp->child[ch -'a'] = new Node();
            }
            temp = temp->child[ch - 'a'];
        }
        temp->isend = true;
    }
    
    bool search(string word) {
        function<bool(Node*,int)> solve = [&](Node* temp,int i) -> bool{
            if(!temp) return false;
            if(i == word.length()) return temp->isend;
            if(word[i] == '.'){
                bool flag = false;
                for(int j = 0;j < 26;j++){
                    if(temp->child[j]){
                        flag = true;
                        if(solve(temp->child[j],i + 1)) return true;
                    }
                }
                if(!flag) return false;
            }
            else{
                return solve(temp->child[word[i] - 'a'],i + 1);
            }
            return false;
        };
        return solve(root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */