/*
** check_turn.c for emacs in /home/Victor/CPE_2016/CPE_2016_matchstick
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Feb 15 10:28:39 2017 Victor Zhu
** Last update Sun Feb 26 15:32:26 2017 Victor Zhu
*/

#include "my.h"

int	check_number_correct(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    i = i + 1;
  if (str[i] != '\0')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (84);
    }
  return (0);
}

int	check_enough_matches(int matches, char **map, int line)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (map[line][i])
    {
      if (map[line][i] == '|')
	count = count + 1;
      i = i + 1;
    }
  if (count < matches)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (84);
    }
  return (0);
}

int	check_matches(char *str, int line, char **map, char **av)
{
  int	check;
  int	matches;

  if ((check = check_number_correct(str)) == 84)
    return (84);
  matches = my_atoi(str);
  if (matches == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (84);
    }
  if (matches > my_atoi(av[2]))
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(my_atoi(av[2]));
      my_putstr(" matches per turn\n");
      return (84);
    }
  if ((check = check_enough_matches(matches, map, line)) == 84)
    return (84);
  return (0);
}

int	check_line(char *str, char **av, char **map)
{
  int	i;
  int	line;
  int	check;

  i = 0;
  if ((check = check_number_correct(str)) == 84)
    return (84);
  if ((line = my_atoi(str)) == 0 || (line = my_atoi(str)) > my_atoi(av[1]))
    {
      my_putstr("Error: this line is out of range\n");
      return (84);
    }
  while (map[line][i] != '|' && map[line][i])
    i = i + 1;
  if (map[line][i] == '\0')
    {
      my_putstr("Error: there is no matches left in this line\n");
      return (84);
    }
  return (0);
}
