/*
** display.c for emacs in /home/Victor/CPE_2016/CPE_2016_matchstick
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Feb 13 22:26:08 2017 Victor Zhu
** Last update Sun Feb 26 16:01:09 2017 Victor Zhu
*/

#include "my.h"
#include <stdlib.h>

int	the_winner(int player)
{
  if (player == 1)
    {
      my_putstr("I lost... snif... but I'll get you next time!!\n");
      return (1);
    }
  my_putstr("You lost, too bad...\n");
  return (2);
}

void	display_ai_plays(int *line, int *stick)
{
  my_putstr("AI removed ");
  my_put_nbr(*stick);
  my_putstr(" match(es) from line ");
  my_put_nbr(*line);
  my_putchar('\n');
}

void	display_player_plays(int *line, int *stick_nbr)
{
  my_putstr("Player removed ");
  my_put_nbr(*stick_nbr);
  my_putstr(" match(es) from line ");
  my_put_nbr(*line);
  my_putchar('\n');
}

void	display_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
