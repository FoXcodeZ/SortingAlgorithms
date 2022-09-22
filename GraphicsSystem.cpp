#include "GraphicsSystem.hpp"


void foxcodez::GraphicsSystem::makeShapes(std::vector<int>* numbersArray)
{
    m_shapes.clear();
    sf::Vector2f histogramScale(1.0f, 10.0f);
    sf::Vector2f histogramPosition(50.0f, 300.0f);
    sf::Vector2f histogramSize(500.0f, 500.0f);
    float barOffset = 10.0f;

    auto arrayCount = numbersArray->size();
    for (int i = 0; i < arrayCount; ++i)
    {
        sf::Vector2f shapeSize(10.0f, 1.0f);
        sf::Vector2f shapePosition;
        auto correctNumber = static_cast<float>(numbersArray->at(i));

        shapeSize.y += (correctNumber * histogramScale.y) + 1.0f; // +1.0f help us to show even 0 on histogram.
        shapePosition.y = histogramPosition.y - shapeSize.y;
        shapePosition.x = histogramPosition.x;
        shapePosition.x += ((shapeSize.x + barOffset) * static_cast<float>(i)) * histogramScale.x;

        sf::RectangleShape shape(shapeSize);
        shape.setPosition(shapePosition);
        shape.setFillColor(m_defaultColor);
        m_shapes.push_back(shape);
        //m_shapes.emplace_back(shapeSize);
    }
}


void foxcodez::GraphicsSystem::drawHistogram()
{
    (*m_window).clear();
    for(auto& shape : m_shapes)
    {
        (*m_window).draw(shape);
    }
    (*m_window).display();
}