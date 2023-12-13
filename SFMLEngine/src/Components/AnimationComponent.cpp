#include "Components/AnimationComponent.h"

AnimationComponent::AnimationComponent()
{

}

AnimationComponent::~AnimationComponent()
{

}

void AnimationComponent::Update(float _delta_time)
{
	if (pause == false)
	{
		Timer += _delta_time;
		if (Timer >= updateTimer)
		{
			id++;
			if (id >= rendererComponent->GetSprites().size())
			{
				id = 0;
			}
			rendererComponent->SetSprite(id);
			Timer = 0;
		}
	}
}

void AnimationComponent::ResetDirection()
{
	rendererComponent->SetSprite(id);
}
