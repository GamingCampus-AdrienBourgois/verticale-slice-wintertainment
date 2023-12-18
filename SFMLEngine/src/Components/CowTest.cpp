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
	if (player->GetComponent<AuraRenderer>()->IsActive() && GetOwner()->GetPosition().Distance(player->GetPosition()) < player->GetComponent<AuraRenderer>()->GetRadius())
	{
		SetSeason(0);
	}
	else
	{
		SetSeason(1);
	}
}
