#include "../HeaderModelsList/MovieList.h"

MovieList::MovieList()
{

}

void MovieList::SetMovieList()
{
	std::ifstream fin("Movies.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		Movies.push_back(read.ReadMovie(linie));
	}
}

void MovieList::ShowMovieList()
{
	std::cout << "The MovieList is: " << std::endl;
	for (auto& m : Movies)
	{
		std::cout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetFormat() << "|" << m.GetCategory() << std::endl;
	}
}

std::list<Movie> MovieList::GetMovies()
{
	return this->Movies;
}

void MovieList::DeleteById(long id)
{
	std::list<Movie> tmp;

	for (auto& m : Movies)
	{
		if (m.GetProductId() != id)
		{
			tmp.push_back(m);

		}
	}
	std::ofstream fout("Movies.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& m : tmp)
	{
		if (m.GetProductId() != lastId)
			fout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetFormat() << "|" << m.GetCategory() << std::endl;
		else
			fout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetFormat() << "|" << m.GetCategory();
	}

	Movies = tmp;
}

void MovieList::Add(Movie m)
{
	std::ofstream fout("Movies.txt");
	Movies.push_back(m);
	std::int64_t lastId;
	if (Movies.size() != 0)
		lastId = Movies.back().GetProductId();
	for (auto& mov : Movies)
	{
		if (mov.GetProductId() != lastId)
			fout << mov.GetProductId() << "|" << mov.GetProductName() << "|" << mov.GetProductDescription() << "|" << mov.GetPrice() << "|" << mov.GetFormat() << "|" << mov.GetCategory() << std::endl;
		else
			fout << mov.GetProductId() << "|" << mov.GetProductName() << "|" << mov.GetProductDescription() << "|" << mov.GetPrice() << "|" << mov.GetFormat() << "|" << mov.GetCategory();
	}
}
