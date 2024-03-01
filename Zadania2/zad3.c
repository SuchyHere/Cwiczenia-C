#include <stdio.h>
typedef struct {
    int x;
    int y;
}Point;
typedef struct {
    int a;
    int b;
} Rectangle;
void change(Point * p){
    p -> x--;
    p -> y++;
}

void count(Rectangle * r){
    int peri = r->a + r->a + r->b + r->b;
    int area = r->a * r->b;
    printf("obwod: %i, pole: %i, ", peri, area);
}
int main() {
    Point p;
    Rectangle r;
    p.x = 3;
    p.y = 2;
    r.a = 5;
    r.b = 10;
    change(&p);
    count(&r);
    printf("x: %i, y: %i",p.x,p.y);
}
