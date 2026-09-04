#include "test.hpp"

#include "imgui.h"

test::test(): width(200.0f), height(100.0f), rotation(0.0f)
{
    rectangle.setSize({width, height});
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition({540.0f, 310.0f});
    rectangle.setOrigin({width / 2.0f, height / 2.0f});
}

void test::update()
{
    ImGui::Begin("Test Rectangle");

    ImGui::SliderFloat("Width", &width, 10.0f, 500.0f);
    ImGui::SliderFloat("Height", &height, 10.0f, 500.0f);
    ImGui::SliderFloat("Rotation", &rotation, 0.0f, 360.0f);

    ImGui::End();

    rectangle.setSize({width, height});
    rectangle.setOrigin({width / 2.0f, height / 2.0f});
    rectangle.setRotation(sf::degrees(rotation));
}

void test::render(sf::RenderWindow& window)
{
    window.draw(rectangle);
}
