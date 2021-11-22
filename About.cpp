#include <iostream>
#include "submenu.h"
using namespace std;

class AboutMenu extends Submenu{
    public:
        AboutMenu();
        void display(){
            cout << "\nThis application lets you search and explore the top films of 2017 using a simple binary search tree. Follow the prompts on screen or enter '?' at any time for help." << endl;
        }
}
