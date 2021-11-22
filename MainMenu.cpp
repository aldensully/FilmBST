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
        void display();
        void run(stack<Submenu*>& submenus,FilmDS films);
        ~MainMenu(){};
};
void MainMenu::display(){
    cout << "\nMAIN MENU" << endl;
    cout << "a - About the Application" << endl;
    cout << "r - Reports" << endl;
    cout << "s - Search the Database" << endl;
    cout << "x - Exit the Program" << endl;
};
void MainMenu::run(stack<Submenu*>& submenus,FilmDS films){

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
        case 'a':
            submenus.push(new AboutMenu());
            break;
        case 'R':
            submenus.push(new ReportsMenu());
            break;
        case 'r':
            submenus.push(new ReportsMenu());
            break;
        case 'S':
            submenus.push(new SearchMenu());
            break;
        case 's':
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
