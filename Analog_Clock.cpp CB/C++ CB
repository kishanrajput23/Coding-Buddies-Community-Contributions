#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
int midx,midy,radious,dradious,sradious;
int secminx[60],secminy[60];
//hour can't be more than 12 but
// when hour is 1 and min is 20 then hour stick should be on 1.2
//that's why we store all avialable storage
int hourx[60],houry[60];
int designx[60],designy[60];
int minitx[60],minity[60];
char str[10];
//here we set the value
void settingup()
{
    midx=getmaxx()/2;
    midy=getmaxy()/2;
    radious=180;
    dradious=radious+10;
    sradious=radious-18;
}
//firt we store all Coordinate
void secmin()
{
    int j=45;
    for(int i=0; i<=360; i+=6)
    {
        //hour Coordinate  storing
        hourx[j]=midx-( (sradious-60) *cos(i*3.14 / 180));
        houry[j]=midy-( (sradious-60)*sin(i*3.14 / 180));
        //storing design Coordinate
        designx[j]=midx-round( dradious*cos(i*3.14 / 180));
        designy[j]=midy-round(dradious*sin(i*3.14 / 180));
        //storing minutes
        minitx[j]=midx-round((sradious-35)*cos(i*3.14 / 180));
        minity[j]=midy-round((sradious-35)*sin(i*3.14 / 180));
        //for storing second Coordinate
        secminx[j]=midx-round(sradious*cos(i*3.14 / 180));
        secminy[j++]=midy-round(sradious*sin(i*3.14 / 180));

        j= j==60 ? 0 : j;
    }

}
// this function will show all the hour
//and upper circle of the watch which used for designing
void customizing()
{

    for(int i=0; i<60; i++)
    {
        if(!(i%5))
        {

            sprintf(str,"%d",i/5 ==0 ? 12:i/5 );
            outtextxy(secminx[i],secminy[i],str);
        }
        circle(designx[i],designy[i],10);

    }

}
//this function is used to create sec stick
void secstick(int x,int y)
{
    setcolor(GREEN);
    line(midx,midy,secminx[x],secminy[y]);
}
//this function is used to create  hour stick
void hourstick(int x,int y)
{
    setcolor(RED);
    //here we add minutes with hour
    int k=(x*5)+(y/10);

    line(midx,midy,hourx[k],houry[k]);

}
//this function is used to create  min stick
void minstick(int x,int y)
{
    setcolor(3);
    line(midx,midy,minitx[x],minity[x]);

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    //setting up all value
    settingup();

    time_t t1;
    struct tm *data;
    //used to  sotore all Coordinate  value
    secmin();
    while(!kbhit())
    {
        //getting time from device
        t1=time(NULL);
        data=localtime(&t1);

        //clearing screen
        cleardevice();
        setcolor(YELLOW);
        //circle
        circle(midx,midy,radious);
        circle(midx,midy,radious+20);
        //printing all hour and design circle
        customizing();
        //printing sec stick
        secstick(data->tm_sec,data->tm_sec);
        //printing hour stick
        hourstick(data->tm_hour%12,data->tm_min);
        //printing min stick
        minstick(data->tm_min,data->tm_min);
        //timer for 1 second
        Sleep(1000);
    }

    getch();
    closegraph();

    return 0;
}
