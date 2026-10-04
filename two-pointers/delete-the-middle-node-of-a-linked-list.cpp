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
    ListNode* deleteMiddle(ListNode* head) {
          if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode * P1=head;
        ListNode * P2=head->next;
        while(P2->next!=NULL && P2->next->next!=NULL){
            P2=P2->next->next;
            P1=P1->next;
        }
        P1->next=P1->next->next;
        return head;
    }
};