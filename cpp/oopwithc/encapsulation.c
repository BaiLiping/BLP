
#include<stdio.h>
#include<stdlib.h>

struct Point{
    int x;
    int y;
    //because the link is acutally extablished manually, so it is possible to name it differently
    void (*s)(struct Point * , int, int);//need mechanism during compile time to link the address of sec function with this.
    void (*m)(struct Point *, int, int);
    int (*d)(struct Point *,struct Point * );
};

void set(struct Point *, int, int);
void move(struct Point *, int, int);
int sqrdistance(struct Point *, struct Point * );

int main(){
    //how i'd like to use it as a client
    struct Point p1;
    struct Point p2;
    p1.s=&set;
    p2.s=&set;
    p1.m=&move;
    p1.d=&sqrdistance;
    //the problem here is that there is no mechanism to link address of set to where the function actually located. Is there a way to get the location of a function during compile time?
    //p1.set is the address linked to set function, to use that function, need to dereference it.
    (*p1.s)(&p1,1,2);
    (*p2.s)(&p2,3,4);
    printf("point p1 has coordinate %d, %d\n",p1.x, p1.y);
    printf("point p2 has coordinate %d, %d\n",p2.x, p2.y);
    (*p1.m)(&p1,5,6);
    printf("point p1 has coordinate %d, %d\n",p1.x, p1.y);
    printf("the distance between p1 and p2 is %d\n",(*p1.d)(&p1,&p2));
    return 0;
}

//the actual implementation of fuction
void set(struct Point * p, int xc, int yc){
    p->x=xc;
    p->y=yc;
}

void move(struct Point * p, int xc, int yc){
    p->x+=xc;
    p->y+=yc;
}
int sqrdistance(struct Point * p1, struct Point * p2){
   return (p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y);
}



