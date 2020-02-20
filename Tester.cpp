#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <iostream>


#define LEFT 4
#define RIGHT 2
#define UP 1
#define BOTTOM 3

using namespace std;


//Snake position
int positionX=20,positionY=20;
int direction;

//Value of body snake



COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setcolor (unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

struct Snake{
	//menampung integer umur
	int value;
	//menampung alamat dari data selanjutnya dan sebelumnya
	Snake *next, *prev;
}*head, *tail, *current;

void pushTail(int value){
	//membuat blok data baru
	current = (struct Snake *)malloc(sizeof (Snake));
	//mengisi data
	current->value = value;
	//membuat penunjuk data lain menjadi NULL terlebih dahulu
	current->prev = current->next = NULL;

	//jika tidak ada data
	if(head==NULL){
		//maka akan jadi data pertama, head dan tail akan sama dengan data baru
		head=tail=current;
	//jika ada data
	}else{
		//pergantian tail menjadi data terbaru
		current->prev = tail;
		tail->next = current;
		tail = current;
	}
}



void move(int dx, int dy)
{
	int newx = positionX + dx;
	int newy = positionY + dy;
	
	positionX = newx;
	positionY = newy;
}

// Initializes game
void InitGame()
{
	for(int i=0;i<3;i++)
	{
		cout << "O";
	}
}

void SnakeRun()
{
//	xHapus = ekorsX[nEkor - 1];  
//	yHapus = ekorsY[nEkor - 1];  
//	for(int j = nEkor - 1; j >= 1; j--)  
//	{	   
//		ekorsX[j] = ekorsX[j-1];   
//		ekorsY[j] = ekorsY[j-1];  
//	}   
//	ekorsX[0] = iX;   
//	ekorsY[0] = iY;
}

void update()
{
	switch (direction) {
    case UP:  move(0, -1); //up
        break;
    case RIGHT: move(2, 0); //right
        break;
    case BOTTOM: move(0, 1); //bottom
        break;
    case LEFT: move(-2, 0); //left
        break;
    }	
}

void Controller (char key)
{
	/*
      W
    A + D
      S

      1
    4 + 2
      3
    */
			switch(key)
			{
				case 's' :
				{
					if(direction!=UP) direction =  3;
					break;
				} //down
				case 'w' :
				{
					if(direction!=BOTTOM) direction = 1;
					break;
				} //up
				case 'a' :
				{
					if(direction!=RIGHT) direction = 4;
					break;
				} //left
				case 'd' :
				{
					if(direction!=LEFT) direction = 2;
					break;
				} //right
			}
}

void Start()
{
	Controller('d');
	gotoxy(20,20);
	InitGame();
	while(1)
	{
		if (kbhit()) {
            // Change to direction determined by key pressed
            (Controller(getch()));
        }
        update();
//        gotoxy(positionX,positionY);
//        cout << "O";
		
        if(direction == UP || direction == BOTTOM)
        {
        	Sleep(150);
		}
		else
		{
			Sleep(100);	
		}
		
	}
}

int main()
{
	Start();
}
