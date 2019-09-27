
#include<stdio.h>
#include<stdlib.h>
struct vtable{
   void (*a)();
   void (*s)();
};
struct Shape{
    int x;
    int y;
    struct vtable * vptr;
    //because the link is acutally extablished manually, so it is possible to name it differently
    void (*s)(struct Shape * , int, int);//need mechanism during compile time to link the address of sec function with this.
    void (*m)(struct Shape *, int, int);
    void (*d)(struct Shape *,struct Shape * );
    void (*a)(int xc, int yc);
};
struct Circle{
    struct Shape centre;
    int r;
    struct vtable * vptr;
    void (*s)(struct Circle*,int, int, int);
    void (*a)(struct Circle *);
};
struct Rectangle{
    struct Shape centre;
    int height;
    int width;
    struct vtable * vptr;
    void (*s)(struct Rectangle*, int, int,int, int);
    void (*a)(struct Rectangle *);
};

void shape_set(struct Shape *, int, int);
void rectangle_set(struct Rectangle *, int , int ,int, int);
void circle_set(struct Circle *, int, int, int);
void move(struct Shape *, int, int);
void sqrdistance(struct Shape *, struct Shape * );
void shape_area(int, int);
void circle_area();
void rectagle_area();

int main(){
    //manualling linking elements together
    //struct Shape p1;
    //struct Shape p2;
    struct Circle c;
    struct Rectangle r;
    
    struct vtable shape_vtable;
    struct vtable circle_vtable;
    struct vtable rectangle_vtable;

    //the linking part, if done manually as shown below can be slow, and error-prone. It is pretty clear from the simple example why a more fixed mechanism for OOP is needed.
    
    c.vptr=&circle_vtable;
    c.centre.vptr=&shape_vtable;
    r.vptr=&rectangle_vtable;
    r.centre.vptr=&shape_vtable;

    shape_vtable.a=&shape_area;
    shape_vtable.s=&shape_set;
    circle_vtable.a=&circle_area;
    circle_vtable.s=&circle_set;
    rectangle_vtable.a=&rectagle_area;
    rectangle_vtable.s=&rectangle_set;
    
    //without the vtable mechanism, the setting up address part of this code would be much less systematic, because with vtable mechanism, it is clear that there are structure and can be programmed generically.
    c.s=c.vptr->s;
    c.a=c.vptr->a;
    c.centre.s=c.centre.vptr->s;
    c.centre.m=&move;
    c.centre.d=&sqrdistance;
    r.s=r.vptr->s;
    r.a=r.vptr->a;
    r.centre.s=r.centre.vptr->s;
    r.centre.m=&move;
    r.centre.d=&sqrdistance;

    
    (*c.s)(&c,1,2,3);
    (*r.s)(&r,4,5,6,7);
    (*c.centre.m)(&(c.centre),8,9);
    (*r.centre.m)(&(c.centre),1,2);
    (*c.centre.d)(&(c.centre),&(r.centre));
    (*c.a)(&c);
    (*r.a)(&r);


/*
    p1.vptr=&shape_vtable;
    p2.vptr=&shape_vtable;
    c.vptr=&circle_vtable;
    r.vptr=&rectable_vtable;

    p1.s=&set;
    p2.s=&set;
    p1.m=&move;
    p1.d=&sqrdistance;
    //the problem here is that there is no mechanism to link address of set to where the function actually located. Is there a way to get the location of a function during compile time?
    //p1.set is the address linked to set function, to use that function, need to dereference it.
    (*p1.s)(&p1,1,2);
    (*p2.s)(&p2,3,4);
    printf("point p2 has coordinate %d, %d\n",p2.x, p2.y);
    (*p1.m)(&p1,5,6);*/
    return 0;
}

//the actual implementation of fuction
void shape_set(struct Shape * p, int xc, int yc){
    p->x=xc;
    p->y=yc;
    printf("centre has coordinate %d, %d\n",p->x, p->y);
}
void circle_set(struct Circle * c, int xc, int yc,int radius){
    c->centre.s(&(c->centre),xc, yc);
    c->r=radius;
    printf("circle has radius %d\n",radius);
}
void rectangle_set(struct Rectangle* r, int xc, int yc, int w, int h){
    r->centre.s(&(r->centre),xc, yc);
    r->width=w;
    r->height=h;
    printf("rectangle has width %d, and height %d\n", w, h);
}

void move(struct Shape * p, int xc, int yc){
    p->x+=xc;
    p->y+=yc;
    printf("centre has been moved to  %d, %d\n",p->x, p->y);
}
void sqrdistance(struct Shape * p1, struct Shape * p2){
   int result= (p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y);
    printf("the distance between p1 and p2 is %d\n",result);
}
void shape_area(int x, int y){
    printf("the area of shape is %d\n",x*y);
}
void circle_area(struct Circle *c){
    int result=(c->r)*(c->r)*3.14;
    printf("the area of circle is %d\n",result);
}
void rectagle_area(struct Rectangle *r){
    int result=(r->width)*(r->height);
    printf("the area of rectangle is %d\n", result);
}


