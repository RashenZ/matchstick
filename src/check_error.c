/*
** check_error.c for emacs in /home/Victor/match
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Feb 13 21:27:43 2017 Victor Zhu
** Last update Sun Feb 26 15:31:41 2017 Victor Zhu
*/

#include "my.h"

int	check_valid_number_preleminary(char **av, int i, int j)
{
  while (av[i])
    {
      if (av[i][j] >= '0' && av[i][j] <= '9' && av[i][0] != '0')
	i = i + 1;
      else
	{
	  my_putstr_error("Syntax error: invalid size given in parameters.\n");
	  return (84);
	}
    }
  if (my_atoi(av[1]) < 1 || my_atoi(av[1]) > 100)
    {
      my_putstr_error("Syntax error: matchstick line size invalid.\n");
      return (84);
    }
  if (my_atoi(av[2]) < 1)
    {
      my_putstr_error("Syntax error: need to remove at least 1 matches.\n");
      return (84);
    }
  return (0);
}

int	check_preleminary(int ac, char **av)
{
  int	check;

  if (ac < 3)
    {
      my_putstr_error("Error: not enough arguments.\n");
      return (84);
    }
  if (ac > 3)
    {
      my_putstr_error("Error: too much arguments.\n");
      return (84);
    }
  if ((check = check_valid_number_preleminary(av, 1, 0)) == 84)
    return (84);
  return (0);
}
