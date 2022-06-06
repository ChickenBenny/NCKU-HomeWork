#include<stdio.h>
#include<stdlib.h>

struct snack
{
    int id;
    int price;
    int weight;
    double value;
};

int cmp(const void *a, const void *b);
void sort_snacks(struct snack snacks[], int n);

int main() {
    int n;
    struct snack snacks[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        snacks[i].id = i+1;
        scanf("%d %d", &snacks[i].price, &snacks[i].weight);
    }
    sort_snacks(snacks, n);
    for(int i=0; i<n; i++) {
        printf("%d %.2f\n", snacks[i].id, snacks[i].value);
    }
    return 0;
}

void sort_snacks(struct snack snacks[], int n) {
    for (int i = 0;i < n;i ++)
        snacks[i].value = (double)snacks[i].weight/ snacks[i].price;
    qsort(snacks, n, sizeof(snacks[0]), cmp);
}

int cmp(const void *a, const void *b) {
    struct snack *c = (struct snack *)a;
    struct snack *d = (struct snack *)b;
    if (c->value < d->value)
        return 1;
    else if ((c->value == d->value) && (c->price == d->price) && (c->id > d->id))
        return 1;
    else if ((c->value == d->value) && (c->price > d->price))
        return 1;
    else
        return -1;
}