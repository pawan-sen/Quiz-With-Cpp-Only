#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
class log
{
char name[50],pass[30],email[100];
char phone[40];
public:
void newac()
{ cout<<"ENTER YOUR NAME\n";
gets(name);
cout<<"ENTER YOUR EMAIL ADDRESS\n";
gets(email);
cout<<"ENTER PHONE NUMBER WITH THE NAME OF COUNTRY(EXAMPLE:-9999999999 INDIA\n";
gets(phone);
cout<<endl;
cout<<"ENTER PASSWORD\n";
gets(pass);
char t[30];
cout<<"PLEASE RE-ENTER THE PASSWORD\n";
gets(t);
if(strcmp(t,pass)==0)
{
cout<<"THANKS FOR JOINING US\n";
getch();
}
else
{cout<<"SORRY PASSWORD MISSMATCH PLEASE REENTER\n";
 newac();
 }
 }
 void disjj()
 {
 cout<<"name=";
 puts(name);
 cout<<"email=";
 puts(email);
 cout<<"phone number with country=";
 puts(phone);
 cout<<"password=";
 puts(pass);
 }
char *retname()
{
return(name);
}
char *retpas()
{
return(pass);
}
};
void mainmenu()
{
void login();
void signin();
clrscr();

cout<<"1.SIGNIN AS NEW USER\n"
    <<"2.LOGIN\n"
    <<"3.EXIT\n";
int d;
cin>>d;
if(d==1)
signin();
else
if(d==2)
login();
else
if(d==3)
{
cout<<"come back soon\n";
getch();
exit(0);
}
else
{cout<<"wrong choice please reenter\n";
getch();
mainmenu();
}

}
void login()
{void c_menu();
void admin_menu();
clrscr();
 ifstream f;
  f.open("people.dat",ios::in|ios::binary);
  log l;
  int p=0;
 char check_n[50],check_p[40];
 cout<<"enter name\n";
 gets(check_n);
 cout<<"enter password\n";
 gets(check_p);
 if((strcmp(check_n,"pawan sen")==0)&&(strcmp(check_p,"pawanpawan")==0))
 admin_menu();
 else
 {
 while(f.read((char*)&l,sizeof(l)))
 {if((strcmp(check_n,l.retname())==0)&&(strcmp(check_p,l.retpas())==0))
 p++;
 }
 if(p==1)
 c_menu();
 else
{ cout<<"no match found\n";
  getch();
  mainmenu();
  }
  }
  f.close();
  }
  void signin()
  {void c_menu();
  clrscr();
  ofstream f;
  f.open("people.dat",ios::app|ios::binary);
  log l;
  int i;
    for(i=0;i<1;i++)
    {
    l.newac();
    f.write((char*)&l,sizeof(l));
    }
    f.close();
    c_menu();
    }

 class quiz
{
 char ques[200],o1[100],o2[100],o3[100];
 int ans;
 int code;
 public:

 void question()
 {
 cout<<"enter question\n";
 gets(ques);
 cout<<"op1\n";
 gets(o1);
 cout<<"op2\n";
 gets(o2);
 cout<<"op3\n";
 gets(o3);
 cout<<"enter option no.\n";
 cin>>ans;
 cout<<"enter the question code(in 3 digits)\n";
 cin>>code;
 }
 void may(int &attempt,int &right,int &wrong)
 {
 clrscr();
 cout<<"question code:"<<code<<endl;
 puts(ques);
 cout<<"1.";
 puts(o1);
 cout<<"2.";
 puts(o2);
 cout<<"3.";
 puts(o3);
 int i;
 cout<<"correct option\n";
 attempt++;
 cin>>i;
 if(ans==i)
 {
 cout<<"good correct \n";
 getch();
 right++;
 score(attempt,right,wrong);
 }
 else
{
 cout<<"wrong";
 getch();
 wrong++;
 score(attempt,right,wrong);
 }
 }
 void score(int &attempt,int &right,int &wrong)
 {
 clrscr();
 cout<<"questions attempted="<<attempt<<endl;
 cout<<"correctly answered="<<right<<endl;
 cout<<"wrong answered="<<wrong<<endl;
 int g=((right*4)-(wrong*1));
 cout<<"score="<<g;
 }
 void disp()
  {
  cout<<"question is=";
  puts(ques);
  cout<<"option 1:";
  puts(o1);
  cout<<"option 2:";
  puts(o2);
  cout<<"option 3:";
  puts(o3);
  cout<<"answer:";
  cout<<ans<<endl;
  cout<<"question code="<<code;
  }

 int qu()
 {
 return code;
 }
 };
 void modify()
 { void admin_menu();
 fstream f;
 f.open("ques.h",ios::app|ios::in|ios::binary);
 quiz q1;
 int we,k=0;
 cout<<"enter the question code to be modified\n";
 cin>>we;
 while(f.read((char*)&q1,sizeof(q1)))
 {
 if(we==q1.qu())
 {
 int a=f.tellp()-sizeof(q1);
 f.seekp(a,ios::beg);
 q1.question();
 f.write((char*)&q1,sizeof(q1));
 k++;
 }
 }
 if(k==0)
 cout<<"question doesn't exist\n";
 else
 cout<<"question has been modified\n";
 f.close();
 getch();
 admin_menu();
 }
 void add()
 {
 void admin_menu();
 ofstream fo;
 fo.open("ques.h",ios::app|ios::binary);
 quiz q1;
 int j,n;
 cout<<"no. to be entered\n";
 cin>>n;
 for(j=0;j<n;j++)
 {
  q1.question();
  fo.write((char*)&q1,sizeof(q1));
  cout<<endl;
  }
  fo.close();
  cout<<"question added\n";
  getch();
  admin_menu();
  }
  void rea1()
  { void admin_menu();
  ifstream fi;
  int a=0,r=0,w=0;
  fi.open("ques.h",ios::in|ios::binary);
  quiz q1;
  while(fi.read((char*)&q1,sizeof(q1)))
 { q1.may(a,r,w);
  getch();
  }
  fi.close();
  admin_menu();
}
void rea2()
{ void c_menu();
  ifstream fi;
  int a=0,r=0,w=0;
  fi.open("ques.h",ios::in|ios::binary);
  quiz q1;
  while(fi.read((char*)&q1,sizeof(q1)))
 { q1.may(a,r,w);
  getch();
  }
  fi.close();
  c_menu();
}
void del()
{
void admin_menu();
ifstream i;
ofstream o;
quiz q1;
int c;
cout<<"enter question code to be deleted\n";
cin>>c;
i.open("ques.h",ios::in|ios::binary);
o.open("re.h",ios::out|ios::binary);
int k=0;
while(i.read((char*)&q1,sizeof(q1)))
{
if(c!=q1.qu())
o.write((char*)&q1,sizeof(q1));
k++;
}
o.close();
i.close();
remove("ques.h");
rename("re.h","ques.h");
if(k!=0)
cout<<"question has been deleted\n";
else
cout<<"question not found\n";
getch();
admin_menu();
}
void update_pl()
{
 void c_menu();
 fstream f;
 f.open("people.dat",ios::in|ios::out|ios::binary);
 log l;
 char ch[30];
 int k=0;
 cout<<"enter your password\n";
 gets(ch);
 while(f.read((char*)&l,sizeof(l)))
 {
 if(strcmp(ch,l.retpas())==0)
 {
 int a=f.tellp()-sizeof(l);
 f.seekp(a);
 l.newac();
 f.write((char*)&l,sizeof(l));
 k++;
 }
 }
 if(k==0)
 cout<<"RECORD NOT FOUND\n";
 else
 cout<<"MODIFIED\n";
 f.close();
 getch();
 c_menu();
 }
void c_menu()
{  void help();
clrscr();
cout<<"1.PLAY\n"
    <<"2.UPDATE YOUR DEATILS\n"
    <<"3.HELP\n"
    <<"4.EXIT\n";
int g;
cin>>g;
if(g==1)
rea2();
else
if(g==3)
help();
if(g==2)
update_pl();
else
if(g==4)
{
cout<<"come back soon\n";
getch();
exit(0);
}
else
{cout<<"wrong choice\n";
getch();
c_menu();
}
}
void help()
{
cout<<endl<<endl<<endl;
cout<<"1.\tYOU WILL BE GIVEN QUESTIONS WITH THE CORRECT OPTIONS.\n"
    <<"2.\tFOR CORRECT OPTION 4 MARKS ARE AWARDED\n"
    <<"3.\tFOR WRONG ANSWER 1 MARKS WILL BE DEDUCTED\n"
    <<"\tHOPE YOU ENJOYED THE GAME\n";
    getch();
c_menu();
}
void del_pl()
{
void admin_menu();
ifstream fi;
ofstream fo;
fi.open("people.dat",ios::in|ios::binary);
fo.open("abc.dat",ios::out|ios::binary);
log l;
char t[30];
cout<<"enter name of the player to be deleted\n";
gets(t);
int k=0;
while(fi.read((char*)&l,sizeof(l)))
{
if(strcmp(t,l.retname())!=0)
{
fo.write((char*)&l,sizeof(l));
k++;
}
}
fi.close();
fo.close();
remove("people.dat");
rename("abc.dat","people.dat");
if(k!=0)
{
cout<<"result not found\n";
}
else
cout<<"deleted\n";
getch();
admin_menu();
}

void displ()
{
void admin_menu();
ifstream f;
f.open("people.dat",ios::in|ios::binary);
log l;
int h=0,k=0;
cout<<"1.ALL PLAYERS\n";
cout<<"2.SELECTED PLAYERS\n";
cin>>h;
if(h==1)
{
while(f.read((char*)&l,sizeof(l)))
{l.disjj();
cout<<endl;
k++;
}
getch();
f.close();
admin_menu();
}
else
if(h==2)
{
char u[30];
cout<<"enter name of the player\n";
gets(u);
while(f.read((char*)&l,sizeof(l)))
{if(strcmp(u,l.retname())==0)
 {l.disjj();
 k++;
 }
 }
 if(k==0)
 cout<<"no match found\n";
 getch();
 f.close();
 admin_menu();
 }
 }
void admin_menu()
{
clrscr();
cout<<"1:PLAY\n"
    <<"2:ADD QUESTION\n"
    <<"3:MODIFY QUESTION\n"
    <<"4:DISPLAY QUESTION\n"
    <<"5:DELETE QUESTION\n"
    <<"6:DISPLAY PLAYERS\n"
    <<"7:DELETE PLAYER\n"
    <<"8:EXIT\n";
quiz q1;
void dis();
int op;
cin>>op;
switch(op)
{
case 1:
{
clrscr();
rea1();
  }
  break;
  case 2:
  { clrscr();
  add();
  }
  break;
  case 3:
  {
   clrscr();
   modify();
   break;
   }
  case 4:
  {
  clrscr();
  dis();
  break;
  }
  case 5:
  {clrscr();
  del();
  break;
  }
  case 8:
  {cout<<"come back soon\n";
  getch();
  exit(0);
  }
  case 6:
  {
  clrscr();
  displ();
  break;
  }
  case 7:
  {clrscr();
  del_pl();
  break;
  }
  default:
  {cout<<"wrong option\n";
  clrscr();
  admin_menu();
  }
  } }
  void dis()
  {
  clrscr();
  cout<<"want to see all question(a) or a single one(s)\n";
  char er;
  cin>>er;
  if(er=='a'||er=='A')
  {
  clrscr();
  ifstream f;
  f.open("ques.h",ios::in|ios::binary);
  quiz q1;
  while(f.read((char*)&q1,sizeof(q1)))
  {
  q1.disp();
  cout<<endl<<endl;
  }
  f.close();
  getch();
  clrscr();
  admin_menu();
  }
  else
  if(er=='s'||er=='S')
  {
  ifstream f;
  f.open("ques.h",ios::in|ios::binary);
  quiz q1;
  int c;
  cout<<"enter the code of question to be displayed\n";
  cin>>c;
  while(f.read((char*)&q1,sizeof(q1)))
  {
  if(c==q1.qu())
  q1.disp();
  }
  f.close();
  X:
  char i;
  cout<<endl;
  cout<<"want to see another question(Y/N)\n";
  cin>>i;
  if(i=='y'||i=='Y')
  {clrscr();
  dis();
  }
  else
  if(i=='n'||i=='N')
  {
  clrscr();
  admin_menu();
  }
  else
  {
  cout<<"wrong choice re-enter\n";
  goto X;
  } }
  else
  { cout<<"wrong input. please re enter\n";
  getch();
  dis();
  }
  }

 void main()
 {
 clrscr();
 cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t\t"<<"WELCOME\n"
     <<endl<<endl<<endl<<endl
     <<"\t\t\t\t"<<"QUIZ........";
 cout<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t\t"<<"MADE BY PAWAN SEN"<<endl
     <<"\t\t\t\t"<<"XII-C";
getch();
clrscr();
mainmenu();
 getch();
 }