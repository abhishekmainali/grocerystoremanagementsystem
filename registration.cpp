#include<iostream>
#include<Fstream>
using namespace std;

class temp{
  string userName,Email,password;
  string searchName, searchPass, searchEmail;
  fstream file;
    public:
      void login();
      void signUP();
      void forgot();
}obj;

int main(){
  char choice;
  cout<<"\n1 - Login";
  cout<<"\n2 - SignUp";
  cout<<"\n3 - Forgot Password";
  cout<<"\n4 - Exit";
  cout<<"\nEnter your choice: ";
  cin>>choice;
  
  switch(choice){
    case '1':
      obj.login();
    break;
    case '2':
      obj.signUP();
    break;
    case '3':
      obj.forgot();
    break;
    case '4':
      return 0;
    break;
    default:
    cout<<"\nInvalid Selection......!";
  }
  }
  void temp :: signUP(){
    cout<<"\n Enter Your Name :: "<<endl;
    getline(cin, userName);
    cout<<"Enter Your Email Address :: "<<endl;
    getline(cin, Email);
    cout<<"Enter Your Password :: ";
    getline(cin , password);

    file.open("LoginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
  }

  void temp:: login(){
    cout<<"----------LOGIN----------"<<endl;
    cout<<"Enter your user name :: "<<endl;
    getline(cin, searchName);
    cout<<"Enter your user Password :: "<<endl;
    getline(cin, searchPass);

    file.open("loginDaa.txt",ios :: in);
    getline(file, userName,'*' );
    getline(file, Email,'*' );
    getline(file, password,'\n');
    while(!file.eof()){
        if(userName == searchName){
        if(password == searchPass){
          cout<<"\n Login Succesfull.....!";
          cout<<"\n Username :: "<<userName<<endl;
          cout<<"\n Email :: "<<Email<<endl;            
      }else{
        cout<<"Your Password is Incorrect.....!";
      }
    }
    getline(file, userName,'*' );
    getline(file, Email,'*' );
    getline(file, password,'\n');
  }
  file.close();
}
void temp :: forgot(){
  cout<<"Enter your UsernName ::";
  getline(cin, userName);
  cout<<"\nEnter Your Email Address :: ";
  getline(cin, searchEmail);

  file.open("loginData.txt", ios :: in);
  getline(file,userName, '*');
  getline(file, Email, '*');
  getline(file, password, '\n');
  while(!file.eof()){
    if(userName == searchName){
      if (Email == searchEmail){
        cout<<" Your Account Has Been FOund :: "<<password;
        cout<<"Your Password :: "<<password<<endl;
        }else{
          cout<<"Not Found---!\n";
        }
    }else{
      cout<<"\nNot Found----!\n";
    }
  }
  file.close();
}