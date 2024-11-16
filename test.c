#include "libft.h"
#include <stdarg.h>

// int	ft_printf(const char*, ...)
// {

	
// }

int sum(int a, int b)
{
	return(a+b);
}

#define CHAR_PARSED "csdiupxfX%"

int main(void)
{
	char *str = "%dgdf, rserse %% %x   %f et %p c bo %23.34s%";

	while(*str)
	{
		if (*str == '%' && *(str + 1) && ft_strchr(CHAR_PARSED, *(str + 1)))
		{
			str++;
			printf("|%%%c|", *str);
		}
		else 
		{
			printf("%c", *str);
		}
		str++;
	}
	printf("\n");

	write(1, "eee", 3);
		// printf("%c", *str++);

	// printf(str, 23);
}