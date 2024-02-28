#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
 *   cppcheck-suppress nullPointer
 */


/* Create an empty queue */
struct list_head *q_new()
{
    struct list_head *new_queue = malloc(sizeof(struct list_head));
    if(!new_queue){
    	return NULL;   //分配記憶體失敗
    }
    INIT_LIST_HEAD(new_queue);
    return new_queue;
}

/* Free all storage used by queue */
void q_free(struct list_head *head) 
{
    if (!head){
    	return;
    }
    if (list_empty(head)){
    	free(head);
    	return;
    }
    element_t *entry, *safe;
    list_for_each_entry_safe(entry, safe, head, member){
    	list_del(entry);
    	free(entry);
    }
    free(head);
}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    if (!head || !s){
    	return false;    //確保s與head不是空指針
    }
    element_t *copy_str = malloc(sizeof(element_t));   //分配給s的空間並製作node
    if (!copy_str){
    	return false;
    }
    copy_str->value = strdup(s);    //複製s到node
    if (!copy_str){
    	free(copy_str);
    	return false;
    }
    list_add(&copy_str->list, head)   //加到head
    return true;
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    if (!head || !s){
    	return false;    //確保s與head不是空指針
    }
    element_t *copy_str = malloc(sizeof(element_t));   //分配給s的空間並製作node
    if (!copy_str){
    	return false;
    }
    copy_str->value = strdup(s);    //複製s到node
    if (!copy_str){
    	free(copy_str);
    	return false;
    }
    list_add(&copy_str->list, head);   //加到head
    return true;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    if (!head || list_empty(head)){
    	return NULL;
    }
    element_t *q_str = list_first_entry(head, element_t, list);   //head的value與list抓出來
    list_del(&q_str->list);
    if (sp != NULL && bufsize-1 > 0){
    	strncpy(sp, q_str->value, bufsize-1);
    	sp[bufsize-1] = '\0';
    }
    return q_str;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    if (!head || list_empty(head)){
    	return NULL;
    }
    element_t *q_str = list_last_entry(head, element_t, list);   //head的value與list抓出來
    list_del(&q_str->list);
    if (sp != NULL && bufsize-1 > 0){
    	strncpy(sp, q_str->value, bufsize-1);
    	sp[bufsize-1] = "\0";
    }
    return q_str;
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if(!head){
    	return 0;
    }
    int count = 0;   //計數
    element_t *node;
    list_for_each(node, head){
    	count += 1;
    }
    
    return count;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    if (!head || list_empty(head)){
    	return false;
    }
    int size_q = q_size(head);
    
    mid = (size_q -1)/2;
    struct list_head *node = head->next;
    int index = 1;   //node指向了第1個不是第0個，所以index設成1
    if (node != head && index < mid){
    	node = node->next;
    	index ++;
    }
    list_del(node);
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
