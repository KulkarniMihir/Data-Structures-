/*
	Mihir Kulkarni
	SE09 F9 23133
	Assignment 11 : Implementation of Sequential File 
*/
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

class student
{
	int roll_no,marks;
	char name[20];
    public:
    	void input(int n);
    	void display();
    	void modify();
    	void del();
    	void search();
};

void student::input(int n)			
{
	fstream outfile;
	outfile.open("students.txt",ios::app);
	
	for(int i=0;i<n;i++)
	{
	cout<<"\nEnter roll no. of the student: ";
	cin>>roll_no;
	cout<<"Enter name of the student: ";
	cin>>name;
	cout<<"Enter marks: ";
	cin>>marks;
	outfile<<roll_no<<"\t"<<name<<"\t"<<marks<<endl;
	}
	
	outfile.close();
	cout<<"\nRecord(s) written to the file successfully!"<<endl;
}

void student::display()
{
	fstream infile;
	infile.open("students.txt",ios::in);
	
	cout<<"\n-------------------------------------------"<<endl;
	cout<<"Roll no.\tName\t\tMarks"<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	while(infile>>roll_no>>name>>marks)
	{
		
		cout<<roll_no<<"\t\t"<<name<<"\t\t"<<marks<<endl;
	}
	
	infile.close();
}

void student::modify()
{
	int roll;
	int flag=0;
	cout<<"\nEnter roll no. whose record has to be modified: ";
	cin>>roll;
	
	fstream infile,outfile;
	infile.open("students.txt",ios::in);
	outfile.open("temp.txt",ios::out);
	
	while(infile>>roll_no>>name>>marks)
	{
	
		if(roll_no==roll)
		{
			flag=1;
			cout<<"\nEnter the modified marks:"<<endl;
			cin>>marks;
			cout<<"\nModification successful!"<<endl;
		}
		outfile<<roll_no<<"\t"<<name<<"\t"<<marks<<endl;
	}
	if(flag==0)
	{
		cout<<"\nNo record found!"<<endl;
	}
	infile.close();
	outfile.close();
}

void student::del()
{
	int roll;
	int flag=0;
	cout<<"\nEnter the roll no. whose record has to be deleted: ";
	cin>>roll;
	
	fstream infile,outfile;
	infile.open("students.txt",ios::in);
	outfile.open("temp.txt",ios::out);
	
	while(infile>>roll_no>>name>>marks)
	{
	
		if(roll_no==roll)
		{
			flag=1;
			cout<<"\nRecord deleted successfully!"<<endl;
		}
		else
		{
			outfile<<roll_no<<"\t"<<name<<"\t"<<marks<<endl;
		}
		
	}
	if(flag==0)
	{
		cout<<"\nNo record found!"<<endl;
	}
	//cout<<"\nRecord deleted successfully!"<<endl;
	infile.close();
	outfile.close();
}

void student::search()
{
	int roll;
	int flag=0;
	cout<<"\nEnter roll no. whose record has to be searched: ";
	cin>>roll;
	
	fstream infile,outfile;
	infile.open("students.txt",ios::in);
	//outfile.open("temp.txt",ios::out);
	
	while(infile>>roll_no>>name>>marks)
	{
	
		if(roll_no==roll)
		{
		flag = 1;
			cout<<"\nRecord Found!"<<endl;
			cout<<"\n-------------------------------------------"<<endl;
			cout<<"Roll no.\tName\t\tMarks"<<endl;
			cout<<roll_no<<"\t\t"<<name<<"\t\t"<<marks<<endl;
		}
		//outfile<<roll_no<<"\t"<<name<<"\t"<<marks<<endl;
	}
	if(flag==0)
	{
		cout<<"\nNo record found!"<<endl;
	}
	infile.close();
	//outfile.close();
}

int main()
{
	student s;
	int choice;
	int i,n;
	do
	{
		cout<<"\n***FILE MENU***\n1)Create database\n2)Add a record\n3)Display database\n4)Delete a record\n5)Modify a record\n6)Search a record\n0)Exit\nEnter your choice :";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the number of records to be added:"<<endl;
			cin>>n;
			s.input(n);
			break;
		case 2:
			s.input(1);
			n++;
			break;
		case 3:
			s.display();
			break;
		case 4:
			s.del();
			remove("students.txt");
			rename("temp.txt","students.txt");
			break;
		case 5:
			s.modify();
			remove("students.txt");
			rename("temp.txt","students.txt");
			break;
		case 6:
			s.search();
			break;
		case 0:
			cout<<"\n***Program Closed***\n";
			break;
		}
	}while(choice != 0);
	return 0;
}
