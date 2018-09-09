/*
** get_next_line.c for emacs in /home/Victor/CPE_2016/getnextline/CPE_2017_getnextline
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Jan  2 10:16:38 2017 Victor Zhu
** Last update Tue Feb 21 14:03:59 2017 Victor Zhu
*/

#include "get_next_line.h"

char	*my_strcat(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*get_the_line(char *buff, char *line, int len, int *start)
{
  char	*newbuff;
  int	ancient_len;

  ancient_len = 0;
  while (buff[ancient_len])
    ancient_len = ancient_len + 1;
  if ((newbuff = malloc(ancient_len + len + 1)) == NULL)
    return (NULL);
  if (buff[0] != '\0')
    my_strcat(newbuff, buff, ancient_len);
  my_strcat(newbuff + ancient_len, line + *start, len);
  *start = *start + (len + 1);
  return (newbuff);
}

char	*put_buff()
{
  char	*buff;

  if ((buff = malloc(1)) == NULL)
    return (NULL);
  buff[0] = '\0';
  return (buff);
}

char		*get_next_line(const int fd)
{
  static char	line[READ_SIZE];
  static int	rsize = 0;
  static int	start = 0;
  int		len;
  char		*buff;

  len = 0;
  buff = put_buff();
  while (1)
    {
      if (rsize <= start)
	{
	  start = 0;
	  if ((rsize = read(fd, line, READ_SIZE)) <= 0)
	    return (NULL);
	  line[rsize] = '\0';
	  len = 0;
	}
      if (line[start + len] == '\n')
	return (buff = get_the_line(buff, line, len, &start));
      if (start + len == rsize - 1)
	buff = get_the_line(buff, line, len + 1, &start);
      len = len + 1;
    }
}
