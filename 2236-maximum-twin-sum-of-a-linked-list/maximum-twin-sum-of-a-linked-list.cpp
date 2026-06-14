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
    int pairSum(ListNode* head) {

        auto reverse = [&](ListNode* node)->ListNode*{

            ListNode* curr = node;
            ListNode* prev = nullptr;
            ListNode* next;

            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            return prev;
        };

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;

        head2 = reverse(head2);

        int maxv = 0;
        while(head && head2){
            maxv = max(maxv,head->val + head2->val);

            head = head->next;
            head2 = head2->next;
        }

        return maxv;
    }
};