// ======================================================================
// Sorting Algorithms
// Created by Marcin 'FoXcodeZ' Grabowy.
// Github: https://github.com/FoXcodeZ
// License: MIT https://opensource.org/licenses/MIT
// ======================================================================

#pragma once
#include <vector>

namespace foxcodez
{
    enum class Algorithm : int
    {
        None = 0,
        BubbleSort,
    };

    class SortingSystem
    {
    private:
        std::vector<int> m_numbersGlobal {};
        std::vector<int> m_numbersBubble {};

    public:
        bool bubbleSort(long long time = 100);

    public:
        void generateNumbers(int arraySize);
        std::vector<int>& getNumbersArray(Algorithm arrayType);
        void printArray(Algorithm arrayType);
        void sort(Algorithm algorithm);
    };
} // namespace foxcodez