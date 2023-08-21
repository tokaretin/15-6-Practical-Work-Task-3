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
#include <algorithm>

int main()
{
    const int maxSize = 5;
    int arr[maxSize] = { 0 }; // Массив из 5 элементов, инициализированный нулями
    int currentIndex = 0;     // Текущий индекс для вставки

    while (true)
    {
        int input;
        std::cout << "Input the numbers: ";
        std::cin >> input;

        if (input == -2)
        {
            std::cout << "Vector numbers: ";
            for (int i = 0; i < maxSize; i++)
            {
                std::cout << arr[i] << " ";
            }

            break; // Завершение программы при вводе -2
        }

        else if (input == -1)
        {
            if (currentIndex >= 5)
            {
                std::sort(arr, arr + maxSize); // После ввода всех элементов, сортируем только первые 5 по возрастанию
                std::cout << "Fifth highest increase in number: " << arr[4] << std::endl; // Пятое по возрастанию число
            }
            else
            {
                std::cerr << "Entered less than 5 numbers." << std::endl;
            }
        }
        else
        {
            if (currentIndex < 5)
            {
                arr[currentIndex] = input;
                currentIndex++;
            }
            else if (input < arr[4])
            {
                int insertIndex = 3;
                
                while (insertIndex >= 0 && arr[insertIndex] > input)
                {
                    arr[insertIndex + 1] = arr[insertIndex];
                    insertIndex--;
                }
                arr[insertIndex + 1] = input;
            }
        }
    }

   
    return 0;
}