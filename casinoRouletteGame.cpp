#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
void display();
void rules();
int main(){
    bool flag=0;//flag is used for winning
    display();//for display casino 
    string name;
    int amount;
    char input;//yes or no
    cout<<"Enter name : ";
    getline(cin,name);
    cout<<endl;
    cout<<"Enter input your amount $ : ";
    cin>>amount;
    cout<<endl;
    do{
        rules();
        int deposit;//for bet
        label1:
        cout<<"Enter amount you want to bet $ : ";
        cin>>deposit;
        if(deposit>amount){
            cout<<"you have  "<<"$"<<amount<<"  you cannot input above this amount"<<endl;
            break;
        }
        cout<<endl;
        int ball=rand()%10+1;//becouse we want only 10choices
        int choose;
        label2:
        cout<<"Enter input method : "<<endl;
        cout<<"press 1 if you want to input your guessing number where ball will stop "<<endl;
        cout<<"press 2 if you think that the number where ball will stop is even number"<<endl;
        cout<<"press 3 if you think that the number where ball will stop is odd number "<<endl;
        cout<<"enter input :  ";
        cin>>choose;
        cout<<endl;
        if(choose==1){
            int number;
            cout<<"enter input chooseing number in between 1-10 : ";
            cin>>number;
            cout<<endl;
            if(number==ball){
                flag=1;
            }else{
                flag=0;
            }
        }
        else if(choose==2){
            if(ball%2==0){//for even
                flag=1;
            }
            else{
                flag=0;
            }
        }
        else if(choose==3){
            if(ball%2!=0){//for odd
                flag=1;
            }
            else{
                flag=0;//if we lose
            }
        }
        else{
            cout<<"Invalid input "<<endl;//if choose wrong input
            goto label2;
        }
        if(flag==1){
            cout<<"Congratulations ! you win "<<endl;
            cout<<"you win $"<<deposit<<endl;
            amount=(amount+deposit)+deposit*10;
        }
        else{
                 cout<<"you lose"<<endl;
                amount=amount-deposit;
        }
        
        if(amount<=0){//if remained amount will be negative
            cout<<"you have not enough money to play"<<endl;
            break;
        }
        
        cout<<"would you like to play again y/n"<<endl;
        cin>>input;
        cout<<endl;
        
    }while(input!='n');
    cout<<name<<" , "<<"you have "<<amount<<"$"<<endl;
    cout<<"\n\n*******************************************************"<<endl;
}
void display(){
    string var="\n====================================================================="
    "\n  CCCCC    A    SSSSSSSSS  IIIIIIIII  NN    NN   OOOOOOOO    "
    "\n CC       A A   SS            III     NN N  NN  OO      OO    "
    "\nCC       A   A  SSSSSSSSS     III     NN  N NN  OO      OO    "
    "\n CC     AAAAAAA        SS     III     NN   N N  OO      OO    "
    "\n  CCCCC A     A SSSSSSSSS  IIIIIIIII  NN    NN   OOOOOOOO    "
    "\n===============================================================================\n";
    for(int i=0;i<var.size();i++){
        Sleep(10);
        cout<<var[i];
    }
}
void rules(){
    system("cls");
    cout<<"\n\n";
    cout<<"*********************************************************\n"<<endl;
    cout<<"\tRULES OF THE GAME\n";
    cout<<"=======================================================\n";
    cout<<"\t 1. choose any number between 1-10 \n";
    cout<<"\t 2.if you win you will get 10 times of money you bet\n";
    cout<<"\t 3.if you bet on wrong number you will lose your betting amount\n\n";
    cout<<"\n\n=========================================================\n";
}