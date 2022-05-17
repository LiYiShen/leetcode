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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *pre = NULL, *fast = head;
        while (fast && fast->next) {  // fastȷ��slow�ߵ������м�
            ListNode* temp = slow;
            slow = slow->next;
            fast = fast->next->next;
            temp->next = pre;
            pre = temp;
        }
        if (fast) slow = slow->next;  // ����Ԫ�ظ���Ϊ����, �������м�Ԫ��
        while (pre && slow) {
            if (pre->val != slow->val) return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;  // �ж�һ�������Ƿ�Ϊ�������� (��������ǰ�벿��)
    }
};