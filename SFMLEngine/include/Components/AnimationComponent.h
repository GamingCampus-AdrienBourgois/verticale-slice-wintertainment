#pragma once

#include "Component.h"
#include "RendererComponent.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class AnimationComponent : public Component
{
public:
	AnimationComponent();
	~AnimationComponent();

	void Update(float _delta_time);

	void SetRendererComponent(RendererComponent* _rendererComponent) { rendererComponent = _rendererComponent; }
	void SetUpdateTimer(float _updateTimer) { updateTimer = _updateTimer; }
	void SetID(int _id) { id = _id; }
	void SetPlayOnce(bool AAAAAAAAAAA) { playOnce = AAAAAAAAAAA; }

	void ResetDirection();

	void SwitchPause() { pause = !pause; }
	void SetPause() { pause = true; }
	void RemovePause() { pause = false; }
	

private:
	std::vector<sf::Sprite*> Animation;

	bool playOnce = false;
	bool pause = false;
	int id = 0;

	float updateTimer; 
	float Timer = 0;
	RendererComponent* rendererComponent = nullptr;

};

