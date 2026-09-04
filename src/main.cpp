#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include "Opdrachten/test.hpp"

int main()
{
    sf::RenderWindow window;

    window.create(sf::VideoMode({1280, 720}), "Opdracht 1");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    if (!ImGui::SFML::Init(window))
        return -1;

    sf::Clock deltaClock;

    // - Rectangle test met  sliders
    test test;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // - Update
        ImGui::SFML::Update(window, deltaClock.restart());
        test.update();

        // - Render
        window.clear(sf::Color::Cyan);
        test.render(window);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
