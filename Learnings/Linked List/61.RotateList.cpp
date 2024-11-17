//https://leetcode.com/problems/rotate-list/
//EASY

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
    ListNode *findNthNode(ListNode *node,int i){
        //1-2-3-4-5-6-7-8; k=3 means  u have to stand on 5 means take 4 jumps
        int jumps=i-1;
        while(jumps){
            node=node->next;
            jumps--;
        }
        return node;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode *tail = head;
        int n = 1;
        while(tail->next){
            n++;
            tail=tail->next;
        }
        if(k%n==0) return head;
        k=k%n;
        tail->next = head;

        ListNode *newLastNode = findNthNode(head,n-k);
        head=newLastNode->next;
        newLastNode->next=NULL;
        return head;
        //O(2n),O(1)
    }
    
};