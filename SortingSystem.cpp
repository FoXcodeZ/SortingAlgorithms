#include "SortingSystem.hpp"
#include <random>
#include <iostream>


void foxcodez::SortingSystem::generateNumbers(int arraySize)
{
    m_numbersGlobal.clear();
    m_numbersBubble.clear();

    for (int i = 0; i < arraySize; ++i)
    {
        m_numbersGlobal.push_back(i);
    }

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::shuffle(&m_numbersGlobal[0], &m_numbersGlobal[arraySize], generator);
    m_numbersBubble = m_numbersGlobal;
}


std::vector<int>& foxcodez::SortingSystem::getNumbersArray(Algorithm arrayType)
{
    switch(arrayType)
    {
        case Algorithm::None:
            return m_numbersGlobal;

        case Algorithm::BubbleSort:
            return m_numbersBubble;

        default:
            return m_numbersGlobal;
    }
}


void foxcodez::SortingSystem::bubbleSort()
{
    auto arraySize = m_numbersBubble.size();
    std::cout << "Array size: " << arraySize << std::endl;

    for (int i = 0; i < arraySize; i++)
    {
        // arraySize-1 because we can't swap last element, there is no next element to compare,
        // It can be out of index, if we could try to do it.
        for(int j = 0; j < arraySize-1; j++)
        {
            if(m_numbersBubble[j] > m_numbersBubble[j + 1])
            {
                std::swap(m_numbersBubble[j], m_numbersBubble[j + 1]);
            }
        }
    }
}


void foxcodez::SortingSystem::printArray(Algorithm arrayType)
{
    std::vector<int>* array {};

    switch(arrayType)
    {
        case Algorithm::None:
            array = &m_numbersGlobal;
            break;
        case Algorithm::BubbleSort:
            array = &m_numbersBubble;
            break;
        default:
            array = &m_numbersGlobal;
    }

    auto arraySize = array->size();

    std::cout << "Array: ";
    for(int i : *array)
    {
        if (!i)
            continue;
        std::cout << i << " ";
    }
    std::cout << "\n";
}


void foxcodez::SortingSystem::sort(Algorithm algorithm)
{
    switch(algorithm)
    {
        case Algorithm::BubbleSort:
            bubbleSort();
            break;
        case Algorithm::None:   // Do nothing.
            break;
        default:
            bubbleSort();
    }
}