#include "get_next_line.h"

int main()
{
	int fd = open("files/test_nr", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	while (str != 0){
		printf("\n\n**GNL**\n%s\n\n" , str);
		str = get_next_line(fd);
	}
	// printf("\n\n**GNL**\n%s\n\n" , str);
	// str = get_next_line(fd);
	printf("\n\n**GNL**\n%s\n\n" , str);
}
