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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int counter = 1;
        while((temp = temp->next) != NULL) counter++;//count all list elements
        for(int i=0; i<floor((float)counter/2); i++)//move head to middle...
            head = head->next;
        return head;
    }
};
