// ======================================================================
// Sorting Algorithms
// Created by Marcin 'FoXcodeZ' Grabowy.
// Github: https://github.com/FoXcodeZ
// License: MIT https://opensource.org/licenses/MIT
// ======================================================================

#include "SortingSystem.hpp"
#include "GraphicsSystem.hpp"

using foxcodez::Algorithm;

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Sorting Algorithms");

    foxcodez::SortingSystem data;
    foxcodez::GraphicsSystem gui(&window);

    data.generateNumbers(20);

    gui.makeShapes(&data.getNumbersArray(Algorithm::None));

    bool runAlgorithm = false;
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    runAlgorithm = true;
                }
            }
        }

        if(runAlgorithm)
        {
            data.bubbleSort(20);
            gui.makeShapes(&data.getNumbersArray(Algorithm::BubbleSort));
        }
        gui.drawHistogram();
    }

    return 0;
}