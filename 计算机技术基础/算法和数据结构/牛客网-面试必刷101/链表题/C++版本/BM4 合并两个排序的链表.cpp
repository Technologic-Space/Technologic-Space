/*
要求：空间复杂度O(1), 时间复杂度O(n)
基本操作抽象：比较一次, 得到一个较小的值, 往下挪动一个。这三个动作组成一组操作。
边界情况：其中一个链表的当前值为null, 也就是一个链表已经空了, 把另一个部分接到表尾就行了。
要求空间复杂度为O(1)，那就选定一个链表为基本，在它身上进行插入。
*/

class Solution{
    public:
        ListNode* Merge(ListNode *pHead1, ListNode* pHead2){
            if (pHead1 == NULL)
                return pHead2;
            if (pHead2 == NULL)
                return pHead1;
            ListNode* head = new ListNode(0);
            ListNode* cur = head;

            while (pHead1 && pHead2){
                if (pHead1->val <= pHead2->val){
                    cur->next = pHead1;
                    pHead1 = pHead1->next;
                }
                else{
                    cur->next = pHead2;
                    pHead2 = pHead2->next;
                }
                cur = cur->next;
            }

            if (pHead1)
                cur->next = pHead1;
            else
                cur->next = pHead2;
            return head->next;
        }
};



