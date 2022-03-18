#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* Init(int num, ...);
struct ListNode* node(int number);
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
void print(struct ListNode *head);

int main(int argc, char *argv[]) {
    struct ListNode* first = Init(5, 1, 2, 3, 4, 5);
    printf("The ListNode's value is:\n");
    print(first);
    print(removeNthFromEnd(first, 2));
    return 0;
}

struct ListNode* Init(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    printf("Length is %d\n", num);
    struct ListNode* need = malloc(sizeof(struct ListNode));
    need->val = va_arg(valist, int), need->next = NULL;
    struct ListNode* point = need;
    for (int i=0; i < num - 1; i++) {
        point->next = node(va_arg(valist, int));
        point = point->next;
    }
    return need;
}


struct ListNode* node(int number)
{
    struct ListNode* need = (struct ListNode *) malloc (sizeof(struct ListNode));
    need->val = number;
    need->next = NULL;
    if (!need) {
        printf("malloc error");
        return NULL;
    }
    return need;
}

void print(struct ListNode *head)
{
    while (head->next) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("%d\b\n", head->val);
}

/* struct ListNode* removeNthFromEnd(struct ListNode* head, int n){ */
/*     struct ListNode* point = head; */
/*     struct ListNode* point2 = head; */
/*     int sz = 0; */
/*     while(point){ */
/*         sz++; */
/*         point = point->next; */
/*     } */
/*     int length = sz - n; */
/*     printf("%d", length); */
/*     if(length == 0){ */
/*         if(head->next == NULL){ */
/*             return NULL; */
/*         } else{ */
/*             head = head->next; */
/*             return head; */
/*         } */
/*     } */
/*     while(length - 1){ */
/*         length--; */
/*         head = head->next; */
/*     } */
/*     if(head->next->next){ */
/*         head->next = head->next->next; */
/*     } else { */
/*         head->next = NULL; */
/*     } */
/*     return point2; */
/* } */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //设置哑结点和快慢指针
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* fast = dummyHead;
    struct ListNode* slow = dummyHead;

    //快指针先移动 n+1 步
    while (n--) {
        fast = fast->next;
    }
    fast = fast->next;
    //快慢指针同时移动
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    //删除 slow->next
    slow->next = slow->next->next;

    return dummyHead->next;
}
