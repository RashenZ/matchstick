/*
** my_strlen.c for emacs in /home/Victor
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Fri Oct  7 19:07:54 2016 Victor Zhu
** Last update Mon Nov  7 16:47:40 2016 Victor Zhu
*/

int	my_strlen(char *str)
{
  int	bullshit;

  bullshit = 0;
  while (str[bullshit] != '\0')
    bullshit = bullshit + 1;
  return (bullshit);
}
