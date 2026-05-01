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
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode *temp = head;
        stack<ListNode*> s;
        int n = 1;
        while(temp->next != NULL){
            s.push(temp);
            temp = temp->next;
            n++;
        }
        s.push(temp);
        temp = head;
        ListNode* aft = head->next;
        int mid = n/2;
        while(mid != 0){
            cout << temp->val << " ";
            temp->next = s.top();
            s.pop();
            temp = temp->next;
            cout << temp->val << " ";
            temp->next = aft;
            temp = aft;
            aft = aft->next;
            mid--;
        }
        temp->next = NULL;
        temp = head;
        while(temp != NULL){
            cout << temp->val;
            temp = temp->next;
        }
        cout << head;
    }
};