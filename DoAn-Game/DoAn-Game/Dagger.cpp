#include "Dagger.h"



Dagger::Dagger() : GameObject()
{
	vx = ITEM_DAGGER_SPEED;
	AddAnimation(DAGGER_ANI);
	SetState(DAGGER_STATE);
}

void Dagger::Render()
{
	animations[state]->Render(-nx, x, y);
}

void Dagger::Update(DWORD dt, vector<LPGAMEOBJECT>* Objects, vector<LPGAMEOBJECT*>* coObject)
{
	if (nx < 0) vx = -ITEM_DAGGER_SPEED;
	else vx = ITEM_DAGGER_SPEED;

	GameObject::Update(dt);
	x += dx;

	// Check collision between Dagger and other objects
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	CalcPotentialCollisions(coObject, coEvents);

	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPGAMEOBJECT * obj = coObject->at(i);
			if (dynamic_cast<Candle*>(*obj))
			{
				Dagger * e = dynamic_cast<Dagger*> (*obj);

				float left, top, right, bottom;

				e->GetBoundingBox(left, top, right, bottom);
				if (dagger->CheckCollision(left, top, right, bottom) == true) // va chạm giữa dao và nến
				{
					// Tạo một random item và thay thế vào vị trí con trỏ của Candle*

					Items * item = new Items();
					item->isEnable = true;
					item->SetPosition(e->x, e->y);
					item->GetRandomItem();

					*(obj) = item;

				}
			}

		}
	}
	// clean up collision events
	for (int i = 0; i < coEvents.size(); i++)
		delete coEvents[i];

}

bool Dagger::CheckCollision(float obj_left, float obj_top, float obj_right, float obj_bottom)
{
	float dagger_left,
		dagger_top,
		dagger_right,
		dagger_bottom;

	GetBoundingBox(dagger_left, dagger_top, dagger_right, dagger_bottom);

	return GameObject::AABB(dagger_left, dagger_top, dagger_right, dagger_bottom, obj_left, obj_top, obj_right, obj_bottom);
}

void Dagger::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = left + DAGGER_BBOX_WIDTH;
	bottom = top + DAGGER_BBOX_HEIGHT;
}

