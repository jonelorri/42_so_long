/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:18:49 by jelorria          #+#    #+#             */
/*   Updated: 2022/05/05 19:42:37 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct s_program
{
	void	*mlx;
	void	*win;
	int		iw;
	int		ih;
	void	*imgz;
	int		xz;
	int		yz;
	void	*imgf;
	void	*imgr;
	void	*imgc;
	void	*imge;
	int		x;
	int		y;
	int		i;
	int		fd;
	char	*line;
	int		len;
	int		con;
	int		**mtrx;
	int		collect;
	int		tocollect;
	int		obj1;
	int		obj2;
	int		obj3;
	int		obj4;
	int		obj5;
	int		len1;
	int		len2;
}			t_program;

size_t	ft_strlen(const char *str, int x);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, char *set);
char	*ft_strdup(char *s1);
char	*end_line(char **holder2, char *buf);
char	*update_line(char **holder, char *buf);
char	*get_next_line(int fd);
int		*read_map(void *param, char **argv);
void	e_m(int cont);
void	rectangle(void *param);
void	loop1(void *param);
void	loop2(void *param);
void	loop3(void *param);
void	loop4(void *param);
void	loop5(void *param);
int		case1(void *param);
int		case2(void *param);
int		case3(void *param);
int		case4(void *param);
void	test_wall(void *param, char **argv);

#endif
