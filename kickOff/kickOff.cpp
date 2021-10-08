#include <iostream>
#include "numToWord.h"

int findSum(std::string numWord)
{
    int sum = 0;
    for (char c : numWord)
    {
        // Convert character to ascii representation
        int ic = (int)c;
        if (ic >= 97 && ic <= 122)
        {
            // Convert to alphebetical value
            ic = ic - 96;
            sum += ic;
        }
    }
    return sum;
}

void checkUntil(int numUntil)
{
    int countOdd = 0, countEven = 0;
    for (int numInt = 1; numInt <= numUntil; ++numInt)
    {
        std::string numWord = convertToWords(numInt);
        int sum = findSum(numWord);

        // Figure out wether odd or even
        int remainder = sum % 2;
        if (remainder == numInt % 2)
        {
            numWord[0] = toupper(numWord[0]);
            std::cout << numWord << "= " << sum << '\n';
            switch (remainder)
            {
            case 0:
                ++countOdd;
                break;
            case 1:
                ++countEven;
                break;
            }
        }
    }
    std::cout << "-\n";
    std::cout << "Odd: " << countOdd << '\n';
    std::cout << "Even: " << countEven << '\n';
    std::cout << "-\n";
}

int main()
{
    std::cout << R"(
    __ __ _      __   ____  __________
   / //_/(_)____/ /__/ __ \/ __/ __/ /
  / ,<  / / ___/ //_/ / / / /_/ /_/ / 
 / /| |/ / /__/ ,< / /_/ / __/ __/_/  
/_/ |_/_/\___/_/|_|\____/_/ /_/ (_)   
    )" << '\n';
    std::cout << "1 - Find the 'special' sum of a given word\n";
    std::cout << "2 - Find the 'special' sum of a given number\n";
    std::cout << "3 - Find all 'special' numbers until given number\n";
    std::cout << "-\n";

    int selection;
    std::cout << "Enter selection: ";
    std::cin >> selection;
    std::cout << "-\n";

    switch (selection)
    {
    case 1:
    {
        std::string word;
        std::cout << "Enter word: ";
        std::cin >> word;
        std::cout << "-\n";
        std::string wordLower = word;
        std::transform(wordLower.begin(), wordLower.end(), wordLower.begin(), ::tolower);
        std::cout << "The sum of " << word << " is " << findSum(wordLower) << '\n';
        break;
    }
    case 2:
    {
        int numInt;
        std::cout << "Enter number: ";
        std::cin >> numInt;
        std::cout << "-\n";
        std::string numWord = convertToWords(numInt);
        std::cout << "The sum of " << numInt << " is " << findSum(numWord) << '\n';
        break;
    }
    case 3:
        int numUntil;
        std::cout << "How many to check: ";
        std::cin >> numUntil;
        std::cout << "-\n";
        checkUntil(numUntil);
        break;
    default:
        std::cout << "Please enter 1, 2, or 3\n";
        return 1;
    }
}
