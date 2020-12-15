// CS 311 HW 3
// Movie Class
// Noah Grassmeyer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie
{

    private:

        string movieName;
        string ratingMPAA;
        vector<unsigned> movieRating = { 0 , 0 , 0 , 0 , 0 , 0 };

    public:

        Movie() :                                                                   // Default ctor.
                movieName{ "" }, 
                ratingMPAA{ "" },
                movieRating{ 0, 0, 0, 0, 0, 0 } {}

        Movie(string movieName, string ratingMPAA) :                                // Parameterized ctor for creating object with specified name and MPAA rating.
                movieName{ movieName },
                ratingMPAA{ ratingMPAA },
                movieRating{ 0, 0, 0, 0, 0, 0} {}

        string getMovieName() const { return movieName; }                           // Getters/accessors for accessing movie names and MPAA ratings.
        string getRatingMPAA() const { return ratingMPAA; }

        float getAverage() const
        {
            return ((float)((movieRating[1] * 1) + (movieRating[2] * 2) + (movieRating[3] * 3) + (movieRating[4] * 4) + (movieRating[5] * 5)) / (float)(movieRating[1] + movieRating[2] + movieRating[3] + movieRating[4] + movieRating[5]));
        }

        void setMovieName(unsigned newMovieName) { movieName = newMovieName; }      // Setters/mutators for changing movie names and MPAA ratings.
        void setRatingMPAA(unsigned newRatingMPAA) { ratingMPAA = newRatingMPAA; }

        void addRating(unsigned newMovieRating)
        {
            if (0 <= newMovieRating <= 5)
                movieRating[newMovieRating]++;
        }
};

int main()
{
    Movie m1{ "Snowden" , "R" };
    Movie m2{ "Avengers: Endgame" , "PG-13" };

    m1.addRating(4);
    m1.addRating(3);
    m1.addRating(2);
    m1.addRating(5);
    m1.addRating(4);
    m1.addRating(3);

    m2.addRating(5);
    m2.addRating(4);
    m2.addRating(5);
    m2.addRating(5);
    m2.addRating(5);
    m2.addRating(3);

    cout << "The average rating for " << m1.getMovieName() << " with rating " << m1.getRatingMPAA() << " is: " << m1.getAverage() << endl;
    cout << "The average rating for " << m2.getMovieName() << " with rating " << m2.getRatingMPAA() << " is: " << m2.getAverage() << endl;

    return 0;
}
