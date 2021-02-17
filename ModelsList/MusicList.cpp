#include "../HeaderModelsList/MusicList.h"

 MusicList::MusicList()
{

}

 void MusicList::SetMusicList()
 {
	 std::ifstream fin("Music.txt");
	 while (!fin.eof())
	 {
		 std::string linie;
		 getline(fin, linie);
		 musicList.push_back(read.ReadMusic(linie));
	 }
 }

void MusicList::ShowMusicList()
 {
	 std::cout << "The MusicList is: " << std::endl;
	 for (auto& m : musicList)
	 {
		 std::cout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice()<<"|" << m.GetMusicGenre() << "|" << m.GetMusicAlbumName() << "|" << m.GetMusicArtist() << std::endl;
	 }
 }

std::list<Music> MusicList::GetmusicList()
{
	return this->musicList;
}

void MusicList::DeleteById(long id)
{
	std::list<Music> tmp;

	for (auto& m : musicList)
	{
		if (m.GetProductId() != id)
		{
			tmp.push_back(m);

		}
	}
	std::ofstream fout("Music.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& m : tmp)
	{
		if (m.GetProductId() != lastId)
			fout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetMusicGenre() << "|" << m.GetMusicAlbumName() << "|" << m.GetMusicArtist() << std::endl;
		else
			fout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetMusicGenre() << "|" << m.GetMusicAlbumName() << "|" << m.GetMusicArtist();
	}

	musicList = tmp;
}

void MusicList::Add(Music m)
{
	std::ofstream fout("Music.txt");
	musicList.push_back(m);
	std::int64_t lastId;
	if (musicList.size() != 0)
		lastId = musicList.back().GetProductId();
	for (auto& ms : musicList)
	{
		if (ms.GetProductId() != lastId)
			fout << ms.GetProductId() << "|" << ms.GetProductName() << "|" << ms.GetProductDescription() << "|" << ms.GetPrice() << "|" << ms.GetMusicGenre() << "|" << ms.GetMusicAlbumName() << "|" << ms.GetMusicArtist() << std::endl;
		else
			fout << ms.GetProductId() << "|" << ms.GetProductName() << "|" << ms.GetProductDescription() << "|" << ms.GetPrice() << "|" << ms.GetMusicGenre() << "|" << ms.GetMusicAlbumName() << "|" << ms.GetMusicArtist();
	}
}
