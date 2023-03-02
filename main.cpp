#include<iostream>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<time.h>
using namespace std;
int option_check=0;//to store the user stroke key to perform the operation of time
int day_check=0; //to store the option for am and pm
char day[7][4]={"sun","mon","tue","wed","thu","fri","sat"};
char mon[12][4]={"bai","jes","asa","sra","bha","aso","kar","man","pou","mag","fal","cha"};
char meridian[2][3]={"AM","PM"};
char arr[15];//to display user time format
char arr1[50][4];//to display user date format
 void option_display()
 { setcolor(GREEN);
 settextstyle(0,HORIZ_DIR,2);
   outtextxy(0,(getmaxy()/2)+55,"1.LOCAL TIME 2.GM TIME 3.SET TIME AND DATE 4.EXIT");
}

    class S_TIME
{
private:
     struct tm t,*local,*gm ;
     time_t tme,new_time;
     char str[100];
public:
     void local_time();
	  void GM_display();
};
void S_TIME::local_time()
	   {
	   while(!_kbhit())
	   {
		 tme=time(NULL);
     local=localtime(&tme);
		 cleardevice();
		 option_display();
		  setcolor(11);
	 outtextxy(0,0,".....LOCAL TIME......");
		 strftime(str,100,"%H:%M:%S",local);
         settextstyle(6,HORIZ_DIR,7);
         outtextxy(150,100,str);


          strftime(str,100,"%p",local);
           settextstyle(6,HORIZ_DIR,2);
           outtextxy(500,100,str);


    strftime(str,100,"%a ,%d %b ,%Y",local);
      setcolor(11);
	 settextstyle(6,HORIZ_DIR,4);
	 outtextxy(150,180,str);
    Sleep(1000);
	   } option_check=_getch();

     }
      void S_TIME::GM_display()
	  {  while(!_kbhit())
	     { tme=time(NULL);
	    gm=gmtime(&tme);
	    cleardevice();
	    option_display();
		   setcolor(11);
		    outtextxy(0,0,".......GM TIME......");
		strftime(str,100,"%H:%M:%S",gm);
      settextstyle(6,HORIZ_DIR,7);
	 outtextxy(150,100,str);

      strftime(str,100,"%p",gm);
           settextstyle(6,HORIZ_DIR,2);
           outtextxy(500,100,str);

      strftime(str,100,"%a ,%d %b ,%Y",gm); setcolor(11);
      settextstyle(6,HORIZ_DIR,4);
	 outtextxy(150,180,str);

      Sleep(1000);}
      option_check=_getch();

	      }
 class user_time
  { private:
	int h,m,s,i,j,ap;//i and j are for the increment in day and month while ap for the increment in meridian scale...
	int date,year;

	public:

	void set_time();
	void set_date();
	void select_day();
	void select_month();
	void time_display();

 };
      void user_time:: set_time()
	{system("cls");
		 cout<<"\t\t\t\t.........ENTER TIME........"<<endl;
	  do{
		   cout<<"HOUR=";cin>>h;
		   if(h<0||h>11)
		   { cout<<"...OUT OF SCOPE....";
		   }
	}while(h<0||h>11);
	    do{
		cout<<"MIN=";cin>>m;
		if(m<0||m>59){
		cout<<".....OUT OF SCOPE...";
		}
	}while(m<0||m>59);

		do{
		cout<<"SEC=";cin>>s;
		if(s<0||s>59)
		{ cout<<"....OUT OF SCOPE...";
		}
		}while(s<0||s>59);
		  cout<<"1.AM"<<endl<<"2.PM"<<endl;
		 do{
		 cin>>ap;
		 if(ap<1 &&ap>2)
		 { cout<<"......INVALID ENTRY......";
		 }
	} while(ap<1 && ap>2);
	}
	 void user_time::set_date()
		{ system("cls");
		  cout<<"\t\t\t\t.........ENTER DATE........."<<endl;
		    select_day();
		    cout<<day[i-1];
		    cout<<endl<<"DATE=";
			  do{
			  cin>>date;
			  if(date<1||date>30)
			  {cout<<".......OUT OF SCOPE.....";}
		}while(date<1||date>30);
			  select_month();
			cout<<endl<<mon[j-1];
			cout<<endl<<"YEAR=";
			  do{
			  cin>>year;
	      if(year<1990)
			  {cout<<"......OUT OF SCOPE.....";}
		}while(year<1990);
	    }


	    void user_time::select_day()
	    { cout<<"\t\t\t\t.......CHOOSE YOUR DAY......";
	      cout<<endl<<"1.SUNDAY";
			cout<<endl<<"2.MONDAY";
			cout<<endl<<"3.TUESDAY";
			cout<<endl<<"4.WEDNESDAY";
			cout<<endl<<"5.THIRSDSY";
			cout<<endl<<"6.FRIDAY";
			cout<<endl<<"7.SATURDAY"<<endl;
			do{
			 cin>>i;
			 if(i<1 || i>7)
			 { cout<<".....INVALI ENTRY....CHOOSE VALID ONE..." ;
			 }
		}while(i<1||i>7);
		  }

		   void user_time::select_month()
			     { cout<<"\t\t\t\t.......CHOOSE YOUR MONTH.....";
	      cout<<endl<<"1.BAISAKH";
			cout<<endl<<"2.JESTHA";
			cout<<endl<<"3.ASAR";
			cout<<endl<<"4.SHRAWAN";
			cout<<endl<<"5.BHADRA";
			cout<<endl<<"6.ASHOJ";
			cout<<endl<<"7.KARTIK";
			cout<<endl<<"8.MANGSIR";
			cout<<endl<<"9.POUSH";
			cout<<endl<<"10.MAGH";
			cout<<endl<<"11.FALGUN";
			cout<<endl<<"12.CHAIT"<<endl;
			do{
			 cin>>j;
			 if(j<1 || j>12)
			 { cout<<".....INVALI ENTRY....CHOOSE VALID ONE..." ;
			 }
		}while(j<1||j>12);
		  }


	    void user_time::time_display()
	       {while(!_kbhit())
		  { cleardevice();
		  option_display();
		   setcolor(11);
     outtextxy(0,0,".....USER TIME AND DATE......");
       sprintf(arr,"%d:%d:%d",h,m,s);
         settextstyle(6,HORIZ_DIR,7);
         outtextxy(150,100,arr);

				 sprintf(arr,"%s",meridian[ap-1]);
           settextstyle(6,HORIZ_DIR,2);
           outtextxy(500,100,arr);

           sprintf(arr1[4],"%s, %d %s, %d",day[i-1],date,mon[j-1],year);
         settextstyle(6,HORIZ_DIR,4);
         outtextxy(150,180,arr1[4]);

	    s++;
	    if(s==60)
					  { m++;
					  s=0;
					   }
					     if(m==60)
					      { h++;
					      m=0;
					      s=0;
						  }
						     if(h==12)
						     { h=0;
						       m=0;
						       s=0;
						    day_check++;
						    ap++;
						       if(ap>1)
						       { ap=0;
							   }
							 }
							   if(day_check==2)
							   { i++;
							     date++;
							   day_check=0;
								 if(i>7)
								 {i=0;
									 }
							   }
							     if(date==30)
							     {  j++;
								 date=0;

									}
								 if(j==12)
								 { year++;
								 j=0;
									 }
					Sleep(1000);
			     } option_check=_getch();
			 }


 int main()
 { system("cls");
system("2F");
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
 S_TIME t1;
  user_time u1;
  int end=0;// end to end the programme.....
  settextstyle(6,HORIZ_DIR,3);
  setcolor(RED);
  outtextxy(0,100,"......DIGITAL CLOCK......BY BINAY.........");
  Sleep(3000);
  do{

  system("cls");
     do
	 {
	 t1.local_time();
     if(option_check!=49 && option_check!=50 && option_check!=51 && option_check!=52  )
     { cout<<"...INVALID ENTRY......";
      Sleep(1000);
     }
	}while(option_check!=49 && option_check!=50 && option_check!=51 && option_check!=52  );
	 switch(option_check)
       {  case 49:

		  t1.local_time();
	  break;
	    case 50:
		t1.GM_display();
		break;
		case 51:
			u1.set_time();
			u1.set_date();
			u1.time_display();
			break;
			case 52:
            exit(0);
                end++;
				break;
	   }
}while(end==0);
closegraph();
 return 0;
}
