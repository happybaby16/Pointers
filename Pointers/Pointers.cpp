#include <iostream>


void changerIntValue(int* a, int value)
{
    *a = value;
}


void createMassive(int* a, int* size) //заполняет и очищает память
{
    for (int i = 0; i < *size; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < *size; i++)
    {
        printf("%i; ", a[i]);
    }
    free(a);
    free(size);
}

void printMassive(int* a, int size) //выводит массив
{
    for (int i=0;i<size; i++)
    {
        printf("%i; ", a[i]);
    }

   /* for(const auto el:a)
    {
      Хотел придумать как не передавать размер, но такой цикл foreach не работает с указателями. 
    }*/
}


void createMatrix(int** a, int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        a[i] = (int*)malloc((i + 1) * sizeof(int));

        for (int j = 0; j <= i; j++)
        {
            a[i][j] = counter;
            counter++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)

        {
            printf("%i ", a[i][j]);
        }
        printf("\n");

    }

}



int myPow(int a)
{
    return a * a;
}

int otherPow(int(*f)(int), int a)
{
    return f(a);
}


int main()
{
    
    setlocale(LC_ALL, "Russian");
    int a = NULL, value;
    while (true)
    {
    printf("Введите действие\n1 - Изменить значение целочисленной переменной\n2 - Динамический массив\n3 - Вывод массива\n4 - Треугольный массив\n5 - Квадрат числа через указатели на функцию\n");
    int switch_on;
    scanf_s("%i", &switch_on);


    int* massive;
    int* size;
    int* size2;
    int* size3;


    int* testMassive;

    int** doubleMassive;

    
        switch (switch_on)
        {
        case 1:
            while (true)
            {
                int answer;
                printf("Значение переменной а=%i\n", a);
                printf("Введите новое значение для переменой 'а': ");
                scanf_s("%i", &value);
                changerIntValue(&a, value);
                printf("Новое значение перменной а=%i\n", a);
                printf("Хотите продолжить? (1 - да, 0 - нет): ");
                scanf_s("%i", &answer);
                if (answer == 0)
                {
                    system("cls");
                    break;
                }
                system("cls");
            }
            break;



        case 2:
            printf("Введите размерность массива: ");
            size = (int*)malloc(sizeof(int));
            scanf_s("%i", size);
            massive = (int*)malloc((*size) * sizeof(int));
            createMassive(massive, size);
            break;


        case 3:
            printf("Введите размерность массива: ");
            size2 = (int*)malloc(sizeof(int));
            scanf_s("%i", size2);
            testMassive = (int*)malloc((*size2) * sizeof(int));



            //Просто заполняю массив для вывода
            for (int i = 0; i < *size2; i++)
            {
                testMassive[i] = i * i;
            }


            printMassive(testMassive, *size2); //вывожу массив
            free(size2);
            free(testMassive);
            break;


        case 4:
            printf("Введите размерность массива: ");
            size3 = (int*)malloc(sizeof(int));
            scanf_s("%i", size3);
            doubleMassive = (int**)malloc((*size3) * sizeof(int));
            createMatrix(doubleMassive, *size3);
            for (int i = 0; i < *size3; i++)
            {
                free(doubleMassive[i]);
            }
            free(size3);
            free(doubleMassive);
            break;
        case 5:
            int val;
            printf("Введите значение, которое хотите возвести в квадрат: ");
            scanf_s("%i", &val);
            int(*f)(int a) = myPow;
            printf("%i - ответ от указателя на функцию\n", f(val));
            printf("%i - ответ от функции, один параметр которой указатель на функцию\n", otherPow(f, val));
            break;

        }
        system("pause");
        system("cls");
    }


}

