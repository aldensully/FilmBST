#include "Submenu.h"
#include "FilmDS.h"
#include <iostream>
#include <stack>
using namespace std;

class ReportsMenu : public Submenu{
    public:
        ReportsMenu(){};
        void display();
        void run(stack<Submenu*>& submenus,FilmDS films);
        ~ReportsMenu(){};
};
void ReportsMenu::display(){
            cout << "\nREPORTS MENU" << endl;
            cout << "t - Order by Film Title report" << endl;
            cout << "r - Order by Rank report" << endl;
            cout << "x - Return to main menu" << endl;
}
void ReportsMenu::run(stack<Submenu*>& submenus, FilmDS films){
    string userInput;
    char inp;
    bool terminate = false; 
    display();

    while(!terminate){
        cout << "\nEnter Selection(or '?' to show menu)-> ";
        cin >> userInput;
        inp = userInput[0];
    
        switch(inp){
            case 'T':
                films.displayInOrder();
                break;
            case 't':
                films.displayInOrder();
                break;
            case 'R':
                films.displayInRankOrder();
                break;
            case 'r':
                films.displayInRankOrder();
                break;
            case '?':
                display();
                break;
            case 'X':
                terminate = true;
                break;
            case 'x':
                terminate = true;
                break;
            default:
                break;
        }
    }

    submenus.pop();

}

