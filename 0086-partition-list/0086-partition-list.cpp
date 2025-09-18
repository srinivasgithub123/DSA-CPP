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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp= head;
        vector<int> partition;
        if (!head) return nullptr;
        while(temp!=nullptr){
            partition.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> partition1;
        for(int i=0; i<partition.size(); i++){
            if(partition[i]<x){
                partition1.push_back(partition[i]);
            }
        }
        for(int i=0; i<partition.size();i++){
            if(partition[i]>=x){
                partition1.push_back(partition[i]);
            }
        }
        ListNode* head1= new ListNode(partition1[0]);
        ListNode* curr=head1;
        for(int i=1; i<partition1.size();i++){
            curr->next=new ListNode(partition1[i]);
            curr=curr->next;
        }
        return head1;
        
    }
};