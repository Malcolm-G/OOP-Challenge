/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movie.h"
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies(std::string name_val)
            :name{name_val}
{
    std::cout<< "Created new Movies object"<<std::endl;
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() 
{
    std::cout<<"Destroying "<<name<<std::endl;
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) 
{
    if (movies.size() <= 0)
    {
        movies.push_back(Movie(name, rating, watched));
        return true;
    }
    else
    {
        for (auto x : movies)
        {
            if (x.get_name()==name)
            {
                return false;
            }
        }
        movies.push_back(Movie(name, rating, watched));
        return true;
    }
    
}


 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) 
{
    if (movies.size() <= 0)
    {
        return false;
    }
    for (auto &x : movies)
    {
        if (x.get_name()==name)
            {
                x.increment_watched();
                return true;
            }
    }
    
   return false;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const 
{
    if  (movies.size() !=0)
    {
        for (auto x : movies)
        {
            x.display();
        }
    }
    else
    {
        std::cout<<"No movies to display"<<std::endl;
    }
}