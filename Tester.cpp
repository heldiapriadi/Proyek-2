#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;


int positionX=5,positionY=5,veloX=1,veloY=0;
int xHapus=3,yHapus=3,ekorsX[200], ekorsY[200],nEkor = 2;
COORD coord={0,0};
void gotoxy(int x,int y)
{
    COORD pos = {x, y};  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

void setcolor (unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void tampil() 
{  
	gotoxy(positionX,positionY); //iX dan iY adalah posisi gambar kepala  
	cout << char(254); //untuk menggambar gambar kepala   
	//nilai makX dan makY adalah random  
} 

void ganti_posisi() //mengganti posisi dari ekor ekor snake 
{  
	xHapus = ekorsX[nEkor - 1];  
	yHapus = ekorsY[nEkor - 1];  
	for(int j = nEkor - 1; j >= 1; j--)  
	{	   
		ekorsX[j] = ekorsX[j-1];   
		ekorsY[j] = ekorsY[j-1];  
	}   
	ekorsX[0] = positionX;   
	ekorsY[0] = positionY; 
} 

void hapus() 
{  
	gotoxy(xHapus, yHapus); //untuk menghapus bagian yang sudah dilewati  
	cout << " "; 
} 

void velo() //fungsi untuk melakukan update posisi snake sesuai tombol 
//yang ditekan 
{      
	ganti_posisi();
	hapus();
	positionX += veloX;  
	positionY += veloY;  
	tampil(); 
} 

void atas() //untuk gerak Snake ke atas 
{   
	veloY = -1;
	veloX = 0; 
} 

// untuk ular kebawah
void bawah() 
{   
	veloY = 1; 
	veloX = 0; 
} 

// untuk ular ke samping kiri
void kiri() 
{   
	veloX = -1; 
	veloY = 0; 
} 

// untuk ular ke samping kanan
void kanan() 
{   
	veloX = 1; 
	veloY = 0; 
} 
void controller(){
	for(int i = 8; i <= 222; i++)  
	{   
		if(GetAsyncKeyState(i) == -32767)   
		{    
			switch(i)    
			{		     
				case 38 : if(veloY != 1)atas();              
				break;
				case 40 : if(veloY != -1)bawah();               
				break;
				case 37 : if(veloX != 1)kiri();               
				break;
				case 39 : if(veloX != -1)kanan();               
				break;
			}   
		}  
	} 
}



int main()
{
	while(1){
		velo();
		controller();
		Sleep(90);
	}
}
