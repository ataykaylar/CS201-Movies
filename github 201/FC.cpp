#include "FC.h"

FC::FC()
{
    size = 30;
    noOfFilms = 0;
    films = new Film[size];
}


FC::FC(const FC &fcToCopy)
{
    noOfFilms = fcToCopy.noOfFilms;
    size = fcToCopy.size;

    if(noOfFilms > 0)
    {
        //films = new  Film[noOfFilms];
        for(unsigned int i = 0; i < noOfFilms; i++)
        {
            films[i] = fcToCopy.films[i];
        }
    }
    else
    {
        films = NULL;
    }
}

void FC::operator=(const FC &right)
{
    size = right.size;
    noOfFilms = right.noOfFilms;

    delete [] films;
    films = new Film[size];

    for(unsigned int i = 0; i < noOfFilms; i++)
    {
        films[i] = right.films[i];
    }

}

unsigned int FC::getFilms(Film *&allFilms) const
{

    allFilms = new Film[noOfFilms];

    for(unsigned int i = 0; i < noOfFilms; i++)
    {
        allFilms[i] = films[i];
    }

    // delete [] allFilms;
    return noOfFilms;
}



bool FC::addFilm(const string fTitle, const string fDirector,
                 const unsigned int fYear,
                 const unsigned int fDuration)
{
    bool a = 1;
    if(noOfFilms >= 0)
    {
        for(unsigned int i = 0; i <= noOfFilms; i++)
        {

            if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
            {
                a = false;
            }

        }

       if(a == true){

        Film film(fTitle, fDirector, fYear, fDuration);
        films[noOfFilms] = film;
                //Actor *leadActors = NULL;
        noOfFilms++;
        }

    }

    return a;
}



bool FC::removeFilm(const string fTitle, const string fDirector)
{

    bool a = false;
    if(noOfFilms >= 1)
    {
        for(unsigned int i = 0; i < noOfFilms; i++)
        {
            if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
            {
                for(unsigned int k = i; k < noOfFilms; k++)
                {
                    films[k] =films[k + 1];

                }
                a = true;
                noOfFilms--;
                delete [] films[i].getActors();

            }
        }
        return a;
    }
    return a;
}

bool FC::addActor(const string fTitle, const string fDirector,
                  const string aName, const string aBirthPlace,
                  const unsigned int aBirthYear)
{
    //getAllActors(allActors);


    if(noOfFilms >= 0)
    {
        for(unsigned int i = 0; i < noOfFilms; i++)
        {


            if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
            {
                //allActors[noOfActors] = actor
                Actor actor(aName, aBirthPlace, aBirthYear);
                Actor* actorArr = films[i].getActors();


                actorArr[films[i].getNoOfActors()] = actor;
                films[i].setNoOfActors();
                delete []actorArr;

                //films[i].setNoOfActors();

                //leadActors[films[i].getNoOfActors()] = actor;

            }

        }

        //films[noOfFilms] = film;

        return true;
    }
    return false;
}

 bool FC::removeActors(const string fTitle, const string fDirector){
        bool a = false;

        for(unsigned int i = 0; i < noOfFilms; i++)
        {
            if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
            {
                delete [] films[i].getActors();
                films[i].getNoOfActors() = 0;
                return true;
            }
        }
        return a;
}








unsigned int FC::calculateAverageDuration() const
{
    int average = 0;

        for(unsigned int i = 0; i < noOfFilms; i++)
        {
            average += films[i].getFilmDuration();
        }
        return average / noOfFilms;

}




FC::~FC()
{

    if(films)
    {
        delete[] films;
    }



}
