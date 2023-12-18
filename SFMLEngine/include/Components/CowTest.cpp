#include "CowTest.h"
#include "RendererComponent.h"
#include "AuraRenderer.h"

CowTest::CowTest()
{
}

CowTest::~CowTest()
{
}

void CowTest::Update(float _delta_time)
{
		if (currentSeason == 0)
		{
			GetOwner()->GetComponent<RendererComponent>()->SetSprite(1);
		}
		if (currentSeason == 1)
		{
			GetOwner()->GetComponent<RendererComponent>()->SetSprite(0);
		}
	GameObject* player = GetOwner()->GetSceneOwner()->FindGameObject("player");
	GameObject* totem = GetOwner()->GetSceneOwner()->FindGameObject("totem1");
	std::vector<GameObject*> totemsObjects;
	std::vector<AuraRenderer*> totems;

	totemsObjects.push_back(player);
	totemsObjects.push_back(totem);

	for (int i = 0; i < totemsObjects.size(); i++)
	{
		totems.push_back(totemsObjects[i]->GetComponent<AuraRenderer>());
	}

	SetSeason(1);
	GetOwner()->GetComponent<RendererComponent>()->SetCurrentSeason(1);

	for (int i = 0; i < totems.size(); i++)
	{
		if (totems[i]->IsActive() && GetOwner()->GetPosition().Distance(totems[i]->GetOwner()->GetPosition()) < totems[i]->GetRadius())
		{
			SetSeason(0);
			GetOwner()->GetComponent<RendererComponent>()->SetCurrentSeason(0);
		}
	}
}
