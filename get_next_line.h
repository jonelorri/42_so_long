/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:18:49 by jelorria          #+#    #+#             */
/*   Updated: 2022/04/06 20:04:15 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct  s_program
{
	void	*mlx;
	void	*win;
	int		iw;
	int		ih;
	void	*imgZ;
	int	xZ;
	int	yZ;
	void	*imgF;
	void	*imgR;
	void	*imgC;
	void	*imgE;
	//void	*imgE_;
	int		x;
	//int	x_;
	int		y;
	//int	y_;
	int		i;
	int		fd;
	char	*line;
	int		len;
	int	contador;
	int	**mtrx;
	int	collect;
	int	tocollect; 
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
int	*read_map(void *param);

#endif
