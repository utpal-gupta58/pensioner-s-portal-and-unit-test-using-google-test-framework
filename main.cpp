//password is  [sumankundu] for faculty and [superintendent] for office
#include<bits/stdc++.h>
#include<fstream>   //File handling.
#include<map> 
#include <string>
//#include<gtest/gtest.h> 
#include "Huffman.h"   //For huffman encoding
using namespace std;

string Name;
string c ;
int age,pension=0;
int pension_increment;
string department;
string name;
string application;
int choice,x,s,e,p,y,g;
char a;
char occupation_check;
int member_check;
//Number of trials , admin can try for password. Can be changed dynamically.
int trial=0;
string encodedstring[1];
//password taken as input by console.
string pass[1];                          
int login(int member_check)
{
        char ch;
        // cout <<"\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO PENSIONER PORTAL OF IIT JODHPUR   \n\t\t\t\t\tLogin with your id to continue";
        // cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Username or Institue ID: ";
        // cin.ignore();
        // getline(cin,name);
        // cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
        
        // cin>>c;
        pass[trial]=c;

    if(trial>=1)
    {
        cout<<"\n\n\t\t\t unsuccessfull attempt"<<endl;
        return 0;
    }
    
    if(member_check==0)
    {        
        calcFreq(pass[trial],pass[trial].length());
        HuffmanCodes(pass[trial].length());
        for(int i=0;i<pass[trial].length();i++){
            encodedstring[trial]+=codes[pass[trial][i]];
        }
        if(c == "sumankundu"){
            cout << "\n\n\n\n\t\t\t\t\t Welcome To the System Mr. "<<name<<"\n\n";   
            return 1;
        }else{
            trial++;
            cout << "\n\n\n\n\t\t\t\t\t\aWrong password...Please Try Again!!\n";
            return login(member_check);            
        }
    }
    else if(member_check==1)
    {        
        calcFreq(pass[trial],pass[trial].length());
        HuffmanCodes(pass[trial].length());
        for(int i=0;i<pass[trial].length();i++){
            encodedstring[trial]+=codes[pass[trial][i]];
        }
        if(c == "superintendent"){
            cout << "\n\n\n\n\t\t\t\t\t Welcome To the System Mr. "<<name<<"\n\n";                
            return 1;         
        }else{
            trial++;
            cout << "\n\n\n\n\t\t\t\t\t\aWrong password...Please Try Again!!\n";
            return login(member_check);
        }
    }    
}
int resignation_approval()
{
                
                //cout<<"\n\n\t\t\tAre your dues Completed? press Y for yes & N for no\n";
                //cin>>a;
                if(a=='Y')
                {
                    cout<<"\n\n\t\t\t  application is approved\n";
                    return 1;

                }
                else if(a=='N')
                {
                    cout<<"\n\n\t\t\t  application is not approved\n";
                    return 0;
                }
}
int director_approval()
{
                cout<<"\n\n\t\tdirector approved your application\n";                   
                return 1;

}

int  apply_for_resignation()
{
                
                // cout<<"\n\n\t\t\twrite your application:";
                // cin.ignore();
                // getline(cin,application);
                if(application.length()>0){
                cout<<"\n\n\t\t\t  application of resignation submitted Successfully\n";
                return 1;
                }
                else{
                    return 0;
                }
}
int update_pension(int pension_increment)
{
                if (pension_increment==0)
                return 0;
                pension+=pension_increment;
                
                
                //cout<<"\n\n\t\t\t  New Pension Updated Successfully: "<<pension;

                
                return 1;



}
int update_profile()
{
                // cout<<"\n\n\t\t\t NAME: ";
                // cin.ignore();
                // getline(cin,Name);
                // cout<<"\n\n\t\t\t AGE: ";
                // cin>>age;
                // cout<<"\n\n\t\t\t DEPARTMENT: ";
                // cin.ignore();
                // cin>>department;
                // cout<<"\n\n\t\t\tprofile updated successfully\n";               
                return 1;
}
int show_resignation_state()
{
        cout<<"\n\t\tfunction show_resignation_state was called\n";
        return 1; 
                
}
int  show_updated_pension()
{
        cout<<"\n\t\tfunction show_updated_pension was called\n";
        return 1;      
}
int show_profile_database()
{
        cout<<"\n\t\tfunction show_profile_database was called\n";
        return 1;
}
int member()
{
    // cout<<"\n\n\t\t\tAre you a faculty or a office member\n";
    // cout<<"\n\t\t\tenter O for office and F for faculty ";
    
    //cin>>occupation_check;
    
    if(occupation_check=='O')
    {
        member_check=1;
        return member_check;
    }
    else if(occupation_check=='F')
    {
        member_check=0;
        return member_check;
    }
    else{exit(1);}
    
}
int choice_function()
{
    // cout << "\n\n\t\t ======  PENSIONER PORTAL OF IIT JODHPUR  ======";
    //     cout <<"\n\n                                          ";
     
    //     cout << "\n\n\t\t\t  1. Update Pensioners Profile";
    //     cout << "\n\n\t\t\t  2. Update Monthly Pension";
    //     cout << "\n\n\t\t\t  3. Open pensioner database ";
    //     cout << "\n\n\t\t\t  4. check updated pension ";
    //     cout << "\n\n\t\t\t  5. Apply for resignation ";
    //     cout << "\n\n\t\t\t  6. Exit Program";
    //     cout << "\n\n\t\t\t  7. approve application(HOd) ";
    //     cout << "\n\n\t\t\t  8. approve application(Director) ";
    //     cout << "\n\n\t\t\t  9. check application";
    //     cout<<"\n\n";
    //     cout<<  " \n\t\t====================================";
    //     cout << "\n\n\t\t\t Select Your Choice ::";
        
        //cin>>choice;
        switch(choice)
        {
            case 1:
            {
                x=update_profile();
                break;
            } 
            case 2:
            {
                //cout<<"\n\n\t\t\t Enter New Pension: ";
                
                //cin>>pension_increment;
                s=update_pension(pension_increment);
                break;
            }
            case 3:
            {
                s=show_profile_database();
                break;
            }
            case 4:
            {
                
                e=show_updated_pension();                
                break;
            }
            case 5:
            {
                p=apply_for_resignation();
                //cout<<p<<"\n";
                break;
            }
            case 6: 
            {   
                std::cerr<<"6 was selected";                
                exit(1);
                break;
            }
            case 7:
            {
                g=resignation_approval();
                break;
            }
            case 8:
            {
                director_approval();
                break;
            }
            case 9:
            {
                y=show_resignation_state();                
                break;
            }
            default:
            {
                cout<<"\n\n\t\t Invalid input";
                cout<<"\n\n\t\tPress Enter to continue";
                std::cerr<<"wrong key chosen"; 
                exit(1);
            }
        }
}
