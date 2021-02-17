#pragma once

#include "../Helpers/Reader.h"
#include "../HeaderModels/Music.h"

#include <list>
#include <fstream>

class MusicList
{
private:
	std::list<Music> musicList;
	Reader read;
public:
	MusicList();

	void SetMusicList();

	void ShowMusicList();

	std::list<Music> GetmusicList();

	void DeleteById(long id);

	void Add(Music m);
};

