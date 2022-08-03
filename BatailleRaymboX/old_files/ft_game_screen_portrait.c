#include "brc.h"

#define SW 18

void	ft_game_screen(char deck[2][3][54], int value[2][2])
{
	 
	// les situations d'animation seront inserer ici


	ft_8line_draw(deck, value);



}


void	ft_8line_draw(char deck[2][3][54], int value[2][2])
{
	int	x;
	int	y;
	int	i8line = 0;

	while (i8line < 6)
	{
		y = 0;
		while (y < 8)
		{
			x = 0;
			while (x < SW)
			{
				if (i8line == 0)
					ft_draw_decklines(deck, x, y, 1);			
				if (i8line == 1)
					ft_draw_playlines(deck, value, x, y, 1);
				if (i8line == 2)
				{
					// diff text and out lines
				}
				if (i8line == 3)
					ft_draw_playlines(deck, value, x, y, 0);
				if (i8line == 4)
					ft_draw_decklines(deck, x, y, 0);
				if (i8line == 5)
				{
					//command lines
				}
				x++;
			}
			y++;
			write (1, "\n", 1);
		}
		i8line++;
	}
}


void	ft_draw_decklines(char deck[2][3][54], int x, int y, int p0b1)
{
	char	c = ' ';
	
	c = ft_char_card(ft_strlen(deck[p0b1][0], 0), '0', "DECK ", 0, x, y);
	if (ft_write_c(c))
	{
		c = ft_char_card(ft_strlen(deck[p0b1][2], 0), '0', "DEPOT", 6, x, y);
		if (ft_write_c(c))
		{
			if (y == 3 && x == 12)
			{
				if (p0b1 == 0)
				{
					write (1, "PLAYER", 6);
					x += 5;
				}
				else
				{
					write (1, "BOT", 3);	
					x += 2;
				}
			}
		else
			write (1, " ", 1);
		}
	}
}

void	ft_draw_playlines(char deck[2][3][54], int value[2][2], int x, int y, int p0b1)
{
	char	c = ' ';
	
	if (deck[p0b1][1][0])
	{
		c = ft_char_card(1, deck[p0b1][1][0], "PLAY ", 0, x, y);
		if (ft_write_c(c))
		{
			if (ft_strlen(deck[1][1], 1) > 0)
				c = ft_char_card(ft_strlen(deck[p0b1][1], 1), deck[p0b1][1][ft_strlen(deck[p0b1][1], 1)], "MISE ", 6, x, y);
		    	if (ft_write_c(c) && value[p0b1][1] > 0)
				c = ft_char_de(value[p0b1][1], 14, x, y);
			write (1, &c, 1);
		}
	}
}


int	ft_write_c(char c)
{
	if (c != ' ')
	{
		write (1, &c, 1);
		return (0);
	}
	return (1);
}	



char	ft_char_de(int value, int offset_x, int x, int y)
{
	char	c = ' ';
	int	xo = x - offset_x;
	
	if (y == 1)
	{
		if (xo == 0)
			c = 'D';
		else if (xo == 1)
			c = 'E';
	}
	else if ((y >= 3 && y <= 5) && ((xo == 0 || xo == 2) || (y == 3 && xo == 3)))
		c = '|';
	else if ((y == 2 && xo == 2) || (y == 3 && xo == 1) || (y == 5 && xo == 1))
		c = '-';
	else if ((y == 2 && xo == 1) || (y == 2 && xo == 3) || (y == 4 && xo == 3))
		c = '/';
	else if (y == 4 && xo == 1)
		c = value - '0';
	return (c);
}



char	ft_char_card(int nbleft, char topcard, char name5char[6], int offset_x, int x, int y)
{
	char	c = ' ';
	int	xo = x - offset_x;

	if (nbleft > 0 && xo >= 0 && xo <= 5)
	{
		if (y == 0)
		{
			if (xo == 0)
				c = nbleft / 10 + '0';
			else if (xo == 1)
				c = nbleft % 10 + '0';
		}
		else if ((y == 1 || y == 5) && (xo >= 0) && (xo <= 4))
			c = '-';
		else if (y >= 2 && y <= 4)
		{
			if (xo == 0 || xo == 4)
				c = '|';
			else if (topcard == '0')
			{
				if ((y == 2 && xo == 1)
						|| (y == 4 && xo == 3))
					c = '\\';
				if ((y == 2 && xo == 3)
						|| (y == 4 && xo == 1))
					c = '/';
				if (y == 3 && xo == 2)
					c = 'X';
			}
			else if ((y == 2 && xo == 1) || (y == 4 && xo == 3))
				c = topcard;
		}
		else if (y == 6)
			c = name5char[xo];		
	}
	return (c);
}


