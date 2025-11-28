#include <stdio.h>

void print_square(size_t N)
{
    int start = 1;
    for(size_t i = 0; i < N; ++i)
    {
        for(size_t j = 0; j < N; ++j)
        {
            printf("%d ", start);
            ++start;
        }
        printf("\n");
    }
}

void print_mas_reverse(int *mas, size_t size)
{
    while(1)
    {
        --size;
        printf("%d ", mas[size]);
        if(size == 0)
            break;
    }
    printf("\n");
}

void print_matrix_triangle(size_t N)
{
    size_t diagonal_pos = N - 1;

    // Заполняем верхний треугольник 1, включая диагональ
    for(size_t i = 0; i < N; ++i)
    {
        for(size_t j = 0; j < N; ++j)
        {
            if(j <= diagonal_pos)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
        --diagonal_pos;
    }
}

void fill_snail(int matrix[][5], size_t N)
{
    // границы
    int vertical_border_up = 1, vertical_border_low = N - 1;
    int horizontal_borfer_left = 0, horizontal_border_right = N - 1;
    // счетчик
    int counter = 1, max = N * N;
    int col = 0, line = 0;
    // inc_col и inc_line - направление движения (-1 - влево/вниз, +1 - вправо/вверх)
    int inc_col = 1, inc_line = 1;
    // is_col - направление движения (1 - столбцы, 0 - строки)
    __uint8_t is_col = 1;

    while(counter <= max)
    {
        // Проверка граничных случаев
        if(col > horizontal_border_right && is_col)
        {
            inc_col = -1;
            is_col ^= 1;
            --horizontal_border_right;
            --col;
            ++line;
        }
        else if(line > vertical_border_low && !is_col)
        {
            inc_line = -1;
            is_col ^= 1;
            --vertical_border_low;
            --line;
            --col;
        }
        else if(col < horizontal_borfer_left && is_col)
        {
            inc_col = 1;
            is_col ^= 1;
            ++horizontal_borfer_left;
            ++col;
            --line;
        }
        else if(line < vertical_border_up && !is_col)
        {
            inc_line = 1;
            is_col ^= 1;
            ++vertical_border_up;
            ++line;
            ++col;
        }

        matrix[line][col] = counter;

        // движение по матрице
        if(is_col)
            col += inc_col;
        else
            line += inc_line;

        // инкремент счётчика
        ++counter;
    }
}

int main()
{
    int mas[5] = {1, 2, 3, 4, 5};
    size_t size_mas = 5;
    int matrix[5][5];
    size_t matrix_size = 5;

    printf("1 задание:\n");
    print_square(3);

    printf("\n2 задание:\n");
    print_mas_reverse(mas, size_mas);

    printf("\n3 задание:\n");
    printf("N = 5:\n");
    print_matrix_triangle(5);
    printf("N = 6:\n");
    print_matrix_triangle(6);

    printf("\n4 задание:\n");
    fill_snail(matrix, matrix_size);
    for(size_t i = 0; i < matrix_size; ++i)
    {
        for(size_t j = 0; j < matrix_size; ++j)
        {
            if(matrix[i][j] < 10)
                printf("%d  ", matrix[i][j]);
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}