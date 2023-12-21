#pragma once

#include "Component.h"
#include "SFML/Audio.hpp"
#include <iostream>

class AudioComponent : public Component {
public:
    AudioComponent();
    ~AudioComponent();

    void Update(float _delta_time);

    void SetMusic(std::string _name) { name = _name; }
    void LoadMusic() { music.openFromFile(name); }
    void Render(sf::RenderWindow* _window) override
    {
        if (!isPlaying)
        {
            music.play();
            isPlaying = true;
        }
    }


private:
    sf::Music music;
    std::string name;
    bool isPlaying = false;

};