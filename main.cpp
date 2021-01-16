#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int width=40, height=25;
int scor=0;

bool GameOver=false;
bool fire=false;

struct player
{
    int x,y;
};

struct player caracter, inamic;

struct proiectil
{
    int x,y;
};

struct proiectil bomb, lansare;

enum Directii
{
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

Directii dir, dir_bomb;

void Draw ()
{
    system("cls");
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
                cout<<"#";
            else if (i==caracter.y && j==caracter.x)
                cout<<"O";
            else if (i==inamic.y && j==inamic.x)
                cout<<"X";
            else if (i==bomb.y && j==bomb.x)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

void bomba ()
{
    if(fire)
    {
        switch (dir_bomb)
        {
        case LEFT:
            bomb.x-=2;
            break;
        case RIGHT:
            bomb.x+=2;
            break;
        case UP:
            bomb.y-=2;
            break;
        case DOWN:
            bomb.y+=2;
            break;
        case STOP:
            break;
        }
    }
}

void Input ()
{
    if(_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir=LEFT;
            if(!fire && dir!=STOP)
                dir_bomb=LEFT;
            break;
        case 's':
            dir=DOWN;
            if(!fire && dir!=STOP)
                dir_bomb=DOWN;
            break;
        case 'd':
            dir=RIGHT;
            if(!fire && dir!=STOP)
                dir_bomb=RIGHT;
            break;
        case 'w':
            dir=UP;
            if(!fire && dir!=STOP)
                dir_bomb=UP;
            break;
        case 'e':
            dir=STOP;
            break;
        case 'p':
            GameOver=true;
        case ' ':
            if(!fire && dir!=STOP)
            {
                fire=true;
                bomb.x=caracter.x;
                bomb.y=caracter.y;
                lansare.x=caracter.x;
                lansare.y=caracter.y;
            }
            break;
        }
    }
}

void reset_bomb ()
{
    bomb.x=-1;
    bomb.y=-1;
    fire=false;
}

void reset_enemy ()
{
    inamic.x=rand()%34+3;
    inamic.y=rand()%19+3;
}

bool close ()
{
    if(inamic.x>=caracter.x-2 && inamic.x<=caracter.x+2 && inamic.y<=caracter.y+2 && inamic.y>=caracter.y-2)
        return true;
    return false;
}

void Logic ()
{
    switch(dir)
    {
    case UP:
        if(caracter.y!=1)
        {
            caracter.y--;
            break;
        }
    case RIGHT:
        if(caracter.x!=width-2)
        {
            caracter.x++;
            break;
        }
    case DOWN:
        if(caracter.y!=height-2)
        {
            caracter.y++;
            break;
        }
    case LEFT:
        if(caracter.x!=1)
        {
            caracter.x--;
            break;
        }
    case STOP:
        break;
    }
    if(caracter.x==1 || caracter.x==width-2 || caracter.y==1 || caracter.y==height-2)
        dir=STOP;
    if(bomb.x<=1 || bomb.x>=width-1 || bomb.y<=1 || bomb.y>=height-1)
        reset_bomb();
    if((lansare.x==inamic.x && bomb.y<=inamic.y+1 && bomb.y>=inamic.y-1) || (lansare.y==inamic.y && bomb.x<=inamic.x+1 && bomb.x>=inamic.x-1))
    {
        reset_enemy();
        while(close())
            reset_enemy();
        reset_bomb();
        scor++;
    }
    if(caracter.x==inamic.x && caracter.y==inamic.y)
        GameOver=true;
}

int main()
{
    srand(time(NULL));
    caracter.x=10;
    caracter.y=10;
    reset_bomb();
    reset_enemy();
    while(close())
        reset_enemy();
    while(!GameOver)
    {
        Draw();
        Input();
        Logic();
        bomba();
        Sleep(20);
    }
    cout<<endl<<"FINAL SCORE: "<<scor;
    return 0;
}
