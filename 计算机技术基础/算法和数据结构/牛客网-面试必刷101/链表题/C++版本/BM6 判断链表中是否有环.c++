/*
要求：空间复杂度O(1), 时间复杂度O(n)
想到图算法中，某个算法可以判断图是否有环。
靠, 我脑子里闪过了一个“相遇”的设想，但是没有深究下去。
设置一个快指针和慢指针，如果没有环，快指针的值永远不会和慢指针的值相同，
除非到尾巴的null。而有环的话, 当快慢指针都进入环中后，就变成了一个追击问题，那就是
快指针永远会追上慢指针。那么下个问题就是快多少的问题，快指针只能是快一步。
*/

class Solution{
    public:
        bool hasCycle(ListNode *head){
            if (head == NULL)
                return false;
            ListNode *fast = head;
            ListNode *slow = head;

            while (fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow)
                    return true;
            } // 正常来说, fast指针会先到链表尾, 所以采用fast指针来判断。

            // 正常没环就跳出循环体正常下来执行
            return false;
        }
};