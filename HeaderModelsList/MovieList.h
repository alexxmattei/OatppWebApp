#pragma once


#include "../Helpers/Reader.h"
#include "../HeaderModels/Movie.h"

#include <list>
#include <fstream>

class MovieList
{
private:
	std::list<Movie> Movies;
	Reader read;
public:
	MovieList();

	void SetMovieList();

	void ShowMovieList();

	std::list<Movie> GetMovies();

	void DeleteById(long id);

	void Add(Movie m);
};


