/*Задача 3
Что нужно сделать
С клавиатуры вводятся числа. Когда пользователь вводит «-1»,  
необходимо выводить на экран пятое по возрастанию число среди введённых. 
Когда пользователь вводит «-2», программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы

Советы и рекомендации
Нужно удостовериться, что можно вывести требуемое число (может быть меньше пяти чисел).*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers;

    while (true)
    {
        int input;
        std::cout << "Input the numbers: ";
        std::cin >> input;

        if (input == -2)
        {
            break; // Завершение программы при вводе -2
        }
        else if (input == -1)
        {
            if (numbers.size() >= 5)
            {
                std::sort(numbers.begin(), numbers.end()); // Сортировка по возрастанию вектора
                std::cout << "Fifth highest increase in number: " << numbers[4] << std::endl; // Пятое по возрастанию число
            }
            else
            {
                std::cerr << "Entered less than 5 numbers." << std::endl;
            }
        }
        else
        {
            numbers.push_back(input); // Добавление числа в вектор
        }
    }

    std::cout << "Vector numbers: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    return 0;
}
