#include "get_next_line.h"

int main()
{
	int fd = open("files/test_nr", O_RDONLY); 
	printf("\n\n**GNL**\n%s\n\n" , get_next_line(fd));
}