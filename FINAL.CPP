#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

class vigenere
{    public:
     int o,k,i,f,b[30],c[30],d[30],g[30];
     char j,a[30],n[30],e[30];
     void pass(char *a,int max)
     {
	char ch;
	int x=0;
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			a[x]='\0';
			break;
		}
		if(ch==8 && x!=0)
		{
			cout<<"\b \b";
			if(x<=max && x>0)
			x--;
		}
		else
		if(x<max && ch!=8)
		{
			cout<<"*";

			a[x]=ch;
			x++;
		}
	}
}
	int so(int z,int v)
	{
	   sound(z);
	   delay(v);
	   nosound();
	   return 0;
	}
void menu()
{
	gotoxy(33,1);
	cout<<"VIGENERE CIPHER"<<endl;
	gotoxy(35,6);
	cout<<"1.ENCRYPT"<<endl;
	gotoxy(35,12);
	cout<<"2.DECRYPT"<<endl;
	gotoxy(35,18);
	cout<<"3.SHOW TABLE"<<endl;
	gotoxy(59,25);
	cout<<"Press ESC key to EXIT";
}
void ptr()
{
	vigenere v1;
	textmode(C80);
	textbackground(BLUE);
	textcolor(WHITE);
	int x=33,y=6,ch;
	char a;
	meh:
	while(1)
	{
		clrscr();
		v1.menu();
		gotoxy(x,y);
		cout<<"->";
		gotoxy(1,25);
		ch=getch();
		switch(ch)
		{
			case 72:
			{
				v1.so(330 ,100);
				y-=6;
				if(y<6)
				{
					y=18;
				}
				break;
			}
			case 80:
			{
				v1.so(330,100);
				y+=6;
				if(y>18)
				{
					y=6;
				}
				break;
			}
			case 13:
			{
				if(y==6)
				{
					v1.so(440,200);
					clrscr();
					cout<<"INSTRUCTIONS:-"<<endl;
					cout<<"->WRITE MESSAGE WITHOUT SPACE."<<endl;
					cout<<"->ENJOY AND DONT USE IT FOR ILLEGAL PURPOSES."<<endl;
					v1.encrypt();
					getch();
				}
				if(y==12)
				{
					v1.so(440,200);
					clrscr();
					cout<<"INSTRUCTIONS:-"<<endl;
					cout<<"->WRITE MESSAGE WITHOUT SPACE."<<endl;
					cout<<"->ENJOY AND DONT USE IT FOR ILLEGAL PURPOSES."<<endl;
					v1.decrypt();
					getch();
				}
				if(y==18)
				{
					v1.so(540,200);
					clrscr();
					v1.showtable();
					getch();
				}
			}
			case 27:
			{
				so(540,200);
				exit(1);
				break;
			}
		}
	}
}
	void showtable()
	{
		vigenere v1;
		cout<<"\n\n"<<endl;
		for(i=97;i<=122;++ i)
		{
			cout<<(char)i<<"="<<i-97<<"\t"<<"|";
		}
		cout<<endl;
		getch();
		v1.ptr();
	}
	void encrypt()
	{
		vigenere v1;
		gotoxy(22,6);
		cout<<"Enter the keyword :";
		gets(a);
		f=strlen(a);
		gotoxy(22,7);
		//cout<<"KEYWORD LENGTH="<<f;
		for(k=0;k<f;k++)
		{
			b[k]=(int)a[k]-97;
		}
		cout<<endl;
		gotoxy(22,8);
		cout<<"Enter the MESSAGE :";
		gets(n);
		o=strlen(n);
		gotoxy(22,9);
      //cout<<"MESSAGE length :"<<o;
      for(i=0;i<o;++i)
      {
	   c[i]=(int)n[i]-97;
      }
      k=0;
      k=o/f;
      for(i=f,j=0;i<o;i++,j++)
	  {
		b[i]=b[j];
	  }
      for(i=0;i<o;++i)
      {
	   d[i]=c[i]+b[i];
      }
      cout<<endl;
      for(i=0;i<o;++i)
      {
	    if(d[i]>=26)
	    {
	     d[i]=d[i]-26;
	    }
      }
      for(i=0;i<o;++i)
      {
	  g[i]=d[i]+97;
      }
      cout<<endl;
      gotoxy(22,10);
      cout<<"ENCRYPTED=";
      gotoxy(22,11);
      for(i=0;i<o;++i)
      {
	  cout<<(char)g[i]<<" ";
      }
      getch();
      v1.ptr();
    }
     void decrypt()
    {
	vigenere v1;
	gotoxy(22,6);
      cout<<"Enter the keyword :";
      gets(a);
      f=strlen(a);
      gotoxy(22,7);
      //cout<<"KEYWORD LENGHT="<<f<<endl;
      for(k=0;k<f;k++)
      {
       b[k]=(int)a[k]-97;
      }
      gotoxy(22,8);
      cout<<"Enter the ENCRYPTED line :";
      gets(n);
      o=strlen(n);
      gotoxy(22,9);
      //cout<<"LINE lenght :"<<o<<endl;
      for(i=0;i<o;++i)
      {
	   c[i]=(int)n[i]-97;
      }
      k=0;
      k=o/f;
      for(i=f,j=0;i<o;i++,j++)
	  {
		b[i]=b[j];
	  }
      for(i=0;i<o;++i)
      {
	   if(b[i]>c[i])
	   {
	    d[i]=b[i]-c[i];
	    d[i]=26-d[i];
	   }
	   else
	   {
	    d[i]=c[i]-b[i];
       }
      }
      gotoxy(22,10);
      cout<<"DECRYPTED:";
      for(i=0;i<o;++i)
      {
	   d[i]=d[i]+97;
      }
      gotoxy(22,11);
      for(i=0;i<o;++i)
      {
	   cout<<(char)d[i]<<" ";
      }
	getch();
	v1.ptr();
    }
};
void main()
{    vigenere v1;
     textmode(C80);
     int ch,s,p,count=5;
     textbackground(BLUE);
     textcolor(WHITE);
     char u[15],ps[11],paco[5]="yeah";
	m:
	clrscr();
	cout<<endl;
	cout<<"ENTER THE USERNAME -> ";
	gets(u);
	cout<<"Enter the PASSWORD -> ";
	v1.pass(ps,10);
	cout<<endl<<endl;
	if(strcmpi(ps,paco)==0 && count>0)
	{
		clrscr();
		v1.so(650,200);
		gotoxy(30,12);
		cout<<"WELCOME "<<u<<" "<<endl;
		getch();
		v1.ptr();
	}
	else
	{
		count--;
		v1.so(330,200);
		cout<<"INCORRECT PASSWORD..RETRY..!-> "<<count<<endl;
		if(count<1)
		{
			clrscr();
			v1.so(540,250);
			cout<<"BYE BYE"<<endl;
			getch();
			exit(1);
		}
		getch();
		goto m;
	}
	clrscr();
	getch();
}
