#pragma once

#include "Product.h";

class Music :public Product
{
private:
	long musicId;
	std::string musicGenre;
	std::string musicAlbumName;
	std::string musicArtist;

public:

	Music();
	Music(std::int64_t, std::string, std::string, std::string, std::string, std::string, double);
	~Music();
	void SetMusicGenre(std::string);
	void SetMusicAlbumName(std::string);
	void SetMusicArtist(std::string);

	std::string GetMusicGenre();
	std::string GetMusicAlbumName();
	std::string GetMusicArtist();
};

