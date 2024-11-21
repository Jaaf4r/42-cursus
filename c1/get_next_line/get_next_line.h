#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>


/*          MAIN FUNCTIONS         */

char	*get_next_line(int fd);


/*         HELPER FUNCTIONS        */

char	*ft_strchr(const char *s, int c);


#endif