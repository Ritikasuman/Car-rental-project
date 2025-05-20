#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<direct.h>
#include<iomanip>
using namespace std;
class customer
{
	public:
		string customername;
		string carmodel;
		string carnumber;
		char data;
};
class rent : public customer
{
	public:
		int days=0,rentalfee=0;
		int login();
		void data()
		{	
		  ifstream inf("Wel.txt");
                char str[800];
                while (inf)
                {
                    inf.getline(str,300);
                    if(inf)cout<<str<<endl;
                }
                inf.close();
            sleep(2);
            system("CLS");
			login();
			sleep(1);
			system("CLS");
			cout<<"\t\t\t\t Please Enter your Name : ";
			cin>>customername;
			cout<<endl;
			int i = 1;
			do 
			{
				cout<<"\t\t\t\t Please Select a Car"<<endl;
				cout<<"\t\t\t\t Enter 'A' For Tesla 2011"<<endl;
				cout<<"\t\t\t\t Enter 'B' For Hyundai 2015"<<endl;
				cout<<"\t\t\t\t Enter 'C' For Ford 2017"<<endl;
				cout<<endl;
				cin>>carmodel;
				cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
				if (carmodel=="A")
				{
					system("CLS");
					cout<<"You Have Choosed Tesla Model 2011"<<endl;
					cout<<endl;
					ifstream inA("InfoA.txt");
					char str[200];
					while(inA)
					{
						inA.getline(str,200);
						if(inA)
						{
							cout<<str<<endl;
						}
					}
				}
				sleep(1);
				if (carmodel=="B")
				{
					system("CLS");
					
					cout<<"You Have Choosed Hyundai Model 2015"<<endl;
					cout<<endl;
					ifstream inB("InfoB.txt");
					char str[200];
					while(inB)
					{
						inB.getline(str,200);
						if(inB)
						{
							cout<<str<<endl;
						}
					}
				}
				sleep(1);
				if (carmodel=="C")
				{
					system("CLS");
					
					cout<<"You Have Choosed Ford Model 2017"<<endl;
					cout<<endl;
					ifstream inC("InfoC.txt");
					char str[200];
					while(inC)
					{
						inC.getline(str,200);
						if(inC)
						{
							cout<<str<<endl;
						}
					}
				}
				sleep(1);
				i++;
			} while (carmodel !="A" && carmodel !="B" && carmodel !="C");
			cout<<"____________________________"<<endl;
			cout<<"Please Enter your Information"<<endl;
			cout<<"Car Number : "<<endl;
			cin>>carnumber;
			cout<<endl;
			cout<<"Enter the NUmber of Days you want to Rent the Car : "<<endl;
			cin>>days;
			cout<<endl;
		}
		void calculate()
		{
			system("CLS");
			cout<<"Calculating Rent PLease wait..........."<<endl;
			sleep(2);
			if(carmodel=="A"||carmodel=="a")
			rentalfee=days*56;
			if(carmodel=="B"||carmodel=="b")
			rentalfee=days*60;
			if(carmodel=="C"||carmodel=="c")
			rentalfee=days*75;	
		}
		void show()
		{
			system("CLS");
			cout<<"\n\t\t                              Car Rental - Customer Invoice                    "<<endl;
			cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;             
			cout<<"\t\t[Invoice no. :] ----------------------------------------------------------------|\t"<<endl;
			cout<<"\t\t[Customer Name :] --------------------------------------------------------------|\t"<<customername<<endl;
			cout<<"\t\t[Car Model :]-------------------------------------------------------------------|\t"<<carmodel<<endl;
			cout<<"\t\t[Car no. :] --------------------------------------------------------------------|\t"<<carnumber<<endl;
			cout<<"\t\t[No. of Days :] ----------------------------------------------------------------|\t"<<days<<endl;
			cout<<"\t\t[Rental Amount :] --------------------------------------------------------------|\t"<<rentalfee<<endl;
			cout<<"\t\t[Caution Money :] --------------------------------------------------------------|\t"<<"0"<<endl;
			cout<<"\t\t[Advance :] --------------------------------------------------------------------|\t"<<"0"<<endl<<endl;
			cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
            cout<<"\t\t| Total Rental Amount is :"<<"----------------------------------------------------|\t"<<rentalfee<<" |"<<endl;
            cout<<"\t\t    # This is a computer generated invoice and it does not"<<endl;
            cout<<"\t\t    require and authorised signature  #"<<endl<<endl;
            cout<<"\t\t///////////////////////////////////////////////////////////////////////////////////"<<endl;
            cout<<"\t\t    you are advised to pay it before the due date."<<endl;
            cout<<"\t\t    otherwise penalty fee will be applied "<<endl;
            cout<<"\t\t///////////////////////////////////////////////////////////////////////////////////"<<endl;

                system("pause");
                system("cls");
                ifstream inf("Thnx.txt");
                char str[300];
                while (inf)
                {
                    inf.getline(str,300);
                    if(inf)cout<<str<<endl;
                }
                inf.close();
		}
};
int rent :: login()
{
	int passkey;
	cout<<"\t\t\t\t Enter Security Password : ";
	cin>>passkey;
	if(passkey==8008)
	{
		cout<<endl<<"\t\t\t\t Successfully login ( > - < )"; 
	}
	else 
	{
		cout<<"\t\t\t\t **Wrong PassWord** ";
		login();
	}
}
int main()
{
		FILE* InfoA;
			InfoA = fopen("InfoA.txt","r");
			fclose(InfoA);
			
		FILE* InfoB;
			InfoB = fopen("InfoB.txt","r");
			fclose(InfoB);
			
		FILE* InfoC;
			InfoC = fopen("InfoC.txt","r");
			fclose(InfoC);	
			
		FILE* Thnx;
			Thnx = fopen("Thnx.txt","r");
			fclose(Thnx);	
		FILE* Wel;
			Wel = fopen("Wel.txt","r");
			fclose(Wel);
	rent car;
	car.data();
	car.calculate();
	car.show();
}