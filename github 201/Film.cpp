#include "Film.h"

Film::Film(const string fTitle, const string fDirector ,
const unsigned int fYear,
const unsigned int fDuration){

        title = fTitle;
        director = fDirector;
        year = fYear;
        duration = fDuration;
        size = 30;
        actors = new Actor[size];
        noOfActors = 0;
}

Film::Film(const Film &fToCopy){
    title = fToCopy.title;
    size = fToCopy.size;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;
    noOfActors = fToCopy.noOfActors;

        actors = new Actor[size];
        for(unsigned int i = 0; i < noOfActors; i++){
            actors[i] = fToCopy.actors[i];
        }


}

 void Film::operator=(const Film &right){
    title = right.title;
    size = right.size;
    director = right.director;
    year = right.year;
    duration = right.duration;
    noOfActors = right.noOfActors;
    if(actors != NULL){
        delete [] actors;

    }
        actors = new Actor[size];
    for(unsigned int i = 0; i < noOfActors; i++){
            actors[i] = right.actors[i];
        }
}

string Film::getFilmTitle() const{
    return title;
}
string Film::getFilmDirector() const{
    return director;
}

unsigned int Film::getFilmYear() const{
    return year;
}
unsigned int Film::getFilmDuration() const{
    return duration;
}

unsigned int& Film::getNoOfActors() {
    return noOfActors;
}
void Film::setNoOfActors(){
    noOfActors++;

    //std::cout << noOfActors;
}





unsigned int Film::calculateAverageActorAge() const{
    int sum = 0;
/*
    for(unsigned int i = 0; i < noOfActors; i++)
    {
        average = ((average * (i)) + (year - actors[i].getBirthYear()))/(i + 1);
    }
    return average;
*/
    for (unsigned int i = 0; i < noOfActors; i++) {
        sum += year - actors[i].getBirthYear();
    }

    return sum / noOfActors;
}

ostream& operator<<(ostream& out, const Film& f){

    out<< f.getFilmTitle()<<", "<<f.getFilmDirector()<<", "<<f.getFilmYear()<<", "<<f.getFilmDuration()<<endl;
    for(int i = 0; i < f.noOfActors; i++)
    {
       out << " " << f.actors[i];
    }

    return out;

}

Actor* Film::getActors() const{
            return actors;

}



Film::~Film(){
    if(actors)
    {
        delete[] actors;
    }
}




