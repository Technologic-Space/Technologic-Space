/*
时间复杂度在O(n*logn), 合并k个升序的链表并将结果作为一个升序的链表, 节点总数为n。
如果采取BM4中的方法呢，它的时间复杂度在多少，确定一个节点的位置需要比较n-1次, 
n-1, n-2, n-3, ... , 0 总共是这么多次。时间复杂度是O(n*n - n)级的。不符合时间复杂度的要求。
那么, 怎么办呢, 看到logn么, 大概率是归并，先两个两个归并为一个, 然后再两个两个归并为1个，就这样一直到最后一个。
然后官方方法又是用到了递归。
传进去的lists是一个链表的列表, 归并用递归来也行, 用循环也可以, 用递归更清晰些。
然后, 我们就边界条件到达时的操作, Merge2定义下。
*/

class Solution{
    public:
        ListNode* Merge2(ListNode *pHead1, ListNode *pHead2){
            if (pHead1 == NULL)
                return pHead2;
            if (pHead2 == NULL)
                return pHead1;
            
            ListNode *head = new ListNode(0);
            ListNode *cur = head;

            while (pHead1 && pHead2){
                if (pHead1->val <= pHead2->val){
                    cur->next = pHead1;
                    pHead1 = pHead1->next;
                }
                else {
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

        ListNode* divideMerge(vector<ListNode*>& lists, int left, int right){
            if (left > right)
                return NULL;
            else if (left == right)
                return lists[left];
            int mid = (left + right)/2;
            return Merge2(divideMerge(lists, left, mid), divideMerge(lists, mid+1, right));
        }

        ListNode* mergeKLists(vector<ListNode*>& lists){
            return divideMerge(lists, 0, lists.size()-1);
        }
};