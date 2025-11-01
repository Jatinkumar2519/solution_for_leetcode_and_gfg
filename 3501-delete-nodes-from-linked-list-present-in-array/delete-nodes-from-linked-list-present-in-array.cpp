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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set;
        for(int& num : nums){
            set.insert(num);
        }
        ListNode* newnode = new ListNode();
        newnode -> next = head;
        head = newnode;
        ListNode* curr = head;
        while(curr->next){
            if(set.count(curr->next->val)){
                curr->next= curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head->next;
    }
};