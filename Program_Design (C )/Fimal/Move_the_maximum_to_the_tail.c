#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val); 
    return 0;
}

void MoveToTail() {
    struct node *max = NULL;
    struct node *prev = NULL;
    int max_num = 0;
    for (struct node* p = head;p != NULL;p = p->next){
        if (p->val > max_num){
            max_num = p->val;
        }
    }
    for (max = head, prev = NULL; max != NULL && max->val != max_num;prev = max, max = max->next);
    if (max->next == NULL)return;
    else {
        prev->next = max->next;
        free(max);
        struct node* tmp = malloc(sizeof(struct node));
        tmp->next = NULL;
        tmp->val = max_num;
        tail->next = tmp;
        tail = tmp;
    }
}
