/* Puzzle Game in which numbers are spread randomly & player

This program is a game in which numbers are spread randomly & player is supposed to arrange them sr=eriouly. */

       #include<iostream.h>

       #include<dos.h>

       #include<conio.h>

       #include<graphics.h>

       #include<stdio.h>

     // GLOBAL VARIABLES

       int a[5][5];

       int t[16]={0,4,11,12,7,1,15,5,13,6,10,3,2,14,8,9};

       int test[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

       struct pos
     {
       int h,v;
     }p[4][4];

     int row=4,col=4;


	      // FUNCTION PROTOTYPES

     void game(int); //MOVEMENT

     void rec();   //DRAWING RECTANGLE

     void pri();   //PRINTING NUMBERS INITIALLY

     int getkey();   // TO TRACE KEY PRESSED

     inline void space() { cout<<"∞   "; }

     inline void print(int r,int c) { cout<<a[r][c]; }

     void init();   //TO STORE CO-ORDINATES

     int stop();     // STOPING CRITERION

     void gopr(int,int);   //TO PRINT NUMBER IN GAME

 void main()
{
     int gm=DETECT,gd=DETECT;
     initgraph(&gm,&gd,"");

  int d,cr=1;
  init();
  rec();
  pri();

   while(cr!=16)
  {
    d=getkey();
    game(d);
    cr=stop();
  }

  settextstyle(10,0,1);
  outtextxy(400,300,"You are winner!");
  getch();


}






   void rec()
  {
      setcolor(5);

     for(int i=0;i<200;i+=50)
    {
      for(int j=0;j<240;j+=60)
      rectangle(j+100,i+100,j+50,i+60);
    }



  }

   void pri()
  {
      int k=1;
   for(int x=0,i=6;x<4;x++,i+=3)
   {
     for(int y=0,j=10;y<4&&k<16;y++,j+=7,k++)
     {

       gotoxy(p[x][y].h,p[x][y].v);
       cout<<a[x][y];
     }
   }



  }

    int getkey()
  {
   union REGS i,o;
   while(!kbhit());
    i.h.ah=0;
   int86(22,&i,&o);
    return(o.h.ah);
  }



 void init()
  {
    int k=1;
    for(int x=0,i=6;x<4;x++,i+=3)
   {
     for(int y=0,j=10;y<4;y++,j+=7)
     {
       p[x][y].h=j;
       p[x][y].v=i;
       a[x][y]=t[k++];
     }
   }

  }


     void game(int s)
  {
	   int r=row-1;
	   int c=col-1;

	    if(s==77 &&c!=0)  //right
	  {
		col--;

	     a[r][c]=a[r][c-1];


	   gopr(r,c-1);

	   space();

	   gopr(r,c);

	   print(r,c-1);


	  }

	    if(s==80 && r!=0)   //down
	  {
	     row--;

	      a[r][c]=a[r-1][c];

	    gopr(r-1,c);

	     space();

	    gopr(r,c);

	    print(r-1,c);


	  }

	      if(s==75 && c!=3)     //left
	 {
	      a[r][c]=a[r][c+1];
	    col++;
	    gopr(r,c+1);

	    space();


	    gopr(r,c);

	    print(r,c+1);

	 }

	    if(s==72 &&r!=3)     //up
	 {

	    a[r][c]=a[r+1][c];

	    row++;

	    gopr(r+1,c);

	    space();

	    gopr(r,c);

	    print(r+1,c);


	 }


      }

	void gopr(int x, int y)
       {
	 gotoxy(p[x][y].h,p[x][y].v);
       }


      int stop()
    {
     int k=0,d=1;
       for(int x=0;x<4;x++)
      {
       for(int y=0;y<4;y++)
       {
	 if(a[x][y]==test[k])
	   d++;

	   k++;
	}
      }
       return d;
     }
