#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<time.h>
#include<conio.h>

bool gameOver;
bool stop=false;
bool hit = false;

const int width=50;
const int height =20;

int x,y,fruitX,fruitY,score;

int tailX[200],tailY[200];

int ntail =3;

typedef enum
{
	STOP =0,
	LEFT,
	RIGHT,
	UP,
	DOWN
	
}Direction;

Direction Dir;

void menu()
{
	int a;
	printf("-----------------------------\n");
	printf("|          贪吃蛇游戏         |\n");
	printf("|          (1)新游戏          |\n");
	printf("|          (2)游戏边界        |\n");
	printf("|          (3)退出游戏        |\n");
	printf("------------------------------\n");
	printf("---->请输入你的选择:");
	scanf("%d",&a);
	
}

void setup()
{
	gameOver=false;
	
	srand(time(NULL));
	Dir=STOP;
	
	x=width/2;
	y=height/2;
	
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
}
void draw()
{
	if(stop==true)
	{
		return ;
	}
	
	system("cls");
	printf("分数:%d",score);
	printf("\n");
	
	int i;
	for(i=0;i<width+1;i++)
	{
		printf("-");
	}
	printf("\n");
	
	
	int p;
	for(p=0;p<height;p++)
	{
		int q;
		for(q=0;q<width;q++)
		{
			if(q==0 || q==width-1)
			{
				printf("|");
			}
			if(p==fruitY && q==fruitX)
			{
				printf("0");
			}
			else {
				int k=0;
				bool print =false;
				for(k=0;k<ntail;k++)
				{
					if(tailX[k]==q && tailY[k]==p)
					{
						printf("*");
						print=true;
					}
				}
				if(!print){
					printf(" ");
				}
			}
			
		}
	printf("\n");
	}
	int j;
	for(j=0;j<width+1;j++)
	{
		printf("-");
	}
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case '4':
	        case 75:
	        	Dir=LEFT;
	        	hit =true;
	        	break;
		
		case '8':
			case 72:
				Dir= UP;
				hit =true;
				break;
				case '6':
				     case 77:
				     	Dir=RIGHT;
				     	hit =true;
				     	break;
				     	case '2':
				     		case 80:
				     			Dir=DOWN;
				     			hit =true;
				     			break;
				     			case 'x':
				     				case 27:
				     					gameOver=true;
				     					break;
				     					case 32:
				     						stop=!stop;
				     						break;} 
	}
	else if(!hit && stop==false)
	{
		x++;
	}
	
	
}


void logic()
{
	if(stop == true)
	{
		return;
	}
	
	int lastX=tailX[0];
	int lastY=tailY[0];
	int last2X,last2Y;
	tailX[0]=x;
	tailY[0]=y;
	int i=0;
	for(i=0;i<ntail;i++)
	{
		last2X=tailX[i];
		last2Y=tailY[i];
		tailX[i]=lastX;
		tailY[i]=lastY;
		lastX=last2X;
		lastY=last2Y;
	}
	switch(Dir)
	{
		case UP:
			y--;
			break;
			case DOWN:
				y++;
				break;
				case LEFT:
					x--;
					break;
					case RIGHT:
						x++;
					break;
	}
	if(x<0 || width<x || y<0||height<y)
	{
		gameOver=true;
		system("cls");
		printf("------------------------------------\n");
		printf("|                                    |\n");
		
		
		printf("                游戏结束                      \n");
			printf("|                                    |\n");
			printf("|                                    |\n");
			printf("|                                    |\n");
			
	}
			if(x==fruitX && y==fruitY)
			{
				ntail++;
				score+=10;
				
				fruitX=rand()%width;
				fruitY=rand()%height;
			}
	}
	

int main()
{
	#if 0
	
	
	while(1)
	{
		printf("%d\n",_getch());
	}
	#endif
	menu();
	setup();
	draw();
	
	while(!gameOver)
	{
		draw();
		input();
		logic();
		Sleep(70);
		
		
	}
	return 0;
}




