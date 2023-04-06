#include <iostream>
#include<fstream>
#include<windows.h>
using namespace std;


struct student
{
char name[90];
char id[90];
int roll_no;
float prog_m,arch_m,writing_sk,alg_m,sum,average;
};
void intro();
void mainmenu();
void acceptdata();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{
    system("color a");
    char c;
    system("cls");
    intro();

    do{
   system("cls");
   system("color e");
   cout<<"\n\n";
   cout<<"\t======= Student Grade Management System ========"<<endl;
   cout<<endl;
   cout<<"\t\t\t\t1. Main Menu\n\n";
   cout<<"\t\t\t\t2. Exit\n\n";
   cout<<"Enter the Options:";
   cin>>c;
   system("cls");
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }
   
   }
    }while(c!='2');
    return 0;
}
void acceptdata()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"The file cannot be open...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t======= Create a Report Card ========\n\n";
    cout<<"First Name: ";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"Student ID Number:  ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"Roll Nu";
    cin>>s.roll_no;
    cout<<"Enter the Programming Grade:  ";
    cin>>s.prog_m;
    cout<<"Enter the Computer Architecture Grade :";
    cin>>s.arch_m;
    cout<<"Enter the Writing Grade :";
    cin>>s.writing_sk;
    cout<<"Enter the Algebra Grade :";
    cin>>s.alg_m;
    s.sum=s.prog_m+s.arch_m+s.writing_sk+s.alg_m;
    s.average=(s.sum/4);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tFile is Saved"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void intro()

{

    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(300);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(300);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\tWelcome to the Student Grade Management System"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void mainmenu()

{
    system("color c");
    char cc;
    cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t1. Create a Student Report Card\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t2. View All Students Report Cards\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t3. View a Single Report Card\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t4. Modify Student's Report Card\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t5. Result\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t6. Delete Record\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\t\tEnter Choice...:) <1-6> :";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
    case '2':
        {
            viewall();
            break;
        }
    case '3':
          {
              int n;
              cout<<"Enter your Roll Number :";
              cin>>n;
              view_Specific(n);
              break;
          }
    case '4':
        {
            int n;
            cout<<"Enter your Roll Number :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout << "Enter your Roll Number :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout << "Enter your Roll Number :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}

void viewall()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"File Not Opened.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\tAll Students Report Cards"<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tStudent's Name :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tID Number :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tRoll Number :"<<s.roll_no<<endl<<endl;
        cout<<"\t\t\t\tProgramming Grade :"<<s.prog_m<<endl<<endl;
        cout<<"\t\t\t\tComputer Architecture Grade :"<<s.arch_m<<endl<<endl;
        cout<<"\t\t\t\tWriting Grade :"<<s.writing_sk<<endl<<endl;
        cout<<"\t\t\t\tAlgebra Grade :"<<s.alg_m<<endl<<endl;
        cout<<"\t\t\t\tTotal Grade :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAverage Grade :"<<s.average<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNo Record Found..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"File Could not be opened ...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t==========Single Student Report==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll_no==n)
        {
        cout<<"\t\t\t\tStudent Name :"<<s.name<<endl;
        cout<<"\t\t\t\tStudent ID :"<<s.id<<endl;
        cout<<"\t\t\t\tRoll Number :"<<s.roll_no<<endl;
        cout<<"\t\t\t\tProgramming Grade :"<<s.prog_m<<endl;
        cout<<"\t\t\t\tComputer Architecture Grade :"<<s.arch_m<<endl;
        cout<<"\t\t\t\tWriting Skills Grade:"<<s.writing_sk<<endl;
        cout<<"\t\t\t\tAlgebra Grade :"<<s.alg_m<<endl;
        cout<<"\t\t\t\tTotal :"<<s.sum<<endl;
        cout<<"\t\t\t\tAverage :"<<s.average<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRecord not Found..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"File Not Opened..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========View Result for Single Student==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll_no==n)
        {
        cout<<"\t\t\t\tStudent's Name:"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tProgramming Grade :"<<s.prog_m<<endl<<endl;
        cout<<"\t\t\t\tComputer Architecture Grade  :"<<s.arch_m<<endl<<endl;
        cout<<"\t\t\t\tWriting Skills Grade :"<<s.writing_sk<<endl<<endl;
        cout<<"\t\t\t\tAlgebra Grade :"<<s.alg_m<<endl<<endl;
        cout<<"\t\t\t\tTotal :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAverage :"<<s.average<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRecord not Found..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"The File cannot be opened..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========Modify the Report Card==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.roll_no==n)
         {
        cout<<"\t\t\t\tStudent Name :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tStudent ID Number :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tRoll Number :"<<s.roll_no<<endl<<endl;
        cout<<"\t\t\t\tProgramming Grade :"<<s.prog_m<<endl<<endl;
        cout<<"\t\t\t\tComputer Architecture Grade :"<<s.arch_m<<endl<<endl;
        cout<<"\t\t\t\tWriting Grade :"<<s.writing_sk<<endl<<endl;
        cout<<"\t\t\t\tAlgebra Grade :"<<s.alg_m<<endl<<endl;
        cout<<"============================================="<<endl;
        cout<<"\t\tEnter the Information"<<endl;
        cout<<"============================================="<<endl;
        cout<<"Enter Your Full Name :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ID Number : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"Roll Number :";
    cin>>s.roll_no;
    cout<<"Programming Grade :";
    cin>>s.prog_m;
    cout<<"Computer Architecture Grade :";
    cin>>s.arch_m;
    cout<<"Writing Skills Grade :";
    cin>>s.writing_sk;
    cout<<"Algebra Grade:";
    cin>>s.alg_m;
    s.sum=s.prog_m+s.arch_m+s.writing_sk+s.alg_m;
    s.average=(s.sum/4);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tThe File is updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRecord Not Found"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"The File Canot be Opened..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========Delete a Report Card==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.roll_no!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRecord Deleted"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }


