
#include<stdio.h>
#include<stdlib.h>

#define SIZE 1024*1024*1024*1024

void VectorAdd(int * a, int * b, int * c, int n){
    for (int i=0;i<n;++i)
        c[i]=a[i]+b[i];
}

int main(){
   int *a,* b, *c;
   a=(int *) malloc (SIZE*sizeof(int));
   b=(int *) malloc (SIZE*sizeof(int));
   c=(int *) malloc (SIZE*sizeof(int));

   for (int i=0;i<SIZE;++i){
       a[i]=i;
       b[i]=i;
       c[i]=0;
   }
   VectorAdd(a,b,c,SIZE);
   free(a);
   free(b);
   free(c);
   
   return 0;
}



