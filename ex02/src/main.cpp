#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> blank;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "\033[38;5;120m--- equal session\033[0m ---" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
            }
        }
        test[MAX_VAL - 1] = 0;
        if (tmp[MAX_VAL - 1] == 0)
            test[MAX_VAL - 1] = 1;
        std::cout << "\033[38;5;196m--- not equal session\033[0m ---" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
            }
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
        }
    }
    std::cout << "\033[38;5;196m--- error case ---\033[0m" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\033[38;5;120m--- reassignment session ---\033[0m" << std::endl;
    int count = 0;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            count++;
        }
        std::cout << mirror[i] << ", " << numbers[i] << std::endl;
    }
    std::cout << "Number of different numbers: " << count << std::endl;
    delete [] mirror;
    return 0;
}