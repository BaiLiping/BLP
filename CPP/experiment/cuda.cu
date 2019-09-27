
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1024*1024*1024
__global__ void VectorAdd(int *a, int *b, int *c, int n){
//void VectorAdd(int *a, int *b, int *c, int n){ 
  int i=threadIdx.x;
    if ( i<n-10){
        a[i]=b[i]*a[i+1]*a[i+2];
        b[i]=a[i+1]+b[i+1]*a[i+4];
        c[i]=a[i+1]*a[i]*a[i+1]*b[i]*b[i+1];
    }
    if(i<n-10){
        c[i]=c[i+1]*c[i+2]*c[i+3]*c[i+4];
    }

}

int main(){
    int *a, *b, *c;
    int *d_a,*d_b,*d_c;
a=(int *) malloc (SIZE*sizeof(int));    
b=(int *) malloc (SIZE*sizeof(int));
c=(int *) malloc (SIZE*sizeof(int));

cudaMalloc(&d_a,SIZE*sizeof(int));
cudaMalloc(&d_b,SIZE*sizeof(int));
cudaMalloc(&d_c,SIZE*sizeof(int));

for (int i=0;i<SIZE;++i){
    a[i]*=i;
    b[i]*=i;
    c[i]=0;
}
cudaMemcpy(d_a, a, SIZE*sizeof(int),cudaMemcpyHostToDevice);
cudaMemcpy(d_b,b,SIZE*sizeof(int),cudaMemcpyHostToDevice);
cudaMemcpy(d_c,c, SIZE*sizeof(int),cudaMemcpyHostToDevice);

VectorAdd<<<1,SIZE>>>(d_a,d_b,d_c,SIZE);
//VectorAdd(a,b,c,SIZE);

cudaMemcpy(c,d_c,SIZE*sizeof(int),cudaMemcpyDeviceToHost);
//for (int i=0;i<100;++i)
//printf("c[%d]=%d\n",i,c[i]);
free(a);
free(b);
free(c);
cudaFree(d_a);
cudaFree(d_b);
cudaFree(d_c);
return 0;
}
