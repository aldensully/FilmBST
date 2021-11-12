#ifndef FILMDS_H
#define FILMDS_H

#include "Film.h"
#include "BinarySearchTree.h"

class FilmDS{
    public:
        FilmDS();
        
        void add(const Film& film);
        void remove(const Film& film);
        void displayInOrder();
        void displayTitles();
        void searchByTitle(string title);
        void searchByKeyword(string keyword);
        void searchByStudio(string studio);
        void searchByMonth(string month);
    private:
        BinarySearchTree<Film> filmsBST;
};

#endif
