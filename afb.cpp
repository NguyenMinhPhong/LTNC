#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
//#include <stdlib.h>

using namespace std;
const int max_badguess=7;


void HangmanRender(int badguess){
    if(badguess==0){
            cout<<"+-------+"<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==1){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==2){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|       0"<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==3){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|       0"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==4){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|       0"<<endl;
            cout<<"|      /|"<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==5){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|       0"<<endl;
            cout<<"|      /|\\"<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==6){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|       0"<<endl;
            cout<<"|      /|\\"<<endl;
            cout<<"|      / "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }
    if(badguess==7){
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|       0"<<endl;
            cout<<"|      /|\\ "<<endl;
            cout<<"|      / \\ "<<endl;
            cout<<"|        "<<endl;
            cout<<"|        "<<endl;
            cout<<"========="<<endl;
    }



}
string Secertword(){
    srand(time(0));
    string s[]={"enjoy","game","football","optional","hangman","motorbike","chicken"};
    int Randomindex=rand()%7;
    string s1=s[Randomindex];
    return s1;

}
string secertword=Secertword();


string Guessword(){
    string s=secertword;
    string s1="";
    for(int i=0;i<s.size();i++){
        s1+="-";
    }
    return s1;
}

string update(string sword,string gword,char guess){
    for(int i=0;i<gword.size();i++){
        if(guess==gword[i]){
            cout<<"you just guess it right, please try again!"<<endl;
            break;
        }
    }
    for(int i=0;i<sword.size();i++){
        if(guess==sword[i]){
            gword[i]=guess;
        }
    }
   return gword;
}
char Guess(){
    char guess;
    cout<<"Your guess: ";
    cin>>guess;
    return guess;
}

bool contains(string s,char c){
    bool check=false;
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            check=true;
        }
    }
    return check;
}

void GamePlay(){
    string guessword=Guessword();

    int count=0;
    bool checkfirst=0;
    do{
       char guess=Guess();

       if(contains(secertword,guess)){
            guessword=update(secertword,guessword,guess);
       }else{
            count++;
       }

        if(checkfirst){
            system("cls");
        }
       HangmanRender(count);//v? hình hangman;
       int countcheck=0;
        for(int i=0;i<secertword.size();i++){
            if(guess==secertword[i]){
                countcheck++;
            }
        }
       cout<<"There are "<<countcheck<<" "<<"'"<<guess<<"'"<<endl;
       cout<<guessword<<endl;
       cout<<"Number of wrong guesses: "<<count<<endl;

       if(!checkfirst){
        checkfirst=1;
       }

    }while(count<max_badguess&&guessword!=secertword);
    if(count<max_badguess){
        cout<<"Congratulation! You win."<<endl;
    }
    else{
        cout<<"Sorry, you lost 🙁"<<endl<<"The Secertword is: "<<secertword<<endl;
    }

}
void GetPlayerName(){
    cout<<"What is your name? ";
    string name;
    cin>>name;
    cout<<"Hello, "<<name<<endl;
    cout<<"Wellcome to Hangman game!";
    cout<<endl;
    cout<<"Your puzzle has "<<secertword.size()<<" letter : ";
    cout<<Guessword()<<endl;
}
void PlayAgain(){
    char continued;
    do{
        GamePlay();
        cout<<"Do you want to play again?('y' to continue ||'n' to stop )";
        cin>>continued;
        if(continued=='n'){
            cout<<"See you again,Thank you !"<<endl;
        }
    }while(continued=='y');
}


int main(){

    GetPlayerName();
    PlayAgain();
    return 0;
}
