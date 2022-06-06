#include<stdio.h>

void pre_order(int tree[], int n);
void in_order(int tree[], int n);
void post_order(int tree[], int n);

int main () {
    int type, num, tree[15000] = {0};
    scanf("%d\n", &type);
    scanf("%d\n", &num);
    for (int i = 1;i <= num;i ++)
        scanf("%d", &tree[i]);
    if (type == 0){
        pre_order(tree, 1 );
    }
    else if (type == 1){
        in_order(tree, 1 );
    }
    else {
        post_order(tree, 1 );
    }

}

void pre_order(int tree[], int n){
    if (tree[n] != 0){
        printf("%d ", tree[n]);
        pre_order(tree, 2 * n);
        pre_order(tree, 2 * n + 1);
    }
    else
        return;
}

void in_order(int tree[], int n){
    if (tree[2*n] != 0){
        in_order(tree, 2 * n);
    }
    printf("%d ", tree[n]);
    if (tree[2*n+1] != 0)
        in_order(tree, 2 * n + 1);
    return;
}

void post_order(int tree[], int n){
    if (tree[2 * n] != 0){
        post_order(tree, 2 * n);
    }
    if (tree[2 * n + 1] != 0){
        post_order(tree, 2 * n + 1);
    }
    printf("%d ", tree[n]);
    return;
}