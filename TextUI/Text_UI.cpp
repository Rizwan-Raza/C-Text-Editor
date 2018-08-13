#include<iostream>
#include<conio.h>
#include<string.h>
#include"rizzu\grphcs.h"
#include<windows.h>
#include<wincon.h>
using namespace std;
void setConsole();
void HomePage();
    void TitleBar();
    void ToolBar();
    void Workspace();
    void StatusBar();
int getKey();
class Window
{
private:
    COORD pos;
    SIZE res;
    unsigned short bc;
    unsigned short fc;
    char title[20];
public:
    Window(int x = 1,int y = 1,int l = 80,int h = 24,int b = 15,int f = 0,const char* t = "Raza")
    {
        pos.X=x;
        pos.Y=y;
        res.cx=l;
        res.cy=h;
        bc=b;
        fc=f;
        strcpy(title,t);
        drawWindow();
    }
    void setWndStyle(int xx,int yy,int ll,int hh,int bb,int ff,const char* tt)
    {
        pos.X=xx;
        pos.Y=yy;
        res.cx=ll;
        res.cy=hh;
        bc=bb;
        fc=ff;
        strcpy(title,tt);
    }
    void drawWindow()
    {
        drawBox2(pos.X,pos.Y,pos.X+res.cx,pos.Y+res.cy,bc,fc);
        drawbgcolor(pos.X+1,pos.Y+1,res.cx-1,1,bc,bc);
        strcat(title," - Rizwan's Editor");
        int len=strlen(title);
        gotoxy(pos.X+(res.cx-len)/2,pos.Y+1);
        textcolor(15);
        printf(title);
        drawXline212(pos.X,pos.Y+2,res.cx-1,bc,fc);
        drawbgcolor(pos.X+1,pos.Y+3,res.cx-1,1,7,7);
        gotoxy(pos.X+2,pos.Y+3);
        textcolor(0);
        printf("_ile  _dit  _earch  _indow  _elp");
        textcolor(12);
        gotoxy(pos.X+2,pos.Y+3);
        printf("F");
        gotoxy(pos.X+8,pos.Y+3);
        printf("E");
        gotoxy(pos.X+14,pos.Y+3);
        printf("S");
        gotoxy(pos.X+22,pos.Y+3);
        printf("W");
        gotoxy(pos.X+30,pos.Y+3);
        printf("H");
        drawbgcolor(pos.X+1,pos.Y+4,res.cx-1,res.cy-4,15,15);
        drawbgcolor(pos.X+res.cx+1,pos.Y+2,1,res.cy-1,8,8);
        drawbgcolor(pos.X+2,pos.Y+res.cy+1,res.cx,1,8,8);
    }
};
int main(int argc,char* argv[])
{
    setConsole();
    HomePage();
    Window Main(10,15,100,25,1,15,"Menu 1"),Main2(20,5,100,25,1,15,"Menu 1");
    textcolor(0);
    textbackground(7);
    gotoxy(5,5);
    int ch=getch();
    printf("%d",ch);
    getch();
    return 0;
}
int getKey() //Returns scan code of the key that has been hit
{
	int ch;
    ch = _getch ();
    if (ch == 0 || ch == 224)
    {
        return _getch ();
    }
    else return 0;
}
void setConsole()
{
    setConSize(150,45);
 /*   HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX font;
    GetCurrentConsoleFontEx(outcon, false, &font);
    font.dwFontSize.X = 4;
    font.dwFontSize.Y = 6;
    SetCurrentFontEx();*/
    BFColor('7','0');
}
void HomePage()
{
    TitleBar();
    ToolBar();
    Workspace();
    StatusBar();
}
void TitleBar()
{
    int p=(150-strlen("Rizwan's Editor"))/2;
    drawBox(1,1,150,3,1,15);
    drawbgcolor(2,2,148,1,1,1);
    gotoxy(p,2);
    textcolor(15);
    printf("Rizwan's Editor");
}
void ToolBar()
{
    drawbgcolor(1,4,150,3,0,0);
    textcolor(15);
    gotoxy(5,5);
    printf("_ile   _dit   _earch   _indow   _elp");
    textcolor(12);
    gotoxy(5,5);
    printf("F");
    gotoxy(12,5);
    printf("E");
    gotoxy(19,5);
    printf("S");
    gotoxy(28,5);
    printf("W");
    gotoxy(37,5);
    printf("H");
}
void Workspace()
{
    drawBar(1,7,150,38,7,1,176);
}
void StatusBar()
{
    gotoxy(125,45);
    printf("Created by Rizwan Raza.");
}
