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
        if(!head || !head->next) return head;
        int length = 1;

        ListNode * dummy = head;

        while(dummy->next){
            dummy = dummy->next;
            length++;
        }

        k = k % length;

        if(k==0){
            return head;
        }

        ListNode * curr = head;

        for(int i = 0; i<length-k-1; i++){
            curr = curr->next;
        }

        ListNode* nhead = curr->next;
        curr->next = nullptr;

        dummy->next = head;


        return nhead;
        
    }
};