#include "push_swap.h"

int ft_is_num(char c)
{
    if (c < '0' || c > '9')
        return (1);
    return (0);
}

int ft_arg_valid(char *string)
{
    int i;

    i = 0;
    if (string[i] == '+' || string[i] == '-')
        i++;
    while (string[i] != '\0')
    {
        if (ft_is_num(string[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}

int ft_atoi(char *string)
{
    int i;
    long number;
    int mult;

    i = 0;
    mult = 1;
    if (string[i] == '+')
        i++;
    if (string[i] == '-')
    {
        i++;
        mult = -1;
    }
    number = string[i] - 48;
    i++;
    while(string[i] != '\0')
    {
        number = (number * 10) + (string[i] - 48);
        if (number < -2147483648 || number > 2147483647)
        {
            printf("Number range is overflowing !");
            exit(1);
        }
        i++;
    }
    number = number * mult;
    return (number);
}

void    ft_print_stack(t_stack *stack)
{
    t_stack *traveler;

    traveler = stack;
    while (traveler -> next != NULL)
    {
        printf("Number : %i\n", traveler -> number);
        traveler = traveler -> next;
    }
    printf("Number : %i", traveler -> number);
}

t_stack *ft_new_number(int number)
{
    t_stack *new_number;

    new_number = malloc(sizeof(t_stack));
    new_number -> number = number;
    new_number -> next = NULL;
    return (new_number);
}

int ft_number_in_stack(int number, t_stack  *stack)
{
    t_stack *traveler;

    traveler = stack;
    while (traveler -> next != NULL)
    {
        if (traveler -> number == number)
            return (1);
        traveler = traveler -> next;
    }
    return (0);
}

void    ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
}
void    ft_add_back(int number, t_stack *stack)
{
    t_stack *traveler;

    traveler = stack;
    while (traveler -> next != NULL)
    {
        traveler = traveler -> next;
    }
    traveler -> next = ft_new_number(number); 
}


int main(int argc, char **argv)
{
    int     i;
    int     current;
    t_stack *stack_a;
    t_stack *stack_b;

    i = 1;
    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
    {
        printf("Can't init stacks");
        return (1);
    }
    if (argc <= 2)
    {
        printf("You have to enter at least 2 numbers");
        return (1);
    }
    while (i < argc)
    {   
        if (ft_arg_valid(argv[i]) == 1)
        {
            printf("Invalid arguments");
            ft_free_stacks(stack_a, stack_b);
            return (1);
        }
        current = ft_atoi(argv[i]);
        if (ft_number_in_stack(current, stack_a) == 0 && i == 1)
        {
            stack_a -> number = current;
            stack_a -> next = NULL;
        }
        if (ft_number_in_stack(current, stack_a) == 0 && i != 1)
        {
            ft_add_back(current, stack_a);
        }
        if (ft_number_in_stack(current, stack_a) == 1)
        {
            printf("You entered duplicates : %i", current);
            exit(1);
        }
        i++;
    }
    ft_swap("sa", &stack_a);
    ft_print_stack(stack_a);
}
