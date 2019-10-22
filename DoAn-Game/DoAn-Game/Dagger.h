#pragma once
#pragma once

#include "GameObject.h"
#include "Sprites.h"
#include "Textures.h"
#include "Ground.h"
#include "Candle.h"
#include "Items.h"

class Dagger : public GameObject
{
	Dagger * dagger;
public:
	Dagger();

	virtual void LoadResources(Textures* &textures, Sprites* &sprites, Animations* &animations) {};
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *Objects = NULL, vector<LPGAMEOBJECT*>* coObject = NULL);

	bool CheckCollision(float obj_left, float obj_top, float obj_right, float obj_bottom);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};

