Brute Force approach
​
Merge the list into one list and sort them
​
```
ListNode* mergeKLists(vector<ListNode*>& lists) {
if(lists.empty())
return NULL;
ListNode *dummyHead = new ListNode(0),*head = dummyHead;
for(auto list : lists){
while(list){
ListNode *temp = new ListNode(list->val);
head->next = temp;
head = head->next;
list = list->next;
}
}
head = dummyHead->next;
ListNode *i = head;
while(i){
ListNode *j = i->next;
ListNode *mn = i;
while(j){
if(j->val < mn->val){
mn = j;
}
j = j->next;
}
swap(i->val,mn->val);
i = i->next;
}
return head;
}
```
​
​