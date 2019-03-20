
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Resource_Manager{
    struct Point_Hander * resource;
    void (*dc)(struct Point_Hander *);
};
struct Point_Hander{
    void (*c)(struct Point_Hander *);
    struct Resource_Manager * manager;
    struct Point * self;
};
struct Point{
    int x;
    int y;
    //because the link is acutally extablished manually, so it is possible to name it differently
    void (*s)(struct Point_Hander * , int, int);//need mechanism during compile time to link the address of sec function with this.
    void (*m)(struct Point_Hander *, int, int);
    int (*d)(struct Point_Hander *,struct Point_Hander * );
};
void constructor(struct Point_Hander *);
void deconstructor(struct Point_Hander*);
void set(struct Point_Hander *, int, int);
void move(struct Point_Hander *, int, int);
int sqrdistance(struct Point_Hander*, struct Point_Hander* );
//aftermain clean up doesn't work because compiler can't access heap
//void cleanup(struct Point_Hander *, struct Point_Hander *)__attribute__ ((destructor));
void cleanup(struct Point_Hander*, struct Point_Hander *);

struct Point_Hander p1;
struct Point_Hander p2;
int main(){
    //how i'd like to use it as a client
    p1.c=&constructor;
    p2.c=&constructor;
    (*p1.c)(&p1);
    (*p2.c)(&p2);
    p1.self->s=&set;
    p2.self->s=&set;
    p1.self->m=&move;
    p1.self->d=&sqrdistance;
    //the problem here is that there is no mechanism to link address of set to where the function actually located. Is there a way to get the location of a function during compile time?
    //p1.set is the address linked to set function, to use that function, need to dereference it.
    
    (*p1.self->s)(&p1,1,2);
    (*p2.self->s)(&p2,3,4);
    printf("point p1 has coordinate %d, %d\n",p1.self->x, p1.self->y);
    printf("point p2 has coordinate %d, %d\n",p2.self->x, p2.self->y);
    (*p1.self->m)(&p1,5,6);
    printf("point p1 has coordinate %d, %d\n",p1.self->x, p1.self->y);
    printf("the distance between p1 and p2 is %d\n",(*p1.self->d)(&p1,&p2));
    //at this point, if you don't engage deconstructor, the program can be compiled and ran, yet there would be memory leak go undetected. 
        
       cleanup(&p1,&p2);
        return 0;
}


//the actual implementation of fuction
void set(struct Point_Hander * p, int xc, int yc){
    p->self->x=xc;
    p->self->y=yc;
}

void move(struct Point_Hander * p, int xc, int yc){
    p->self->x+=xc;
    p->self->y+=yc;
}
int sqrdistance(struct Point_Hander * p1, struct Point_Hander* p2){
   return (p1->self->x-p2->self->x)*(p1->self->x-p2->self->x)+(p1->self->y-p2->self->y)*(p1->self->y-p2->self->y);
}
void constructor(struct Point_Hander *p){
    p->self=(struct Point *)malloc(sizeof(struct Point));
    p->manager=(struct Resource_Manager *)malloc(sizeof(struct Resource_Manager));
    p->manager->resource=p;
    p->manager->dc=&deconstructor;
    printf("A point has been constructed\n");
}
void deconstructor(struct Point_Hander * p){
    free(p->self);
    printf("A point has been distroyed\n");
}
//at this point, we are out of main, how to get the address on heap?
//this scheme does not work becase the compiler can't access heap
/*void cleanup(struct Point_Hander*p1,struct Point_Hander * p2){
    (*(p1->manager->dc))(p1);
    (*(p2->manager->dc))(p2);
}*/
void cleanup(struct Point_Hander * p1, struct Point_Hander *p2){
    (*(p1->manager->dc))(p1);
    (*(p2->manager->dc))(p2);
}
