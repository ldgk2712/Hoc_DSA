#include<stdio.h>
void deleteArray(int a[], int* n, int index){
    for (int i = index ; i < *n-1; i++)
    {
        a[i] = a[i+1];
    }
    (*n)--;
}

int main(){
    int n, a[100], index;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&index);

    deleteArray(a,&n,index);
    for(int i = 0; i < n; i++){
    printf("%d ",a[i]);
    }
    printf("\n");
}
