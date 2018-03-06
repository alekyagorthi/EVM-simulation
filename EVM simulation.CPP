#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<fstream.h>
#include<graphics.h>
int d;
void read();
void write();
void modify();
int mock();
void result();
int start();
class vote
{
char pname[32],c;
public:
int noreg,b,vote;
int returnnoreg()
{
return(noreg);
}
void input()
{
cout<<"enter your party name \n";
gets(pname);
vote=0;
cout<<"enter your party symbol(in no)";
cin>>b;
c=b;
}
void output()
{
vote=0;
cout<<noreg<<"\t";
cout<<pname<<"\t\t";
cout<<c<<"\t\t";
cout<<vote<<endl;
}
void display()
{
cout<<noreg<<"\t";
cout<<pname<<"\t\t";
cout<<c<<"\n";
}
void getresult()
{
cout<<noreg<<"\t";
cout<<pname<<"\t\t";
cout<<c<<"\t\t";
cout<<vote<<"\n";
}
};
void main()
{
int ch;
char a[5];
start();
clrscr();
write();
clrscr();
read();
getch();
clrscr();
mock();
clrscr();
cout<<"enter password:";
for(int i=0;i<=4;i++)
{
a[i]=getch();
cout<<"*";
}

a[i]=NULL;
if(strcmp(a,"abcde")==0)
{
clrscr();
result();
getch();
}
else
exit(0);
}
void write()
{
vote v1[16];
fstream fout("party.dat",ios::out|ios::binary);
cout<<"enter no of registrations\n";int n;cin>>n;
for(int i=1;i<=n;i++)
{
v1[i].noreg=i;
v1[i].input();
fout.write((char*)&v1[i],sizeof(vote));
}

fout.close();
}
void read()
{
clrscr();
vote v1;
ifstream fin("party.dat",ios::binary);
cout<<"sn.no\t"<<"party\t\t"<<"party symbol\t"<<"vote\n";
while(fin.read((char*)&v1,sizeof(vote)))
{
v1.output();
}
fin.close();
}
void show()
{
clrscr();
vote v1;
ifstream fin("party.dat",ios::binary);
cout<<"sn.no\t"<<"party\t\t"<<"party symbol\n";
while(fin.read((char*)&v1,sizeof(vote)))
{
v1.display();
}
fin.close();
}
void modify()
{
int pos;
fstream file1("party.dat",ios::in|ios::out|ios::binary);
vote v1;
while(file1.read((char*)&v1,sizeof(vote)))
{
  if(v1.returnnoreg()==d)
	{
	int pos=(-1)*sizeof(vote);
	v1.vote++;
	file1.seekp(pos,ios::cur);
	file1.write((char*)&v1,sizeof(vote));
  }
}
file1.close();
}
int mock()
{

clrscr();
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "..//bgi");
errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
setbkcolor(WHITE);
setcolor(RED);
settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(SANS_SERIF_FONT , HORIZ_DIR,8);
outtextxy(300, 200, "ELECTIONS");
getch();
closegraph();
char a;
for (int i=0;i<30;i++)
{
clrscr();
cout<<"Is there a voter (y/n)";
cin>>a;
if(a=='y')
{
show();
cout<<"\n enter sn no. of the party u want to vote \n";
cin>>d;
modify();
}
else
{
return(0);
}

 }
}
void result()
{
clrscr();
vote v1;
ifstream fin("party.dat",ios::binary);
cout<<"sn.no\t"<<"party\t\t"<<"party symbol\t"<<"vote\n";
while(fin.read((char*)&v1,sizeof(vote)))
{
v1.getresult();
}
fin.close();
}

int start()
{

   int gdriver = EGA, gmode = EGAHI, errorcode;
   int bkcol, maxcolor, x, y;
   char msg[80];
   initgraph(&gdriver, &gmode, "..//bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   maxcolor = getmaxcolor();
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   x = getmaxx() / 2;
   y = getmaxy() / 2;
   cleardevice();
   setbkcolor(WHITE);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(GOTHIC_FONT, HORIZ_DIR,5);
   setcolor(BLUE);
   sprintf(msg, "EVM");
   outtextxy(325, 125, msg);
   sprintf(msg, "Electronic Voting Machine");
   outtextxy(325, 175, msg);

   getch();
   closegraph();
   return 0;
}