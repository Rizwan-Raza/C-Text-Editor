#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include"rizzu\grphcs.h"
using namespace std;
void setConsole();
void HomePage();
    void TitleBar();
    void ToolBar();
    void Workspace();
    void StatusBar();
int getKey();
void insertion();
void savefile(char[500][150]);
void openfile(char[500][150]);

short int i=0,j=0,x=3,y=5;
char ch[500][150]={0};
short key,flag=0,down;

int main(int argc,char* argv[])
{
    setConsole();
    HomePage();
    textcolor(0);
    textbackground(15);
    for(gotoxy(x,y);down!=23;)
    {
        down=_getch();
        if(down >= ' ' && down <= '~' || down == 13)
        {
            if(flag)
            {
                i--;
                x--;
                flag=0;
            }
            if(down == 13)
                ch[i][j]='\n';
            else
            {
                ch[i][j]=down;
/*                while(ch[i+1][j])
                    insertion();*/
            }
        }
        if (down == 0 || down == 224)
        {
            key=_getch();
            if(key==75) //Left Key
            {
                x--;
                i--;
            }
            else if(key==77) //Right Key
            {
                x++;
                i++;
            }
            else if(key==72) //Up key
            {
                y--;
                j--;
            }
            else if(key==80) //Down Key
            {
                y++;
                j++;
            }
            gotoxy(x,y);
        }
        if(down==8 && (i > 0 || j > 0)) // Backspace key is pressed
        {
            if(i>0)
            {
                x--;
                i--;
                ch[i][j]=0;
            }
            else
            {
                i=0;
                x=0;
            }
            gotoxy(x,y);
            cout<<" ";
            gotoxy(x,y);
        }
        if(down >= ' ' && down <= '~' ) //If character is valid
        {
            gotoxy(x,y);
            cout<<(char)ch[i++][j];
            x++;
        }
        if(down==13)  //Enter key is Pressed For new Line
        {
            x=4;
            y++;
            i+=2;
            ch[i][j]='\n';
            i++;
            //i=0;
            //j++;
            gotoxy(x-1,y);
            flag=1;
        }
        if(down==19) //Saving  the file when Ctrl+S is pressed
            savefile(ch);
        if(down==15) //Opening  the file when Ctrl+O is pressed
            openfile(ch);
        if(down==14)
        {
            drawbgcolor(1,4,150,20,15,15);
            x=3,y=5;
            textcolor(0);
            gotoxy(x,y);
        }
    }
    gotoxy(3,20);
    textbackground(15);
    cout<<"Going to Exit...";
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
    setConSize(150,40);
    /*  Changing Font
    HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
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
    //ToolBar();
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
    cout<<"Rizwan's Editor";
}
void ToolBar()
{
    drawbgcolor(1,4,150,3,0,0);
    textcolor(15);
    gotoxy(3,5);
    cout<<(char)179<<" _ile "<<(char)179<<" _dit "<<(char)179<<" _earch "<<(char)179<<" _indow "<<(char)179<<" _elp "<<(char)179;
    textcolor(12);
    gotoxy(5,5);
    cout<<"F";
    gotoxy(12,5);
    cout<<"E";
    gotoxy(19,5);
    cout<<"S";
    gotoxy(28,5);
    cout<<"W";
    gotoxy(37,5);
    cout<<"H";
}
void Workspace()
{
    drawbgcolor(1,4,150,34,15,15);
}
void StatusBar()
{
    textcolor(0);
    textbackground(7);
    gotoxy(2,38);
    cout<<"Press Ctrl + W to Close current document";
    gotoxy(2,39);
    cout<<"Press Ctrl + S to Save current document";
    gotoxy(2,40);
    cout<<"Press Ctrl + O to Open existing document";
    gotoxy(125,39);
    cout<<"Created by Rizwan Raza.";
}
void insertion()
{
    if(ch[i+1][j]!=0)
    {
        ch[++i][j]=ch[i][j];
    }
}
void savefile(char ch[500][150])
{
    char filename[15];
    drawBox(50,19,100,26,1,15);
    drawbgcolor(51,20,49,6,7,7);
    drawBox(51,23,99,25,15,0);
    drawbgcolor(52,24,47,1,15,15);
    textbackground(1);
    gotoxy(75-strlen(" Saving File ")/2,19);
    cout<<" Saving File ";
    textcolor(0);
    textbackground(7);
    gotoxy(52,21);
    cout<<"Enter file Name: ";
    textbackground(15);
    textcolor(12);
    gotoxy(52,24);
    fflush(stdin);
    gets(filename);
    ofstream fout(filename);
//  cout<<endl<<"Data Written: "<<endl;
    for(int i=0;i<150;i++)
    {
        for(int j=0;j<500;j++)
        {
            if(ch[i][j]==13)
                fout<<endl;
            else if(ch[i][j])
                fout<<(char)ch[i][j];
            else
                break;
        }
    }
    drawbgcolor(50,19,52,8,15,15);
    gotoxy(52,39);
    textcolor(0);
    textbackground(7);
    cout<<"Data has been saved in "<<filename;
    textbackground(15);
    gotoxy(x,y);
}
void openfile(char ch[500][150])
{
    char filename[15];
    drawBox(50,19,100,27,1,15);
    drawbgcolor(51,20,49,7,7,7);
    drawBox(51,23,99,25,15,0);
    drawbgcolor(52,24,47,1,15,15);
    textbackground(1);
    gotoxy(75-strlen(" Opening File ")/2,19);
    cout<<" Opening File ";
    textcolor(0);
    textbackground(7);
    gotoxy(52,21);
    cout<<"Enter file Name: ";
    textbackground(15);
    textcolor(12);
    gotoxy(52,24);
    fflush(stdin);
    gets(filename);
    fstream file(filename,ios::out|ios::in);
    if(!file)
    {
        gotoxy(51,26);
        cout<<"The file can't open because it is not present";
    }
    else
    {
        int i;
        textcolor(0);
        drawbgcolor(50,19,52,9,15,15);
        gotoxy(52,39);
        textcolor(0);
        textbackground(7);
        cout<<"Data has been retrieved from "<<filename;
        textbackground(15);
        for(i=0;i<500;i++)
        {
            if(!file.eof())
            {
                file.getline(ch[i],150);
                gotoxy(3,5+i);
                cout<<ch[i];
            }
        }
        x=2+strlen(ch[i-2]);
        y=i-1;
    }
    gotoxy(x,y);
}
