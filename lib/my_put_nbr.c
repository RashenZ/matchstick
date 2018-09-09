/*
** my_put_nbr.c for emacs in /home/Victor
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Thu Oct  6 15:15:24 2016 Victor Zhu
** Last update Mon Feb 13 22:29:40 2017 Victor Zhu
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	ent;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + 48);
  if (nb > 9)
    {
      ent = nb % 10;
      my_put_nbr(nb / 10);
      my_putchar(ent + 48);
    }
  return (0);
}
