#include <iostream> 
#include <fstream>
#include "Vampvar.h"
#include <vector>
//For timer
#include <chrono> //library for time 
using namespace std;

//Game menu difficulty
void vampgame::Gamemenu(){ 
 
  int gamechoice; //user's input for choosing a difficulty
  vector<int>menu;
  cout <<"\n1- Easy \n";
  cout <<"2- Medium \n";
  cout <<"3- Hard \n";  
  cout <<"4- Back\n";
  cout<<"What would you like ? (1-4): ";
  cin>> gamechoice;

  switch(gamechoice){ 

    case 1:  
      RandomMathEasy(); 
      break;

    case 2: 
      RandomMathMedium();
      break;

    case 3: 
      RandomMathHard(); 
      break;

    case 4: 
      MainMenu();
      break;
      
    default: 
      cout<<"That's not an option try again...\n"; 
      Gamemenu(); 
      break;
  }
}

//if else statements: user dies or survives w/timer
void vampgame::Useranswers(){  
  ofstream outputFile; 
  
  //start timer 
  auto start = chrono::high_resolution_clock::now();

  //displaying problem and asking user's answer
  cout<<"What is the answer!\n";
  cout<<number1<<op<<number2<<"\n";  
  cin>>Useranswer;  

  //user dies: shows kills/elapse time and timer ends
  if(Useranswer != answer ){
    
    cout<<"\nYikes....you're dead\n"; 
    auto finish = chrono::high_resolution_clock::now();
    cout<<"Killed Vampires: "<<vampirekills; 
    chrono::duration<double> elapsed = finish - start;
    cout <<"\nElapsed time:  "<<elapsed.count()<<" seconds\n";
    Alive=false;

    //data.txt file is created here/stored
    outputFile.open("score.txt", fstream::in | fstream::out | fstream::app);
    //info printed out here
    outputFile<<"Kills: "<<vampirekills<<"\t\t"<<"Elapsed time: "<<elapsed.count()<<" Seconds\n\t";
    outputFile.close(); 

    //ask if user wants to play again.
    again();
  }  

  //User answer right: program countinue/add points
  else if (Useranswer == answer){   
    cout<<"\nThat's correct, next vampire!\n";
    vampirekills++; 
    Alive=true;
  }
  
  //User answers all correctly: congrats shows kills/elapse time and timer ends
  if( vampirekills == TotalVampires){
    cout<<"\nYAY! You've survived...\n"; 
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout <<"\nElapsed time: "<< elapsed.count()<<" seconds\n";

    //data.txt file is created here/stored
    outputFile.open("score.txt", fstream::in | fstream::out | fstream::app);
    
    //Prints into file 
    outputFile<<"Slayed all vampires! "<<"\t\t"<<"Elapsed time: "<<elapsed.count()<<" Seconds\n\t";
    outputFile.close(); 




    again();
  }  

}

//EASY
void vampgame::RandomMathEasy(){  
  vampirekills = 0; 
  TotalVampires = 10; 
  //Users life
  Alive = true;   

  cout<<"\nSlay 10 vampires...Quickly!\n";

  while(Alive == true && vampirekills != TotalVampires ){
    //setting the seed for number/operator randomization
    srand(time(0));
    //randomizing the first and second number 0-10
    number1 = rand()%10; 
    number2 = rand()%10; 
    //randomizing operators 
    op = "+-*"[rand()%3]; 

    //Allow operators to switch in every question
    switch(op){
      case '+': 
        answer = number1 + number2;  
        break;
      case '-': 
        answer = number1 - number2;
        break;   
      case '*': 
        answer = number1 * number2;
        break;
    }
    Useranswers();
  }//END WHILE LOOP
}

//MEDIUM
void vampgame::RandomMathMedium(){
  vampirekills = 0; 
  TotalVampires = 25; 
  Alive = true; 

  cout<<"\nSlay 25 vampires...Quickly!\n";

  while(Alive == true && vampirekills != TotalVampires ){
    srand(time(0));
    //randomizing the numbers 0-20 
    number1 = rand()%50; 
    number2 = rand()%50; 
    op = "+-*"[rand()%3];  

    switch(op){
      case '+': 
        answer = number1 + number2;  
        break;
      case '-': 
        answer = number1 - number2;
        break;   
      case '*': 
        answer = number1 * number2;
        break;  
      }
    
   
    Useranswers();
  } //END WHILE LOOP
}

//HARD
void vampgame::RandomMathHard(){
  vampirekills = 0;
  TotalVampires = 30; 
  Alive = true; 

  cout<<"\nSlay 30 vampires...Quickly!\n";

  while(Alive == true && vampirekills != TotalVampires ){
    srand(time(0)); 
    //randomizing the numbers 0-100
    number1 = rand()%100; 
    number2 = rand()%100; 
    op = "+-*"[rand()%3];

    switch(op){
      case '+': 
        answer = number1 + number2;  
        break;
      case '-': 
        answer = number1 - number2;
        break;   
      case '*': 
        answer = number1 * number2;
        break; 
    }
    Useranswers();
  }//END OF WHILE LOOP
}