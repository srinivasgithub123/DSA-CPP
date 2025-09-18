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
    ListNode* sortList(ListNode* head) {
        if(!head)return nullptr;
        vector<int> sort1;
        ListNode* temp= head;
        while(temp){
            sort1.push_back(temp->val);
            temp= temp->next;
        }
        sort(sort1.begin(), sort1.end());
        ListNode* head1= new ListNode(sort1[0]);
        ListNode* curr= head1;

        for(int i=1; i<sort1.size(); i++){
            curr->next= new ListNode(sort1[i]);
            curr=curr->next;
        }

        return head1;
    }
};