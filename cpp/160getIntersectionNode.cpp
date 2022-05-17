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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb) {  // ʹ pa pb �߹���ͬ���ȵľ���, ֱ���ཻ
            pa = (pa != NULL) ? pa->next : headB;
            pb = (pb != NULL) ? pb->next : headA;
        }
        return pa;  // �ҵ������������ཻ����ʼ�ڵ�
    }
};