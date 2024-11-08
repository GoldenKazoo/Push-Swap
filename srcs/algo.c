#include "push_swap.h"
#include <limits.h>

t_stack    *ft_point_to_number(t_stack *stack, int n)
{
    while (stack != NULL)
    {
        if (stack -> number == n)
            return (stack);
        stack = stack -> next == NULL;
    }
}

void ft_set_closest_small(t_stack *a, t_stack *b)
{
    int n;
    long max;
    int delta;

    max = b -> number;
    while (b)
    {
        if (max < b -> number)
        {
            max = b -> number;
        }
    }
    while (a)
    {
        delta == INT_MAX;
        while (b)
        {
            if ((a -> number) - (b -> number) < delta && (a -> number) > (a -> number) - (b -> number) > 0)
            {
                delta = (a -> number) - (b -> number);
                n = b -> number;
            }
        }
        if (delta == INT_MAX)
        {
            a -> target == ft_point_to_number(b, max);
        }
        a -> target == ft_point_to_number(b, n);
    }
}

void ft_set_closest_big(t_stack *a, t_stack *b)
{
    int n;
    long min;
    int delta;

    min = b -> number;
    while (b)
    {
        if (min > b -> number)
        {
            min = b -> number;
        }
    }
    while (a)
    {
        delta == INT_MAX;
        while (b)
        {
            if ((a -> number) - (b -> number) > delta && (a -> number) > (a -> number) - (b -> number) < 0)
            {
                delta = (a -> number) - (b -> number);
                n = b -> number;
            }
        }
        if (delta == INT_MAX)
        {
            a -> target == ft_point_to_number(b, min);
        }
        a -> target == ft_point_to_number(b, n);
    }
}

void ft_set_cost()
void ft_sort_alg(t_stack *a, t_stack *b)
{
    //Etape 1 : on push 2 premiers elements dans B
    ft_push("pb", a, b);
    ft_push("pb", a, b);
    //Etape 2 : on set la target la plus petite et la plus proche si y a pas le plus grand
    ft_set_closest_small(a, b);
    //Etape 3 : on calcule le cout pour mettre le node quón regarde et sa target en haut des piles
    ft_set_cost(a, b);
    //Etape 4 : on effectue la suite dínstruction la moins couteuse
    ft_moove(a, b);
    // on repeat 2, 3 et 4 jusquá avoir stacklen(a == 3)
    //on trie la stack b a 3 elements

    //Etape 5 : on set la target la plus grande et la plus proche si y a pas, la plus petit
    ft_set_closest_big(a, b);
    //Etape 7 : regarde la mediane si c'est en dessous, rra sinon ra puis on push l'elements
}
