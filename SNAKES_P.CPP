#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
struct snake{
int x,y;	       //x and y co-ordinates of the body of the snake
struct snake *next;
}*head,*snake_node;
struct food{
int x,y;               //x and y co-ordinates of food
}*f;
int score=0,flag=0;
void display_score();
void border();
void newgame();
void move_snake();
void display();
void delete_last();  //to delete the last node
void insert();
void insert_second();
void check();
void display_food();
void check_eat_food();
void main()
{
int gd=DETECT,gm=0;
initgraph(&gd,&gm,"c:\\TC\\BGI");
border();
f->x=((rand()%621)/10)*10;
f->y=((rand()%351)/10)*10;

newgame();
move_snake();
getch();
}

void border()
{
setcolor(RED);
int i,j=0;

for(i=0;i<620;i+=10)
{                               //to display horizontal lines of the boundary
outtextxy(i,j,"*");
outtextxy(i,j+350,"*");
}
j=0;
for(i=0;i<=350;i+=10)
{                              //to display the vertical lines of the boundary
outtextxy(j,i,"*");
outtextxy(j+620,i,"*");
}
}

void newgame()
{
struct snake *new_snake_node;
snake_node=(struct snake*)malloc(sizeof(struct snake));
snake_node->next=NULL;
snake_node->x=((rand()%250)/10)*10;
snake_node->y=((rand()%250)/10)*10;
head=snake_node;
int i;
outtextxy(head->x,head->y,"@");
for(i=10;i<=40;i+=10)
{
new_snake_node=(struct snake*)malloc(sizeof(struct snake));
new_snake_node->x=(head->x)+i;
new_snake_node->y=(head->y);
new_snake_node->next=NULL;
snake_node->next=new_snake_node;
snake_node=new_snake_node;
}
display();

}

void display()
{
int count=1;
struct snake *temp=head;
 while(temp!=NULL)
 {
 if(count==1)
 {
 outtextxy(temp->x,temp->y,"@");
 count++;
 }
 else{
 outtextxy(temp->x,temp->y,"#");
 }
 temp=temp->next;

 }//end of while


}//end of display function

void delete_last()
{
struct snake *temp,*t=head;
while(t->next!=NULL)
{
  temp=t;
  t=t->next;
}
temp->next=NULL;
outtextxy(t->x,t->y," ");
free(t);
}

void insert_second()
{
struct snake *newnode;
newnode=(struct snake*)malloc(sizeof(struct snake));
newnode->x=head->x;
newnode->y=head->y;
newnode->next=head->next;
head->next=newnode;

}
void move_snake(){
char key,pkey;
while(key!=27 && flag!=1)
{
if(kbhit() && flag!=1)
{

key=getch();
if(key=='a'&& pkey=='d')
key='d';
if(key=='w'&& pkey=='s')
key='s';
if(key=='d'&& pkey=='a')
key='a';
if(key=='s'&& pkey=='w')
key='w';

if(key=='a')
{pkey='a';
while(!kbhit() && flag!=1)
{
insert_second();
 head->x=(head->x)-10;
delete_last();
clrscr();
border();
display_score();
display();
check();
check_eat_food();
delay(100);
}
}

if(key=='w')
{pkey='w';
while(!kbhit() && flag!=1)
{
insert_second();
 head->y=(head->y)-10;
delete_last();
clrscr();
display_score();
border();
display();
check();
check_eat_food();
delay(100);
}
}

if(key=='d')
{pkey='d';
while(!kbhit() && flag!=1)
{
insert_second();
 head->x=(head->x)+10;
delete_last();
clrscr();
display_score();
border();
display();
check();
check_eat_food();
delay(100);
}
}

if(key=='s')
{pkey='s';
while(!kbhit() && flag!=1)
{
insert_second();
 head->y=(head->y)+10;
delete_last();
clrscr();
display_score();
border();
display();
check();
check_eat_food();
delay(100);
}
}

}

}//end of while

}


void check(){

struct snake *temp;
if(head->x >=620 || head->x <=0 || head->y <=0 || head->y>=350)
flag=1;
temp=head->next;
while(temp!=NULL)
{
if(temp->x == head->x && temp->y == head->y)
{ flag=1;

}
temp=temp->next;
}

if(flag==1)
{
clrscr();
outtextxy(310,175,"GAME OVER");
 char a[10];
 sprintf(a,"%d",score);
outtextxy(310,190,"score");
outtextxy(370,190,a);
}
}

void display_food(){
f->x=10+((rand()%610)/10)*10;
f->y=10+((rand()%340)/10)*10;

}



void check_eat_food(){
if(head->x==f->x && head->y==f->y)
{
insert();
display_food();
score+=9;

}
if(flag==0)
outtextxy(f->x,f->y,"F");

}
void insert()
{
struct snake *temp,*newnode;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
newnode=(struct snake*)malloc(sizeof(struct snake));
newnode->next=NULL;
temp->next=newnode;
}

void display_score()
{
   char a[10];
   sprintf(a,"%d",score);
outtextxy(110,370,"score");
outtextxy(250,360,"SNAKE GAME");
outtextxy(110,380,a);
outtextxy(450,370,"BY:-");
outtextxy(480,380,"VACHAN ANAND");
}

