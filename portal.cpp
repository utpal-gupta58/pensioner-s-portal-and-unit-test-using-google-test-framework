//password is  [sumankundu] for faculty and [superintendent] for office
#include<bits/stdc++.h>
#include<conio.h>   //system("PAUSE") and system("CLS")   
#include<fstream>   //File handling.
#include<map> 
#include <string> 
//#include"gtest/gtest.h"


#include "Huffman.h"   //For huffman encoding
//#include<chrono>  //Chrono for time.
#include<ctime>    //time library
using namespace std;

string Name;
int age,pension=0;
string department;


//Number of trials , admin can try for password. Can be changed dynamically.
int trial=0;
string encodedstring[1];
//password taken as input by console.
string pass[1];

int login(int member_check)
{
    if(trial>=1)
    {
        cout<<"\n\n\t\t\t unsuccessfull attempt"<<endl;
        //return 0;
        exit(0);
        //Exiting the program after Unsuccessfull attempt.

    }
    string name;
    char ch;
    if(member_check==0)
    {
        cout <<"\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO PENSIONER PORTAL OF IIT JODHPUR   \n\t\t\t\t\tLogin with your id to continue";
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Username or Institue ID: ";
        cin.ignore();
        getline(cin,name);
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
       //_getch() read input from console but it doesn't write that input on console.
        ch = _getch();
        while(ch != 13)
        {
        //character 13 is Enter defined under ASCII table, Carriage return line feed.
        pass[trial].push_back(ch);
        //Printing * as console takes input. It secures the password.
        cout << '*';
        ch = _getch();
        }
        //calculatinf freq of each character of password.
        calcFreq(pass[trial],pass[trial].length());
        //Build the huffman tree.
        HuffmanCodes(pass[trial].length());
        //Get the encoded string.
        for(int i=0;i<pass[trial].length();i++){
            encodedstring[trial]+=codes[pass[trial][i]];
        }
        //Compare with encoded actual password.
        if(encodedstring[trial] == "000111001010011011110100111"){
            cout << "\n\n\n\n\t\t\t\t\t Welcome To the System Mr. "<<name<<"\n\n";    
            system("PAUSE");   //Press any key to continue...
            cin.get();
            return 1;
        }else{
            trial++;
            cout << "\n\n\n\n\t\t\t\t\t\aWrong password...Please Try Again!!\n";
            system("PAUSE");
           system("CLS");   //Opening console with cleared previous lines.
            login(member_check);
            
        }

    }
    else if(member_check==1)
    {
        cout <<"\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO PENSIONER PORTAL OF IIT JODHPUR   \n\t\t\t\t\tLogin with your Office id to continue";
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Username or Institue ID: ";
        cin.ignore();
        getline(cin,name);
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
        ch = _getch();
        while(ch != 13)
        {
        //character 13 is Enter defined under ASCII table, Carriage return line feed.
        pass[trial].push_back(ch);
        //Printing * as console takes input. It secures the password.
        cout << '*';
        ch = _getch();
        }
        calcFreq(pass[trial],pass[trial].length());
        //Build the huffman tree.
        HuffmanCodes(pass[trial].length());
        //Get the encoded string.
        for(int i=0;i<pass[trial].length();i++){
            encodedstring[trial]+=codes[pass[trial][i]];
        }
        //Compare with encoded actual password.
        if(encodedstring[trial] == "101011111110011011100100110010010000100110"){
            cout << "\n\n\n\n\t\t\t\t\t Welcome To the System Mr. "<<name<<"\n\n";            
           system("PAUSE");   //Press any key to continue...
            cin.get();
            return 1;
            
        }else{
            trial++;
            cout << "\n\n\n\n\t\t\t\t\t\aWrong password...Please Try Again!!\n";
            system("PAUSE");
            system("CLS");   //Opening console with cleared previous lines.
            cin.get();
            login(member_check);
        }
    }
    
}
int resignation_approval()
{
                char a,c,b;
                cout<<"\n\n\t\t\tAre your dues Completed? press Y for yes & N for no\n";
                cin>>a;
                if(a=='Y')
                {
                    system("CLS");
                    ofstream fout;
                    fout.open("resignation.dat", ios:: out | ios::app);
                    cout<<"\n\n\t\t\t  application is approved\n";
                    system("PAUSE");
                    cin.get();
                    fout<<"Name : "<<Name<<endl;
                    fout<<"Application:"<<"approved"<<endl<<endl;
                    return 1;

                }
                else
                {
                    cout<<"\n\n\t\t\t  application is not approved\n";
                    system("PAUSE");
                    cin.get();
                    return 0;
                }
}
int director_approval()
{
                cout<<"\n\n\t\tdirector approved your application\n"; 
                system("PAUSE");
                cin.get();
                return 1;

}

void apply_for_resignation()
{
                system("CLS");
                ofstream fout;
                fout.open("resignation.dat", ios:: out | ios::app);
                string application;
                cout<<"\n\n\t\t\twrite your application:";
                cin.ignore();
                getline(cin,application);
                cout<<"\n\n\t\t\t  application of resignation submitted Successfully\n";
                system("PAUSE");
                cin.get();
                fout<<"Name : "<<Name<<endl;
                fout<<"Application:"<<application<<endl<<endl;




}
int update_pension(int pension)
{
                system("CLS");
                ofstream fout;
                fout.open("pension.dat", ios:: out | ios::app);
                
                //cin>>pension;
                cout<<"\n\n\t\t\t  New Pension Updated Successfully\n "<<pension;
                 system("PAUSE");
                 
                 cin.get();
                fout<<"Name : "<<Name<<endl;
                fout<<"AGE : "<<age<<endl;
                fout<<"department: "<<department<<endl;
                fout<<"updated pension: "<<pension<<endl<<endl;
                return 1;



}
void update_profile()
{
                system("CLS");
                ofstream fout;
                fout.open("database.dat", ios:: out | ios::app);
                cout<<"\n\n\t\t\t NAME: ";
                cin.ignore();
                getline(cin,Name);
                cout<<"\n\n\t\t\t AGE: ";
                cin>>age;
                cout<<"\n\n\t\t\t DEPARTMENT: ";
                cin.ignore();
                cin>>department;
                cout<<"\n\n\t\t\tprofile updated successfully\n";
                system("PAUSE");
                cin.get();
                fout<<"Name : "<<Name<<endl;
                fout<<"AGE : "<<age<<endl;
                fout<<"department: "<<department<<endl<<endl;
                return;
}
void show_resignation_state()
{
                ifstream fin;
                fin.open("resignation.dat");
                string line;
                while(fin){
                  getline(fin,line);
                  cout<<line<<endl;
                }
                fin.close();

                system("PAUSE");
               cin.get();
}
void show_updated_pension()
{
                ifstream fin;
                fin.open("pension.dat");
                string line;
                while(fin){
                  getline(fin,line);
                  cout<<line<<endl;
                }
                fin.close();

                system("PAUSE");
                cin.get();
}
void show_profile_database()
{
                ifstream fin;
                fin.open("database.dat");
                string line;
                while(fin){
                  getline(fin,line);
                  cout<<line<<endl;
                }
                fin.close();

                system("PAUSE");
                cin.get();
}


int main()
{
    cout<<"\n\n\t\t\tAre you a faculty or a office member\n";
    cout<<"\n\t\t\tenter O for office and F for faculty ";
    char occupation_check;
    cin>>occupation_check;
    int member_check;
    if(occupation_check=='O')
    {
        member_check=1;
    }
    else
    {
        member_check=0;
    }
    system("CLS");
    login(member_check);
    while(1) 
    {
        system("CLS");
        cout << "\n\n\t\t ======  PENSIONER PORTAL OF IIT JODHPUR  ======";
        cout <<"\n\n                                          ";
     
        cout << "\n\n\t\t\t  1. Update Pensioners Profile";
        cout << "\n\n\t\t\t  2. Update Monthly Pension";
        cout << "\n\n\t\t\t  3. Open pensioner database ";
        cout << "\n\n\t\t\t  4. check updated pension ";
        cout << "\n\n\t\t\t  5. Apply for resignation ";
        cout << "\n\n\t\t\t  6. Exit Program";
        cout << "\n\n\t\t\t  7. approve application(HOd) ";
        cout << "\n\n\t\t\t  8. approve application(Director) ";
        cout << "\n\n\t\t\t  9. check application";
        cout<<"\n\n";
        cout<<  " \n\t\t====================================";
        cout << "\n\n\t\t\t Select Your Choice ::";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                update_profile();
                break;
            } 
            case 2:
            {
                cout<<"\n\n\t\t\t Enter New Pension: ";
                cin>>pension;
                update_pension(pension);
                break;
            }
            case 3:
            {
                show_profile_database();
                break;
            }
            case 4:
            {
                
                show_updated_pension();                
                break;
            }
            case 5:
            {
                apply_for_resignation();
                break;
            }
            case 6: 
            {
                 //exiting from the system at the end of the day.
                system("CLS");
                exit(0);
                break;
            }
            case 7:
            {
                resignation_approval();
                break;
            }
            case 8:
            {
                director_approval();
                break;
            }
            case 9:
            {
                show_resignation_state();                
                break;
            }
            default:
            {
                cout<<"\n\n\t\t Invalid input";
                cout<<"\n\n\t\tPress Enter to continue";
            }
        }
        

    }
    
    return 0;  
}