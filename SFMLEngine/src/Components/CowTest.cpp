#include "Components/CowTest.h"
#include "Components/RendererComponent.h"
#include "Renderer/AuraRenderer.h"

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
	GameObject* totem1 = GetOwner()->GetSceneOwner()->FindGameObject("totem1");
	GameObject* totem2 = GetOwner()->GetSceneOwner()->FindGameObject("totem2");

	std::vector<GameObject*> totemsObjects;
	std::vector<AuraRenderer*> totems;

	totemsObjects.push_back(player);
	totemsObjects.push_back(totem1);
	totemsObjects.push_back(totem2);


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
