/*
** my_putstr_error.c for emacs in /home/Victor/CPool_workshoplib/lib/my
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sun Dec 25 11:37:07 2016 Victor Zhu
** Last update Mon Feb 13 22:30:31 2017 Victor Zhu
*/

#include "my.h"
#include <unistd.h>

void	my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
}
