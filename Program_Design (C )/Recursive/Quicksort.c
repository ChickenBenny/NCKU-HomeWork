#include <stdio.h>
#define N 500
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int size;

int main(void)
{
    int array[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

void quicksort(int a[], int low, int high) {
    int middle;

    if (low >= high)
        return;
    middle = partition( a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int partition(int a[], int low, int high) {
    int i = low - 1, j, tmp;
    for (j = low;j < high;j ++){
        if (a[j] <= a[high]){
            i += 1;
            if (i == j)
                continue;
            else {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    tmp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = tmp;
    if (high == (size - 1) && low == 0) {
        printf("[ ");
        for (int count = 0; count < high + 1; count++) {
            if (count == i + 1)
                printf("*%d ", a[count]);
            else
                printf("%d ", a[count]);
        }
        printf("]\n");
    }
    else if (high < (size - 1) && low == 0){
        printf("[ ");
        for (int count = 0; count < high + 1; count++) {
            if (count == i + 1)
                printf("*%d ", a[count]);
            else
                printf("%d ", a[count]);
        }
        printf("] ");
        for (int count = high + 1;count < size;count ++)
            printf("%d ", a[count]);
        printf("\n");
    }
    else if (high == (size - 1) && low > 0){
        for (int count = 0;count < low;count ++)
            printf("%d ", a[count]);
        printf("[ ");
        for (int count = low; count < (high + 1); count++) {
            if (count == i + 1)
                printf("*%d ", a[count]);
            else
                printf("%d ", a[count]);
        }
        printf("]\n");
    }
    else if (high < (size - 1) && low > 0 ){
        for (int count = 0;count < low;count ++)
            printf("%d ", a[count]);
        printf("[ ");
        for (int count = low; count < (high + 1); count++) {
            if (count == i + 1)
                printf("*%d ", a[count]);
            else
                printf("%d ", a[count]);
        }
        printf("] ");
        for (int count = (high + 1);count < (size);count ++)
            printf("%d ", a[count]);
        printf("\n");
    }
    return i + 1;
}