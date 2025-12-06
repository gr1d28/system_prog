#include <stdio.h>
#include <string.h>

#define STRING_SIZE 20

typedef struct abonent {
    char name[STRING_SIZE];
    char second_name[STRING_SIZE];
    char tel[STRING_SIZE];
} Abonent;

void print_help()
{
    printf("1) Добавить абонента\n");
    printf("2) Удалить абонента\n");
    printf("3) Поиск абонентов по имени\n");
    printf("4) Вывод всех записей\n");
    printf("5) Выход\n");
}

void clean_list(Abonent *list, size_t abonent_max_size)
{
    for(size_t i = 0; i < abonent_max_size; ++i)
    {
        memset(list->name, 0, STRING_SIZE);
        memset(list->second_name, 0, STRING_SIZE);
        memset(list->tel, 0, STRING_SIZE);
        ++list;
    }
}

void add_abonent(Abonent *ptr)
{
    while(ptr->name[0] != 0 || ptr->second_name[0] != 0 || ptr->tel[0] != 0)
        ++ptr;
    printf("Имя: ");
    scanf("%s", ptr->name);
    printf("Фамилия: ");
    scanf("%s", ptr->second_name);
    printf("Номер телефона: ");
    scanf("%s", ptr->tel);
}

Abonent *find_abonent(Abonent *list, size_t abonent_max_size, char *name)
{
    for(size_t i = 0; i < abonent_max_size; ++i)
    {
        if(strncmp(list->name, name, STRING_SIZE) == 0)
            return list;
        ++list;
    }
    return NULL;
}

int delete_abonent(Abonent *list, size_t abonent_max_size, char *name)
{
    Abonent *find = find_abonent(list, abonent_max_size, name);
    if(find == NULL)
        return -1;
    memset(find->name, 0, STRING_SIZE);
    memset(find->second_name, 0, STRING_SIZE);
    memset(find->tel, 0, STRING_SIZE);
    return 0;
}

void print_all_abonents(Abonent *list, size_t count_abonents)
{
    size_t count = 0;
    while(count != count_abonents)
    {
        if(list->name[0] == 0 && list->second_name[0] == 0 && list->tel[0] == 0)
        {
            ++list;
            continue;
        }
        printf("%ld: %s, %s, %s\n", count + 1, list->name, list->second_name, list->tel);
        ++list;
        ++count;
    }
}

void skip_whitespace()
{
    char ch = getchar();
    while(ch != '\n')
        ch = getchar();
}

int main()
{
    Abonent abonent_list[100], *ptr_find;
    char name_for_find[STRING_SIZE];
    size_t abonent_max_size = 100, count_abonents = 0;
    char action = '\0';

    clean_list(abonent_list, abonent_max_size);

    while(1)
    {
        print_help();
        scanf("%c", &action);
        switch(action)
        {
            case '1':
                if(count_abonents == abonent_max_size)
                {
                    printf("Достигнуто максимальное количество абонентов (%ld)\n", abonent_max_size);
                    break;
                }
                add_abonent(abonent_list);
                ++count_abonents;
                break;
            case '2':
                if(count_abonents == 0)
                {
                    printf("Список абонентов пуст\n");
                    break;
                }
                memset(name_for_find, 0, STRING_SIZE);
                printf("Имя абонента, которого нужно удалить: ");
                scanf("%s", name_for_find);
                if(delete_abonent(abonent_list, abonent_max_size, name_for_find) == 0)
                {
                    printf("Абонент удален из списка\n");
                    --count_abonents;
                }
                else
                    printf("Абонент не найден\n");
                break;
            case '3':
                if(count_abonents == 0)
                {
                    printf("Список абонентов пуст\n");
                    break;
                }
                memset(name_for_find, 0, STRING_SIZE);
                printf("Имя абонента, которого нужно найти: ");
                scanf("%s", name_for_find);
                ptr_find = find_abonent(abonent_list, abonent_max_size, name_for_find);
                if(ptr_find != NULL)
                {
                    printf("Абонент найден\n");
                    printf("Имя: %s\nФамилия: %s\nНомер телефона: %s\n", ptr_find->name, ptr_find->second_name, ptr_find->tel);
                }
                else
                    printf("Абонент с именем \"%s\" не найден\n", name_for_find);
                break;
            case '4':
                print_all_abonents(abonent_list, count_abonents);
                break;
            case '5':
                return 0;
            default:
                printf("Неопределенная команда\n");
                break;
        }
        skip_whitespace();
    }
    return 0;
}