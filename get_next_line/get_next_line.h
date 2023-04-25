#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char	*dest, const char *src, size_t size);
char	*gnl_strdup(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);

#endif
