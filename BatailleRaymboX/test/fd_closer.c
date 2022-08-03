#include <unistd.h>

int	main()
{
	int	i = 2;

	while (close(++i) != -1)
	{}
}
