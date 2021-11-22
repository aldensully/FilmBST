#ifndef SUBMENU_H
#define SUBMENU_H
#include "FilmDS.h"
#include <stack>

class Submenu{
    public:
        virtual void display(){};
        virtual void run(stack<Submenu*>&submenus,FilmDS films){};
        ~Submenu(void){};
};
#endif
