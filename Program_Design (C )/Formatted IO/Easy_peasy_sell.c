#include<stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
    printf("\\    %3d%%off!    \\\n", a);
    printf("\\ Before  $%5d \\\n", b);
    printf("\\ After   $%5.2f \\\n", (float) b * (1 -((float) a/ 100)));
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");
    return 0;
}