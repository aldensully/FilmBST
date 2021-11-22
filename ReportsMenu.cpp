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
        void orderByTitleReport(FilmDS& films);
        void orderByRankReport(FilmDS& films);
        ~ReportsMenu(){};
};
void ReportsMenu::display(){
            cout << "\nREPORTS MENU" << endl;
            cout << "T - Order by Film Title report" << endl;
            cout << "R - Order by Rank report" << endl;
            cout << "X - Return to main menu" << endl;
}
void ReportsMenu::run(stack<Submenu*>& submenus, FilmDS films){
    string userInput;
    char inp;
    
    display();

    while(inp != 'X' && inp != 'x'){
        cout << "\nEnter Selection(or '?' to show menu)-> ";
        cin >> userInput;
        inp = userInput[0];
    
        switch(inp){
            case 'T':
                orderByTitleReport(films);
                break;
            case 'R':
                orderByRankReport(films);
                break;
            case '?':
                display();
                break;
        }
    }

    submenus.pop();

}
void ReportsMenu::orderByTitleReport(FilmDS& films){
    films.displayInOrder();
}
void ReportsMenu::orderByRankReport(FilmDS& films){
    films.displayInRankOrder();
}

