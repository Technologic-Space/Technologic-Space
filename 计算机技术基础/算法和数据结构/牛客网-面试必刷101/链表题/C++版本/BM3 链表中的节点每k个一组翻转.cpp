/*
一个很自然的想法就是一步步地走, 对于每一次翻转，我们先找到链表尾, 然后翻转，找到了链表尾巴也就找到了下一次翻转的链表头。
然后，对于每一次翻转，就可以应用提取出的子步骤一个一个处理。这个子步骤相当于模块化一下：
然后查找链表尾的时候，进行一个计数, 这样就可以找出结尾的不足k个的组。

这个官方代码是递归了, 但是实际上可以不用递归, 对吧, 大多数的递归是可以用循环来化解的。
*/

class Solution{
    public:
        ListNode* reverseKGroup(ListNode*head , int k){
            ListNode *tail = head;
            for (int i = 0; i < k; i++){
                if (tail == NULL)
                    return head;
                tail = tail->next;
            } //注意，这边的tail是第k+1个。
            ListNode* pre = NULL;
            ListNode* cur = head;

            while (cur != tail){
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            } // 所以, 第一组的pre是整个翻转链表的头结点。

            head->next = reverseKGroup(tail,k);

            return pre;
        }
};