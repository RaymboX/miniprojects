#include "brc.h"
#include "var_extern.h"

void	ft_sit_check()
{
	if (input == '\n')
	{
		if (value[0][0] + value[1][0] == 0)
			sit = START;
		else
		{
			if (value[0][1] > 0 && value[0][1] == value[1][1])
				sit = REINITIALISATION;
			else
			{
				switch (value[0][0] - value[1][0])
				{
					case 0://deux cartes identiques
						sit = BATAILLE;
						break;
					case -100 ... -7://BOT OVER de plus de 6
						sit = BO6;
						break;
					case 7 ... 100://PLAYER OVER de plus de 6
						sit = PO6;
						break;
					case -6 ... -1://BOT OVER entre 1 et 6
						if (value[0][1] + value[1][1] == 0)//pas de de lancer
							sit = B1TO6;
						else if (value[0][1] > 0 && value[1][1] == 0)//Player de lancer
						{
							if (value[0][0] + value[0][1] == value[1][0])//P carte + de = carte bot
								sit = BATAILLE;
							else if (value[0][0] + value[0][1] < value[1][0])//P carte + de < carte bot
								sit = YOU_FAIL;
							else if (value[0][0] + value[0][1] > value[1][0])//P carte + de > carte bot
								sit = YOU_SUCCEED;
						}
						else if (value[0][1] > 0 && value[1][1] > 0)//deux de lancer
						{
							if (value[0][0] + value[0][1] < value[1][0])//P carte + de < carte bot
							{
								if (value[0][1] < value[1][1])//P de < de bot
									sit = BOT_WINALL;
								else if (value[0][1] > value[1][1])//P de > de bot
									sit = BOT_WINPLAY;
							}
							else if (value[0][0] + value[0][1] > value[1][0])//P carte + de > carte bot
							{
								if (value[0][1] < value[1][1])//p de < de bot
									sit = YOU_WINPLAY;
								else if (value[0][1] > value[1][1])//p de > de bot
									sit = YOU_WINALL;
							}
						}
						break;
					case 1 ... 6://PLAYER OVER entre 1 et 6
						if (value[1][1] + value[0][1] == 0)//pas de de lancer
							sit = P1TO6;
						else if (value[1][1] > 0 && value[0][1] == 0)//BOT de lancer
						{
							if (value[1][0] + value[1][1] == value[0][0])//BOT carte + de = carte P
								sit = BATAILLE;
							else if (value[1][0] + value[1][1] < value[0][0])//BOT carte + de < carte P
								sit = BOT_FAIL;
							else if (value[1][0] + value[1][1] > value[0][0])//BOT carte + de > carte P
								sit = BOT_SUCCEED;
						}
						else if (value[1][1] > 0 && value[0][1] > 0)//deux de lancer
						{
							if (value[1][0] + value[1][1] < value[0][0])//BOT carte + de < carte P
							{
								if (value[1][1] < value[0][1])//BOT de < de P
									sit = YOU_WINALL;
								else if (value[1][1] > value[0][1])//BOT de > de P
									sit = YOU_WINPLAY;
							}
							else if (value[1][0] + value[1][1] > value[0][0])//BOT carte + de > carte P
							{
								if (value[1][1] < value[0][1])//BOT de < de P
									sit = BOT_WINPLAY;
								else if (value[1][1] > value[0][1])//BOT de > de P
									sit = BOT_WINALL;
							}
						}
						break;
				}
			}
		}
	}
	else
	{
		switch (input)
		{
			case 'p':
				if (value[0][0] + value[1][0] == 0)
					sit = PLAY;
				else if (value[0][0] < value[1][0])
					sit = YOU_PASS;
				else if (value[0][0] > value[1][0])
					sit = BOT_PASS;
				break;
			case 'm':
				if (value[0][0] + value[1][0] == 0)
					sit = MENU;
				else if (value[0][1] == 0 ^ value[1][1] == 0)
					sit = BATAILLE_BET;
				else if (value[0][0] < value[1][0])
					sit = YOU_TRY;
				else if (value[0][0] > value[1][0])
					sit = BOT_TRY;
				break;
			case 'd':
				sit = YOU_DICE;
				break;
			case 'D':	
				sit = BOT_DICE;
				break;
			case 'c':
				sit = BAT_BOTBETALL;
				break;
			case 'C':
				sit = BAT_YOUBETALL;
				break;
			case 'S':
				sit = SPLIT;
				break;
			case 'w':
				sit = YOU_LOSEGAME;
				break;
			case 'W':
				sit = YOU_WINGAME;
				break;
			case 'n':
				sit = YOU_NOTRY;
				break;
			case 'N':
				sit = BOT_NOTRY;
				break;
			case 'R':
				if (value[0][0] < value[1][0])
					sit = YOU_RETRY;
				else if (value[0][0] > value[1][0])
					sit = BOT_RETRY;
				break;
		}
		input = '\n';
	}
}



