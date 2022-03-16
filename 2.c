#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* Init(int num, ...);
struct ListNode* node(int number);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void print(struct ListNode *head);
int main(int argc, char *argv[]) {
    struct ListNode* first = Init(4, 9, 9, 9, 9);
    struct ListNode* second = Init(7, 9,9,9,9,9,9,9);
    /* struct ListNode* first = Init(3, 4, 0, 2); */
    /* struct ListNode* second = Init(3, 8, 9, 3); */
    /* struct ListNode* first = Init(2, 1, 8); */
    /* struct ListNode* second = Init(1, 0); */

    printf("The first ListNode's value is:\n");
    print(first);
    printf("The second ListNode's value is:\n");
    print(second);
    printf("Test for the add:\n");
    struct ListNode* result = addTwoNumbers(first, second);
    print(result);
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int value = l1->val + l2->val;
    int mold = value / 10, remainder = value % 10;
    struct ListNode * result = (struct ListNode *) malloc (sizeof(struct ListNode));
    if (!result) {
        printf("malloc error");
        return NULL;
    }
    result->val = remainder, result->next = NULL;
    l1 = l1->next, l2 = l2->next;
    struct ListNode* point = result;
    while (l1 && l2) {
        struct ListNode* temp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!temp) {
            printf("malloc error");
            return NULL;
        }
        value = l1->val + l2->val + mold;
        mold = value / 10, remainder = value % 10;
        temp->val = remainder, temp->next = NULL;
        point->next = temp, point = point->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    struct ListNode* end = l1 ? l1 : l2;
    while (end) {
        end->val += mold;
        if (end->val / 10) {
            mold = 1;
            end->val -= 10;
        } else {
            mold = 0;
        }
        point->next = end;
        point = point->next;
        end = end->next;
    }
    if (mold) {
        struct ListNode* temp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!temp) {
            printf("malloc error");
            return NULL;
        }
        temp->val = mold, temp->next = NULL;
        point->next = temp;
    }
    return result;
}
/* struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) */
/* { */
/*     int value = l1->val + l2->val, mold=0, remainder=0; */
/*     mold = value / 10, remainder = value % 10; */
/*     struct ListNode *result = (struct ListNode *) malloc (sizeof(struct ListNode)); */
/*     if (!result) { */
/*         printf("malloc error"); */
/*         return NULL; */
/*     } */
/*     result->val = remainder, result->next = NULL; */
/*     struct ListNode *point = result; */
/*     l1 = l1->next, l2 = l2->next; */
/*     while (l1 && l2) { */
/*         value = l1->val + l2->val + mold; */
/*         mold = value / 10, remainder = value % 10; */
/*         struct ListNode* temp = (struct ListNode *) malloc(sizeof(struct ListNode)); */
/*         if (!temp) { */
/*             printf("malloc error"); */
/*             return NULL; */
/*         } */
/*         temp->val = remainder, temp->next = NULL; */
/*         point->next = temp, point = point->next; */
/*         l1 = l1->next; */
/*         l2 = l2->next; */
/*     } */
/*     if (mold) { */
/*          struct ListNode* temp = (struct ListNode *) malloc(sizeof(struct ListNode)); */
/*         if (!temp) { */
/*             printf("malloc error"); */
/*             return NULL; */
/*         } */
/*         temp->val = mold, temp->next = NULL; */
/*         point->next = temp, point = point->next; */
/*     } */
/*     print(result); */
/*     /\* point->val += (l1->val + l2->val) % 10; *\/ */
/*     /\* l1 = l1->next, l2 = l2->next; *\/ */
/*     while (l1) { */
/*         value = l1->val + mold; */
/*         mold = value / 10, remainder = value % 10; */
/*         struct ListNode* temp = (struct ListNode *) malloc(sizeof(struct ListNode)); */
/*         if (!temp) { */
/*             printf("malloc error"); */
/*             return NULL; */
/*         } */
/*         temp->val = remainder, temp->next = NULL; */
/*         point->next = temp, point = point->next; */
/*         l1 = l1->next; */
/*     } */
/*     /\* point = point->next; *\/ */
/*     /\* printf("%d %d\n", point->val, l2->val); *\/ */
/*     /\* print(result); *\/ */
/*     while (l2) { */
/*         value = l2->val + mold; */
/*         mold = value / 10, remainder = value % 10; */
/*         struct ListNode* temp = (struct ListNode *) malloc(sizeof(struct ListNode)); */
/*         if (!temp) { */
/*             printf("malloc error"); */
/*             return NULL; */
/*         } */
/*         temp->val = remainder, temp->next = NULL; */
/*         point->next = temp, point = point->next; */
/*         l2= l2->next; */
/*     } */
/*     return result; */
/* } */



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
