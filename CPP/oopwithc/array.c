
#include<stdio.h>
#include<stdlib.h>
void fillarray(int **);
int main(){
    int * ptr_list[10];
    fillarray(ptr_list);
    
    printf("%d\n",*(ptr_list[1]));
    return 0;
}
void fillarray(int  ** list){
    for (int i=0;i<10;++i){
        list[i]=(int *)malloc(sizeof(int));
        *list[i]=i;
    }

}
