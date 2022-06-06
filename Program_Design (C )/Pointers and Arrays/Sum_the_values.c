#include <stdio.h>

void star(int*, int*);

int main()
{
    int arr[5], result;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);
    
    star(arr, &result);

    printf("%d", result);

    return 0;
}

void star(int *arr, int *result) {
    *result = 0;
    int *i;
    for (i = &arr[0];i <= &arr[5];i ++){
        *result += *i;
    }
}
