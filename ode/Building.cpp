#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    line(0, 479, 637, 479);


    setfillstyle(LINE_FILL, WHITE);

    rectangle(0, 78, 36, 479);
    floodfill(20, 164, WHITE);
    line(36, 78, 46, 85);
    line(46, 85, 46, 479);


    rectangle(59, 196, 152, 479);
    floodfill(106, 334, WHITE);
    line(152, 196, 168, 203);
    line(168, 203, 168, 479);


    rectangle(186, 117, 296, 479);
    floodfill(240, 313, WHITE);
    line(296, 117, 315, 126);
    line(315, 126, 315, 479);


    rectangle(328, 244, 419, 479);
    floodfill(377, 364, WHITE);
    line(419, 244, 434, 251);
    line(434, 251, 434, 479);


    rectangle(450, 173, 550, 479);
    floodfill(494, 326, WHITE);
    line(550, 173, 562, 182);
    line(562, 182, 562, 479);

    rectangle(574, 60, 687, 479);
    floodfill(606, 297, WHITE);




    getch();
    closegraph();
    return 0;
}
