#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int seat=60;

class book
{
public:
  string code;
  string name;
  string date;
  int cost;

  void insert_details()
  {
    string k;
    ofstream fout;
    book b;
    cout<<"Enter Movie Code: ";
    cin>>b.code;
    cout<<"Enter Movie Name: ";
    getline(cin,k);
    getline(cin,b.name);
    cout<<"Enter Release Date: ";
    cin>>b.date;
    cout<<"Enter the cost per ticket: ";
    cin>>b.cost;

    fout.open("data.txt",ios::app);

    fout<<b.code<<" "<<b.date<<" "<<b.cost<<" "<<b.name<<endl;
  	printf("Record insert Sucessfull\n");

    fout.close();
  }

  void find()
  {
    book b;
    ifstream fin;

    string ch;
    cout<<"Enter movie code: ";
    cin>>ch;

    fin.open("data.txt");

    while(fin)
  	{
      fin>>b.code>>b.date>>b.cost;
      getline(fin,b.name);
  		if(b.code==ch)
  		{
  			printf("\n Record Found\n");
        cout<<"\n\t\tCode ::"<<b.code;
        cout<<"\n\t\tMovie Name ::"<<b.name;
        cout<<"\n\t\tMovie Date ::"<<b.date;
        cout<<"\n\t\tPrice of Ticket ::"<<b.cost;
        break;
  		}
  	}

    fin.close();
  }

  void viewAll()
  {
  	string line;
  	ifstream fin;

    fin.open("data.txt");

  	while(fin)
    {
      getline(fin,line);
      cout<<line<<endl;
    }

  	fin.close();
  }

  void book_ticket()
  {
    book b;
  	ifstream fin;

  	int total_seat,total_amount;
  	string name,mobile;


  	string line;
  	string movie_code;

  	fin.open("data.txt");

  	system("clear");
  	while(fin)
    {
      getline(fin,line);
      cout<<line<<endl;
    }

    fin.close();
  	printf("\n For Book ticket Choose Movie\n");
  	printf("\n Enter movie code :");
  	cin>>movie_code;

  	fin.open("data.txt");

  	while(fin)
  	{
      fin>>b.code>>b.date>>b.cost;
      getline(fin,b.name);
  		if(b.code==movie_code)
  		{
  			printf("\n Record Found\n");
        cout<<"\n\t\tCode ::"<<b.code;
        cout<<"\n\t\tMovie name ::"<<b.name;
        cout<<"\n\t\tRelease Date ::"<<b.date;
        cout<<"\n\t\tPrice of ticket::"<<b.cost;
        break;
  		}
  	}
    string k;
  	printf("\n* Fill Deatails  *");
  	printf("\n your name :");
    getline(cin,k);
  	getline(cin,name);
  	printf("\n mobile number :");
  	cin>>mobile;
  	printf("\n Total number of tickets :");
  	cin>>total_seat;


  	total_amount = b.cost * total_seat;

  	printf("\n ENJOY MOVIE \n");
    cout<<"\n\t\tName :"<<name;
    cout<<"\n\t\tMobile Number : "<<mobile;
    cout<<"\n\t\tMovie Name : "<<b.name;
    cout<<"\n\t\tTotal seats : "<<total_seat;
    cout<<"\n\t\tCost per Ticket : "<<b.cost;
    cout<<"\n\t\tTotal Amount : "<<total_amount;

    ofstream fout;
    fout.open("oldTransection.txt",ios::app);
    fout<<name<<" "<<mobile<<" "<<total_seat<<" "<<total_amount<<" "<<b.name<<" "<<b.cost<<endl;
  	printf("\n Record insert Sucessfull to the old record file");
  	printf("\n");
  	fin.close();
    fout.close();
  }

  void old_record()
  {
  	string line;
  	ifstream fin;

    fin.open("oldTransection.txt");

  	system("clear");
  	while(fin)
    {
      getline(fin,line);
      cout<<line<<endl;
    }

  	fin.close();
  }

};

int main()
{
  int ch;
  book ba;
 do{
 printf("\n====================================================================");
 printf("\n");
 printf("\t Moive Ticket booking ");
 printf("\n");
 printf("\n====================================================================");

 printf("\nPress <1> Insert Movie");
   printf("\nPress <2> View All Movie");
 printf("\nPress <3> Find Movie ");
 printf("\nPress <4> Book Ticket");
 printf("\nPress <5> View All Transections");
   printf("\nPress <0> Exit ");

   printf("\nEnter your Choice ::");
   scanf("%d",&ch);

   switch (ch)
   {
       case 1 :
       ba.insert_details();
     break;
   case 2:
       ba.viewAll();
     break;

   case 3:
       ba.find();
     break;

   case 4:
   ba.book_ticket();
   break;

   case 5:
   ba.old_record();
   break;

       case 0:
       exit(0);
       break;

       default:
       printf("Wrong choice !");
       break;
   }
}while(ch!=0);

}
