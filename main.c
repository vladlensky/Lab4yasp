#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "func.h"
int main() {
    /*first part of program */
    Node_t *list = malloc(sizeof(Node_t));
    int sum;
    if(List_read(list)) {
        sum = List_sum(list);
        printf("Сумма элементов списка равна %d\n", sum);
        printf("Введите элемент, который хотите получить из списка: \n");
        int number;
        if (!scanf("%d", &number))
            printf("Некорректный ввод.\n");
        else {
            Node_t *node = List_node_at(list, number);
            if (node != NULL)
                printf("Результат - %d\n", List_get(list, number));
            else
                printf("Нет элемента с таким индексом! Размер списка - %d\n",List_length(list));
        }
        List_free(list);
    } else{
        printf("Не был прочитан ни один элемент!\n");
    }
    /*second part of program */
    list = malloc(sizeof(Node_t));
    if(List_read(list)) {
        list = list->next;
        printf("Список через пробел : ");
        foreach(list, &node_print_space);
        printf("\n");
        printf("Список через перенос строки : \n");
        foreach(list, &node_print_transfer);
        Node_t *newList = map(list, square);
        printf("Каждый элемент списка в квадрате : \n");
        foreach(newList, &node_print_space);
        printf("\n");
        List_free(newList);
        newList = map(list, cube);
        printf("Каждый элемент списка в кубе : \n");
        foreach(newList, &node_print_space);
        printf("\n");
        int maxX = 2147483647;
        int minX = -2147483648;
        sum = 0;
        sum = foldl(list, summ, 0);
        printf("Сумма - %d\n", sum);
        int max = foldl(list, more, minX);
        printf("Максимальное число - %d\n", max);
        int min = foldl(list, less, maxX);
        printf("Минимальное число - %d\n", min);
        map_mut(list, abs);
        printf("Модули элементов : \n");
        foreach(list, &node_print_space);
        printf("\n");
        List_free(newList);
    }
    else{
        printf("Не был прочитан ни один элемент!\n");
    }
    Node_t* iterateList = iterate(2,10,mul2);
    printf("Степени двойки до 10 : \n");
    foreach(iterateList,&node_print_space);
    printf("\n");
    List_free(list);
    List_free(iterateList);
}