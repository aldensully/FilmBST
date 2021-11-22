#include <iostream>
#include "Submenu.h"
#include "AboutMenu.cpp"
#include "ReportsMenu.cpp"
#include "SearchMenu.cpp"
#include "FilmDS.h"
#include <stack>
using namespace std;

class MainMenu : public Submenu{
    public:
        MainMenu(){};
        FilmDS* films;
        void display();
        void run(stack<Submenu*>& submenus,FilmDS films);
        ~MainMenu(){};
};
void MainMenu::display(){
    cout << "\nMAIN MENU" << endl;
    cout << "A - About the Application" << endl;
    cout << "R - Reports" << endl;
    cout << "S - Search the Database" << endl;
    cout << "X - Exit the Program" << endl;
};
void MainMenu::run(stack<Submenu*>& submenus,FilmDS films){

    films = films;
    string userInput;
    char inp;
   
    display();
    cout << "\nEnter Selection-> ";
    cin >> userInput;
    inp = userInput[0];

    switch(inp){
        case 'A':
            submenus.push(new AboutMenu());
            break;
        case 'R':
            submenus.push(new ReportsMenu());
            break;
        case 'S':
            submenus.push(new SearchMenu());
            break;
        case 'X':
            submenus.pop();
            break;
        case 'x':
            submenus.pop();
            break;
        default:
            break;
    }

};
