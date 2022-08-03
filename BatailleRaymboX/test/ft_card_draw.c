//test (la vrai fonction devra dessiner toute les cartes d'un coup)
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void	main()
{
	int x;
	int y;
	char c[] = "123456789XJQKF";
	int card;

	srand(time(NULL));
	card = rand() % 14;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (y == 0 || y == 4)
				write(1, "-", 1);
			else
			{
				if (x == 0 || x == 4)
					write (1, "|", 1);
				else if (y == 2 && x == 2)
					write (1, &c[card], 1);
				else
					write (1, " ", 1);
			}
			x++;
		}
		y++;
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
	printf("card: %d value: %c\n", card, c[card]);
}
