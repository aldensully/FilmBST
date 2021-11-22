#ifndef FILM_H
#define FILM_H
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
        string getAllInfo(void);
        double getTotalGross(void);
        double getOpeningGross(void);
        void printAllInfo(void); 
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
#endif
