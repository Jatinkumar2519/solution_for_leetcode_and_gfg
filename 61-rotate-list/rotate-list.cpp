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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 ||!head->next){
            return head;
        }
        ListNode* n = head;
        int len = 1;
        while(n->next){
            len++;
            n = n -> next;
        }
        n->next = head;
        k = k % len;
        k = len - k;
        for(int i = 0; i < k - 1;i++){
            head = head->next;
        }
        ListNode* newnode = head->next;
        head->next = nullptr;
        return newnode;
    }
};