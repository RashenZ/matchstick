/*
** player_turn.c for emacs in /home/Victor/CPE_2016/CPE_2016_matchstick
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Feb 14 05:50:44 2017 Victor Zhu
** Last update Sun Feb 26 15:26:23 2017 Victor Zhu
*/

#include "my.h"
#include <stdlib.h>

int	take_line(char *str, int **line, char **av, char **map)
{
  int	check;

  check = 0;
  if ((check = check_line(str, av, map)) == 0)
    {
      **line = my_atoi(str);
      return (2);
    }
  return (1);
}

char	*get_player_line(char **av, int *line, int *stick_nbr, char **map)
{
  char	*str;

  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  return (str);
}

int	player_turn(char **av, int *line, int *stick_nbr, char **map)
{
  char	*str;
  int	check;
  int	put;

  put = 1;
  my_putstr("Your turn:\nLine: ");
  if ((str = get_player_line(av, line, stick_nbr, map)) == NULL)
    return (84);
  if ((put = take_line(str, &line, av, map)) == 1)
    player_turn(av, line, stick_nbr, map);
  if (put == 2)
    {
      my_putstr("Matches: ");
      if ((str = get_next_line(0)))
	{
	  if ((check = check_matches(str, *line, map, av)) == 0)
	    {
	      *stick_nbr = my_atoi(str);
	      display_player_plays(line, stick_nbr);
	      return (0);
	    }
	}
      player_turn(av, line, stick_nbr, map);
    }
}
