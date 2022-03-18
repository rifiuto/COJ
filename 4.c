#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* Init(int num, ...);
struct ListNode* node(int number);
struct ListNode* rotateRight(struct ListNode* head, int k);
void print(struct ListNode *head);
int main(int argc, char *argv[]) {
    struct ListNode* first = Init(5, 1, 2, 3, 4, 5);
    /* struct ListNode* first = Init(3, 0, 1, 2); */
    printf("The first ListNode's value is:\n");
    print(first);
    struct ListNode *result = rotateRight(first, 4);
    print(result);
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

struct ListNode* rotateRight(struct ListNode* head, int k){
    int count = 0;
    struct ListNode *point = head;
    struct ListNode *back;
    while (point) {
        back = point;
        point = point->next;
        count++;
    }
    if (!count) {
        return NULL;
    }
    point = back;
    point->next = head;
    int need_length = count - k % count -1 ;
    while (need_length--) {
        head = head->next;
    }
    point = head->next;
    head->next = NULL;
    return point;
}
