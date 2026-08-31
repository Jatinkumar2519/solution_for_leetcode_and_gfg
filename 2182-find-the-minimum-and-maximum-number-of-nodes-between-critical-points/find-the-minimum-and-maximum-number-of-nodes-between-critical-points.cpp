/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int len = 2;

        ListNode* prev = head;
        ListNode* temp = head->next;

        vector<int> arr;

        while(temp && temp->next){
            if((prev->val > temp->val && temp->val < temp->next->val) || 
                (prev->val < temp->val && temp->val > temp->next->val)){
                arr.push_back(len);
            }
            len++;

            prev = temp;
            temp = temp->next;
        }

        if(arr.size() < 2) return {-1,-1};

        int maxv = arr.back() - arr[0];
        int minv = INT_MAX;

        for(int i = 1;i < arr.size();i++){
            minv = min(minv,arr[i] - arr[i - 1]);
        }
        return {minv,maxv};
    }
};