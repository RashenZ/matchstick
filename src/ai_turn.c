/*
** ia_turn.c for emacs in /home/Victor/CPE_2016/CPE_2016_matchstick
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Feb 15 13:39:25 2017 Victor Zhu
** Last update Wed Feb 22 12:38:03 2017 Victor Zhu
*/

#include "my.h"
#include <stdlib.h>
#include <time.h>

int	get_matches_for_ai(char **map, int *line)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (map[*line][i])
    {
      if (map[*line][i] == '|')
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

int	check_ai_line(int r_number, char **map, char **av)
{
  int	i;
  int	check;

  i = 0;
  if (r_number < 1 || r_number > my_atoi(av[1]))
    return (84);
  while (map[r_number][i] != '|' && map[r_number][i])
    i = i + 1;
  if (map[r_number][i] == '\0')
    return (84);
  return (0);
}

int	check_ai_matches(int r_number, char **map, char **av, int count)
{
  if (r_number > my_atoi(av[2]))
    return (84);
  if (r_number < 1)
    return (84);
  if (r_number > count)
    return (84);
  return (0);
}

void	ai_turn(char **map, char **av, int *line, int *stick)
{
  int	r_number;
  int	check;
  int	count;

  my_putstr("AI's turn...\n");
  srand(time(NULL));
  r_number = rand() % my_atoi(av[1]);
  while ((check = check_ai_line(r_number, map, av)) != 0)
    r_number = rand() % (my_atoi(av[1]) + 1);
  *line = r_number;
  count = get_matches_for_ai(map, line);
  r_number = rand() % count;
  while ((check = check_ai_matches(r_number, map, av, count)) != 0)
    r_number = rand() % (count + 1);
  *stick = r_number;
  display_ai_plays(line, stick);
}
