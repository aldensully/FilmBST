#ifndef FILM_H
#include <string>
using namespace std;

class Film{
    public:
        Film();
        Film(string data);
        int getRank(void);
        int getTotalTheaters(void);
        int getOpeningTheaters(void);
        string getOpeningDate(void);
        string getFilmTitle(void);
        string getStudio(void);
        double getTotalGross(void);
        double getOpeningGross(void);
        void printAllInfo(void) const; 
        void printTitle(void) const;
        bool operator< (const Film& rhs) const;
        bool operator> (const Film& rhs) const;
        bool operator== (const Film& rhs) const;

    private:
        int rank;
        int totalTheaters;
        int openingTheaters;
        string openingDate;
        string filmTitle;
        string studio;
        double totalGross;
        double openingGross;
};
#define FILM_H
#endif