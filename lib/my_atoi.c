/*
** my_atoi.c for emacs in /home/Victor/test
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Thu Nov 10 13:38:09 2016 Victor Zhu
** Last update Mon Feb 13 22:30:08 2017 Victor Zhu
*/

#include "my.h"

int	my_atoi(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  result = (result * 10) + str[i] - '0';
	  i = i + 1;
	}
      else
	{
	  my_putstr("Syntax error");
	  return (84);
	}
    }
  return (result);
}
