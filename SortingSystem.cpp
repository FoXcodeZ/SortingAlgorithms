#include "SortingSystem.hpp"
#include <random>
#include <iostream>
#include <chrono>
#include <thread>

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


bool foxcodez::SortingSystem::bubbleSort(long long time)
{
    auto arraySize = m_numbersBubble.size();
    static int i = 0;
    static int j = 0;

    std::this_thread::sleep_for(std::chrono::milliseconds(time));

    if (i < arraySize)
    {
        // arraySize-1 because we can't swap last element, there is no next element to compare,
        // It can be out of index, if we could try to do it.
        if(j < arraySize-1)
        {
            if(m_numbersBubble[j] > m_numbersBubble[j + 1])
            {
                std::swap(m_numbersBubble[j], m_numbersBubble[j + 1]);
            }
            j++;
            return true;
        }
        i++;
        j = 0;
        return true;

    }
    if (i == arraySize)
    {
        i = 0;
        j = 0;
        return false;
    }
    return true;
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
            bubbleSort(100);
    }
}