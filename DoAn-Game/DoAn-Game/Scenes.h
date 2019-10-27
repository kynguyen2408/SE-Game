#pragma once
#include"Define.h"
#include"Game.h"
#include"GameObject.h"

#include"Simon.h"
#include"TileMap.h"

#include<map>
using namespace std; 

class Scenes
{
	static Scenes * _instance; 
	vector<LPGAMEOBJECT> objects;
public: 

	Scenes();
	~Scenes();
	void Update(DWORD dt);
	void Render();

	void PushObject(LPGAMEOBJECT object);
	void InsertObject(LPGAMEOBJECT object);
	int GetListObjectSize() { return objects.size(); };
	//void PutItem()
}