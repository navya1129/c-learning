/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        map<ListNode*,ListNode*> m;
        int pos = 0;
        ListNode* temp = head;
        while(temp->next != NULL){
            // if(temp->next->val == temp->val) return true;
            if(m.find(temp) != m.end() && m[temp] == temp->next) return true;
            else if(m.find(temp) == m.end()) m[temp] = temp->next;
            pos++;
            temp = temp->next;
        }
        return false;
    }
};