/*
** my.h for emacs in /home/Victor/CPE_2016/CPE_2016_matchstick/include
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Feb 13 21:53:05 2017 Victor Zhu
** Last update Wed Feb 22 13:11:31 2017 Victor Zhu
*/

#ifndef MY_H
#define MY_H

void	my_putstr_error(char *str);
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_put_nbr(int nbr);
int	my_atoi(char *str);

char	*get_next_line(const int fd);

int	check_preleminary(int ac, char **av);
char	**define_map(char **map, int line_len, int space, char **av);
void	display_map(char **map);
void	display_player_plays(int *line, int *stick_nbr);
void	display_ai_plays(int *line, int *stick_nbr);

void	ai_turn(char **map, char **av, int *line, int *stick);
int	player_turn();
int	the_winner(int player);
int	check_matches();
int	check_line();

#endif
