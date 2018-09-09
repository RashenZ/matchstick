/*
** main.c for emacs in /home/Victor/match
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Feb 13 18:02:25 2017 Victor Zhu
** Last update Sun Feb 26 15:41:45 2017 Victor Zhu
*/

#include "my.h"
#include <stdlib.h>

char	**modif_game(char **map, int *line, int stick_nbr)
{
  int	i;

  i = my_strlen(map[0]);
  while (map[*line][i] != '|')
    i = i - 1;
  while (stick_nbr > 0)
    {
      map[*line][i] = ' ';
      i = i - 1;
      stick_nbr = stick_nbr - 1;
    }
  display_map(map);
  *line = 0;
  return (map);
}

int	get_number_of_stick(char **av)
{
  int	stick;
  int	stock_stick;
  int	line;

  stick = 1;
  stock_stick = 1;
  line = my_atoi(av[1]) - 1;
  while (line != 0)
    {
      stock_stick = stock_stick  + 2;
      stick = stick + stock_stick;
      line = line - 1;
    }
  return (stick);
}

int	matchstick_start(char **map, char **av, int line, int stick_nbr)
{
  int	stick_number;
  int	player;

  player = 1;
  stick_number = get_number_of_stick(av);
  display_map(map);
  while (stick_number != 0)
    {
      my_putchar('\n');
      if (player == 1)
	{
	  if (player_turn(av, &line, &stick_nbr, map) == 84)
	    return (0);
	  player = 2;
	}
      else
	{
	  ai_turn(map, av, &line, &stick_nbr);
	  player = 1;
	}
      map = modif_game(map, &line, stick_nbr);
      stick_number = stick_number - stick_nbr;
      stick_nbr = 0;
    }
  return (the_winner(player));
}

int	main(int ac, char **av)
{
  char	**map;
  int	line_len;
  int	i;
  int	check;

  line_len = 1;
  i = 1;
  if ((check = check_preleminary(ac, av)) == 84)
    return (84);
  while (i < my_atoi(av[1]))
    {
      line_len = line_len + 2;
      i = i + 1;
    }
  line_len = line_len + 2;
  if ((map = malloc(sizeof(char*) * (my_atoi(av[1]) + 3))) == NULL)
    return (84);
  map = define_map(map, line_len, my_atoi(av[1]) - 1, av);
  return (matchstick_start(map, av, 0, 0));
}
