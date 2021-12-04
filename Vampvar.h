#include <iostream>
#include <chrono> 
using namespace std; 


class vampgame{ 
  public:  
    int gamechoice;
    void RandomMathEasy(); 
    void RandomMathMedium(); 
    void RandomMathHard(); 
    void Useranswers(); 
    void MainMenu();
    void again();
    char playagain;
    void Gamemenu(); 

  private: 
  
    // string for the users to read the entrie timestamp.    
    string mydata;

    //user's life
    bool Alive;

    //math values for problem/user's anwer 
    int number1, number2, answer, Useranswer;
    
    //number of vampires the user killed (shows if died early)
    int vampirekills;

    //the total vampires that the user needs to kill   
    int TotalVampires; 
    
    //display math operator
    char op;
};

