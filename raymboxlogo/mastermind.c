#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMMIN 4
#define NUMMAX 8

int	main()
{
	int	combinaison[4];	//store la combinaison a trouver
	int	i;		//compteur
	int	checked[4];	//Entrer verifier (0 si non verifier 1 si verifier/compter dans resultat)
	int 	resultat[2];	//[0]: nb Exact  [1]: nb present
	int	combtry[4];	//Essais de l'utilisateur

	printf("Bonjour et bienvenue au jeux mastermind\n");
	printf("Essayez de deviner la combinaison comprenant 4 caracteres composes de A a D.\n");
	printf("Le resultat donnera X si emplacement exact et O si present mais non exact./n");
	srand(time(NULL));
	i = 0;
	while (i++ < 4)
	{	
		combinaison[i] = (rand() % 4);
	}
	i = 0;
	var_reset(checked, resultat);
	while (resultat[0] != 4)
	{
		//fonction entrer operateur et validation (verifie si 4 char et si lettre attendu)
		//Fonction de comparaison et verification
		//Fonction de retour feedback a l'utilisateur (win, nb good etc)
	}
}	

void	var_reset(int *checked, int *resultat)
{
	int	i = 0;
	
	while (i < 4)
	{
		checked[i] = 0;
		if (i < 2)
			resultat[i] = 0;
}
