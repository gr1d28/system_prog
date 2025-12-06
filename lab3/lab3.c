#include <stdio.h>

void task1()
{
    char *ptr, t;
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);
    printf("Введите число t для смены значения в 3 байте числа n: ");
    scanf("%hhd", &t);
    ptr = (char *)&n;
    ptr += 2;
    *ptr = t;
    printf("Результат замены 3 байта: n = %d\n", n);
}

void task2()
{
    float x = 5.0;
    printf("x = %f, ", x);
    float y = 6.0;
    printf("y = %f\n", y);
    float *xp = &y;
    float *yp = &y;
    printf("Результат: %f\n", *xp + *yp);
}

void task3()
{
    int mas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = mas;

    for(int i = 0; i < 10; ++i)
    {
        printf("%d\n", *ptr);
        ptr += 1;
    }
}

int check_sub(char *ptr1, char *ptr2)
{
    while(1)
    {
        if(*ptr2 == '\0')
            return 0;
        if(*ptr1 != *ptr2)
            return -1;
        ++ptr1;
        ++ptr2;
    }
    return -1;
}

void task4()
{
    char str1[40], str2[40];
    char *ptr1;
    printf("Введите строку: ");
    scanf("%s", str1);
    printf("Введите подстроку, вхождение которой нужно найти: ");
    scanf("%s", str2);

    ptr1 = str1;

    while(*ptr1 != '\0')
    {
        if(*ptr1 == *str2)
        {
            if(check_sub(ptr1, str2) == 0)
            {
                printf("Начало вхождения подстроки найдено: %s\n", ptr1);
                return;
            }
        }
        ++ptr1;
    }

    printf("Подстрока не найдена, NULL\n");
}

int main()
{
    // Первое задание
    task1();
    printf("\n");

    // Второе задание
    task2();
    printf("\n");

    // Тертье задание
    task3();
    printf("\n");

    // Четвертое задание
    task4();
    return 0;
}
