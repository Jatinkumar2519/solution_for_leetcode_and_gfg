class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        struct Node{
            bool isEnd;
            vector<Node*> child;

            Node(){
                isEnd = false;
                child.resize(10,nullptr);
            }
        };

        Node* root = new Node();
        
        function<void(string&)> insert = [&](string& num){
            Node* temp = root;

            for(auto& ch : num){
                if(!temp->child[ch - '0']){
                    temp->child[ch - '0'] = new Node();
                }

                temp = temp->child[ch - '0'];
            }

            temp->isEnd = true;
        };

        function<int(string&)> search = [&](string& num)->int{
            Node* temp = root;

            int count = 0;
            for(auto& ch : num){
                if(!temp->child[ch - '0']) break;

                temp = temp->child[ch - '0'];
                count++;
            }

            return count;
        };

        for(auto& num : arr1){

            string strnum = to_string(num);
            insert(strnum);
        }

        int res = 0;
        for(auto& num : arr2){

            string strnum = to_string(num);
            res = max(res,search(strnum));
        }

        return res;

    }
};