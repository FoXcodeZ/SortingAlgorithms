// ======================================================================
// Sorting Algorithms
// Created by Marcin 'FoXcodeZ' Grabowy.
// Github: https://github.com/FoXcodeZ
// License: MIT https://opensource.org/licenses/MIT
// ======================================================================

#pragma once
#include <SFML/Graphics.hpp>

namespace foxcodez
{
    class GraphicsSystem
    {
    private:
        sf::RenderWindow* m_window {};
        sf::Color m_defaultColor {sf::Color::Yellow};
        sf::Color m_selectedColor {sf::Color::Red};
        sf::Color m_taggedColor {sf::Color::Cyan};
        sf::Color m_finishedColor {sf::Color::Green};
        std::vector<sf::RectangleShape> m_shapes;

    public:
        explicit GraphicsSystem(sf::RenderWindow* window) : m_window(window){};
        void makeShapes(std::vector<int>* numbersArray);
        void drawHistogram();
    };
} // namespace foxcodez