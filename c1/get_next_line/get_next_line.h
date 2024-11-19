#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 20

char	*get_next_line(int fd);


#endif