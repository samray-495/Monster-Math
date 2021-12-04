#include <iostream> 
#include <vector> 
#include <fstream>
#include "Vampvar.h"
using namespace std;

//MAIN MENU
void vampgame::MainMenu(){ 
  int choice;
  vampgame run; //calling the Game.cpp file to start game

  cout <<"\n\n---------------MAIN MENU---------------------\n";
  cout <<"\n1- play game.\n";
  cout <<"2- Timestamp.\n";
  cout <<"3- Exit.\n";
  cout << "\nENTER YOUR CHOICE HERE (1-3):  ";
  cin >> choice;

  switch (choice){

  case 1:
    run.Gamemenu();
    break;

  case 2:{

    cout<<"\n-----------User's Records-----------\n";
    // read the entire file 
    ifstream readfile("score.txt");

    //taking file to a readble form to string
    while (getline(readfile,mydata)) 
    cout<<"\n"<<mydata;
    readfile.close();
    MainMenu();
    break;
  }
  
  case 3:  
    cout<<"Thanks for playing!"; 
    break;
  

  default: 
    cout<<"That's not an option try again...";  
  } 
}

//User can choose to play again or not 
//(can pick a different difficulty)
void vampgame::again(){ 
  
  vector<int>menu;

  cout<<"\nWanna play again? Y or N:  "; 
  cin>>playagain; 

  switch(playagain){
    case'Y': 
      Gamemenu(); 
      break; 

    case 'N':
      return MainMenu(); 
      break; 

    default: 
      cout<<"That's not an option...try again."; 
      again(); 
      break;
    }
}

//Intro
int main(){
  vector<int>menu;
  vampgame run; //calling the Game.cpp file to start game

  vector<string>user;
  string Username;
  ofstream outputFile; 

  cout <<"\n\t\t\t--- WELCOME TO THE VAMPIRE GAME --- \n\t\t\t\t---Created by: Destiny Ray---\n";
  cout<<"\n\t\t\tCount Von Count turned evil...\n";
  cout<<"\n\tHe's sending his minions to execute you...uh oh\n";
  cout<<"\n\tTo exterminate them...You have to use your brain.\n\n";

  cout << "\nCreate a Username!:  ";
  cin>>Username; 
  user.push_back(Username);

  //data.txt file is created/stored
  outputFile.open("score.txt",fstream::in| fstream::out |  fstream::app);
  
  //Prints into file 
  outputFile<<"\n"<<Username<<endl;
  outputFile.close(); 

  //redirects to main menu
  run.MainMenu(); 

}