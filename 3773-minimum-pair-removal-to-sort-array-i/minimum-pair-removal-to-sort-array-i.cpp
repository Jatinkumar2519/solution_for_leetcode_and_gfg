class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        struct Node{
            int val;
            Node* next;
            Node(int val){
                this->val = val;
                next = nullptr;
            }
        };

        Node* head;
        auto feasible = [&](){
            Node* temp = head;
            while(temp->next){
                if(temp->val > temp->next->val) return false;
                temp = temp->next;
            }
            return true;
        };
        
        Node* dummy = new Node(0);
        Node* temp = dummy;

        for(int i = 0;i < n;i++){
            temp->next = new Node(nums[i]);
            temp = temp->next;
        }

        head = dummy->next;

        int count = 0;
        while(!feasible()){

            temp = head;
            Node* currprev = nullptr;

            Node* prev = nullptr;
            Node* curr = nullptr;

            int minv = INT_MAX;

            while(temp->next){
                int sum = temp->val + temp->next->val;

                if(sum < minv){
                    minv = sum;
                    prev = currprev;
                    curr = temp;
                }

                currprev = temp;
                temp = temp->next;
            }

            int sum = curr->val + curr->next->val;
            Node* newnode = new Node(sum);

            if(prev == nullptr){
                newnode->next = curr->next->next;
                head = newnode;
            }
            else{
                prev->next = newnode;
                newnode->next = curr->next->next;
            }

            count++;
        }

        return count;
    }
};