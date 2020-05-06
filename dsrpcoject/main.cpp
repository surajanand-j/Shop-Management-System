#include <iostream>
#include<windows.h>
#include<mysql.h>
#include<time.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<sstream>
#include<string>

using namespace std;


    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
    string query;
void clear()
{
    system("cls");
    printf(" Loading...");
    Sleep(1000);
    system("cls");
}

//=========go to desire position in output screen===========
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//=========================Time & Date==========================
int t(void)
{
	//struct date d;
	//struct time t;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	//getdate(&d);
//	gettime(&t);
	gotoxy(53+45,46-12);
	printf("Date: %d-%d-%d ",now->tm_mday,now->tm_mon+1,now->tm_year+1900);
	gotoxy(53+45,48-12);
	printf("Time: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
	return 0;
}


//==================== global variables ===========================
int i;
//function for auto increment customer & supplier Id.
int getcust_id();
int getsupp_id();
//function for welcome & main menu
void welcome();
void main_menu();
//function for all box
void main_box();
void box1();
void wbox();
//function for bill slip
void bill();
//function for about menu
void about();
//function for medicine menu
void medicine();
void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();
void remainder();
//function for supplier menu
void supplier();
void supp_entry();
void supp_list();
void sup_update();
void search();
void search_id();
void search_name();
//function for customer menu
void customer();
void cust_search();
void search_cid();
void search_cname();
void cust_entry();
void cust_list();
void cust_update();
//function for report menu
void report_menu();
void report();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();

void login();
//===================================structures =========================
struct medical
{
	int id;
	string medi_name;
	int rack;
	string cabnit;
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	string pur_date;
	string exp_date;
	string manu_date;
	int bill_no;
	string comp_name;
	string supp_name;
 };

struct medical temp;
struct medical x[20];


char a[10];
struct supplier
{
	int supp_id;
	string supp_name;
	string city;
	string mob_no;
	string email;

};
struct supplier temp1;

struct customer
{
	int cust_id;
	string cust_name;
	string city;
	string mob_no;
	string email;

};
struct customer temp_c;


struct bill
{
    int billno;
	string cname;
	string mediname;
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;

struct sales_report
{
	int medi_id;
	string medir_name;
	string cust_name;
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;

struct purchase_report
{
	int medi_id;
	string medir_name;
	string supp_name;
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct profit_report
{
	int medi_id;
	string medir_name;
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;

int main()
{
    qstate=0;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

    login();

	getch();
}






void linkfloat()
{
	float f,*p;
	p=&f;
	f=*p;
}

//=======================Animation ==========================
void animation()
{
	for (i=45; i>=1; i--)
	{
		Sleep(30);
		gotoxy(1+35,i);
		//clreol();
	}
	for (i=1; i<=20; i++)
	{
		//clreol();
		Sleep(40);
		gotoxy(1+35,i);
	}
}


//======================boxes==================================

void box()
{
   for(i=3+35;i<=79+35;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
    	gotoxy(i,45);
		printf("%c",219);
	}

	for(i=3;i<=45;i++)
	{                       //vertically till the 3th row is reached.
		gotoxy(3+35,i);
		printf("%c",219);
		gotoxy(79+35,i);
		printf("%c",219);
	}

}
void wbox()
{
	for(i=45;i<=115;i++) 	//This 'FOR' loop will print a combination of
	{
		gotoxy(i,5);    //the 75th column is reached.
		printf("%c",219);
        gotoxy(74,40);
		printf("%c",219);
		gotoxy(i,40);
		printf("%c",219);
	}

	for(i=5;i<=40;i++)      //This 'FOR' loop will print asteriks 'I'
	{                       //vertically till the 17th row is reached.
		gotoxy(45,i);
		printf("%c",219);

	}
		for(i=5;i<=40;i++)      //This 'FOR' loop will print asteriks 'I'
	{                       //vertically till the 17th row is reached.
		gotoxy(115,i);
		printf("%c",219);

	}
}

//============================small box ===============
void box1()
{
	gotoxy(1+35,3);
	printf("%c",201);
	for(i=1+35;i<79+35;i++)
	{
		gotoxy(1+i,3);
		printf("%c",205);
	}

	gotoxy(80+35,3);
	printf("%c",187);
	gotoxy(1+35,3);
	for(i=4;i<8;i++)
	{
		gotoxy(1+35,i);
		printf("%c",186);
	}
	gotoxy(1+35,9);
	for(i=4;i<8;i++)
	{
		gotoxy(80+35,i);
		printf("%c",186);
	}
}

//============================ box for label ==========
void lbox()
{
	gotoxy(25+35,6);
	printf("%c",201);
	for(i=26;i<55;i++)
	{
		gotoxy(i+35,6);
		printf("%c",205);
	}
	gotoxy(55+35,6);
	printf("%c",187);
	gotoxy(25+35,6);
	for(i=6;i<8;i++)
	{
		gotoxy(25+35,i+1);
		printf("%c",186);
	}
	gotoxy(25+35,9);
	printf("%c",200);
	for(i=26;i<55;i++)
	{
		gotoxy(i+35,9);
		printf("%c",205);
	}
	gotoxy(55+35,9);
	printf("%c",188);
	gotoxy(55+35,6);
	for(i=6;i<8;i++)
	{
		gotoxy(55+35,i+1);
		printf("%c",186);
	}

}

//=========================welcome screen ==============

void welcome()
{
 int j,k,l,m;
 system("cls");
 box();
	for(i=0;i<16;i++)
	{
		gotoxy(35+35,20);
		printf("WELCOME");
		k=i+2;
		gotoxy(38+35,22);
		printf("TO");
		l=i+3;
		gotoxy(28+35,24);
		printf("MEDICAL");
		gotoxy(36+35,24);
		printf("STORE");
		gotoxy(42+35,24);
		printf("SYSTEM");
		gotoxy(52+35,45);
		j=i+1;
		printf("Loading......");
		Sleep(200);
	}
}

void main_box()
{
	gotoxy(1+35,6);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(i+36,6);
		printf("%c",205);
	}

	gotoxy(80+35,6);
	printf("%c",187);
	gotoxy(1+35,6);
	for(i=5;i<35;i++)
	{
		gotoxy(1+35,2+i);
		printf("%c",186);
	}
	gotoxy(1+35,37);
	printf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(i+36,37);
		printf("%c",205);
	}
	gotoxy(80+35,37);
	printf("%c",188);
	gotoxy(80+35,6);
	for(i=5;i<35;i++)
	{
		gotoxy(80+35,2+i);
		printf("%c",186);
	}
}

void main_menu()
{
  char ch;

	do
	{
		system("cls");
		gotoxy(3+35,5);
		printf("Supplier Info");
		gotoxy(19+35,5);
		printf("Customer Info");
		gotoxy(36+35,5);
		printf("Medicine");
		gotoxy(48+35,5);
		printf("RReport");
		gotoxy(57+35,5);
		printf("Bill");

		gotoxy(64+35,5);
		printf("About");

		gotoxy(72+35,5);
		printf("Exit");
		t();   //this function display date & time
		box1();
		main_box();
		gotoxy(30+35,10);
		printf("Welcome To Medical Store ");
		gotoxy(2+35+35,28);
		remainder();//this function is active when medicine qty is less then 10.
		gotoxy(10+35,40);
		printf("Press First Character for further Menu  ");

		ch=toupper(getche());
		switch(ch)
		{
			case 'S':supplier();
				 break;
			case 'C':customer();
				 break;
			case 'M':medicine();

				 break;
			case 'R':report_menu();
				 break;
			case 'B':bill();
				 break;
			case 'A':about();
				 break;
			case 'E':gotoxy(23+35,20);
            printf("Do you want to exit now? Y/N :");
			Sleep(100);
			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{
				animation();
				system("cls");
				gotoxy(35+35,20);
				printf(" Please wait.....");
				Sleep(2000);
				system("cls");
				exit(0);
			}
			else
			{
				main_menu();
			}

			default:
            gotoxy(11+35,34);
			printf("Plese Enter right character ONLY (S,C,M,R,B,A).");
			getch();
		}
	}while(ch!='E');
}
void login()
{
    string name;
	string pass;
	int count=0,i;

	system("cls");

	start:
	wbox();
	lbox();
	gotoxy(35+35,7);
	printf(" LOGIN ");

	gotoxy(32+35,18);
	printf("Enter user name :");
	gotoxy(32+35,22);
	printf("Enter password  :");

	gotoxy(51+35,18);
    cin>>name;
    gotoxy(51+35,22);
    cin>>pass;
	if(name.compare("shubham")!=0 || pass.compare("123")!=0)
	{
    clear();
	 system("cls");
	 gotoxy(20+35,20);
	 printf("Please Enter vailid Username & Passward!!!!!");
	 count++;
	 gotoxy(20+35,23);
	 printf("%d chance left!!!!",3-count);
	 getch();
	 system("cls");
	 if(count==3)
	 exit(0);
	 else
	 goto start;
	}
	else
	{
	    //clear();

        welcome();
        main_menu();
	}
}



void supplier()
{
  char ch;
	do
	{
	  system("cls");
	  gotoxy(34+35,3);
	  printf("----------------");
	  gotoxy(35+35,4);
	  printf("Supplier MENU");
	  gotoxy(34+35,5);
	  printf("----------------");
	  gotoxy(25+35,11);
	  printf("1.Add New Supplier");

	  gotoxy(25+35,15);
	  printf("2.Update Supplier");

	  gotoxy(25+35,19);
	  printf("3.Search Supplier");

	  gotoxy(25+35,23);
	  printf("4.List of Existing Supplier");

	  gotoxy(25+35,27);
	  printf("5.Main Menu");
	  main_box();

	  gotoxy(10+35,40);
	  printf("Press Number for further Operation ");


	  ch=getche();
	  switch(ch)
	  {
		case '1':animation();
			 supp_entry();
			 break;
		case '2':animation();
			 sup_update();
			 break;
		case '4':animation();
			 supp_list();
			 break;
		case '3':clear();
		    search();
			 break;
		case '5':main_menu();
			 break;
		default:
			gotoxy(11+35,34);
			printf("Please Enter right choice.");
			getch();
	  }
	}while(ch!='5');

}
//=========================For customer ===========================
void customer()
{
	char ch;
	do
	{
	  system("cls");

	  gotoxy(34+35,3);
	  printf("---------------");

	  gotoxy(35+35,4);
	  printf("Customer Menu.");

	  gotoxy(34+35,5);
	  printf("---------------");

	  gotoxy(25+35,11);
	  printf("1.Add New Customer");

	  gotoxy(25+35,15);
      printf("2.Update Customer");

	  gotoxy(25+35,19);
	  printf("3.Search Customer");

	  gotoxy(25+35,23);
	  printf("4.List of Existing Customer");

	  gotoxy(25+35,27);
	  printf("5.Main Menu");
	  main_box();

	  gotoxy(10+35,40);
	  printf("Press Number for further Operations  ");


	  ch=getche();
	  switch(ch)
	  {
		case '1':animation();
			 cust_entry();
			 break;
		case '2':animation();
			 cust_update();
			 break;
		case '4':animation();
			 cust_list();
			 break;
		case '3':cust_search();
			 break;
		case '5':main_menu();
			 break;
		default:
			gotoxy(11+35,34);
			printf("Please Enter right Choice.");
			getch();
	  }
	}while(ch!='5');

}
//=========================For Medicine ===========================
void medicine()
{
	char  ch;
	do
	{
	  system("cls");

	  gotoxy(34+35,3);
	   printf("---------------");
	  gotoxy(35+35,4);
	  printf("Medicine Menu.");
	  gotoxy(34+35,5);
	  printf("---------------");
	  gotoxy(25+35,15);
	  printf("1.Purchase New Medicine");

	  gotoxy(25+35,19);
	  printf("2.Sale Medicine");

	  gotoxy(25+35,23);
	  printf("3.Stock of Medicine");

	  gotoxy(25+35,27);
	  printf("4.Search Medicine");

	  gotoxy(25+35,31);
	  	  printf("5.Main Menu");
	  main_box();

	  gotoxy(10+35,40);
	  printf("Press First Character for further Operations  ");


	  ch=getche();
	  switch(ch)
	  {
		case '1':medi_entry();
			 break;
		case '2':medi_sale();
			 break;
		case '3':stock();
			 break;
		case '4':medi_search();
			 break;
		case '5':main_menu();
			 break;
		default:
			gotoxy(11+35,34);
			printf("Plaese Enter right choice.");
			getch();
	  }
	}while(ch!='5');

}
//=========================For Report ===========================
void report_menu()
{
    char ch;
	do
	{
	  system("cls");

	  gotoxy(34+35,3);
        printf("---------------");
	  gotoxy(35+35,4);
	  printf("Report Menu.");
	  gotoxy(34+35,5);
	  printf("---------------");
	  gotoxy(25+35,12);
	  printf("1.Purchase Report");

	  gotoxy(25+35,16);
	  printf("2.Sale Report");

	  gotoxy(25+35,20);
	  printf("3.Profit Report");

	  gotoxy(25+35,24);
	  printf("5.Daily Sale Report");

	  gotoxy(25+35,28);
	  printf("5.Daily Purchase Report");

	  gotoxy(25+35,32);
	  printf("6.Main Menu");
	   main_box();

	  gotoxy(10+35,40);
	  printf("Press Number for further Operations  ");


	  ch=getche();
	  switch(ch)
	  {
		case '1':pur_rpt();
			 break;
		case '2':sale_rpt();
			 break;
		case '4':cout<<"sale_rpt_daily()";
			 break;
        case '3':profit_rpt();
			 break;
		case '5':cout<<"pur_rpt_daily()";
			 break;
        case '6':main_menu();
			 break;
		default:
			gotoxy(11+35,34);
			printf("Plese Enter Right choice .");
			getch();
	  }
	}while(ch!='6');

}

void about()
{  char c;
   system("cls");

   do
   {
    gotoxy(28+35,4);
	printf("***** MEDICAL STORE *****");
	gotoxy(10+35,8);
	printf("=> This Project Is About Medical Store ");
	gotoxy(10+35,10);
	printf("=> In This Project we Can Add Medicine ,Customer,Supplier Details");
	gotoxy(10+35,12);
	printf("=> We Can Modifed & Delete Existing Record");
	gotoxy(10+35,14);
	printf("=> We Can Also Search Medicine ,Customer,Supplier Details");
	gotoxy(10+35,16);
	printf("=> It's Helpfull For Display Stock Of Medicine ");

	printf("<<<<-Press 1 for main menu->>>>");
	c = getche();

	switch (c)
			{
			case '1':animation(); main_menu();
			default:
				gotoxy(26+35,24);
				puts("<<--ENTER FROM 1 PLEASE-->>");
                getch();
		}

}while(c != '1');

}
//======================Remainder for medicine stock ===============
void remainder()
{
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	query="select * from medicial where quantity <10;";
	   const char *q=query.c_str();

	   qstate=mysql_query(conn,q);
	   //cout<<mysql_error(conn);
//cout<<query;

    gotoxy(40+35,23);
    cout<<"REMAINDER";
	   res=mysql_store_result(conn);
    qstate=mysql_num_rows(res);
	while(row=mysql_fetch_row(res))
	{
			gotoxy(25+35,25);

			cout<<"  Quantity of "<<row[1]<<" is less then 10";

	}
}

//========================for bill =============================
void bill()
{
//struct date d;
    time_t td = time(0);   // get time now
    struct tm * now = localtime( & td );

	   char id[6];
	   int j=1,d1,m,y,k;
	   float netamt=0.0;
	   d1=now->tm_mday;
	   m=now->tm_mon;
	   y=now->tm_year;

	   system("cls");
	   lbox();
	   gotoxy(33+35,8);
	   printf("Enter bill no : ");

	   cin>>id;
	   system("cls");
	   gotoxy(25+35,3);

	   box();
	   gotoxy(7+35,7);
	   cout<<"Bill No: ";
	   cout<<id;

	   stringstream ss;
        ss <<"select * from bill where id="<<id<<";";

	   query=ss.str();
	   const char *q=query.c_str();

	   qstate=mysql_query(conn,q);

	   res=mysql_store_result(conn);

        qstate=mysql_num_rows(res);
	   gotoxy(7+35,9);
	   printf("Customer Name: ");


	   gotoxy(50+35,7);
	   printf("Date : ");
	   printf("%d-%d-%d",d1,m+1,y+1900);
	   gotoxy(7+35,12);
	   printf("Sr.No   Medicine Name       Qty          Rate       Total ");
	   gotoxy(6+35,14);
	   printf("---------------------------------------------------------------------");

	   i=15;
    if(qstate<1)
    {
         gotoxy(20+35,27);
         cout<<"Bill Number not associated with any customer";
    }

	   while(row=mysql_fetch_row(res))
	   {

				gotoxy(7+35,i);
				cout<<j;
				gotoxy(14+35,i);
				cout<<row[3];
				gotoxy(22+35,9);
				cout<<row[2];
				gotoxy(35+35,i);
				cout<<row[4];
				gotoxy(47+35,i);
				cout<<row[5];
				gotoxy(59+35,i);
				cout<<row[6];
				netamt=netamt+stoi(row[6]);
				i++;
				j++;
				gotoxy(35+35,32);
				printf("                                ");
				gotoxy(20+35,50);

        }


	   gotoxy(6+35,35);
	   printf("---------------------------------------------------------------------");
	   gotoxy(50+35,37);
	   printf("Net Amount : ");
	   printf("%.2f",netamt);
	   getch();
       main_menu();
	   clear();
}

int getsupp_id()
{
    int count;
    temp1.supp_id=100;
    qstate=0;
    //=================  mysql connection =============================
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);
    query="select * from supplier";
    const char *q=query.c_str();

    if(conn)
    {
        qstate=mysql_query(conn,q);
        if(!qstate)
        {
            //cout<<"hi";
            res=mysql_store_result(conn);

            count=mysql_num_rows(res);
        }
    }


	 return temp1.supp_id+1+count;
}

int getcust_id()
{
    int count;
    temp_c.cust_id=100;
    qstate=0;
    //=================  mysql connection =============================
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);
    query="select * from customer";
    const char *q=query.c_str();

    if(conn)
    {
        qstate=mysql_query(conn,q);
        if(!qstate)
        {
            res=mysql_store_result(conn);

            count=mysql_num_rows(res);
        }
    }


	 return temp_c.cust_id+1+count;
}

//========FOR SUPPLIERS ENTRY=================
void supp_entry()
{
 int id;
 char ch;
 system("cls");
    qstate=0;
     conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	   ch='y';
	   while(ch=='y')
	   {
		system("cls");
		t();
		box();
		lbox();
		gotoxy(30+35,8);
		cout<<" SUPPLIER ENTRY ";
		gotoxy(8+35,13);
		cout<<"id          :  ";
		temp1.supp_id=getsupp_id();
        cout<<temp1.supp_id;
		gotoxy(39+35,13);
		cout<<"SUPPLIER NAME : ";
		gotoxy(8+35,18);
		cout<<"CITY        : ";
		gotoxy(39+35,18);
		cout<<"CONTACT NO.   : ";
		gotoxy(8+35,23);
		cout<<"EMAIL ID    : ";

//--------		taking inputs -------------;
		gotoxy(55+35,13);
		getline(cin,temp1.supp_name);
		gotoxy(22+35,18);
		getline(cin,temp1.city);

		gotoxy(55+35,18);
		getline(cin,temp1.mob_no);


		gotoxy(22+35,23);
		getline(cin,temp1.email);

		//flushall();

		gotoxy(20+35,30);
		printf("Save");
		gotoxy(28+35,30);
		printf("Cancel");
		gotoxy(18+35,36);
		printf("Press First charecter for the operation : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
		    stringstream ss;
			ss <<"insert into supplier values ("<<temp1.supp_id<<",'"<<temp1.supp_name<<"','"<<temp1.mob_no<<"','"<<temp1.city<<"','"<<temp1.email<<"');";
            query=ss.str();
			const char *q=query.c_str();

			qstate=mysql_query(conn,q);

			if(qstate==0)
            {
			system("cls");
            	clear();
			gotoxy(20+35,20);

			printf("Supplier Added successfully!!!!!");
			gotoxy(20+35,25);
			printf("More entries  [y/n]");
			ch=getche();
			}

		}
	   }
	   clear();

}
//=========FOR SUPPLIER DISPLAY LIST ==========
void supp_list()
{
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);
    query="select * from supplier;";
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

       res=mysql_store_result(conn);


       system("cls");
	   box();

	   lbox();
	   gotoxy(30+35+2,8);
	   printf(" SUPPLIER LIST ");
	   gotoxy(5+35+4,10);
	   printf("ID.  SUPPLIER NAME.      PH.NO.     CITY.         EMAIL");
	   gotoxy(4+35+4,12);
	   i=14;
	   printf("=================================================================");
	 if(!qstate)
	  {
	   while(row=mysql_fetch_row(res))
	   {
		gotoxy(4+35+4,i);
		cout<<row[0];
		gotoxy(9+35+4,i);
		cout<<row[1];
		gotoxy(29+35+4,i);
		cout<<row[2];
		gotoxy(41+35+4,i);
		cout<<row[3];
		gotoxy(54+35+4,i);
		cout<<row[4];
		i=i+2;
	   }
	  }
	   gotoxy(8+35+2,48);
	   printf("Press Anykey to go to SUPPLIER MENU !!!");
	   getche();
}

//======================search supplier==================
void search()
{
  int ch;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	do
	 {
	   system("cls");
       gotoxy(17+35,10);
	   printf(" Two options Available for searching ");
	   gotoxy(15+35,15);
	   printf("1.Search by ID number");

	   gotoxy(15+35,18);
	   printf("2.Search by Name");

	   gotoxy(15+35,21);
	   printf("3.Return");
	   main_box();
	   gotoxy(17+35,24);
	   printf("Press Number for the operation : ");
	   ch=toupper(getche());
	   switch(ch)
	   {
		case '1':
			animation();
			search_id();

			break;
		case '2':
			animation();
			search_name();
			break;
		case '3':
			animation();
			supplier();
			break;
		default:
			gotoxy(22+35,18);
			printf("You entered wrong choice!!!!!");
			getch();
	   }
	   }while(ch!='3');

}

//=============================== Search by id =============================
void search_id()
{
  int id;

    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);



	   system("cls");
	   box();
	   gotoxy(13+35,8);
	   printf("Enter id to be searched:");
	   cin>>id;

	stringstream ss;
	ss <<"select * from supplier where id="<<id<<";";
    query=ss.str();
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);

	  gotoxy(5+35+4,14);
	   printf("ID.  SUPPLIER NAME.      PH.NO.     CITY.         EMAIL");
	   gotoxy(4+35+4,16);
	   i=18;
	   printf("=================================================================");

        qstate=mysql_num_rows(res);
        row=mysql_fetch_row(res);
		if(qstate==1)
		{
			gotoxy(4+35+4,i);
		cout<<row[0];
		gotoxy(9+35+4,i);
		cout<<row[1];
		gotoxy(29+35+4,i);
		cout<<row[2];
		gotoxy(41+35+4,i);
		cout<<row[3];
		gotoxy(54+35+4,i);
		cout<<row[4];
			i++;
		}
	  else
	   {
		gotoxy(20+35,30);
		printf("Record not found!");
	   }
      gotoxy(20+35,35);
	   printf("Press Any key to Return Back Menu ....");

	   getche();
}
//============================ Search by name =============================
void search_name()
{
  string name;

        conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);


	   system("cls");
	   box();
	   gotoxy(13+35,8);
	   printf(" Enter Supplier Name to be searched : ");
	   cin>>name;

	   stringstream ss;

	   ss <<"select * from supplier where name like'%"<<name<<"%';";
    query=ss.str();
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);





	   gotoxy(5+35+4,14);
	   printf("ID.  SUPPLIER NAME.      PH.NO.     CITY.         EMAIL");
	   gotoxy(4+35+4,16);
	   i=18;
	   printf("=================================================================");

		qstate=mysql_num_rows(res);

		if(qstate!=0)
		{
		    while(row=mysql_fetch_row(res))

			{
			    if(qstate==0)
                    break;
            gotoxy(4+35+4,i);
            cout<<row[0];
            gotoxy(9+35+4,i);
            cout<<row[1];
            gotoxy(29+35+4,i);
            cout<<row[2];
            gotoxy(41+35+4,i);
            cout<<row[3];
            gotoxy(54+35+4,i);
            cout<<row[4];
            i++;
			qstate--;
			}
		}

    else
	   {
		gotoxy(20+35,30);
		printf("Record not found!!!");
	   }
	   gotoxy(20+35,35);
       printf("Press Any key to Return Back Menu ....");
	   getche();
}

//============supp update=================
void sup_update()
{
  int i;
  char ch;
  int id;
  system("cls");
  box();
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	   lbox();
	   gotoxy(30+35,8);
	   printf(" Modifying Supplier ");
	   gotoxy(12+35,13);
	   printf("Enter supplier ID :  ");
	   cin>>id;
	   gotoxy(12+35,15);
	   stringstream ss;
	ss <<"select * from supplier where id="<<id<<";";
    query=ss.str();
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);

        qstate=mysql_num_rows(res);
        row=mysql_fetch_row(res);
		if(qstate==1)
		{
                gotoxy(12+35,17);
					cout<<" Existing Record  ";


					gotoxy(5+35+4,19);
                    printf("ID.  SUPPLIER NAME.      PH.NO.     CITY.         EMAIL");
                    gotoxy(4+35+4,21);
                    i=18+5;
                    printf("=================================================================");
                    gotoxy(4+35+4,i);
                    cout<<row[0];
                    gotoxy(9+35+4,i);
                    cout<<row[1];
                    gotoxy(29+35+4,i);
                    cout<<row[2];
                    gotoxy(41+35+4,i);
                    cout<<row[3];
                    gotoxy(54+35+4,i);
                    cout<<row[4];





					gotoxy(12+35,22+5);
					cout<<"Enter New Name       : ";
					cin>>temp1.supp_name;


					gotoxy(12+35,24+5);
					cout<<"Enter New mobile no  : ";
                    cin>>temp1.mob_no;

					gotoxy(12+35,26+5);
                    cout<<"Enter New City       : ";
                    cin>>temp1.city;

					gotoxy(12+35,28+5);

					cout<<"Enter New email      : ";
					cin>>temp1.email;
					gotoxy(20+35,32+5);

					cout<<"Update";
					gotoxy(30+35,32+5);

					printf("Cancel");

					gotoxy(18+35,36+5);
					printf("Press First charecter for the operation : ");
					ch=getch();
					if(ch=='u' || ch=='U')
					{
					   stringstream ss;
                    ss <<"update  supplier set name='"<<temp1.supp_name<<"',number='"<<temp1.mob_no<<"',city='"<<temp1.city<<"',email='"<<temp1.email<<"' where id="<<row[0]<<";";
                    query=ss.str();
                    const char *q=query.c_str();
                    qstate=0;
                    qstate=mysql_query(conn,q);
                    cout<<mysql_error(conn);

                    if(qstate==0)
					    gotoxy(20+35,38+5);
					    printf("Supplier updated successfully...");
					    getch();
					    clear();

					}
					else
                    {
                        getch();
                        clear();
                        sup_update();
                    }
        }
                else
                {
                    gotoxy(12+35,30);
                    cout<<"No record Found";
                    getch();
                    supplier();
                }
}

//========FOR customer  ENTRY=================
void cust_entry()
{
 int id;
 char ch;
 system("cls");
    qstate=0;
     conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	   ch='y';
	   while(ch=='y')
	   {
		system("cls");
		t();
		box();
		lbox();
		gotoxy(30+35,8);
		cout<<" CUSTOMER ENTRY ";
		gotoxy(8+35,13);
		cout<<"id          :  ";
		temp1.supp_id=getcust_id();
        cout<<temp1.supp_id;
		gotoxy(39+35,13);
		cout<<"CUSTOMER NAME : ";
		gotoxy(8+35,18);
		cout<<"CITY        : ";
		gotoxy(39+35,18);
		cout<<"CONTACT NO.   : ";
		gotoxy(8+35,23);
		cout<<"EMAIL ID    : ";

//--------		taking inputs -------------;
		gotoxy(55+35,13);
		getline(cin,temp1.supp_name);
		gotoxy(22+35,18);
		getline(cin,temp1.city);

		gotoxy(55+35,18);
		getline(cin,temp1.mob_no);


		gotoxy(22+35,23);
		getline(cin,temp1.email);

		//flushall();

		gotoxy(20+35,30);
		printf("Save");
		gotoxy(28+35,30);
		printf("Cancel");
		gotoxy(18+35,36);
		printf("Press First charecter for the operation : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
		    stringstream ss;
			ss <<"insert into customer values ("<<temp1.supp_id<<",'"<<temp1.supp_name<<"','"<<temp1.mob_no<<"','"<<temp1.city<<"','"<<temp1.email<<"');";
            query=ss.str();
			const char *q=query.c_str();

			qstate=mysql_query(conn,q);

			if(qstate==0)
            {
			system("cls");
			clear();
			gotoxy(20+35,20);

			printf("Customer Added Successfully!!!!!");
			gotoxy(20+35,25);
			printf("More entries  [y/n]");
			ch=getche();
			}

		}
	   }
	   clear();

}
//=========FOR customer DISPLAY LIST ==========
void cust_list()
{
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);
    query="select * from customer;";
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

       res=mysql_store_result(conn);


       system("cls");
	   box();

	   lbox();
	   gotoxy(30+35+2,8);
	   printf(" CUSTOMER LIST ");
	   gotoxy(5+35+4,10);
	   printf("ID.  CUSTOMER NAME.      PH.NO.     CITY.         EMAIL");
	   gotoxy(4+35+4,12);
	   i=14;
	   printf("=================================================================");
	 if(!qstate)
	  {
	   while(row=mysql_fetch_row(res))
	   {
		gotoxy(4+35+4,i);
		cout<<row[0];
		gotoxy(9+35+4,i);
		cout<<row[1];
		gotoxy(29+35+4,i);
		cout<<row[2];
		gotoxy(41+35+4,i);
		cout<<row[3];
		gotoxy(54+35+4,i);
		cout<<row[4];
		i=i+2;
	   }
	  }
	   gotoxy(8+35+2,48);
	   printf("Press Anykey to go to CUSTOMER MENU !!!");
	   getche();
}

//======================search coustomer==================
void cust_search()
{
  int ch;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	do
	 {
	   system("cls");
       gotoxy(17+35,10);
	   printf(" Two options Available for searching ");
	   gotoxy(15+35,15);
	   printf("1.Search by ID number");

	   gotoxy(15+35,18);
	   printf("2.Search by Name");

	   gotoxy(15+35,21);
	   printf("3.Return");
	   main_box();
	   gotoxy(17+35,24);
	   printf("Press Number for the operation : ");
	   ch=toupper(getche());
	   switch(ch)
	   {
		case '1':
			animation();
			search_cid();

			break;
		case '2':
			animation();
			search_cname();
			break;
		case '3':
			animation();
			customer();
			break;
		default:
			gotoxy(22+35,18);
			printf("You entered wrong choice!!!!!");
			getch();
	   }
	   }while(ch!='3');

}

//=============================== Search by id =============================
void search_cid()
{
  int id;

    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);



	   system("cls");
	   box();
	   gotoxy(13+35,8);
	   printf("Enter id to be searched:");
	   cin>>id;

	stringstream ss;
	ss <<"select * from customer where id="<<id<<";";
    query=ss.str();
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);

	  gotoxy(5+35+4,14);
	   printf("ID.  CUSTOMER NAME.      PH.NO.     CITY.         EMAIL");
	   gotoxy(4+35+4,16);
	   i=18;
	   printf("=================================================================");

        qstate=mysql_num_rows(res);
        row=mysql_fetch_row(res);
		if(qstate==1)
		{
			gotoxy(4+35+4,i);
		cout<<row[0];
		gotoxy(9+35+4,i);
		cout<<row[1];
		gotoxy(29+35+4,i);
		cout<<row[2];
		gotoxy(41+35+4,i);
		cout<<row[3];
		gotoxy(54+35+4,i);
		cout<<row[4];
			i++;
		}
	  else
	   {
		gotoxy(20+35,30);
		printf("Record not found!");
	   }
      gotoxy(20+35,35);
	   printf("Press Any key to Return Back Menu ....");

	   getche();
}
//============================ Search by name =============================
void search_cname()
{
  string name;

        conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);


	   system("cls");
	   box();
	   gotoxy(13+35,8);
	   printf(" Enter Customer Name to be searched : ");
	   cin>>name;

	   stringstream ss;

	   ss <<"select * from customer where name like'%"<<name<<"%';";
    query=ss.str();
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);





	   gotoxy(5+35+4,14);
	   printf("ID.  CUSTOMER NAME.      PH.NO.     CITY.         EMAIL");
	   gotoxy(4+35+4,16);
	   i=18;
	   printf("=================================================================");

		qstate=mysql_num_rows(res);

		if(qstate!=0)
		{
		    while(row=mysql_fetch_row(res))

			{
			    if(qstate==0)
                    break;
            gotoxy(4+35+4,i);
            cout<<row[0];
            gotoxy(9+35+4,i);
            cout<<row[1];
            gotoxy(29+35+4,i);
            cout<<row[2];
            gotoxy(41+35+4,i);
            cout<<row[3];
            gotoxy(54+35+4,i);
            cout<<row[4];
            i++;
			qstate--;
			}
		}

    else
	   {
		gotoxy(20+35,30);
		printf("Record not found!!!");
	   }
	   gotoxy(20+35,35);
       printf("Press Any key to Return Back Menu ....");
	   getche();
}

//============CUSTOMER update=================
void cust_update()
{
  int i;
  char ch;
  int id;
  system("cls");
  box();
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	   lbox();
	   gotoxy(30+35,8);
	   printf(" Modifying CUSTOMER ");
	   gotoxy(12+35,13);
	   printf("Enter Customer ID :  ");
	   cin>>id;
	   gotoxy(12+35,15);
	   stringstream ss;
	ss <<"select * from customer where id="<<id<<";";
    query=ss.str();
    const char *q=query.c_str();
           qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);

        qstate=mysql_num_rows(res);
        row=mysql_fetch_row(res);
		if(qstate==1)
		{
                gotoxy(12+35,17);
					cout<<" Existing Record  ";


					gotoxy(5+35+4,19);
                    printf("ID.  CUSTOMER NAME.      PH.NO.     CITY.         EMAIL");
                    gotoxy(4+35+4,21);
                    i=18+5;
                    printf("=================================================================");
                    gotoxy(4+35+4,i);
                    cout<<row[0];
                    gotoxy(9+35+4,i);
                    cout<<row[1];
                    gotoxy(29+35+4,i);
                    cout<<row[2];
                    gotoxy(41+35+4,i);
                    cout<<row[3];
                    gotoxy(54+35+4,i);
                    cout<<row[4];





					gotoxy(12+35,22+5);
					cout<<"Enter New Name       : ";
					cin>>temp1.supp_name;


					gotoxy(12+35,24+5);
					cout<<"Enter New mobile no  : ";
                    cin>>temp1.mob_no;

					gotoxy(12+35,26+5);
                    cout<<"Enter New City       : ";
                    cin>>temp1.city;

					gotoxy(12+35,28+5);

					cout<<"Enter New email      : ";
					cin>>temp1.email;
					gotoxy(20+35,32+5);

					cout<<"Update";
					gotoxy(30+35,32+5);

					printf("Cancel");

					gotoxy(18+35,36+5);
					printf("Press First charecter for the operation : ");
					ch=getch();
					if(ch=='u' || ch=='U')
					{
					   stringstream ss;
                    ss <<"update  customer set name='"<<temp1.supp_name<<"',number='"<<temp1.mob_no<<"',city='"<<temp1.city<<"',email='"<<temp1.email<<"' where id="<<row[0]<<";";
                    query=ss.str();
                    const char *q=query.c_str();
                    qstate=0;
                    qstate=mysql_query(conn,q);
                    cout<<mysql_error(conn);

                    if(qstate==0)
					    gotoxy(20+35,38+5);
					    printf("Customer updated successfully...");
					    getch();
					    clear();

					}
					else
                    {
                        getch();
                        clear();
                        cust_update();
                    }
        }
                else
                {
                    gotoxy(12+35,30);
                    cout<<"No record Found";
                    getch();
                    customer();
                }
}

//============================ FOR MEDICINE PURCHASE    ===================
void medi_entry()
{
  char ch,id[6];

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
  int f;
  system("cls");


	  ch='Y';
	  while(ch=='Y')
	  {
		system("cls");
		box();
		lbox();
		gotoxy(30+35,8);

		printf(" MEDICINE PURSHASE  ");
		{

			gotoxy(7+35,11);
			printf("MEDICINE ID    : ");

			gotoxy(40+35,11);
			printf("MEDICINE NAME  : ");

			gotoxy(7+35,14);
			printf("ENTER RACK NO  : ");

			gotoxy(40+35,14);
			printf("CABNIT NO      : ");

			gotoxy(7+35,18);
			printf("COMPANY NAME   : ");

			gotoxy(40+35,18);
			printf("SUPPLIER NAME  : ");

			gotoxy(7+35,21);
			printf("UNIT COST   Rs.:  ");

			gotoxy(40+35,21);
			printf("SALE COST   Rs.: ");

			gotoxy(7+35,24);
			printf("QUANTITY       :  ");

			gotoxy(7+35,27);
			printf("MFG.DATE(YYYY-MM-DD): ");

			gotoxy(7+35,29);
			printf("EXP.DATE(YYYY-MM-DD): ");

			gotoxy(25+35,11);
			cin>>id;


            conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);
        stringstream ss;

    	ss <<"select * from medicial where id="<<id<<";";
    query=ss.str();

    const char *q=query.c_str();
           qstate=mysql_query(conn,q);
        res=mysql_store_result(conn);

        qstate=mysql_num_rows(res);




			if(qstate==1)
			{
				gotoxy(20+35,31);
				printf("ID Allready Exists");
				gotoxy(20+35,33);
				cout<<"Update Stock [y/n]";
				ch=getche();
				if(ch=='y' or ch=='Y')
                {
                    update_stock();
                }

				system("cls");
				medi_entry();
			}





			gotoxy(58+35,11);
			cin>>temp.medi_name;
			p_r.medir_name=temp.medi_name;

			gotoxy(25+35,14);

			cin>>temp.rack;

			gotoxy(58+35,14);
			cin>>temp.cabnit;

			gotoxy(25+35,18);
            cin>>temp.comp_name;

            string name;
			supp:


			gotoxy(58+35,18);
        cin>>name;

	   stringstream os;

os <<"select * from supplier where name like'"<<name<<"';";
                    query=os.str();
            const char *q1=query.c_str();
           qstate=mysql_query(conn,q1);

            res=mysql_store_result(conn);
            qstate=mysql_num_rows(res);
          if(qstate==0)
			{
			    gotoxy(58+35,18);
			    cout<<"NO Such Supplier Exits";
                getch();
			    system("cls");
		box();
		lbox();
		gotoxy(30+35,8);

		printf(" MEDICINE PURSHASE  ");
		{

			gotoxy(7+35,11);
			printf("MEDICINE ID    : ");

			gotoxy(40+35,11);
			printf("MEDICINE NAME  : ");

			gotoxy(7+35,14);
			printf("ENTER RACK NO  : ");

			gotoxy(40+35,14);
			printf("CABNIT NO      : ");

			gotoxy(7+35,18);
			printf("COMPANY NAME   : ");

			gotoxy(40+35,18);
			printf("SUPPLIER NAME  : ");

			gotoxy(7+35,21);
			printf("UNIT COST   Rs.:  ");

			gotoxy(40+35,21);
			printf("SALE COST   Rs.: ");

			gotoxy(7+35,24);
			printf("QUANTITY       :  ");

			gotoxy(7+35,27);
			printf("MFG.DATE(dd-mm-yyyy): ");

			gotoxy(7+35,29);
			printf("EXP.DATE(dd-mm-yyyy): ");

			gotoxy(25+35,11);
			cout<<id;

            gotoxy(58+35,11);
			cout<<temp.medi_name;

			gotoxy(25+35,14);

			cout<<temp.rack;

			gotoxy(58+35,14);
			cout<<temp.cabnit;

			gotoxy(25+35,18);
            cout<<temp.comp_name;

            goto supp;

			}
        }
            temp.supp_name=name;
			p_r.supp_name=temp.supp_name;

			gotoxy(25+35,21);

			cin>>temp.unit;
			p_r.rate=temp.unit;

			gotoxy(58+35,21);

			cin>>temp.sale;
			gotoxy(25+35,24);

			cin>>temp.quantity;
			p_r.qty=temp.quantity;

			gotoxy(29+35,27);
			cin>>temp.manu_date;

			gotoxy(29+35,29);
			cin>>temp.exp_date;

			gotoxy(7+35,31);
			printf("==========================================================");
			temp.total=temp.quantity*temp.sale;

			gotoxy(10+35,33);
			printf("TOTAL SALE COST = Rs. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);
			gotoxy(40+35,33);
			printf("TOTAL UNIT COST = Rs. %.2f",temp.cost);
			p_r.total=temp.cost;
			p_r.sDay=now->tm_mday;
			p_r.sMonth=now->tm_mon;
			p_r.sYear=now->tm_year;
		 }
		gotoxy(20+35,35);

		printf("Save");
		gotoxy(28+35,35);

		printf("Cancel");
		gotoxy(18+35,38);
		printf("Press First charecter for the operation : ");


		ch=toupper(getche());

		if(ch=='S')
		{

            stringstream ss;
			qstate=0;
            ss <<"insert into medicial values("<<id<<",'"<<temp.medi_name<<"',"<<temp.rack<<",'"<<temp.cabnit<<"','"<<temp.comp_name<<"','"<<temp.supp_name<<"',"<<temp.unit<<","<<temp.sale<<","<<temp.quantity<<",'"<<temp.manu_date<<"','"<<temp.exp_date<<"');";


            query=ss.str();

            const char *q2=query.c_str();
      qstate=mysql_query(conn,q2);
                cout<<mysql_error(conn)<<endl;


            stringstream qs;
			qstate=0;
           qs <<"insert into purchase values("<<id<<",'"<<p_r.medir_name<<"','"<<p_r.supp_name<<"',"<<p_r.qty<<","<<p_r.rate<<","<<p_r.total<<",'"<<p_r.sYear+1900<<"-"<<p_r.sMonth<<"-"<<p_r.sDay<<"');";
            query=qs.str();
         const char *q3=query.c_str();
           qstate=mysql_query(conn,q3);

            getch();
			system("cls");
			box1();
			gotoxy(20+35,20);
			printf("Medicine Added sucessfully!!!!!!");
			gotoxy(20+35,25);
			printf("More entries  [y/n]");
			ch=toupper(getche());
            if(ch=='Y')
			{
				system("cls");
				medi_entry();
			}
			else if (ch=='N')
            {
                clear();
                medicine();
            }

		}

	   }
}

//===========FOR MEDICINE SALE=========================
void medi_sale()
{
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

  struct bill bil;
  time_t t = time(0);
    struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char ch;
  string tamediname,c_name,cname,u,s,qunt;
    int tar;
    int unit,sale,quantity;

  d1=now->tm_mday;
  m=now->tm_mon+1;
  y=now->tm_year;

		system("cls");
		box();
		for(i=3;i<=45;i++)
		{
		gotoxy(50+35,i);
		printf("%c",219);
		}
		i=9;
		gotoxy(52+35,7);
		printf("Cust_ID    Cust_Name");

		query="select * from customer;";
        const char *q=query.c_str();
        qstate=mysql_query(conn,q);

        res=mysql_store_result(conn);

		while(row=mysql_fetch_row(res))
		{
			gotoxy(53+35,i);
			cout<<row[0];
			gotoxy(64+35,i);
			cout<<row[1];
			i+=2;
		}

		gotoxy(9+35,7);
		printf("ENTER MEDICINE ID TO BE SOLD  : ");
        cin>>tar;
		j=0;


		 stringstream ss;

    	ss <<"select * from medicial where id="<<tar<<";";
        query=ss.str();


        const char *kl=query.c_str();
        qstate=mysql_query(conn,kl);
        res=mysql_store_result(conn);

        row=mysql_fetch_row(res);
        qstate=mysql_num_rows(res);

        if(qstate!=1)

		{
		    cout<<"hi";
			system("cls");
			gotoxy(33+35,10);
			printf("Not in stock!!!!!");
			getch();
			return;
		}





       if(qstate==1)
        {



        temp.medi_name=row[1];
        temp.cabnit=row[3];
        temp.comp_name=row[4];
        temp.supp_name=row[5];
        u=row[6];
        s=row[7];
        qunt=row[8];


        unit=stoi(u);
        sale=stoi(s);
    quantity=stoi(qunt) ;



				gotoxy(8+35,10);
				printf(" Medicine Name        : ");
				cout<<temp.medi_name;
				gotoxy(8+35,12);
				cout<<" Quantity in stock    : ";
                cout<<quantity;
				gotoxy(8+35,14);
                printf(" Sales price          : ");
                cout<<sale;
				gotoxy(8+35,16);
				printf("Enter bill number     : ");
                cin>>bil.billno;
				gotoxy(8+35,18);
				printf("Enter customer Name   : ");
                cin>>c_name;
				gotoxy(8+35,20);
				printf("Quantity want to sale : ");
				cin>>a;

				pr_r.profit=(sale-unit)*a;

				temp.quantity=(quantity-a);
				temp.total=(quantity*sale);
				temp.cost=(quantity*unit);
				temp.bye=(sale*a);
				b=temp.bye;
				temp.qty=a;

				bil.cname=c_name;
				s_r.cust_name=c_name;
				bil.mediname=temp.medi_name;
				bil.medi_qty=a;
				bil.medi_rate=sale;
				bil.total=sale*a;

				bil.day=d1;
				bil.month=m;
				bil.year=y+1900;

				stringstream po;

            po <<"insert into bill(id,consumer,medicine,quantity,rate,total,date) values("<<bil.billno<<",'"<<bil.cname<<"','"<<bil.mediname<<"',"<<bil.medi_qty<<","<<bil.medi_rate<<","<<bil.total<<",'"<<bil.year<<"-"<<bil.month<<"-"<<bil.day<<"');";
            //getch();
			query=po.str();
			const char *w=query.c_str();
				qstate=mysql_query(conn,w);

				s_r.sDay=d1;
				s_r.sMonth=m;
				s_r.sYear=y+1900;
				s_r.medi_id=tar;
				s_r.medir_name=temp.medi_name;
				s_r.qty=a;
				s_r.rate=sale;
				s_r.total=sale*a;

				//sale report

				stringstream s;

            s <<"insert into salereport(id,medicine,consumer,quantity,rate,total,date) values("<<s_r.medi_id<<",'"<<s_r.medir_name<<"','"<<s_r.cust_name<<"',"<<s_r.qty<<","<<s_r.rate<<","<<s_r.total<<",'"<<s_r.sYear<<"-"<<s_r.sMonth<<"-"<<s_r.sDay<<"');";

			query=s.str();
			const char *r=query.c_str();
				qstate=mysql_query(conn,r);

                //profit report

				pr_r.sDay=d1;
				pr_r.sMonth=m;
				pr_r.sYear=y+1900;
				pr_r.medi_id=tar;
				pr_r.medir_name=temp.medi_name;
				pr_r.qty=a;
				pr_r.rate=sale;
				pr_r.unit=unit;

				stringstream ppo;

            ppo <<"insert into profitreport(id,medicine,quantity,unit,rate,profit,date) values("<<pr_r.medi_id<<",'"<<s_r.medir_name<<"',"<<pr_r.qty<<","<<pr_r.unit<<","<<pr_r.rate<<","<<pr_r.profit<<",'"<<pr_r.sYear<<"-"<<pr_r.sMonth<<"-"<<pr_r.sDay<<"');";

			query=ppo.str();
			const char *ru=query.c_str();
			qstate=mysql_query(conn,ru);
            system("cls");

		stringstream k;

            k <<"update medicial set quantity="<<temp.quantity<<" where id="<<tar<<";";

			query=k.str();
			const char *ro=query.c_str();
			qstate=mysql_query(conn,ro);


		system("cls");
		box();
		gotoxy(8+35,15);
		printf("* Price paid by customer = %.2f",b);
		gotoxy(8+35,17);
		printf("* Quantity sold          = %d",a);
		getch();
		gotoxy(10+35,20);
		printf("more enteries=(y/n) :");
		ch=getche();
		if(ch=='Y'||ch=='y')
            medi_sale();
        }

 }


 //=============================== FOR MEDICINE SEARCH ====================
void medi_search()
{
   conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

  int mid;
  int i;
  char ch;

  system("cls");

	   system("cls");
	   box();

	   gotoxy(10+35,7);
	   printf("Enter Medicine Id to be searched : ");
	   cin>>mid;
	   system("cls");
	   box();
	   lbox();
	   gotoxy(45+25,8);
	   printf(" MEDICINE ");
        i=16;
	   gotoxy(9+35,12);
	   printf("ID. MEDICINE NAME.   QTY   Supplier_Name   Man.Date     Exp.Date");
	   gotoxy(9+35,14);
	   printf("==================================================================\n");

	   		 stringstream ss;

    	ss <<"select * from medicial where id="<<mid<<";";
        query=ss.str();


        const char *kl=query.c_str();
        qstate=mysql_query(conn,kl);
        res=mysql_store_result(conn);

        row=mysql_fetch_row(res);
        qstate=mysql_num_rows(res);


        if(qstate==1)
		{
			gotoxy(9+35,i);
			cout<<row[0];
			gotoxy(15+35,i);
			cout<<row[1];
			gotoxy(32+35,i);
            cout<<row[8];
			gotoxy(40+35,i);
			cout<<row[5];
			gotoxy(52+35,i);
			cout<<row[9];
            gotoxy(65+35,i);
			cout<<row[10];


		}


        else
	   {
		gotoxy(20+35,20);
		printf("Not in Stock.....");
	   }

        gotoxy(10+35,20);
		printf("search another medicine[y/n]");
		ch=getche();
		if(ch=='Y'||ch=='y')
            medi_search();
        clear();

}
//===========================MEDICINE STOCK=====================================
void stock()
{
  char ch;
  int i,c;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

	   do
	   {
        stringstream ss;
        ss <<"select * from medicial";
        query=ss.str();


        const char *kl=query.c_str();
        qstate=mysql_query(conn,kl);
        res=mysql_store_result(conn);


        qstate=mysql_num_rows(res);

		system("cls");
		box();
		lbox();

		gotoxy(30+35,8);

		printf(" STOCK OF MEDICINE ");

		i=14;
		gotoxy(9+35,10);
		printf("ID. MEDICINE NAME.   QTY   Supplier_Name   Man.Date     Exp.Date");
		gotoxy(9+35,12);
		printf("==================================================================\n");

		while( row=mysql_fetch_row(res))
		{
            gotoxy(9+35,i);
			cout<<row[0];
			gotoxy(15+35,i);
			cout<<row[1];
			gotoxy(32+35,i);
            cout<<row[8];
			gotoxy(40+35,i);
			cout<<row[5];
			gotoxy(52+35,i);
			cout<<row[9];
            gotoxy(65+35,i);
			cout<<row[10];
			i+=2;
		}
		gotoxy(10+35,42);
		printf("Press [1] for Update Medicine Stock  & [0] for main menu ");
		c = (getche());
		switch (c)
		{
			case '0':animation();
				 main_menu();
				 break;
			case '1':update_stock();
				 break;
		}

	   }while(c != '1');
	   getche();
}
//============================ FOR MEDICINE UPDATE =====================
void update_stock()
{
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

    int d1,m,y;
      time_t t = time(0);
    struct tm * now = localtime( & t );
  int mid;
  int j,a,count=0,n;
  system("cls");
    d1=now->tm_mday;
  m=now->tm_mon+1;
  y=now->tm_year;
  string u,s,qunt;
  int unit,sale,quantity;

	   system("cls");
	   box();

	   gotoxy(27+35,8);

	   printf(" UPDATE MEDICINE QUANTITY ");

	   gotoxy(9+35,10);
	   printf("Enter medicine id to be update qty: ");
        cin>>mid;
        stringstream ss;
        ss <<"select * from medicial where id="<<mid<<";";
        query=ss.str();


        const char *kl=query.c_str();
        qstate=mysql_query(conn,kl);
        res=mysql_store_result(conn);


        qstate=mysql_num_rows(res);
		if(qstate==1)
		{
		    row=mysql_fetch_row(res);
			gotoxy(8+35,12);
			cout<<"Medicine Name     :";
			cout<<row[1];
			gotoxy(8+35,14);
			cout<<"Quantity In Stock  : ";
			cout<<row[8];
			gotoxy(8+35,16);
			cout<<"Quantity want to update : ";
			cin>>a;

        temp.medi_name=row[1];
        temp.cabnit=row[3];
        temp.comp_name=row[4];
        temp.supp_name=row[5];
        u=row[6];
        s=row[7];
        qunt=row[8];


            unit=stoi(u);
            sale=stoi(s);
            quantity=stoi(qunt) ;



			p_r.sDay=now->tm_mday;
			p_r.sMonth=now->tm_mon;
			p_r.sYear=now->tm_year;


			quantity=quantity+a;


        stringstream qs;
        qstate=0;
        qs <<"insert into purchase values("<<mid<<",'"<<temp.medi_name<<"','"<<temp.supp_name<<"',"<<a<<","<<unit<<","<<unit*quantity<<",'"<<p_r.sYear+1900<<"-"<<p_r.sMonth<<"-"<<p_r.sDay<<"');";
            query=qs.str();
         const char *q3=query.c_str();
           qstate=mysql_query(conn,q3);


        stringstream k;

            k <<"update medicial set quantity="<<quantity<<" where id="<<mid<<";";

			query=k.str();
			const char *ro=query.c_str();
			qstate=mysql_query(conn,ro);
        gotoxy(33+35,30);
		 cout<<"Stock Updated ";
		 return;

		}

	   else
	   {
		 system("cls");
		 gotoxy(33+35,10);
		 printf("Not in stock!!!!!!");
		 return;
	   }

}

//===================== view report =============================/
void sale_rpt()
{
  char ch;
  int j;
  system("cls");
  conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

        box();
	   lbox();
	   gotoxy(30+35,8);

	   printf("Sales Report");
      gotoxy(7+35,10);
	   printf("ID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
	   gotoxy(7+35,12);
	   printf("===================================================================");
	   query="select * from salereport;";
	   const char *q=query.c_str();

	   qstate=mysql_query(conn,q);

	   res=mysql_store_result(conn);

	   j=14;

	   while(row=mysql_fetch_row(res))
	   {
		gotoxy(6+35,j);
		cout<<row[1];
		gotoxy(11+35,j);
		cout<<row[2];
		gotoxy(28+35,j);
		cout<<row[3];
		gotoxy(44+35,j);
        cout<<row[4];
		gotoxy(50+35,j);
		cout<<row[5];
		gotoxy(57+35,j);
		cout<<row[6];
		gotoxy(65+35,j);
		cout<<row[7];
		j=j+2;
	   }
	   getche();
}
//======================= VIEW Profit REPORT ===========================
void profit_rpt()
{
  char ch;
  int j;
  system("cls");
  conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

        box();
	   lbox();

	   gotoxy(30+35,8);

	   printf("Profit Report");
      gotoxy(7+35,10);
	   printf("ID. Medicine Name.   Date        Qty.  Unit Price  Sale Price. Profit. ");
	   gotoxy(7+35,12);
	   printf("===================================================================");
	   query="select * from profitreport;";
	   const char *q=query.c_str();

	   qstate=mysql_query(conn,q);

	   res=mysql_store_result(conn);

	   j=14;

	   while(row=mysql_fetch_row(res))
	   {
        gotoxy(6+35,j);

		cout<<row[1];
		gotoxy(11+35,j);
        cout<<row[2];
        gotoxy(28+35,j);
		cout<<row[7];
		gotoxy(41+35,j);
		cout<<row[3];
		gotoxy(48+35,j);
		cout<<row[4];
		gotoxy(60+35,j);
		cout<<row[5];
		gotoxy(70+35,j);
		cout<<row[6];
		gotoxy(10+35,j);
		printf("%c",124);

		j=j+2;
	   }
	   gotoxy(70+35,j);
	   getche();
}
//========================= report of profit ===========================
void pur_rpt()
{

  char ch;
  int j;
  system("cls");
  conn=mysql_init(0);
    conn=mysql_real_connect(conn,"localhost","root","","ds",0,NULL,0);

        box();
	   lbox();

	   gotoxy(30+35,8);

	   printf("Purchase Report");
      gotoxy(7+35,10);
	 printf("ID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
	   gotoxy(7+35,12);
	   printf("===================================================================");
	   query="select * from purchase;";
	   const char *q=query.c_str();

	   qstate=mysql_query(conn,q);

	   res=mysql_store_result(conn);

	   j=14;

	   while(row=mysql_fetch_row(res))
	   {
		gotoxy(6+35,j);
		cout<<row[0];
		gotoxy(11+35,j);
		cout<<row[1];
		gotoxy(28+35,j);
		cout<<row[2];
		gotoxy(44+35,j);
        cout<<row[3];
		gotoxy(50+35,j);
		cout<<row[4];
		gotoxy(57+35,j);
		cout<<row[5];
		gotoxy(65+35,j);
		cout<<row[6];
		j=j+2;
	   }
	   getche();
}






