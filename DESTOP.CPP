//IMPORTANT:- READ THE BELOW CAUTIONS CAREFULLY

/*
CAUTION (1)
///////////////////////////////////////////////////
/      While compiling if it shows the error of   /
/      "SEGMENT-TEXT EXCEED 64K"                  /
/      Then, follow the steps to run the program:-/
/      1)Go to 'Options'                          /
/      2)Click 'Compiler'                         /
/      3)Click 'Code Generation'                  /
/      4)In the dialog box of 'Code Generation'   /
/         -Select Model as "Huge"                 /
/      5)Click 'OK'                               /
/      8)Now, Run the program.                    /
/      9)If shows same problem then follow same   /
/	 above steps 2-3 times.                   /
///////////////////////////////////////////////////

CAUTION (2)
///////////////////////////////////////////////////
/      If shows "Graphics error" during run       /
/      Then,                                      /
/      1)Go to line  133                          /
/      2)Change this                              /
/      "initgraph(&gdriver,&gmode,"D:\\TC\\BGI");"/
/                          TO                     /
/      "initgraph(&gdriver,&gmode,"C:\\TC\\BGI");"/
/      3)Then save the program.                   /
/      4)Now, Run the program.                    /
/      5)If shows same problem then               /
/	 -Go to 'File'                            /
/	 -Click 'Change Directory'                /
/	 -Copy 'Directory Name'                   /
/	 -And replace                             /
/	  "C:\\TC\\BGI"                           /
/	    To                                    /
/	  "Directory Name"instead of BIN write BGI/
/	  NOTE:- Syntax should be same as above.  /
/      6)Now Run the program.                     /
///////////////////////////////////////////////////
*/
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<fstream.h>

#define ESC 27
#define UPARR 72
#define LEFTARR 75
#define DOWNARR 80
#define RIGHTARR 77
#define SAVE 60
#define LOAD 61


union REGS i,o;
enum Bool{false,true};

int icon;
int backto;
char pass[50];
int remain=3;

void windows();
void backicon();
void icons1();
void icons2();
void icons3();
void icons4();
void icons5();
void google();
void snake();
void hangman();
void tic();
void taj();
void solar();

void InitMouse();
void ShowMouse();
void HideMouse();
int GetX();
int GetY();
int GetB();
int ButtonStatus;

void OnLButtonDown(int x,int y);
void OnMouseMove(int ,int ,int );
void OnLButtonUp(int ,int );

void OnLButtonDown1(int x,int y);
void OnMouseMove1(int ,int ,int );
void OnLButtonUp1(int ,int );

void OnLButtonDown2(int x,int y);
void OnMouseMove2(int ,int ,int );
void OnLButtonUp2(int ,int );

void OnLButtonDown3(int x,int y);
void OnMouseMove3(int ,int ,int );
void OnLButtonUp3(int ,int );

void OnLButtonDown4(int x,int y);
void OnMouseMove4(int ,int ,int );
void OnLButtonUp4(int ,int );

void OnLButtonDown5(int x,int y);
void OnMouseMove5(int ,int ,int );
void OnLButtonUp5(int ,int );

void OnLButtonDown6(int x,int y);
void OnMouseMove6(int ,int ,int );
void OnLButtonUp6(int ,int );

void OnLButtonDown7(int x,int y);
void OnMouseMove7(int ,int ,int );
void OnLButtonUp7(int ,int );

void ini();

int ButtonMoveStatus;
int PrevX,PrevY;

void InitMouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
}

void ShowMouse()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

void HideMouse()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}

int GetB()
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	return o.x.bx;
}

int GetX()
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	return o.x.cx;
}

int GetY()
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	return o.x.dx;
}

void ini()
{
int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"D:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
{
     cout<<"\n Graphics Error";
     getch();
     exit(0);
}
}

//////////////////////////BACKTO//////////////////////
void OnLButtonUp7(int ,int ){ButtonStatus=0;}
void OnMouseMove7(int ,int ,int ){}
Bool IsBetween7(int x,int y)                  //IMPORTANT
{
   if(x>=625 && x<=639 && y>=0 && y<=12)
   {
      icon=6;
      return true;
   }
   else if(x>=40 && x<=90 && y>=10 && y<=40)
   {
      icon=7;
      return true;
   }
   else
   return false;
}


void OnLButtonDown7(int x,int y)
{
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween7(x,y)==true && icon==6)
    windows();
    else if(IsBetween7(x,y)==true && icon==7 && backto==1)
    icons1();
    else if(IsBetween7(x,y)==true && icon==7 && backto==2)
    icons2();
    else if(IsBetween7(x,y)==true && icon==7 && backto==3)
    icons3();
    else
    icon=0;
}

void backicon()
{
   clrscr();
   ini();
   cleardevice();
   rectangle(0,0,getmaxx(),getmaxy());

   setcolor(1);
   setfillstyle(1,1);
   rectangle(50,20,90,30);
   floodfill(51,21,1);
   setcolor(2);
   line(50,10,50,40);
   line(50,10,40,25);
   line(50,40,40,25);
   setcolor(14);
   outtextxy(53,40,"BACK");


   setcolor(4);                //Close Button (WORKING)
   setfillstyle(1,4);
   rectangle(625,0,639,12);
   floodfill(626,1,4);
   setcolor(0);
   line(625,0,639,12);
   line(639,0,625,12);
   setcolor(4);
   outtextxy(getmaxx()/2-25,getmaxy()/2,"EMPTY");

   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();

   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove7(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown7(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp7(GetX(),GetY());
		}
   }
   //getch();
   //closegraph();
}


///////////////////////////SOLAR SYSTEM////////////////
void square(int x,int y,int size)
{//-------------------------------------------------------------------
rectangle((10+size)+x,(0+size)+y,(getmaxx()-640-size)+x,(getmaxy()-470-size)+y);
rectangle((11+size)+x,(1+size)+y,(getmaxx()-641-size)+x,(getmaxy()-471-size)+y);
}//---------------------------------------------------------------------


void solar()
{

    ini();
    cleardevice();
 /*  if(x>680)
 { x=300;}
  if(y>680)
 { y=350;} */


//////////////
  int x=300,y=220;
  int time=50;
  moveto(x,y);
//for(int r=50;r<410;r=r+5)
  float r=170;  int show_path=1;int stop=0;
  {
  for(float i=1;;i=i+0.03)

    {

  setcolor(13);
  setcolor(13);
  settextstyle(2,0,4);
  outtextxy(10,0,"  (======= SOLAR SYSTEM ========)           PRESS P TO SHOW PATH.   PRESS C TO CLEAR PATH.");setcolor(14);
  outtextxy(10,13,"PRESS 1 TO 7 FOR CHANGING SPEED.  PRESS S FOR STOP.   PRESS X FOR EXIT.      	PROGRAMED BY SUMIT SAGAR (TM).");
  setcolor(2);  rectangle(7,25,getmaxx()-7,getmaxy()-7);
	setcolor (15);        // This becomes drawing color
	circle(300,220, 35);    // Draw the circle
	setfillstyle(9, 15); // Set pattern to fill interior
	floodfill(300,220, 15);  // Fill the circle
	setcolor (11 );

       setaspectratio(2,4.01);
       setcolor(7);

  if(kbhit())
  {char a=getch();if(a=='1')time=10;if(a=='2')time=40;if(a=='3')time=50; if(a=='4')time=70;
  if(a=='5')time=100;if(a=='6')time=150;  if(a=='7')time=200;
  if(a=='x'||a=='X'){windows();}if(a=='s'||a=='S')stop=1;
  if(a=='C'||a=='c')show_path=0; if(a=='p'||a=='P')show_path=1;
  }


  int a=x+(r+100)*sin(i);
  int b=y+(r+100)*cos(i)/1.5; //x,y axis for earth

  int a1=x+(220)*sin(i*3);
  int b1=y+(220)*cos(i); //x,y axis for venus


  int a2=x+(190)*sin(i*3);
  int b2=y+(190)*(cos(i*3)/2);
			 //int MaxX=getmaxx();  int MaxY=getmaxy();for (int i=0 ;i<100;++i){ setcolor(15);circle(random(MaxX), random(MaxY),1);putpixel(random(MaxX), random(MaxY),15 );}
  int moon_x=a+(40)*sin(i*18);
  int moon_y=b+(40)*(cos(i*18));//x,y axis for moon  line(x,y,a,b);

  int a3=x+(115)*(sin(i*5));
  int b3=y+(115)*(cos(i*5)/2);//x,y axis for mercury
	 if(show_path==1){
	 circle(300,220, 280);//earth path
	 circle(300,220, 190);//venus path
	 circle(300,220, 110);
	 //circle(a,b, 40);
	 }//mercury path


	 setaspectratio(1,1);
	setcolor (6);        // This becomes drawing color
	circle(moon_x,moon_y, 5);    // Draw the circle
	setfillstyle(6,6); // Set pattern to fill interior
	floodfill(moon_x,moon_y,6);  // Fill the circle


	setcolor (9);        // This becomes drawing color
	circle(a, b, 13);    // Draw the circle
	setfillstyle(6, 9); // Set pattern to fill interior
	floodfill(a,b, 9);  // Fill the circle
				    //setcolor (random(15));

	 setcolor (2);        // This becomes drawing color
	circle(a2, b2, 10);    // Draw the circle
	setfillstyle(6, 2); // Set pattern to fill interior
	floodfill(a2,b2, 2);  // Fill the circle					      // if(i>5){cleardevice();}

	setcolor (6);        // This becomes drawing color
	circle(a3, b3, 10);    // Draw the circle
	setfillstyle(6, 6); // Set pattern to fill interior
	floodfill(a3,b3, 6);  // Fill the circle					  // line(300,220,a,b);
	putpixel(a3,b3,15);
  int x=a1,y=b1;
  setcolor (12);
  //solar panal
  square(x+10,y+25,8);square(x+10,y+25,5); square(x+85,y+25,8);square(x+85,y+25,5);
  square(x+25,y+25,4); square(x+70,y+25,4);
  //middle box
  moveto(x+40,y+20); lineto(x+40,y+40); lineto(x+65,y+40); lineto(x+65,y+20); lineto(x+40,y+20);
  moveto(x+40+1,y+20); lineto(x+40+1,y+40-1); lineto(x+65-1,y+40-1); lineto(x+65-1,y+20+1); lineto(x+40+1,y+20+1);
  circle(x+45,y+32,1); circle(x+58,y+32,1);  circle(x+52,y+27,1);  circle(x+52,y+27,3);
  // anntina
  line(x+40,y+10,x+50,y+20);circle(x+40,y+10,2);    line(x+65,y+10,x+55,y+20);circle(x+65,y+10,2);

  delay(time);
  // r=r+0.05;
  if(stop==1){getch();stop=0;}
  cleardevice();
     }
  }

}



///////////////////////////TAJ MAHAL////////////////
void taj()
{
ini();
cleardevice();
int h=40;
line(0,440,639,440);

//line(20,30+h,619,30+h);

//line(25,400,38,120);
//line(85,400,78,120);
//line(85,400,78,120);


//=================================Ist tower========================//
//=================================IIsttower============================//
//#################TOWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
int l=-20;
line(28+l,400+h,33+l,333+h);
line(86+l,400+h,80+l,333+h);
//||||||||||||||||||||||||||||||Iststage||||||||||||||||||||||||||||||||||||||||||||//
line(23+l,328+h,32+l,334+h);               // slant
line(88+l,328+h,80+l,334+h);                       // slant
line(83+l,323+h,75+l,334+h);                       // slant
line(75+l,323+h,70+l,332+h);
line(66+l,323+h,65+l,332+h);                       // slant
line(57+l,323+h,57+l,332+h);                       // slant
line(30+l,323+h,39+l,334+h);                       // slant
line(38+l,323+h,45+l,332+h);
line(48+l,323+h,51+l,332+h);      // slant

ellipse(57+l,320+h,350,190,34,5);
ellipse(57+l,327+h,350,190,34,5);
ellipse(57+l,337+h,0,180,25,5);
line(22+l,320+h,22+l,328+h);
line(91+l,320+h,91+l,327+h);
setfillstyle(6,15);
floodfill(60+l,320+h,15);

setfillstyle(10,15);

floodfill(60+l,320+h+15,15);


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//+++++++++++++++++++++++++++++++++++2nd+++++++++++++++++++++++++++

line(35+l,315+h,38+l,242+h);
line(80+l,315+h,75+l,242+h);

//||||||||||||||||||||||||||||||2ststage||||||||||||||||||||||||||||||||||||||||||||//
int t=-93;
line(23+4+l,328+t+3+h,32+5+l,334+t+h);               // slant
line(88+l,328+t+2+h,76+l,334+t+h);                       // slant
//line(+l83,323+t+4,75,334+t);                       // slant
line(78+l,323+t+3+h,71+l,332+t+h);
line(66+l,323+t+2+h,65+l,332+t+h);                       // slant
line(57+l,323+t+2+h,57+l,332+t-2+h);                       // slant
//line(30,323+t+2,39,334+t);                       // slant
line(35+l,323+t+3+h,45-3+l,332+t+h);
line(48+l,323+t+2+h,51+l,332+t-2+h);      // slant

ellipse(57+l,320+t+3+h,360,190,30,5);
ellipse(57+l,327+t+3+h,360,190,30,5);
ellipse(57+l,337+t-1+h,0,180,18,5);

line(26+l,320+t+3+h,26+l,328+t+2+h);
line(88+l,320+t+3+h,88+l,327+t+3+h);
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
setfillstyle(6,15);
floodfill(60+l,320+h+t,15);                            ////////////////
setfillstyle(10,15);
floodfill(60+l,320+h-35,15);

//||||||||||||||||||||||||||||||3rdstage||||||||||||||||||||||||||||||||||||||||||||//

line(38+l,225+h,41+l,152+h);
line(75+l,225+h,72+l,152+h);



 t=-182;
line(32+l,328+t+4+h,32+7+l,334+t+h);               // slant
line(80+l,328+t+4+h,73+l,334+t+h);                       // slant
//line(+l83,323+t+4,75,334+t);                       // slant
line(76+l,323+t+5+h,71+l,332+t+h);
line(66+l,323+t+4+h,65+l,332+t+h);                       // slant
line(57+l,323+t+4+h,57+l,332+t-2+h);                       // slant
//line(30,323+t+2,39,334+t);                       // slant
line(39+l,323+t+6+h,45+l,332+t+1+h);
line(48+l,323+t+4+h,51+l,332+t+h);      // slant

ellipse(57+l,320+t+6+h,360,190,24,5);
ellipse(57+l,327+t+4+h,360,190,24,5);
ellipse(57+l,337+t-1+h,0,170,16,5);

line(32+l,320+t+6+h,32+l,328+t+3+h);
line(81+l,320+t+6+h,81+l,327+t+3+h);

setfillstyle(6,15);
floodfill(60+l,322+h+t,15);
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
setfillstyle(10,15);
floodfill(60+l,322+h+t+30,15);
//GGF################TOWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

ellipse(51+l,132+h,340,216,4,15);
ellipse(62+l,131+h,327,216,4,15);
ellipse(72+l,132+h,327,216,2,15);
ellipse(42+l,132+h,327,216,2,15);
ellipse(57+l,107+h,0,170,16,5);
line(40+l,107+h,40+l,140+h);
line(75+l,107+h,75+l,140+h);

line(34+l,107+h,40+l,107+h);
line(75+l,107+h,81+l,107+h);

line(34+l,107+h,28+l,102+h);                      //slant
line(81+l,107+h,87+l,102+h);

line(28+l,102+h,34+l,98+h);
line(87+l,102+h,81+l,98+h);

line(34+l,98+h,58+l,95+h);
line(58+l,95+h,81+l,98+h);


ellipse(65+l,92+h,104,190,30,30);

ellipse(50+l,92+h,350,76,30,30);

line(58+l,61+h,58+l,63+h);
circle(58+l,58+h,3);
line(58+l,55+h,58+l,53+h);
circle(58+l,50+h,2);
line(58+l,48+h,58+l,47+h);
circle(58+l,45+h,1);
line(58+l,44+h,58+l,41+h);
setfillstyle(6,15);
floodfill(60+l-2,322+h+t-60,15);

setfillstyle(10,15);
floodfill(60+l-2,322+h+t-30,15);


//=================================IIsttower============================//
//#################TOWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
 l=547;


line(28+l,400+h,33+l,333+h);
line(86+l,400+h,80+l,333+h);
//||||||||||||||||||||||||||||||Iststage||||||||||||||||||||||||||||||||||||||||||||//
line(23+l,328+h,32+l,334+h);               // slant
line(88+l,328+h,80+l,334+h);                       // slant
line(83+l,323+h,75+l,334+h);                       // slant
line(75+l,323+h,70+l,332+h);
line(66+l,323+h,65+l,332+h);                       // slant
line(57+l,323+h,57+l,332+h);                       // slant
line(30+l,323+h,39+l,334+h);                       // slant
line(38+l,323+h,45+l,332+h);
line(48+l,323+h,51+l,332+h);      // slant

ellipse(57+l,320+h,350,190,34,5);
ellipse(57+l,327+h,350,190,34,5);
ellipse(57+l,337+h,0,180,25,5);
line(22+l,320+h,22+l,328+h);
line(91+l,320+h,91+l,327+h);
setfillstyle(6,15);
floodfill(60+l,320+h,15);

setfillstyle(10,15);

floodfill(60+l,320+h+15,15);


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//+++++++++++++++++++++++++++++++++++2nd+++++++++++++++++++++++++++

line(35+l,315+h,38+l,242+h);
line(80+l,315+h,75+l,242+h);

//||||||||||||||||||||||||||||||2ststage||||||||||||||||||||||||||||||||||||||||||||//
t=-93;
line(23+4+l,328+t+3+h,32+5+l,334+t+h);               // slant
line(88+l,328+t+2+h,76+l,334+t+h);                       // slant
//line(+l83,323+t+4,75,334+t);                       // slant
line(78+l,323+t+3+h,71+l,332+t+h);
line(66+l,323+t+2+h,65+l,332+t+h);                       // slant
line(57+l,323+t+2+h,57+l,332+t-2+h);                       // slant
//line(30,323+t+2,39,334+t);                       // slant
line(35+l,323+t+3+h,45-3+l,332+t+h);
line(48+l,323+t+2+h,51+l,332+t-2+h);      // slant

ellipse(57+l,320+t+3+h,360,190,30,5);
ellipse(57+l,327+t+3+h,360,190,30,5);
ellipse(57+l,337+t-1+h,0,180,18,5);

line(26+l,320+t+3+h,26+l,328+t+2+h);
line(88+l,320+t+3+h,88+l,327+t+3+h);
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
setfillstyle(6,15);
floodfill(60+l,320+h+t,15);                            ////////////////
setfillstyle(10,15);
floodfill(60+l,320+h-35,15);

//||||||||||||||||||||||||||||||3rdstage||||||||||||||||||||||||||||||||||||||||||||//

line(38+l,225+h,41+l,152+h);
line(75+l,225+h,72+l,152+h);



 t=-182;
line(32+l,328+t+4+h,32+7+l,334+t+h);               // slant
line(80+l,328+t+4+h,73+l,334+t+h);                       // slant
//line(+l83,323+t+4,75,334+t);                       // slant
line(76+l,323+t+5+h,71+l,332+t+h);
line(66+l,323+t+4+h,65+l,332+t+h);                       // slant
line(57+l,323+t+4+h,57+l,332+t-2+h);                       // slant
//line(30,323+t+2,39,334+t);                       // slant
line(39+l,323+t+6+h,45+l,332+t+1+h);
line(48+l,323+t+4+h,51+l,332+t+h);      // slant

ellipse(57+l,320+t+6+h,360,190,24,5);
ellipse(57+l,327+t+4+h,360,190,24,5);
ellipse(57+l,337+t-1+h,0,170,16,5);

line(32+l,320+t+6+h,32+l,328+t+3+h);
line(81+l,320+t+6+h,81+l,327+t+3+h);

setfillstyle(6,15);
floodfill(60+l,322+h+t,15);
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
setfillstyle(10,15);
floodfill(60+l,322+h+t+30,15);
//GGF################TOWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

ellipse(51+l,132+h,340,216,4,15);
ellipse(62+l,131+h,327,216,4,15);
ellipse(72+l,132+h,327,216,2,15);
ellipse(42+l,132+h,327,216,2,15);
ellipse(57+l,107+h,0,170,16,5);
line(40+l,107+h,40+l,140+h);
line(75+l,107+h,75+l,140+h);

line(34+l,107+h,40+l,107+h);
line(75+l,107+h,81+l,107+h);

line(34+l,107+h,28+l,102+h);                      //slant
line(81+l,107+h,87+l,102+h);

line(28+l,102+h,34+l,98+h);
line(87+l,102+h,81+l,98+h);

line(34+l,98+h,58+l,95+h);
line(58+l,95+h,81+l,98+h);


ellipse(65+l,92+h,104,190,30,30);

ellipse(50+l,92+h,350,76,30,30);

line(58+l,61+h,58+l,63+h);
circle(58+l,58+h,3);
line(58+l,55+h,58+l,53+h);
circle(58+l,50+h,2);
line(58+l,48+h,58+l,47+h);
circle(58+l,45+h,1);
line(58+l,44+h,58+l,41+h);
setfillstyle(6,15);
floodfill(60+l-2,322+h+t-60,15);

setfillstyle(10,15);
floodfill(60+l-2,322+h+t-30,15);
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

//GGF################TOWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

ellipse(51+l,132+h,340,216,4,15);
ellipse(62+l,131+h,327,216,4,15);
ellipse(72+l,132+h,327,216,2,15);
ellipse(42+l,132+h,327,216,2,15);
ellipse(57+l,107+h,0,170,16,5);
line(40+l,107+h,40+l,140+h);
line(75+l,107+h,75+l,140+h);

line(34+l,107+h,40+l,107+h);
line(75+l,107+h,81+l,107+h);

line(34+l,107+h,28+l,102+h);                      //slant
line(81+l,107+h,87+l,102+h);

line(28+l,102+h,34+l,98+h);
line(87+l,102+h,81+l,98+h);

line(34+l,98+h,58+l,95+h);
line(58+l,95+h,81+l,98+h);


ellipse(65+l,92+h,104,190,30,30);

ellipse(50+l,92+h,350,76,30,30);

line(58+l,61+h,58+l,63+h);
circle(58+l,58+h,3);
line(58+l,55+h,58+l,53+h);
circle(58+l,50+h,2);
line(58+l,48+h,58+l,47+h);
circle(58+l,45+h,1);
line(58+l,44+h,58+l,41+h);


//=================================Ist tower========================//

//+++++++++++++++++++++++++++++++++TAJ mahal++++++++++++++++++++++++//

////setcolor(15);

rectangle(275,290,365,440);         //  inner
rectangle(268,283,372,440);           //     //inner
setfillstyle(1,15);
floodfill(274,294,15);
line(280,440,280,350);
//line(283,440,283,350);
ellipse(315,349,130,180,35,40);
ellipse(275,280,290,326,53,40);

line(360,440,360,350);
ellipse(325,349,360,50,35,40);
ellipse(361,280,216,255,53,40);
setfillstyle(9,7);
floodfill(277,386,15);
putpixel(277,386,14);

line(280,360,359,360);
line(280,364,359,364);
setfillstyle(1,15);
floodfill(281,362,15);

rectangle(295+4,370,345-4,440);
rectangle(292+4,367,348-4,440);
setfillstyle(1,15);
floodfill(294+4,369,15);
rectangle(296,378,344,380);
floodfill(301,379,15);


line(302,405,302,440);
line(338,405,338,440);
ellipse(327,405,108,180,25,20);

ellipse(313,405,360,74,25,20);

setfillstyle(7,15);
//putpixel(312,416,11);
//floodfill(312,406,15);
line(329,390,329,440);
line(310,391,310,440);
line(311,402,329,402);
line(311,422,329,422);
line(302,412,310,412);
line(329,412,338,412);

line(302,428,310,428);
line(329,428,338,428);
//setfillstyle(7,15);


 int p=-60;
line(302,405+p,302,440+p-20);
line(338,405+p,338,440+p-20);
ellipse(327,405+p,108,180,25,20);

ellipse(313,405+p,360,74,25,20);
setfillstyle(7,15);
floodfill(311,406,15);
line(329,390+p,329,440+p-20);
line(310,391+p,310,440+p-20);
line(311,402+p,329,402+p);
line(311,422+p-7,329,422+p-7);
line(302,412+p,310,412+p);
line(329,412+p,338,412+p);



//??//////////////////////////////////2nd portion/////////////////////


rectangle(245,260,400,440);         //  inner
rectangle(230,245,415,440);           //     //inner

rectangle(230,425,275,440);
setfillstyle(1,15);
floodfill(231,426,15);
floodfill(249,426,15);
////setcolor(8);
rectangle(230+135,425,275+140,440);
//setfillstyle(1,15);

floodfill(231+160,426,15);
floodfill(249+159,426,15);



////setcolor(15);
line(415,290,415,440);
line(420,245,420,440);

line(415,240,415,205);
line(420,240,420,205);


line(225,245,225,440);          //vertical
line(230,250,230,440);

line(225,240,225,205);          //vertical
line(230,240,230,205);

line(222,240,425,240);
line(222,245,425,245);                    //horz

ellipse(222,242.5,90,270,2.5,2.5);
ellipse(425,242.5,270,90,2.5,2.5);

rectangle(231,230,414,239);



ellipse(227,206,0,180,9,1);
ellipse(227,204,0,180,9,1);
putpixel(220,204,15);
putpixel(220,205,15);
putpixel(220,206,15);
putpixel(235,204,15);
putpixel(235,205,15);
putpixel(235,206,15);
ellipse(227,203,0,180,6,7);
line(227,195,227,192);
int r=190;

ellipse(227+r,206,0,180,9,1);
ellipse(227+r,204,0,180,9,1);
putpixel(220+r,204,15);
putpixel(220+r,205,15);
putpixel(220+r,206,15);
putpixel(235+r,204,15);
putpixel(235+r,205,15);
putpixel(235+r,206,15);

ellipse(227+r,203,0,180,6,7);
line(227+r,195,227+r,192);

/*

//floodfill(305,424,15);
//floodfill(305,429,15);
//floodfill(325,424,15);
//floodfill(325,421,15);
//floodfill(332,420,15);
//floodfill(332,429,15);
*/

ellipse(315,170,140,210,105,100);
ellipse(330,170,330,40,105,100);

ellipse(292,167,105,140,75,95);
ellipse(353,167,40,75,75,95);

ellipse(323,78,350,190,60,8);
ellipse(323,77,350,190,60,8);


//ellipse(259,24,295,358,58,51);
ellipse(240,24,321,358,78,71);
ellipse(192,40,342,7,128,100);

ellipse(448,30,180,203,128,100);
ellipse(443,5,194,220,128,100);
ellipse(438,-9,203,234,128,100);
ellipse(198,-6,310,340,128,100);

ellipse(319,30,0,360,7,2);

floodfill(320,29,15);
circle(319,24,3);
line(319,20,319,18);
circle(319,14,4);
line(319,9,319,0);
//ellipse(319,4,0,360,2,3);
circle(319,2,1);
line(316,6,322,6);
line(316,6,314,4);
line(322,6,324,4);
//???????????????????????????????????

//////////////////////////////////////////////////////////
//ellipse();
ellipse(321,258,48,130,140,50);
ellipse(321,255,48,130,140,50);

ellipse(321,241,48,130,140,50);
ellipse(321,238,48,130,140,50);
//setfillstyle(6,11);
//  line(265,79,277,70);
//////setcolor(4);
  //line(385,81,380,76);

//while(!kbhit())
//{
 delay(300);
setfillstyle(10,15);

floodfill(322,160,15);
setfillstyle(6,15);

floodfill(322,193,15);

//}
//line(319,26,319,480+h);//center



///////////////////////////////////////////new////////////////////////////
rectangle(150,283,225,294);

//line(146,294,225,294);
line(150,298,225,298);

line(150,240,150,440);            //pole
line(146,240,146,440);

line(150,299,150,440);            //pole
line(146,299,146,440);


r=-80;
int n=34;

ellipse(227+r,206+n,0,180,9,1);
ellipse(227+r,204+n,0,180,9,1);
putpixel(220+r,204+n,15);
putpixel(220+r,205+n,15);
putpixel(220+r,206+n,15);
putpixel(235+r,204+n,15);
putpixel(235+r,205+n,15);
putpixel(235+r,206+n,15);

ellipse(227+r,203+n,0,180,6,7);
line(227+r,195+n,227+r,192+n);

l=128;
h=150;

ellipse(51+l,132+h-7,340,216,4,15);
ellipse(62+l,131+h-7,327,216,4,15);
ellipse(72+l,132+h-7,327,216,2,15);
ellipse(42+l,132+h-7,327,216,2,15);
ellipse(57+l,107+h,0,170,16,5);
line(40+l,107+h,40+l,140+h-7);
line(75+l,107+h,75+l,140+h-7);

line(34+l,107+h,40+l,107+h);
line(75+l,107+h,81+l,107+h);

line(34+l,107+h,28+l,102+h);                      //slant
line(81+l,107+h,87+l,102+h);

line(28+l,102+h,34+l,98+h);
line(87+l,102+h,81+l,98+h);

line(34+l,98+h,58+l,95+h);
line(58+l,95+h,81+l,98+h);


ellipse(65+l,92+h,104,190,30,30);

ellipse(50+l,92+h,350,76,30,30);

line(58+l,61+h,58+l,63+h);
circle(58+l,58+h,3);
line(58+l,55+h,58+l,53+h);
circle(58+l,50+h,2);
line(58+l,48+h,58+l,47+h);
circle(58+l,45+h,1);
line(58+l,44+h,58+l,41+h);


line(100-5,240+15,100-5,440);            //pole
line(96-5,240+15,96-5,440);

r=-134;
 n=49;
ellipse(227+r,206+n,0,180,9,1);
ellipse(227+r,204+n,0,180,9,1);
putpixel(220+r,204+n,15);
putpixel(220+r,205+n,15);
putpixel(220+r,206+n,15);
putpixel(235+r,204+n,15);
putpixel(235+r,205+n,15);
putpixel(235+r,206+n,15);

ellipse(227+r,203+n,0,180,6,7);
line(227+r,195+n,227+r,192+n);


line(146,294,97,302);
line(146,298,97,306);

line(146,283,97,291);


///////////////////////////////////////inner/////////////////

//rectangle(275+k,290,365+k,440);         //  inner
//rectangle(268+k,283,372+k,440);           //     //inner

//line(225,367,151,367);
rectangle(155,302,220,364);
rectangle(155,302+70,220,364+75);

int q=-133;
int d=-2;
line(302+q-5,405+d,302+q-5,440+d);
line(338+q+5,405+d,338+q+5,440+d);
ellipse(327+q+5,405+d,108,180,35,30);

ellipse(313+q-5,406+d,360,74,35,30);


d=-77;
line(302+q-5,405+d,302+q-5,440+d);
line(338+q+5,405+d,338+q+5,440+d);
ellipse(327+q,405+d,105,180,30,25);

ellipse(313+q,405+d,360,80,30,25);
putpixel(163,300,11);
setfillstyle(6,15);
floodfill(163,330,15);
floodfill(160,380,15);

line(141,305,141,360);
line(101,310,101,365);
line(141,305,101,310);
line(141,360,101,365);


int x=70;
line(141,305+x,141,440);
line(101,310+x,101,440);
line(141,305+x,101,310+x);



q=-200;
line(302+q+4,405+d,302+q+4,440+d);
line(338+q-1,405+d,338+q-1,440+d-2);
ellipse(327+q,405+d,105,180,20,15);
ellipse(313+q+4,405+d,360,80,20,15);

d=1;
line(302+q+4,405+d,302+q+4,440+d-2);
line(338+q-1,405+d,338+q-1,440+d-2);
ellipse(327+q,405+d,105,180,20,15);
ellipse(313+q+4,405+d,360,80,20,15);

rectangle(178,415,197,439);
setfillstyle(7,15);
floodfill(179,416,15);
 rectangle(178,415-75,197,440-76);
setfillstyle(7,15);
floodfill(179,415-75+1,15);

line(130-3,417,130-3,440);
line(113+3,420,113+3,440);

line(113+3,420,130-3,417);
putpixel(114,423,4);
line(113,440,130,440);
floodfill(114+3,423,15);



int a=-76;
line(130-3,417+a,130-3,440+a-3);
line(113+3,420+a,113+3,440+a);

line(113+3,420+a,130-3,417+a);
putpixel(114,423,4);
floodfill(114+3,423+a,15);



line(10,400+h,615,400+h);



//////////////////////////////////////////////right\\\\\\\\\\\


int e=270;
rectangle(150+e,283,226+e,294);
line(146+e+4,294,225+e,294);
line(146+e+4,298,225+e,298);


line(150+e+80,240,150+e+80,440);            //pole
line(146+e+80,240,146+e+80,440);

line(150+e+80,299,150+e+80,440);            //pole
line(146+e+80,299,146+e+80,440);





l=400;
h=+149;
ellipse(51+l,132+h-7,340,216,4,15);
ellipse(62+l,131+h-7,327,216,4,15);
ellipse(72+l,132+h-7,327,216,2,15);
ellipse(42+l,132+h-7,327,216,2,15);
ellipse(57+l,107+h,0,170,16,5);
line(40+l,107+h,40+l,140+h-7);
line(75+l,107+h,75+l,140+h-7);

line(34+l,107+h,40+l,107+h);
line(75+l,107+h,81+l,107+h);

line(34+l,107+h,28+l,102+h);                      //slant
line(81+l,107+h,87+l,102+h);

line(28+l,102+h,34+l,98+h);
line(87+l,102+h,81+l,98+h);

line(34+l,98+h,58+l,95+h);
line(58+l,95+h,81+l,98+h);


ellipse(65+l,92+h,104,190,30,30);

ellipse(50+l,92+h,350,76,30,30);

line(58+l,61+h,58+l,63+h);
circle(58+l,58+h,3);
line(58+l,55+h,58+l,53+h);
circle(58+l,50+h,2);
line(58+l,48+h,58+l,47+h);
circle(58+l,45+h,1);
line(58+l,44+h,58+l,41+h);

r=270;
n=n-15;

ellipse(227+r,206+n,0,180,9,1);
ellipse(227+r,204+n,0,180,9,1);
putpixel(220+r,204+n,15);
putpixel(220+r,205+n,15);
putpixel(220+r,206+n,15);
putpixel(235+r,204+n,15);
putpixel(235+r,205+n,15);
putpixel(235+r,206+n,15);

ellipse(227+r,203+n,0,180,6,7);
line(227+r,195+n,227+r,192+n);



line(146+e+135,302,97+e+135,294);
line(146+e+135,306,97+e+135,298);

line(146+e+135,291,97+e+135,283);



line(100-5+e+190,240+15,100-5+e+190,440);            //pole
line(96-5+e+190,240+15,96-5+e+190,440);





r=325;
n+=15;
ellipse(227+r,206+n,0,180,9,1);
ellipse(227+r,204+n,0,180,9,1);
putpixel(220+r,204+n,15);
putpixel(220+r,205+n,15);
putpixel(220+r,206+n,15);
putpixel(235+r,204+n,15);
putpixel(235+r,205+n,15);
putpixel(235+r,206+n,15);

ellipse(227+r,203+n,0,180,6,7);
line(227+r,195+n,227+r,192+n);


rectangle(155+e,302,220+e,364);
rectangle(155+e,302+70,220+e,364+75);


q=140;
d-=1;
line(302+q-5,405+d,302+q-5,440+d);
line(338+q+5,405+d,338+q+5,440+d);
ellipse(327+q+5,405+d,108,180,35,30);

ellipse(313+q-5,406+d,360,74,35,30);

d=-77;
line(302+q-5,405+d,302+q-5,440+d);
line(338+q+5,405+d,338+q+5,440+d);
ellipse(327+q,405+d,105,180,30,25);

ellipse(313+q,405+d,360,80,30,25);
putpixel(163,300,11);
setfillstyle(6,15);
floodfill(163,330,15);
floodfill(160,380,15);
/////////////////////////////
e=e-15;
line(141+e+150,305+5,141+e+150,360+5);
line(101+e+150,310-5,101+e+150,365-5);
line(101+e+150,305,141+e+150,310);
line(101+e+150,360,141+e+150,365);

int v=75;
line(141+e+150,305+5+v-5,141+e+150,440);
line(101+e+150,310-5+v-5,101+e+150,440);
line(101+e+150,305+v-5,141+e+150,310+v-5);
//line(101+e+150,360+v,141+e+150,365+v);

e=e+18;
rectangle(178+e,415,197+e,439);
setfillstyle(7,15);
floodfill(179+e,416,15);
int f=-75;
rectangle(178+e,415+f,197+e,439+f);
setfillstyle(7,15);
floodfill(179+e,416+f,15);


e+=130;
line(130-3+e,440+a-2,130-3+e,417+a+2);
line(113+3+e,440+a-2,113+3+e,420+a-2);

line(113+3+e,417+a,130-3+e,420+a);
putpixel(114+e,423,4);
floodfill(114+3+e,423+a,15);

a=1;
line(130-3+e,440+a-2,130-3+e,417+a+2);
line(113+3+e,440+a-2,113+3+e,420+a-2);

line(113+3+e,417+a,130-3+e,420+a);
putpixel(114+e,423,4);
line(113+3+e,440,130-3+e,440);
floodfill(114+3+e,423+a,15);


q=204;
line(302+q+4,405+d,302+q+4,440+d-2);
line(338+q-1,405+d,338+q-1,440+d+2);
ellipse(327+q,405+d,105,180,20,15);
ellipse(313+q+4,405+d,360,80,20,15);
q=204;

d=0;
line(302+q+4,405+d,302+q+4,440+d-1);
line(338+q-1,405+d,338+q-1,440+d);
ellipse(327+q,405+d,105,180,20,15);
ellipse(313+q+4,405+d,360,80,20,15);
line(302+q+4,440,302+q+4,440);




setfillstyle(10,15);
floodfill(322,160,15);
setfillstyle(6,15);

floodfill(322,193,15);
///////////////////////////////////////////////walls//////////////
setfillstyle(9,15);
floodfill(110,294,15);
floodfill(210,290,15);
floodfill(430,290,15);
floodfill(520,290,15);
/////////////////////////////////////////////poles
setfillstyle(6,15);
floodfill(93,394,15);
floodfill(148,394,15);
floodfill(227,394,15);
floodfill(417,394,15);
floodfill(498,394,15);
floodfill(553,394,15);


setfillstyle(9,15);
floodfill(185,224,15);
floodfill(465,224,15);



while(!kbhit())
{
delay(40);
putpixel(random(640),random(248),random(15));
 }

  getch();
  windows();
}

/////////////////////////// TIC-TAC-TOE/////////////
char square1[10] = {'0','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

void tic()
{
	clrscr();
	int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;

		cout << "                        Player " << player << ", Enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square1[1] == '1')

			square1[1] = mark;
		else if (choice == 2 && square1[2] == '2')

			square1[2] = mark;
		else if (choice == 3 && square1[3] == '3')

			square1[3] = mark;
		else if (choice == 4 && square1[4] == '4')

			square1[4] = mark;
		else if (choice == 5 && square1[5] == '5')

			square1[5] = mark;
		else if (choice == 6 && square1[6] == '6')

			square1[6] = mark;
		else if (choice == 7 && square1[7] == '7')

			square1[7] = mark;
		else if (choice == 8 && square1[8] == '8')

			square1[8] = mark;
		else if (choice == 9 && square1[9] == '9')

			square1[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	windows();
}

/*********************************************

	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square1[1] == square1[2] && square1[2] == square1[3])

		return 1;
	else if (square1[4] == square1[5] && square1[5] == square1[6])

		return 1;
	else if (square1[7] == square1[8] && square1[8] == square1[9])

		return 1;
	else if (square1[1] == square1[4] && square1[4] == square1[7])

		return 1;
	else if (square1[2] == square1[5] && square1[5] == square1[8])

		return 1;
	else if (square1[3] == square1[6] && square1[6] == square1[9])

		return 1;
	else if (square1[1] == square1[5] && square1[5] == square1[9])

		return 1;
	else if (square1[3] == square1[5] && square1[5] == square1[7])

		return 1;
	else if (square1[1] != '1' && square1[2] != '2' && square1[3] != '3'
		    && square1[4] != '4' && square1[5] != '5' && square1[6] != '6'
		  && square1[7] != '7' && square1[8] != '8' && square1[9] != '9')

		return 0;
	else
		return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
	clrscr();
	cout << "                                        \n\n\t\t\t\tTic Tac Toe\n\n";

	cout << "                         Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "                                   |     |     " << endl;
	cout << "                                " << square1[1] << "  |  " << square1[2] << "  |  " << square1[3] << endl;

	cout << "                              _____|_____|_____" << endl;
	cout << "                                   |     |     " << endl;

	cout << "                                " << square1[4] << "  |  " << square1[5] << "  |  " << square1[6] << endl;

	cout << "                              _____|_____|_____" << endl;
	cout << "                                   |     |     " << endl;

	cout << "                                " << square1[7] << "  |  " << square1[8] << "  |  " << square1[9] << endl;

	cout << "                                   |     |     " << endl << endl;
}

////////////////////////////HANGMAN GAME///////////////
const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=7;

int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);
void hangman ()
{
	char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	clrscr();
	char words[][MAXLENGTH] =
	{
		"india",

		"pakistan",

		"nepal",

		"malaysia",

		"philippines",

		"australia",

		"iran",

		"ethiopia",

		"oman",

		"indonesia"
	};

	//choose and copy a word from array of words randomly
	randomize();
	int n=random(10);
	strcpy(word,words[n]);

	// Initialize the secret word with the * character.
	initUnknown(word, unknown);

	// welcome the user
	cout << "\n\n                          Welcome to hangman...Guess a country Name";
	cout << "\n\n                             Each letter is represented by a star.";
	cout << "\n\n                           You have to type only one letter in one try";
	cout << "\n\n                           You have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n                                   " << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "                  Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "              You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "                            You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left.   " << endl;
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\n                  Sorry, you lose...you've been hanged." << endl;
		cout << "                    The word was : " << word << endl;
	}
	getch();
	windows();
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */



int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


// Initialize the unknown word

void initUnknown (char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}


////////////////////////////// SNAKE GAME    //////////////////
void snake()
{
void starting(void);
void make_xy(char **,char **);
void getrand(char *,char *,char *,char *,char *,int,char);
char getkey(char,char);
void savegame(char *,char *,int,char);
int loadgame(char *,char *,char *);
void win_message(void);


char *x,*y,pos_x,pos_y,num,out=0,old_ch=0,ch=0,new_ch,new_x,new_y,old_num=0;
int i,length=6;


starting();
make_xy(&x,&y);
getrand(&pos_x,&pos_y,&num,x,y,length,ch);


while(!out){
if((new_ch=getkey(old_ch,ch))==ESC)
out=2;
if(out)
break;
if(new_ch==SAVE)
savegame(x,y,length,old_ch);
else if(new_ch==LOAD){
length=loadgame(x,y,&ch);
getrand(&pos_x,&pos_y,&num,x,y,length,ch);
}
else
ch=new_ch;
new_x=x[0];
new_y=y[0];
if(ch==UPARR)
new_y=y[0]-1;
else if(ch==LEFTARR)
new_x=x[0]-1;
else if(ch==DOWNARR)
new_y=y[0]+1;
else if(ch==RIGHTARR)
new_x=x[0]+1;
old_ch=ch;
if((new_x<2)|(new_y<2)|(new_x>79)|(new_y>22))
out=1; /* HIGHEST POSSIBLE SCORE ї (78*21-6)*5 = 8160 ї 10,000 */
for(i=1;i<length-!old_num;i++) /* NOT "length": TAIL-END MAY MOVE AWAY! */
if((new_x==x[i])&(new_y==y[i])){
out=1;
break;
}
if((pos_x==new_x)&(pos_y==new_y)){
old_num+=num;
/* x=(char *)realloc(x,(score+6)*sizeof(char));
y=(char *)realloc(y,(score+6)*sizeof(char)); */
/* if((x==0)|(y==0)) */ /* PROBLEM IS NOT HERE */
/* x=x;*//* SOMEHOW realloc ISN'T COPYING PROPERLY */
getrand(&pos_x,&pos_y,&num,x,y,length,ch);
}
if(!old_num){
gotoxy(x[length-1],y[length-1]);
putchar(' ');
}
else{
length++;
if(length==1638){
win_message();

}
gotoxy(67,25);
printf("Score = %5d",length-6);
old_num--;
x[i+1]=x[i];
y[i+1]=y[i];
}
for(i=length-1;i>0;i--){
x[i]=x[i-1];
y[i]=y[i-1];
if(i==1){
gotoxy(x[i],y[i]);
putchar('л');
}
}
x[0]=new_x;
y[0]=new_y;
gotoxy(x[0],y[0]);
printf("\b"); /* USE THE FUNCTION _setcursortype() */
if(out)
break;
delay(99);
}
if(out==1){
gotoxy(1,24);
printf("The snake collided with the wall or with itself!\n"
"GAME OVER!!\t\t(Press 'q' to terminate...)");
gotoxy(x[0],y[0]);
while(toupper(getch())!='Q');
}
windows();
}


/*-------------------------------------------------------------------------*/


void starting()
{
char i;


clrscr(); /* FIRST TO DRAW A BOUNDARY for THE GAME */
putchar('Щ');
for(i=0;i<78;i++)
putchar('Э');
putchar('Л');
gotoxy(1,23);
putchar('Ш');
for(i=0;i<78;i++)
putchar('Э');
putchar('М');
window(1,2,1,23);
for(i=0;i<21;i++)
cprintf("К");
window(80,2,80,23);
for(i=0;i<21;i++)
cprintf("К"); /* THE BOUNDARY IS DRAWN */
window(1,1,80,25);
gotoxy(38,12);
printf("ллллл"); /* THE "SNAKE" IS PUT for THE FIRST TIME */
gotoxy(1,24);
printf("Welcome to the game of SNAKE!\n(Press any arrow key to start now,"
" Escape to leave at any time...)"); /* WELCOME MESSAGE */
gotoxy(43,12);
while(!kbhit());
gotoxy(30,24);
delline();delline(); /* REMOVING MESSAGE */
cprintf("\n( EAT THE NUMBER !! ) Score = 0");
gotoxy(43,12); /* GO TO THE HEAD OF THE SNAKE */
}


void make_xy(char **px,char **py)
{
char i;


*px=(char *)malloc(1638*sizeof(char)); /*EARLIER IT WAS 6, NOT 1638; BUT*/
*py=(char *)malloc(1638*sizeof(char)); /*realloc IS NOT COPYING PROPERLY*/
for(i=0;i<6;i++){
(*px)[i]=43-i;
(*py)[i]=12;
} /* THE TWO ARRAYS for COORDINATES OF THE SNAKE ARE SIMULATED */
}


void getrand(char *px,char *py,char *pn,char *x,char *y,int length,char ch)
{
int allowed=0,i; /* i AND length MUST BE int */


while(!allowed){
allowed=1;
srand((unsigned)time(0));
*px=rand()%78+2; /* GENERATING RANDOM POSITIONAL COORDINATES for */
srand((unsigned)time(0));
*py=rand()%21+2; /* PUTTING A RANDOM NUMBER */
if(ch==UPARR){
if((*px==x[0])&(*py==y[0]-1))
allowed=0;
}
else if(ch==DOWNARR){
if((*px==x[0])&(*py==y[0]+1))
allowed=0;
}
else if(ch==LEFTARR){
if((*px==x[0]-1)&(*py==y[0]))
allowed=0;
}
else if((ch==RIGHTARR)&(*px==x[0]+1)&(*py==y[0]))
allowed=0;
for(i=0;(i<length)&&allowed;i++)
if((*px==x[i])&(*py==y[i]))
allowed=0;
} /* THE RANDOM NUMBER GENERATED SHOULD NOT BE PUT ON SNAKE'S BODY */
srand((unsigned)time(0));
*pn=rand()%9+1; /* THE NUMBER */
gotoxy(*px,*py);
putchar(*pn+48);
gotoxy(x[0],y[0]);
}


char getkey(char old_ch,char ch)
{
char i;


if(kbhit())
for(i=0;i<5;i++){ /* if i too low, takes too many keystrokes */
while((ch=getch())==0);
if(ch==27){
/* out=2;
i=5;
break;*/return ch;
}
if((ch!=LOAD)&(ch!=SAVE)&(ch!=UPARR)&(ch!=DOWNARR)&
(ch!=LEFTARR)&(ch!=RIGHTARR))
continue;
if((ch!=old_ch)|(!kbhit()))
break;
}
else
for(i=0;(i<12)&(!kbhit());i++)
delay(100);
return ch;
}


void savegame(char *px,char *py,int length,char ch)
{
FILE *fp;
int i;


rename("snake.sav","snake.bak");
fp=fopen("snake.sav","wb");
fprintf(fp,"%d %c",length,ch);
for(i=0;i<length;i++)
fprintf(fp,"%c%c",px[i],py[i]);
fclose(fp);
}


int loadgame(char *px,char *py,char *pch)
{
FILE *fp;
int length,i;


fp=fopen("snake.sav","rb");
if(!fp){
clrscr();
puts("ERROR: no saved game found in current directory!!!\n\n\t\t"
"Exiting...\n");
sleep(3);
exit(1);
}
window(2,2,79,22);
clrscr();
/* fscanf(fp,"%d %c ",&length,pch);*/
fscanf(fp,"%d %c",&length,pch);
for(i=0;i<length;i++){
/* fscanf(fp,"%d %d ",&px[length],&py[length]);*/
fscanf(fp,"%c%c",&px[i],&py[i]);
gotoxy(px[i]-1,py[i]-1);
putchar('л');
}
window(1,1,80,25);
gotoxy(30,24);
delline();delline(); /* REMOVING MESSAGE */
cprintf("\n( EAT THE NUMBER !! ) Score = %5d",length-6);
gotoxy(px[0],py[0]);
printf("\b");
fclose(fp);
return length;
}


void win_message()
{
window(1,1,80,25);
gotoxy(1,24);
delline();delline();
textcolor(14);
cprintf("CONGRATULATION!! YOU HAVE COMPLETED THE GAME!!\r\n"
"(Press any key to terminate...)");
clrscr();
textcolor(7);
}


/////////////////////////////////ICONS 6////////////////
void OnLButtonUp6(int ,int ){ButtonStatus=0;}
void OnMouseMove6(int ,int ,int ){}
Bool IsBetween6(int x,int y)                   //IMPORTANT
{
   if(x>=120 && x<=275 && y>=275 && y<=310)
   {
      icon=10;
      return true;
   }
   else if(x>=350 && x<=535 && y>=275 && y<=310)
   {
      icon=11;
      return true;
   }
   else if(x>=553 && x<=617 && y>=11 && y<=35)
   {
      icon=12;
      return true;
   }
   else if(x>=625 && x<=639 && y>=0 && y<=12)
   {
      icon=6;
      return true;
   }
   else
   return false;
}


void OnLButtonDown6(int x,int y)
{

    setcolor(4);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween6(x,y)==true && icon==10)
    outtextxy(250,350,"Connection Failed");
    else if(IsBetween6(x,y)==true && icon==11)
    outtextxy(250,350,"Connection Failed");
    else if(IsBetween6(x,y)==true && icon==12)
    outtextxy(250,350,"Connection Failed");
    else if(IsBetween6(x,y)==true && icon==6)
    windows();
    else
    icon=0;
}


void google()
{
   cleardevice();
   ini();
   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();
   setbkcolor(1);

   setcolor(4);                //Close Button (WORKING)
   setfillstyle(1,4);
   rectangle(625,0,639,12);
   floodfill(626,1,4);
   setcolor(0);
   line(625,0,639,12);
   line(639,0,625,12);

   setcolor(4);
   rectangle(0,0,getmaxx(),getmaxy());
   setcolor(9);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
   outtextxy(175,120,"G");
   setcolor(2);
   outtextxy(225,120,"O");
   setcolor(3);
   outtextxy(275,120,"O");
   setcolor(7);
   outtextxy(325,120,"G");
   setcolor(6);
   outtextxy(375,120,"L");
   setcolor(13);
   outtextxy(425,120,"E");
   setcolor(3);
   setcolor(6);
   settextstyle(SMALL_FONT,HORIZ_DIR,6);
   outtextxy(400,200,"India");
   setcolor(2);

   rectangle(150,235,500,260);
   rectangle(120,275,275,310);
   rectangle(350,275,535,310);
   setcolor(10);
   rectangle(553,11,617,35);
   setcolor(8);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   outtextxy(125,280," Google Search            I'm  Feeling Lucky");
   setcolor(5);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   outtextxy(380,10,"+You Images Gmail Sign In");
   setcolor(9);
   outtextxy(10,450,"Advertisement Policy Help");
   outtextxy(500,450,"Privacy Setting");
   char a[50];
   cprintf("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
   gets(a);


   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove6(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown6(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp6(GetX(),GetY());
		}
   }
  //getch();
  //closegraph();
}

/////////////////////////////ICONS 5////////////////////
void OnLButtonUp5(int ,int ){ButtonStatus=0;}
void OnMouseMove5(int ,int ,int ){}
Bool IsBetween5(int x,int y)                   //IMPORTANT
{
   if(x>=300 && x<=350 && y>=170 && y<=220)
   {
      icon=8;
      return true;
   }
   else if(x>=350 && x<=430 && y>=270 && y<=290)
   {
      icon=9;
      return true;
   }
   else
   return false;
}


void OnLButtonDown5(int x,int y)
{

    time_t t;
    time(&t);
    setcolor(15);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween5(x,y)==true && icon==8)
    {
       fstream fin("log.txt",ios::out|ios::app);
       fin<<pass<<" <- "<<"OUT"<<" <- "<<ctime(&t)<<"\n";
       fin.close();
       closegraph();

    }
    else if(IsBetween5(x,y)==true && icon==9)
    windows();
    else
    icon=0;
}
void icons5()
{

   cleardevice();
   time_t t;
   time(&t);
   ini();
   rectangle(0,0,getmaxx(),getmaxy());
   //start bar
   setcolor(9);                        //(WORKING)
   setfillstyle(1,9);
   rectangle(0,450,getmaxx(),getmaxy());
   floodfill(300,452,9);

   setcolor(2);
   setfillstyle(1,2);
   circle(15,463,13);               //Start Symbol (WORKING)
   floodfill(6,456,2);
   setcolor(4);
   setfillstyle(1,4);
   circle(15,463,5);
   floodfill(15,463,4);


   setcolor(1);
   rectangle(45,452,72,474);    //Windows Media Player(WORKING)
   setcolor(12);
   setfillstyle(1,12);
   circle(58,463,12);
   floodfill(56,463,12);
   setcolor(15);
   setfillstyle(1,15);
   line(55,453,55,473);
   line(55,453,70,463);
   line(55,473,70,463);
   floodfill(60,463,15);

   setcolor(6);
   setfillstyle(1,6);
   rectangle(80,452,107,474);   //My Files(WORKING)
   floodfill(81,453,6);
   line(80,460,107,460);
   setcolor(1);
   setfillstyle(1,1);
   rectangle(83,460,104,474);
   floodfill(84,461,1);


   setcolor(13);
   setfillstyle(1,13);
   circle(128,463,13);        //Chrome (WORKING)
   floodfill(116,461,13);
   setcolor(1);
   setfillstyle(1,1);
   circle(128,462,5);
   floodfill(128,462,1);
   setcolor(4);
   line(128,457,140,457);
   setcolor(14);
   line(128,467,120,471);
   setcolor(2);
   line(123,465,118,457);

   setcolor(2);
   setfillstyle(1,2);
   rectangle(440,450,getmaxx(),getmaxy());           //Date and Time (WORKING)
   floodfill(441,451,2);
   setcolor(4);
   outtextxy(441,460,ctime(&t));

   //Desktop

   setcolor(6);
   setfillstyle(1,6);
   rectangle(20,40,47,62);
   floodfill(21,41,6);
   line(20,48,47,48);            //My Files (WORKING)
   setcolor(1);
   setfillstyle(1,1);
   rectangle(23,48,44,62);
   floodfill(24,49,1);
   setcolor(15);
   outtextxy(10,65,"My Files");

   setcolor(15);
   setfillstyle(1,15);
   rectangle(20,115,47,137);
   floodfill(21,116,15);              //My Computer (WORKING)
   setcolor(0);
   outtextxy(25,119,"MY");
   outtextxy(30,128,"C");
   setcolor(15);
   rectangle(30,137,36,140);
   outtextxy(5,143,"My Computer");

   setcolor(7);
   setfillstyle(1,7);
   rectangle(25,195,45,215);         //Recycle Bin (WORKING)
   floodfill(26,196,7);
   setcolor(0);
   arc(35,195,190,355,10);
   setcolor(15);
   outtextxy(10,220,"Recycle Bin");

   setcolor(2);
   setfillstyle(1,2);
   rectangle(15,250,45,280);         //Snake Game (WORKING);
   floodfill(16,251,2);
   setcolor(4);
   outtextxy(20,255,"SG");
   setcolor(1);
   outtextxy(20,265,"");
   setcolor(15);
   outtextxy(10,290,"Snake Game");


   setcolor(4);
   setfillstyle(1,4);
   rectangle(15,340,45,370);         //Hangman (WORKING)
   floodfill(16,341,4);
   setcolor(14);
   outtextxy(20,345,"HM");
   setcolor(2);
   outtextxy(20,355,"");
   setcolor(15);
   outtextxy(10,380,"Hangman");

   setcolor(1);
   setfillstyle(1,1);
   rectangle(120,30,150,60);           //Tic-Tac-Toe  (WORKING)
   floodfill(121,31,1);
   setcolor(4);
   outtextxy(125,35,"TTT");
   setcolor(14);
   outtextxy(125,45,"");
   setcolor(15);
   outtextxy(95,65,"Tic-Tac-Toe");


   setcolor(14);
   setfillstyle(1,14);
   rectangle(120,110,150,140);         //Taj Mahal (WORKING)
   floodfill(121,111,14);
   setcolor(1);
   outtextxy(125,115,"TJM");
   setcolor(4);
   outtextxy(125,125,"");
   setcolor(15);
   outtextxy(110,143,"Taj Mahal");

   setcolor(6);
   setfillstyle(1,6);
   rectangle(120,180,150,210);         //Solar System (WORKING)
   floodfill(121,181,6);
   setcolor(14);
   outtextxy(125,185,"SS");
   setcolor(5);
   outtextxy(125,195,"");
   setcolor(15);
   outtextxy(120,220,"Solar");
   outtextxy(117,230,"System");

   setcolor(3);
   setfillstyle(1,3);
   rectangle(120,250,150,280);          //Car Race  (WORKING)
   floodfill(121,251,3);
   setcolor(4);
   outtextxy(125,255,"LOG");
   setcolor(6);
   outtextxy(125,265,"");
   setcolor(15);
   outtextxy(110,290,"Computer Log");

   setcolor(10);
   setfillstyle(1,10);
   rectangle(120,340,150,370);     //Snake & Ladder (WORKING)
   floodfill(121,341,10);
   setcolor(6);
   outtextxy(125,345,"CM");
   setcolor(0);
   outtextxy(125,355,"");
   setcolor(15);
   outtextxy(80,380,"Check Malfunction");



   setcolor(15);
   setfillstyle(1,15);
   rectangle(200,100,450,300);
   floodfill(201,101,15);
   setcolor(1);
   setfillstyle(1,1);
   rectangle(200,150,450,260);
   floodfill(201,151,1);

   setcolor(4);
   setfillstyle(1,4);
   rectangle(300,170,350,220);
   floodfill(301,171,4);
   setcolor(3);
   setfillstyle(1,3);
   circle(325,195,10);
   floodfill(325,195,3);
   setcolor(6);
   setfillstyle(1,6);
   rectangle(350,270,430,290);
   floodfill(351,271,6);

   setcolor(5);
   outtextxy(280,125,"CONFORMATION");
   setcolor(14);
   outtextxy(250,230,"Shutdown Windows 20");
   setcolor(2);
   outtextxy(365,278,"Cancel");

   /*settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
   outtextxy(getmaxx()/2-80,getmaxy()/2-100,"WINDOWS");
   outtextxy(getmaxx()/2-25,getmaxy()/2-50,"20");
   */
   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();
   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove5(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown5(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp5(GetX(),GetY());
		}
   }
   //getch();
   //closegraph();
}

////////////////////////ICONS 4///////////////////////////
void OnLButtonUp4(int ,int ){ButtonStatus=0;}
void OnMouseMove4(int ,int ,int ){}
Bool IsBetween4(int x,int y)                   //IMPORTANT
{
   if(x>=625 && x<=639 && y>=0 && y<=12)
   {
      icon=6;
      return true;
   }
   else if(x>=295 && x<=325 && y>=440 && y<=470)
   {
      icon=7;
      return true;
   }
   else if(x>=330 && x<=345 && y>=440 && y<=470)
   {
      icon=8;
      return true;
   }
   else if(x>=275 && x<=290 && y>=440 && y<=470)
   {
      icon=9;
      return true;
   }
   else
   return false;
}


void OnLButtonDown4(int x,int y)
{

    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween4(x,y)==true && icon==6)
    windows();
    else if(IsBetween4(x,y)==true && icon==7)
    outtextxy(getmaxx()/2-50,getmaxy()/2-50,"NOTHING TO PLAY");
    else if(IsBetween4(x,y)==true && icon==8)
    outtextxy(getmaxx()/2-50,getmaxy()/2-50,"NOTHING TO PLAY");
    else if(IsBetween4(x,y)==true && icon==9)
    outtextxy(getmaxx()/2-50,getmaxy()/2-50,"NOTHING TO PLAY");

    else
    icon=0;
}
void icons4()
{
   cleardevice();
   ini();

   rectangle(0,0,getmaxx(),getmaxy());


   setcolor(4);                //Close Button (WORKING)
   setfillstyle(1,4);
   rectangle(625,0,639,12);
   floodfill(626,1,4);
   setcolor(0);
   line(625,0,639,12);
   line(639,0,625,12);

   setcolor(15);
   rectangle(5,425,634,430);
   setcolor(9);
   setfillstyle(1,9);
   rectangle(210,440,410,470);
   floodfill(211,441,9);

   setcolor(1);
   setfillstyle(1,1);
   circle(310,455,15);
   floodfill(309,455,1);
   setcolor(2);
   setfillstyle(1,2);
   line(310,440,310,470);              //Play
   line(310,440,325,455);
   line(310,470,325,455);
   floodfill(311,455,2);

   setcolor(14);
   setfillstyle(1,14);
   line(330,440,330,470);              //Next
   line(330,440,345,455);
   line(330,470,345,455);
   line(345,445,345,465);
   floodfill(331,443,14);

   line(290,440,290,470);
   line(290,440,275,455);             //Back
   line(290,470,275,455);
   line(275,445,275,465);
   floodfill(289,443,14);

   setcolor(4);
   setfillstyle(1,4);
   rectangle(220,445,235,465);              //Stop
   floodfill(221,446,4);

   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();


   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove4(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown4(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp4(GetX(),GetY());
		}
   }

  // getch();
   //closegraph();
}



///////////////////////////////ICONS 3///////////////////
void OnLButtonUp3(int ,int ){ButtonStatus=0;}
void OnMouseMove3(int ,int ,int ){}
Bool IsBetween3(int x,int y)                  //IMPORTANT
{
   if(x>=625 && x<=639 && y>=0 && y<=12)
   {
      icon=6;
      return true;
   }
   else if(x>=9 && x<=80 && y>=128 && y<=139)
   {
      icon=7;
      return true;
   }
   else if(x>=9 && x<=70 && y>=148 && y<=159)
   {
      icon=8;
      return true;
   }
   else if(x>=9 && x<=80 && y>=168 && y<=179)
   {
      icon=9;
      return true;
   }
   else if(x>=5 && x<=108 && y>=188 && y<=199)
   {
      icon=10;
      return true;
   }
   else if(x>=9 && x<=80 && y>=218 && y<=229)
   {
      icon=11;
      return true;
   }
   else if(x>=9 && x<=50 && y>=238 && y<=249)
   {
      icon=12;
      return true;
   }
   else if(x>=9 && x<=80 && y>=258 && y<=269)
   {
      icon=13;
      return true;
   }
   else if(x>=9 && x<=60 && y>=278 && y<=289)
   {
      icon=14;
      return true;
   }
   else if(x>=9 && x<=80 && y>=298 && y<=309)
   {
      icon=15;
      return true;
   }
   else if(x>=9 && x<=60 && y>=318 && y<=329)
   {
      icon=16;
      return true;
   }
   else if(x>=9 && x<=80 && y>=348 && y<=359)
   {
      icon=17;
      return true;
   }
   else if(x>=1 && x<=108 && y>=368 && y<=379)
   {
      icon=18;
      return true;
   }
   else if(x>=1 && x<=108 && y>=388 && y<=399)
   {
      icon=19;
      return true;
   }
   else if(x>=1 && x<=108 && y>=408 && y<=419)
   {
      icon=20;
      return true;
   }
   else if(x>=9 && x<=70 && y>=438 && y<=449)
   {
      icon=21;
      return true;
   }
   else
   return false;
}


void OnLButtonDown3(int x,int y)
{
    backto=3;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween3(x,y)==true && icon==6)
    windows();
    else if(IsBetween3(x,y)==true && icon==7)
    backicon();
    else if(IsBetween3(x,y)==true && icon==8)
    backicon();
    else if(IsBetween3(x,y)==true && icon==9)
    backicon();
    else if(IsBetween3(x,y)==true && icon==10)
    backicon();
    else if(IsBetween3(x,y)==true && icon==11)
    backicon();
    else if(IsBetween3(x,y)==true && icon==12)
    backicon();
    else if(IsBetween3(x,y)==true && icon==13)
    backicon();
    else if(IsBetween3(x,y)==true && icon==14)
    backicon();
    else if(IsBetween3(x,y)==true && icon==15)
    backicon();
    else if(IsBetween3(x,y)==true && icon==16)
    backicon();
    else if(IsBetween3(x,y)==true && icon==17)
    icons2();
    else if(IsBetween3(x,y)==true && icon==18)
    backicon();
    else if(IsBetween3(x,y)==true && icon==19)
    backicon();
    else if(IsBetween3(x,y)==true && icon==20)
    backicon();
    else if(IsBetween3(x,y)==true && icon==21)
    outtextxy(320,400,"No Network");
    else
    icon=0;
}
void icons3()
{
   cleardevice();
   ini();

   rectangle(0,0,getmaxx(),getmaxy());

   setcolor(13);
   setfillstyle(1,13);
   rectangle(0,100,getmaxx(),getmaxy());          //Frames
   floodfill(1,101,13);
   setcolor(0);
   setfillstyle(1,0);
   rectangle(110,100,getmaxx(),getmaxy());
   rectangle(110,100,getmaxx(),getmaxy());
   floodfill(111,101,0);
   setcolor(9);
   setfillstyle(1,9);
   rectangle(0,50,getmaxx(),100);
   floodfill(1,49,9);
   setcolor(10);
   setfillstyle(1,10);
   rectangle(0,50,getmaxx(),100);
   floodfill(1,51,10);


   setcolor(4);                //Close Button (WORKING)
   setfillstyle(1,4);
   rectangle(625,0,639,12);
   floodfill(626,1,4);
   setcolor(0);
   line(625,0,639,12);
   line(639,0,625,12);



   setcolor(11);
   setfillstyle(1,11);
   rectangle(19,23,60,34);         //(WORKING)
   floodfill(21,25,11);
   rectangle(79,23,120,34);
   floodfill(80,24,11);
   rectangle(139,23,180,34);
   floodfill(140,24,11);
   rectangle(199,23,240,34);
   floodfill(200,24,11);

   setcolor(13);
   outtextxy(20,25,"Files");
   outtextxy(80,25,"Edit");
   outtextxy(140,25,"Tool");
   outtextxy(200,25,"Help");


   setcolor(8);
   setfillstyle(1,8);
   rectangle(19,73,85,84);         //(WORKING)
   floodfill(20,74,8);


   setcolor(1);
   outtextxy(20,75,"Organize");



   setcolor(6);
   setfillstyle(1,6);
   rectangle(9,128,80,139);      //(WORKING)
   floodfill(10,129,6);
   rectangle(9,148,70,159);
   floodfill(10,149,6);
   rectangle(9,168,80,179);
   floodfill(10,169,6);
   rectangle(5,188,108,199);
   floodfill(6,189,6);


   setcolor(14);
   outtextxy(10,130,"Favorite");
   outtextxy(10,150,"Desktop");
   outtextxy(10,170,"Downloads");
   outtextxy(6,190,"Recent Places");

   setcolor(2);
   setfillstyle(1,2);
   rectangle(9,218,80,229);          //(WORKING)
   floodfill(10,219,2);
   rectangle(9,238,50,249);
   floodfill(10,239,2);
   rectangle(9,258,80,269);
   floodfill(10,259,2);
   rectangle(9,278,60,289);
   floodfill(10,279,2);
   rectangle(9,298,80,309);
   floodfill(10,299,2);
   rectangle(9,318,60,329);
   floodfill(10,319,2);

   setcolor(1);
   outtextxy(10,220,"Libraries");
   outtextxy(10,240,"Apps");
   outtextxy(10,260,"Documents");
   outtextxy(10,280,"Musics");
   outtextxy(10,300,"Pictures");
   outtextxy(10,320,"Videos");


   setcolor(14);
   setfillstyle(1,14);
   rectangle(9,348,80,359);
   floodfill(10,349,14);
   rectangle(1,368,108,379);
   floodfill(2,369,14);
   rectangle(1,388,108,399);
   floodfill(2,389,14);
   rectangle(1,408,108,419);
   floodfill(2,409,14);

   setcolor(0);
   outtextxy(10,350,"Computers");
   outtextxy(2,370,"Local Disk C:");
   outtextxy(2,390,"Local Disk D:");
   outtextxy(2,410,"Local Disk E:");

   setcolor(15);
   setfillstyle(1,15);
   rectangle(9,438,70,449);
   floodfill(10,439,15);
   setcolor(4);
   outtextxy(10,440,"Network");

   outtextxy(getmaxx()/2,getmaxy()/2-50,"EMPTY");

   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();

   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove3(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown3(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp3(GetX(),GetY());
		}
   }
   //getch();
   //closegraph();
}

///////////////////////////////////ICONS 2///////////////
void OnLButtonUp2(int ,int ){ButtonStatus=0;}
void OnMouseMove2(int ,int ,int ){}
Bool IsBetween2(int x,int y)                  //IMPORTANT
{
   if(x>=150 && x<=300 && y>=195 && y<=210)
   {
      icon=1;
      return true;
   }
   else if(x>=310 && x<=460 && y>=195 && y<=210)
   {
      icon=2;
      return true;
   }
   else if(x>=470 && x<=630 && y>=195 && y<=210)
   {
      icon=3;
      return true;
   }
   else if(x>=180 && x<=200 && y>=300 && y<=340)
   {
      icon=4;
      return true;
   }
   else if(x>=380 && x<=420 && y>=300 && y<=340)
   {
      icon=5;
      return true;
   }
   else if(x>=625 && x<=639 && y>=0 && y<=12)
   {
      icon=6;
      return true;
   }
   else if(x>=9 && x<=80 && y>=128 && y<=139)
   {
      icon=7;
      return true;
   }
   else if(x>=9 && x<=70 && y>=148 && y<=159)
   {
      icon=8;
      return true;
   }
   else if(x>=9 && x<=80 && y>=168 && y<=179)
   {
      icon=9;
      return true;
   }
   else if(x>=5 && x<=108 && y>=188 && y<=199)
   {
      icon=10;
      return true;
   }
   else if(x>=9 && x<=80 && y>=218 && y<=229)
   {
      icon=11;
      return true;
   }
   else if(x>=9 && x<=50 && y>=238 && y<=249)
   {
      icon=12;
      return true;
   }
   else if(x>=9 && x<=80 && y>=258 && y<=269)
   {
      icon=13;
      return true;
   }
   else if(x>=9 && x<=60 && y>=278 && y<=289)
   {
      icon=14;
      return true;
   }
   else if(x>=9 && x<=80 && y>=298 && y<=309)
   {
      icon=15;
      return true;
   }
   else if(x>=9 && x<=60 && y>=318 && y<=329)
   {
      icon=16;
      return true;
   }
   else if(x>=9 && x<=80 && y>=348 && y<=359)
   {
      icon=17;
      return true;
   }
   else if(x>=1 && x<=108 && y>=368 && y<=379)
   {
      icon=18;
      return true;
   }
   else if(x>=1 && x<=108 && y>=388 && y<=399)
   {
      icon=19;
      return true;
   }
   else if(x>=1 && x<=108 && y>=408 && y<=419)
   {
      icon=20;
      return true;
   }
   else if(x>=9 && x<=70 && y>=438 && y<=449)
   {
      icon=21;
      return true;
   }
   else
   return false;
}
void OnLButtonDown2(int x,int y)
{
    backto=2;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween2(x,y)==true && icon==1)
    backicon();
    else if(IsBetween2(x,y)==true && icon==2)
    backicon();
    else if(IsBetween2(x,y)==true && icon==3)
    backicon();
    else if(IsBetween2(x,y)==true && icon==4)
    outtextxy(310,350,"Nothing Inserted");
    else if(IsBetween2(x,y)==true && icon==5)
    outtextxy(310,350,"Nothing Inserted");
    else if(IsBetween2(x,y)==true && icon==6)
    windows();
    else if(IsBetween2(x,y)==true && icon==7)
    backicon();
    else if(IsBetween2(x,y)==true && icon==8)
    backicon();
    else if(IsBetween2(x,y)==true && icon==9)
    backicon();
    else if(IsBetween2(x,y)==true && icon==10)
    backicon();
    else if(IsBetween2(x,y)==true && icon==11)
    backicon();
    else if(IsBetween2(x,y)==true && icon==12)
    backicon();
    else if(IsBetween2(x,y)==true && icon==13)
    backicon();
    else if(IsBetween2(x,y)==true && icon==14)
    backicon();
    else if(IsBetween2(x,y)==true && icon==15)
    backicon();
    else if(IsBetween2(x,y)==true && icon==16)
    backicon();
    else if(IsBetween2(x,y)==true && icon==17)
    icons2();
    else if(IsBetween2(x,y)==true && icon==18)
    backicon();
    else if(IsBetween2(x,y)==true && icon==19)
    backicon();
    else if(IsBetween2(x,y)==true && icon==20)
    backicon();
    else if(IsBetween2(x,y)==true && icon==21)
    outtextxy(320,400,"No Network");
    else
    icon=0;
}
void icons2()
{
   cleardevice();
   ini();

   rectangle(0,0,getmaxx(),getmaxy());

   setcolor(13);
   setfillstyle(1,13);
   rectangle(0,100,getmaxx(),getmaxy());          //Frames
   floodfill(1,101,13);
   setcolor(0);
   setfillstyle(1,0);
   rectangle(110,100,getmaxx(),getmaxy());
   rectangle(110,150,getmaxx(),getmaxy());
   rectangle(110,270,getmaxx(),getmaxy());
   floodfill(111,101,0);
   floodfill(111,151,0);
   floodfill(111,271,0);
   setcolor(15);

   line(110,150,getmaxx(),150);
   line(110,270,getmaxx(),270);

   setcolor(9);
   setfillstyle(1,9);
   rectangle(0,50,getmaxx(),100);
   floodfill(1,49,9);
   setcolor(10);
   setfillstyle(1,10);
   rectangle(0,50,getmaxx(),100);
   floodfill(1,51,10);

   outtextxy(115,140,"Hard Disk Drive (3)");
   outtextxy(115,260,"Device with Removable Storage (2)");

   setcolor(4);                //Close Button (WORKING)
   setfillstyle(1,4);
   rectangle(625,0,639,12);
   floodfill(626,1,4);
   setcolor(0);
   line(625,0,639,12);
   line(639,0,625,12);



   setcolor(11);
   setfillstyle(1,11);
   rectangle(19,23,60,34);         //(WORKING)
   floodfill(21,25,11);
   rectangle(79,23,120,34);
   floodfill(80,24,11);
   rectangle(139,23,180,34);
   floodfill(140,24,11);
   rectangle(199,23,240,34);
   floodfill(200,24,11);

   setcolor(13);
   outtextxy(20,25,"Files");
   outtextxy(80,25,"Edit");
   outtextxy(140,25,"Tool");
   outtextxy(200,25,"Help");


   setcolor(8);
   setfillstyle(1,8);
   rectangle(19,73,85,84);         //(WORKING)
   floodfill(20,74,8);
   rectangle(99,73,180,84);
   floodfill(100,74,8);
   rectangle(199,73,330,84);
   floodfill(260,74,8);
   rectangle(349,73,585,84);
   floodfill(350,74,8);

   setcolor(1);
   outtextxy(20,75,"Organize");
   outtextxy(100,75,"Properties");
   outtextxy(200,75,"System Poperties");
   outtextxy(350,75,"Uninstall or change a program");


   setcolor(6);
   setfillstyle(1,6);
   rectangle(9,128,80,139);      //(WORKING)
   floodfill(10,129,6);
   rectangle(9,148,70,159);
   floodfill(10,149,6);
   rectangle(9,168,80,179);
   floodfill(10,169,6);
   rectangle(5,188,108,199);
   floodfill(6,189,6);


   setcolor(14);
   outtextxy(10,130,"Favorite");
   outtextxy(10,150,"Desktop");
   outtextxy(10,170,"Downloads");
   outtextxy(6,190,"Recent Places");

   setcolor(2);
   setfillstyle(1,2);
   rectangle(9,218,80,229);          //(WORKING)
   floodfill(10,219,2);
   rectangle(9,238,50,249);
   floodfill(10,239,2);
   rectangle(9,258,80,269);
   floodfill(10,259,2);
   rectangle(9,278,60,289);
   floodfill(10,279,2);
   rectangle(9,298,80,309);
   floodfill(10,299,2);
   rectangle(9,318,60,329);
   floodfill(10,319,2);

   setcolor(1);
   outtextxy(10,220,"Libraries");
   outtextxy(10,240,"Apps");
   outtextxy(10,260,"Documents");
   outtextxy(10,280,"Musics");
   outtextxy(10,300,"Pictures");
   outtextxy(10,320,"Videos");


   setcolor(14);
   setfillstyle(1,14);
   rectangle(9,348,80,359);
   floodfill(10,349,14);
   rectangle(1,368,108,379);
   floodfill(2,369,14);
   rectangle(1,388,108,399);
   floodfill(2,389,14);
   rectangle(1,408,108,419);
   floodfill(2,409,14);

   setcolor(0);
   outtextxy(10,350,"Computers");
   outtextxy(2,370,"Local Disk C:");
   outtextxy(2,390,"Local Disk D:");
   outtextxy(2,410,"Local Disk E:");

   setcolor(15);
   setfillstyle(1,15);
   rectangle(9,438,70,449);
   floodfill(10,439,15);
   setcolor(4);
   outtextxy(10,440,"Network");



   setcolor(14);
   rectangle(150,195,300,210);
   rectangle(310,195,460,210);
   rectangle(470,195,630,210);

   setcolor(15);
   outtextxy(155,180,"Local Disk (C:)");
   outtextxy(315,180,"Local Disk (D:)");
   outtextxy(475,180,"Local Disk (E:)");



   outtextxy(150,223,"97GB free of 97GB");
   outtextxy(310,223,"97GB free of 97GB");
   outtextxy(470,223,"97GB free of 97GB");

   setcolor(4);
   rectangle(180,300,200,340);
   circle(190,320,10);
   circle(190,320,5);
   circle(400,320,20);
   circle(400,320,10);

   setcolor(15);
   outtextxy(210,320,"Removable Disk (H:)");
   outtextxy(430,320,"DVD RW Drive (I:)");

   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();


   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove2(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown2(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp2(GetX(),GetY());
		}
   }
   //getch();
   //closegraph();
}
 ///////////////////////////////////////////////ICONS 1////////////
void OnLButtonUp1(int ,int ){ButtonStatus=0;}
void OnMouseMove1(int ,int ,int ){}
Bool IsBetween1(int x,int y)                  //IMPORTANT
{
   if(x>=200 && x<=250 && y>=150 && y<=200)
   {
      icon=1;
      return true;
   }
   else if(x>=350 && x<=400 && y>=150 && y<=200)
   {
      icon=2;
      return true;
   }
   else if(x>=500 && x<=550 && y>=150 && y<=200)
   {
      icon=3;
      return true;
   }
   else if(x>=200 && x<=250 && y>=300 && y<=350)
   {
      icon=4;
      return true;
   }
   else if(x>=350 && x<=400 && y>=300 && y<=350)
   {
      icon=5;
      return true;
   }
   else if(x>=625 && x<=639 && y>=0 && y<=12)
   {
      icon=6;
      return true;
   }
   else if(x>=9 && x<=80 && y>=128 && y<=139)
   {
      icon=7;
      return true;
   }
   else if(x>=9 && x<=70 && y>=148 && y<=159)
   {
      icon=8;
      return true;
   }
   else if(x>=9 && x<=80 && y>=168 && y<=179)
   {
      icon=9;
      return true;
   }
   else if(x>=5 && x<=108 && y>=188 && y<=199)
   {
      icon=10;
      return true;
   }
   else if(x>=9 && x<=80 && y>=218 && y<=229)
   {
      icon=11;
      return true;
   }
   else if(x>=9 && x<=50 && y>=238 && y<=249)
   {
      icon=12;
      return true;
   }
   else if(x>=9 && x<=80 && y>=258 && y<=269)
   {
      icon=13;
      return true;
   }
   else if(x>=9 && x<=60 && y>=278 && y<=289)
   {
      icon=14;
      return true;
   }
   else if(x>=9 && x<=80 && y>=298 && y<=309)
   {
      icon=15;
      return true;
   }
   else if(x>=9 && x<=60 && y>=318 && y<=329)
   {
      icon=16;
      return true;
   }
   else if(x>=9 && x<=80 && y>=348 && y<=359)
   {
      icon=17;
      return true;
   }
   else if(x>=1 && x<=108 && y>=368 && y<=379)
   {
      icon=18;
      return true;
   }
   else if(x>=1 && x<=108 && y>=388 && y<=399)
   {
      icon=19;
      return true;
   }
   else if(x>=1 && x<=108 && y>=408 && y<=419)
   {
      icon=20;
      return true;
   }
   else if(x>=9 && x<=70 && y>=438 && y<=449)
   {
      icon=21;
      return true;
   }
   else
   return false;
}
void OnLButtonDown1(int x,int y)
{
    backto=1;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween1(x,y)==true && icon==1)
    backicon();
    else if(IsBetween1(x,y)==true && icon==2)
    backicon();
    else if(IsBetween1(x,y)==true && icon==3)
    backicon();
    else if(IsBetween1(x,y)==true && icon==4)
    backicon();
    else if(IsBetween1(x,y)==true && icon==5)
    backicon();
    else if(IsBetween1(x,y)==true && icon==6)
    windows();
    else if(IsBetween1(x,y)==true && icon==7)
    backicon();
    else if(IsBetween1(x,y)==true && icon==8)
    backicon();
    else if(IsBetween1(x,y)==true && icon==9)
    backicon();
    else if(IsBetween1(x,y)==true && icon==10)
    backicon();
    else if(IsBetween1(x,y)==true && icon==11)
    backicon();
    else if(IsBetween1(x,y)==true && icon==12)
    backicon();
    else if(IsBetween1(x,y)==true && icon==13)
    backicon();
    else if(IsBetween1(x,y)==true && icon==14)
    backicon();
    else if(IsBetween1(x,y)==true && icon==15)
    backicon();
    else if(IsBetween1(x,y)==true && icon==16)
    backicon();
    else if(IsBetween1(x,y)==true && icon==17)
    icons2();
    else if(IsBetween1(x,y)==true && icon==18)
    backicon();
    else if(IsBetween1(x,y)==true && icon==19)
    backicon();
    else if(IsBetween1(x,y)==true && icon==20)
    backicon();
    else if(IsBetween1(x,y)==true && icon==21)
    outtextxy(320,400,"No Network");
    else
    icon=0;
}
void icons1()
{
   cleardevice();
   ini();

   rectangle(0,0,getmaxx(),getmaxy());

   setcolor(13);
   setfillstyle(1,13);
   rectangle(0,100,getmaxx(),getmaxy());          //Frames
   floodfill(1,101,13);
   setcolor(0);
   setfillstyle(1,0);
   rectangle(110,100,getmaxx(),getmaxy());
   rectangle(110,100,getmaxx(),getmaxy());
   floodfill(111,101,0);
   setcolor(9);
   setfillstyle(1,9);
   rectangle(0,50,getmaxx(),100);
   floodfill(1,49,9);
   setcolor(10);
   setfillstyle(1,10);
   rectangle(0,50,getmaxx(),100);
   floodfill(1,51,10);


   setcolor(4);                //Close Button (WORKING)
   setfillstyle(1,4);
   rectangle(625,0,639,12);
   floodfill(626,1,4);
   setcolor(0);
   line(625,0,639,12);
   line(639,0,625,12);



   setcolor(11);
   setfillstyle(1,11);
   rectangle(19,23,60,34);         //(WORKING)
   floodfill(21,25,11);
   rectangle(79,23,120,34);
   floodfill(80,24,11);
   rectangle(139,23,180,34);
   floodfill(140,24,11);
   rectangle(199,23,240,34);
   floodfill(200,24,11);

   setcolor(13);
   outtextxy(20,25,"Files");
   outtextxy(80,25,"Edit");
   outtextxy(140,25,"Tool");
   outtextxy(200,25,"Help");


   setcolor(8);
   setfillstyle(1,8);
   rectangle(19,73,85,84);         //(WORKING)
   floodfill(20,74,8);
   rectangle(99,73,245,84);
   floodfill(100,74,8);
   rectangle(259,73,294,84);
   floodfill(260,74,8);
   rectangle(319,73,400,84);
   floodfill(320,74,8);

   setcolor(1);
   outtextxy(20,75,"Organize");
   outtextxy(100,75,"Include in Library");
   outtextxy(260,75,"Burn");
   outtextxy(320,75,"New Folder");


   setcolor(6);
   setfillstyle(1,6);
   rectangle(9,128,80,139);      //(WORKING)
   floodfill(10,129,6);
   rectangle(9,148,70,159);
   floodfill(10,149,6);
   rectangle(9,168,80,179);
   floodfill(10,169,6);
   rectangle(5,188,108,199);
   floodfill(6,189,6);


   setcolor(14);
   outtextxy(10,130,"Favorite");
   outtextxy(10,150,"Desktop");
   outtextxy(10,170,"Downloads");
   outtextxy(6,190,"Recent Places");

   setcolor(2);
   setfillstyle(1,2);
   rectangle(9,218,80,229);          //(WORKING)
   floodfill(10,219,2);
   rectangle(9,238,50,249);
   floodfill(10,239,2);
   rectangle(9,258,80,269);
   floodfill(10,259,2);
   rectangle(9,278,60,289);
   floodfill(10,279,2);
   rectangle(9,298,80,309);
   floodfill(10,299,2);
   rectangle(9,318,60,329);
   floodfill(10,319,2);

   setcolor(1);
   outtextxy(10,220,"Libraries");
   outtextxy(10,240,"Apps");
   outtextxy(10,260,"Documents");
   outtextxy(10,280,"Musics");
   outtextxy(10,300,"Pictures");
   outtextxy(10,320,"Videos");


   setcolor(14);
   setfillstyle(1,14);
   rectangle(9,348,80,359);
   floodfill(10,349,14);
   rectangle(1,368,108,379);
   floodfill(2,369,14);
   rectangle(1,388,108,399);
   floodfill(2,389,14);
   rectangle(1,408,108,419);
   floodfill(2,409,14);

   setcolor(0);
   outtextxy(10,350,"Computers");
   outtextxy(2,370,"Local Disk C:");
   outtextxy(2,390,"Local Disk D:");
   outtextxy(2,410,"Local Disk E:");

   setcolor(15);
   setfillstyle(1,15);
   rectangle(9,438,70,449);
   floodfill(10,439,15);
   setcolor(4);
   outtextxy(10,440,"Network");


   setcolor(15);
   setfillstyle(1,15);
   rectangle(200,150,250,200);
   floodfill(201,151,15);
   rectangle(350,150,400,200);
   floodfill(351,151,15);
   rectangle(500,150,550,200);
   floodfill(501,151,15);
   rectangle(200,300,250,350);
   floodfill(201,301,15);
   rectangle(350,300,400,350);
   floodfill(351,301,15);

   setcolor(3);
   outtextxy(210,210,"Apps");
   outtextxy(345,210,"Documents");
   outtextxy(500,210,"Musics");
   outtextxy(200,360,"Pictures");
   outtextxy(350,360,"Videos");


   settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
   setcolor(4);
   outtextxy(210,140,"A");
   outtextxy(360,140,"D");
   outtextxy(510,140,"M");
   outtextxy(210,290,"P");
   outtextxy(360,290,"V");

   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();

   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove1(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown1(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp1(GetX(),GetY());
		}
   }
   //getch();
   //closegraph();
}


////////////////////////////DESKTOP/////////////////////////
void OnLButtonUp(int ,int ){ButtonStatus=0;}
void OnMouseMove(int ,int ,int ){}
Bool IsBetween(int x,int y)                  //IMPORTANT  Checking Click
{
   if(x>=20 && x<=47 && y>=40 && y<=62)
   {
      icon=1;
      return true;
   }
   else if(x>=20 && x<=47 && y>=115 && y<=137)
   {
      icon=2;
      return true;
   }
   else if(x>=25 && x<=45 && y>=195 && y<=215)
   {
      icon=3;
      return true;
   }
   else if(x>=15 && x<=45 && y>=250 && y<=280)
   {
      icon=4;
      return true;
   }
   else if(x>=15 && x<=45 && y>=340 && y<=370)
   {
      icon=5;
      return true;
   }
   else if(x>=120 && x<=150 && y>=30 && y<=60)
   {
      icon=6;
      return true;
   }
   else if(x>=120 && x<=150 && y>=110 && y<=140)
   {
      icon=7;
      return true;
   }
   else if(x>=120 && x<=150 && y>=180 && y<=210)
   {
      icon=8;
      return true;
   }
   else if(x>=120 && x<=150 && y>=250 && y<=280)
   {
      icon=9;
      return true;
   }
   else if(x>=120 && x<=150 && y>=340 && y<=370)
   {
      icon=10;
      return true;
   }
   else if(x>=2 && x<=28 && y>=450 && y<=476)
   {
      icon=11;
      return true;
   }
   else if(x>=45 && x<=72 && y>=452 && y<=474)
   {
      icon=12;
      return true;
   }
   else if(x>=80 && x<=107 && y>=452 && y<=474)
   {
      icon=13;
      return true;
   }
   else if(x>=115 && x<=141 && y>=450 && y<=476)
   {
      icon=14;
      return true;
   }
   else
   return false;
}

void OnLButtonDown(int x,int y)            //Checking Icon
{
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    if(IsBetween(x,y)==true&&icon==1)
    {
       icons1();
    }
    else if(IsBetween(x,y)==true&&icon==2)
    {
       icons2();
    }
    else if(IsBetween(x,y)==true&&icon==3)
    {
       icons3();
    }
    else if(IsBetween(x,y)==true&&icon==4)
    {
       closegraph();
       snake();
    }
    else if(IsBetween(x,y)==true&&icon==5)
    {
       closegraph();
       hangman();
    }
    else if(IsBetween(x,y)==true&&icon==6)
    {
       closegraph();
       tic();
    }
    else if(IsBetween(x,y)==true&&icon==7)
    {
       closegraph();
       taj();
    }
    else if(IsBetween(x,y)==true&&icon==8)
    {
       closegraph();
       solar();
    }
    else if(IsBetween(x,y)==true&&icon==9)
    {
       closegraph();
       char ch;
       fstream fout("log.txt",ios::in);
       while(!fout.eof())
       {
	  fout.get(ch);
	  if(fout.eof())
	  break;
	  if(ch==32)
	  cout<<" ";
	  else if(ch=='\n')
	  cout<<"\n";
	  cout<<ch;
      }
      getch();
      fout.close();
      windows();
    }
    else if(IsBetween(x,y)==true&&icon==10)
    {
       outtextxy(200,350,"MALFUNCTION OF PROGRAM, RESTART DOS");
    }
    else if(IsBetween(x,y)==true&&icon==11)
    {
       icons5();
    }
    else if(IsBetween(x,y)==true&&icon==12)
    {
       icons4();
    }
    else if(IsBetween(x,y)==true&&icon==13)
    {
       icons1();
    }
    else if(IsBetween(x,y)==true&&icon==14)
    {
       google();
    }
    else
    icon=0;
}

void windows()
{
   clrscr();
   time_t t;
   time(&t);

   ini();
   setbkcolor(5);
   rectangle(0,0,getmaxx(),getmaxy());
   //start bar
   setcolor(9);                        //(WORKING)
   setfillstyle(1,9);
   rectangle(0,450,getmaxx(),getmaxy());
   floodfill(300,452,9);

   setcolor(2);
   setfillstyle(1,2);
   circle(15,463,13);               //Start Symbol (WORKING)
   floodfill(6,456,2);
   setcolor(4);
   setfillstyle(1,4);
   circle(15,463,5);
   floodfill(15,463,4);


   setcolor(1);
   rectangle(45,452,72,474);    //Windows Media Player(WORKING)
   setcolor(12);
   setfillstyle(1,12);
   circle(58,463,12);
   floodfill(56,463,12);
   setcolor(15);
   setfillstyle(1,15);
   line(55,453,55,473);
   line(55,453,70,463);
   line(55,473,70,463);
   floodfill(60,463,15);

   setcolor(6);
   setfillstyle(1,6);
   rectangle(80,452,107,474);   //My Files(WORKING)
   floodfill(81,453,6);
   line(80,460,107,460);
   setcolor(1);
   setfillstyle(1,1);
   rectangle(83,460,104,474);
   floodfill(84,461,1);


   setcolor(13);
   setfillstyle(1,13);
   circle(128,463,13);        //Chrome (WORKING)
   floodfill(116,461,13);
   setcolor(1);
   setfillstyle(1,1);
   circle(128,462,5);
   floodfill(128,462,1);
   setcolor(4);
   line(128,457,140,457);
   setcolor(14);
   line(128,467,120,471);
   setcolor(2);
   line(123,465,118,457);

   setcolor(2);
   setfillstyle(1,2);
   rectangle(440,450,getmaxx(),getmaxy());           //Date and Time (WORKING)
   floodfill(441,451,2);
   setcolor(4);
   outtextxy(441,460,ctime(&t));

   ///////////////////////////////////////////Desktop

   setcolor(6);
   setfillstyle(1,6);
   rectangle(20,40,47,62);
   floodfill(21,41,6);
   line(20,48,47,48);            //My Files (WORKING)
   setcolor(1);
   setfillstyle(1,1);
   rectangle(23,48,44,62);
   floodfill(24,49,1);
   setcolor(15);
   outtextxy(10,65,"My Files");

   setcolor(15);
   setfillstyle(1,15);
   rectangle(20,115,47,137);
   floodfill(21,116,15);              //My Computer (WORKING)
   setcolor(0);
   outtextxy(25,119,"MY");
   outtextxy(30,128,"C");
   setcolor(15);
   rectangle(30,137,36,140);
   outtextxy(5,143,"My Computer");

   setcolor(7);
   setfillstyle(1,7);
   rectangle(25,195,45,215);         //Recycle Bin (WORKING)
   floodfill(26,196,7);
   setcolor(0);
   arc(35,195,190,355,10);
   setcolor(15);
   outtextxy(10,220,"Recycle Bin");

   setcolor(2);
   setfillstyle(1,2);
   rectangle(15,250,45,280);         //Snake Game (WORKING);
   floodfill(16,251,2);
   setcolor(4);
   outtextxy(20,255,"SG");
   setcolor(1);
   outtextxy(20,265,"");
   setcolor(15);
   outtextxy(10,290,"Snake Game");


   setcolor(4);
   setfillstyle(1,4);
   rectangle(15,340,45,370);         //Hangman (WORKING)
   floodfill(16,341,4);
   setcolor(14);
   outtextxy(20,345,"HM");
   setcolor(2);
   outtextxy(20,355,"");
   setcolor(15);
   outtextxy(10,380,"Hangman");

   setcolor(1);
   setfillstyle(1,1);
   rectangle(120,30,150,60);           //Tic-Tac-Toe  (WORKING)
   floodfill(121,31,1);
   setcolor(4);
   outtextxy(125,35,"TTT");
   setcolor(14);
   outtextxy(125,45,"");
   setcolor(15);
   outtextxy(95,65,"Tic-Tac-Toe");


   setcolor(14);
   setfillstyle(1,14);
   rectangle(120,110,150,140);         //Taj Mahal (WORKING)
   floodfill(121,111,14);
   setcolor(1);
   outtextxy(125,115,"TJM");
   setcolor(4);
   outtextxy(125,125,"");
   setcolor(15);
   outtextxy(110,143,"Taj Mahal");

   setcolor(6);
   setfillstyle(1,6);
   rectangle(120,180,150,210);         //Solar System (WORKING)
   floodfill(121,181,6);
   setcolor(14);
   outtextxy(125,185,"SS");
   setcolor(5);
   outtextxy(125,195,"");
   setcolor(15);
   outtextxy(120,220,"Solar");
   outtextxy(117,230,"System");

   setcolor(3);
   setfillstyle(1,3);
   rectangle(120,250,150,280);          //Car Race  (WORKING)
   floodfill(121,251,3);
   setcolor(4);
   outtextxy(125,255,"LOG");
   setcolor(6);
   outtextxy(125,265,"");
   setcolor(15);
   outtextxy(110,290,"Computer Log");

   setcolor(10);
   setfillstyle(1,10);
   rectangle(120,340,150,370);     //Snake & Ladder (WORKING)
   floodfill(121,341,10);
   setcolor(6);
   outtextxy(125,345,"CM");
   setcolor(0);
   outtextxy(125,355,"");
   setcolor(15);
   outtextxy(80,380,"Check Malfuction");

   setcolor(2);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   outtextxy(getmaxx()/2-80,getmaxy()/2-100,"WINDOWS");
   outtextxy(getmaxx()/2-25,getmaxy()/2-50,"20");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   ButtonStatus=0;
   ButtonMoveStatus=false;
   InitMouse();
   ShowMouse();
   PrevX=GetX();
   PrevY=GetY();
   while(!kbhit())
   {
		if(PrevX!=GetX() || PrevY!=GetY())
		{
			OnMouseMove(GetB(),GetX(),GetY());
			PrevX=GetX();
			PrevY=GetY();
		}
		else if(GetB()==1 && ButtonStatus==0)
		{
			OnLButtonDown(GetX(),GetY());
		}
		else if(GetB()==0 && ButtonStatus==1)
		{
			OnLButtonUp(GetX(),GetY());
		}
   }
   //getch();
   fstream fin("log.txt",ios::out|ios::app);
   fin<<pass<<" <- "<<"OUT"<<" <- "<<ctime(&t)<<"\n";
   fin.close();
   closegraph();
   exit(0);
}
void caution1()
{
   cprintf("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
   gets(pass);
}
void caution();
void did()
{

   time_t t;
   time(&t);


   char *str1="Sumit",*str2="NPSwamy",*str3="Anshul";
   if(remain==3||remain==2)
   {

       if((strcmpi(str1,pass)==0)||(strcmpi(str2,pass)==0)||(strcmpi(str3,pass)==0))
       {

	  fstream fin("log.txt",ios::out|ios::app);
	  fin<<pass<<" -> "<<"IN"<<" -> "<<ctime(&t)<<"\n";
	  fin.close();
       }
       else
       {

	  --remain;
	  caution();
       }

   }
   else if(remain==1)
   {
       if((strcmpi(pass,str1)==0)||(strcmpi(pass,str2)==0)||(strcmpi(str3,pass)==0))
       {

	  fstream fin("log.txt",ios::out|ios::app);
	  fin<<pass<<" -> "<<"IN"<<" -> "<<ctime(&t)<<"\n";
	  fin.close();
       }
       else
       {

	  cleardevice();
	  setcolor(2);
	  setfillstyle(2,2);
	  rectangle(0,0,getmaxx(),getmaxy());
	  floodfill(1,1,2);
	  setbkcolor(1);

	  outtextxy(getmaxx()/2-200,getmaxy()/2-100,"HARD DISK CRASHED");
	  getch();
	  exit(0);
       }

   }
   else if(remain==0)
   {

      cleardevice();
      setcolor(1);
      outtextxy(getmaxx()/2-200,getmaxy()/2-100,"HARD DISK CRASHED");
      getch();
      exit(0);
   }
   else
   remain=0;
}
void caution()
{
   char *wrong="1";
   char *wrong3="3";
   char *wrong2="2";

   ini();

   setbkcolor(14);
   rectangle(0,0,getmaxx(),getmaxy());
   setcolor(4);
   outtextxy(10,10,"CAUTION:- IMPORTANT FOR EVERYBODY");
   setcolor(1);
   outtextxy(20,30,"1) ALWAYS SHUTDOWN THE PROGRAM USING");

   setcolor(2);
   setfillstyle(1,2);
   circle(330,30,13);
   floodfill(320,30,2);

   setcolor(4);
   setfillstyle(1,4);
   circle(330,30,5);
   floodfill(330,30,4);

   setcolor(1);
   outtextxy(350,30,"IN THE START BAR.");
   outtextxy(20,50,"2) IF THE PROGRAM SHOWS ANY MALFUNCTON DURING RUN THEN,PRESS ANY KEY TO EXIT.");
   outtextxy(20,60,"3) DO NOT USE THE MOUSE POINTER RAPIDLY FOR CHANGING THE WINDOWS.");
   outtextxy(20,70,"4) IF PROGRAM IS NOT RUNNING PROPERLY THEN,EXIT THE PROGRAM AND RESTART DOS.");

   setcolor(5);
   outtextxy(150,100,"THIS PROGRAM IS FOR SPECIAL PERSONS OF MY LIFE");
   outtextxy(190,120,"1> NP Swamy (My Computer Teacher)");
   outtextxy(190,130,"2> All my FAMILY and FRIENDS");
   outtextxy(190,140,"3> ESPECIALL FOR MY LATE GRANDFATHER");
   setcolor(15);
   line(0,150,getmaxx(),150);
   setcolor(1);
   outtextxy(150,280,"PASSWORD:");
   setcolor(6);
   rectangle(220,265,420,290);
   if(remain==1)
   {

     outtextxy(250,310,"LEFT CHANCES: ");
     outtextxy(360,310,wrong);
   }
   else if(remain==2)
   {

     outtextxy(250,310,"LEFT CHANCES: ");
     outtextxy(360,310,wrong2);
   }
   else if(remain==3)
   {

     outtextxy(250,310,"LEFT CHANCES: ");
     outtextxy(360,310,wrong3);
   }
   setcolor(4);
   outtextxy(220,330,"WARNING! WARNING! WARNING!");
   outtextxy(50,350,"IF YOU TYPE 3 TIMES WRONG PASSWORD THEN YOU HARDISK WOULD BE CRASH");
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
   setcolor(2);
   outtextxy(200,200,"WINDOWS 20");
   caution1();
   did();

}

void intro()
{
   clrscr();
   ini();
   setcolor(5);
   line(250,150,450,150);
   line(250,150,220,300);
   line(450,150,420,300);
   line(220,300,480,300);
   line(450,150,480,300);

   setcolor(4);
   setfillstyle(1,4);
   rectangle(250,150,350,225);
   floodfill(251,151,4);

   setcolor(1);
   setfillstyle(1,1);
   rectangle(250,225,350,300);
   floodfill(251,226,1);

   setcolor(2);
   setfillstyle(1,2);
   rectangle(350,150,450,225);
   floodfill(351,151,2);

   setcolor(14);
   setfillstyle(1,14);
   rectangle(350,225,450,300);
   floodfill(351,226,14);

   setcolor(3);
   outtextxy(280,350,"Starting Windows");
   circle(260,450,6);
   outtextxy(257,446,"s");
   outtextxy(280,450,"Sumit Corporation");
   delay(5000);
   closegraph();
}
void main()
{
   clrscr();
   caution();
   intro();
   windows();
   getch();
}