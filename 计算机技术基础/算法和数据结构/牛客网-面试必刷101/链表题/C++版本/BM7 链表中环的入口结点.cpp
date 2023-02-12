/*
要求: 空间复杂度O(1), 时间复杂度O(n)
然后就是找到环的入口, 无环的可视为环为null的环。
没有思路
*/

class Solution{
    public:
        ListNode* hasCycle(ListNode* head){
            if (head == NULL)
                return NULL;
            
            ListNode* fast = head;
            ListNode* slow = head;

            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow)
                    return slow;
            }
            return NULL;
        }

        ListNode* EntryNodeOfLoop(ListNode* pHead){
            ListNode* slow = hasCycle(pHead);
            if (slow == NULL)
                return NULL;
            ListNode* fast = pHead;
            // 在此相遇即是环入口

            while (fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
};
/*
这边讨论一下，为什么再次相遇即是环入口。
*/