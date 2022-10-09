#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
void rain()
{
    setcolor(WHITE);
    int x,y;
    for(int i=0; i<500; i++)
    {
        y=rand()%getmaxy();
        x=rand()%getmaxx();
        line(x,y,x-2,y+3);
    }
}
int main()
{
    int gd = DETECT, gm;
    int i, maxx, midy,x,y,j,c;
    initgraph(&gd, &gm,"");
    maxx = getmaxx();
    midy = getmaxy()/2;
    for (i=0; i < maxx-130 && !kbhit(); i=i+5)
    {
        cleardevice();
        rain();
        // draw a white road
        setcolor(BLUE);
        setlinestyle(0,0,2);
        line(0, midy + 37, maxx, midy + 37);
        setlinestyle(0,0,1);
        //Draw Car
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, RED);
        line(i, midy + 23, i, midy);
        line(i, midy, 40 + i, midy - 20);
        line(40 + i, midy - 20, 80 + i, midy - 20);
        line(80 + i, midy - 20, 100 + i, midy);
        line(100 + i, midy, 120 + i, midy);
        line(120 + i, midy, 120 + i, midy + 23);
        line(0 + i, midy + 23, 18 + i, midy + 23);
        arc(30 + i, midy + 23, 0, 180, 12);
        line(42 + i, midy + 23, 78 + i, midy + 23);
        arc(90 + i, midy + 23, 0, 180, 12);
        line(102 + i, midy + 23, 120 + i, midy + 23);
        line(28 + i, midy, 43 + i, midy - 15);
        line(43 + i, midy - 15, 57 + i, midy - 15);
        line(57 + i, midy - 15, 57 + i, midy);
        line(57 + i, midy, 28 + i, midy);
        line(62 + i, midy - 15, 77 + i, midy - 15);
        line(77 + i, midy - 15, 92 + i, midy);
        line(92 + i, midy, 62 + i, midy);
        line(62 + i, midy, 62 + i, midy - 15);
        floodfill(5 + i, midy + 22, YELLOW);
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, DARKGRAY);
        //Wheels
        circle(30 + i, midy + 25, 9);
        circle(90 + i, midy + 25, 9);
        floodfill(30 + i, midy + 25, BLUE);
        floodfill(90 + i, midy + 25, BLUE);
        //delay
        setcolor(YELLOW);
        outtextxy(215,350," S U P P E R   C A R !!!! ");
        outtextxy(215,380," W H A T   A   R A I N Y    D A Y !!!!  ");
        delay(150);
        if(i==150){
            getch();
        }
    }
    getch();
    closegraph();
    return 0;
}
