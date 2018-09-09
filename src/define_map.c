/*
** define_map.c for emacs in /home/Victor/match
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Feb 13 18:30:36 2017 Victor Zhu
** Last update Mon Feb 13 22:23:18 2017 Victor Zhu
*/

#include "my.h"
#include <stdlib.h>

char	*fill_map(char *str, int space, int space_nd, int stick)
{
  int	i;

  i = 1;
  str[0] = '*';
  while (space != 0)
    {
      str[i] = ' ';
      i = i + 1;
      space = space - 1;
    }
  while (stick != 0)
    {
      str[i] = '|';
      i = i + 1;
      stick = stick - 1;
    }
  while (space_nd != 0)
    {
      str[i] = ' ';
      i = i + 1;
      space_nd = space_nd - 1;
    }
  str[i] = '*';
  str[i + 1] = '\0';
  return (str);
}

char	*full_stars(char *str, int line_len)
{
  int	i;

  i = 0;
  while (i < line_len)
    {
      str[i] = '*';
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

char	**define_map(char **map, int line_len, int space, char **av)
{
  int	i;
  int	stick;

  i = 0;
  stick = 1;
  while (i < my_atoi(av[1]) + 2)
    {
      if ((map[i] = malloc(line_len + 1)) == NULL)
	return (NULL);
      if (i == 0 || i == my_atoi(av[1]) + 1)
	map[i] = full_stars(map[i], line_len);
      else
	{
	  map[i] = fill_map(map[i], space, space, stick);
	  space = space - 1;
	  stick = stick + 2;
	}
      i = i + 1;
    }
  map[i] = NULL;
  return (map);
}
