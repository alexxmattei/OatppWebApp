#include "../HeaderModels/Music.h"

Music::Music()
{
}

Music::Music(std::int64_t id,std::string genre, std::string albumName, std::string artist, std::string prodName, std::string prodDescription, double price)
{
	this->musicGenre = genre;
	this->musicAlbumName = albumName;
	this->musicArtist = artist;
	this->SetProductId(id);
	this->SetProductName(prodName);
	this->SetProductDescription(prodDescription);
	this->SetProductPrice(price);


	std::string musicString = "Music";
	musicString.append("|");
	musicString.append(std::to_string(this->GetProductId()));
	musicString.append("|");
	musicString.append(this->GetProductName());
	musicString.append("|");
	musicString.append(this->GetProductDescription());
	musicString.append("|");
	musicString.append(std::to_string(this->GetPrice()));
	musicString.append("|");
	musicString.append(this->GetMusicGenre());
	musicString.append("|");
	musicString.append(this->GetMusicAlbumName());
	musicString.append("|");
	musicString.append(this->GetMusicArtist());

	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << musicString << "\n";
	outfile.close();
}

Music::~Music()
{
}

void Music::SetMusicGenre(std::string newMusicGenre)
{
	this->musicGenre = newMusicGenre;
}

void Music::SetMusicAlbumName(std::string newAlbumName)
{
	this->musicAlbumName = newAlbumName;
}

void Music::SetMusicArtist(std::string newMusicArtist)
{
	this->musicArtist = newMusicArtist;
}

std::string Music::GetMusicGenre()
{
	return this->musicGenre;
}

std::string Music::GetMusicAlbumName()
{
	return this->musicAlbumName;
}

std::string Music::GetMusicArtist()
{
	return this->musicArtist;
}
