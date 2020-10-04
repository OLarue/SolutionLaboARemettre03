// But :
/*
Complétez ce programme pour qu’il donne la possibilité à l’utilisateur de deviner le nombre contenu dans iRandom.
L’utilisateur a un maximum de 5 chances. Le programme vérifie que l’utilisateur a bien entré un nombre entre 0 et
100 et lui indique s’il gagne ou dans le cas contraire lui indique le nombre d’essais restant et lui redemande un
nombre.

*/
// Auteur : Olivier Larue
// Date : 2020-05-octobre

#include <iostream>

#include <time.h>
using namespace std;
int main()
{
	//Variable
	int iRandom; // permet de mémoriser le nombre choisi aléatoirement par l’ordinateur
	
	int choixUtilisateur; // Choix de l'utilisateur 

	srand(time(0)); // pour activer l’aléatoire dans le programme
	iRandom = rand() % 101;// l’ordinateur calcule un nombre aléatoire entre 0 et 100 et le stocke dans iRandom

	cout << "Veuillez entrer votre choix: ";
	cin >> choixUtilisateur;

	if (choixUtilisateur < 1 || choixUtilisateur > 100) //Pour s'assurer que le nombre est bien entre 1 et 100
	{
		cout << "ERREUR: Vous devez entrer un chiffre entre 1 et 100.";
		return 0;
	}

	for (int compteur = 1; compteur < 5 ; compteur++) //La boucle for puisque je sais le nombre d'essais que l'utilisateur a.
	{
		
		if (choixUtilisateur != iRandom) // si le choix n'est pas égale a iRandom la boucle continue jusqu'à 5 fois ou jusqu'à ce que l'utilisateur obtient la bonne réponse (il va alors entrer dans le else)
		{
			if (choixUtilisateur < iRandom) // Pour savoir si le chiffre que l'utilisateur chercher est plus grand que le chiffre automatisé
			{
				cout << "Le chiffre que vouz cherchez est plus grand que " << choixUtilisateur << endl;
			}
			if (choixUtilisateur > iRandom)// Pour savoir si le chiffre que l'utilisateur cherche est plus petit que celui qui est automatisé.
			{
				cout << "Le chiffre que vouz cherchez est plus petit que " << choixUtilisateur << endl;
			}

			cout << "Veuillez entrer votre choix: ";
			cin >> choixUtilisateur;

			if (choixUtilisateur < 1 || choixUtilisateur > 100) //Pour s'assurer que le nombre est bien entre 1 et 100
			{
				cout << "ERREUR: Vous devez entrer un chiffre entre 1 et 100.";
				return 0;
			}
			if (choixUtilisateur == iRandom)// j'ai ajouter un if ici puisque lorsque je rentrais mon 5ieme choix, le dernier, et qu'il était le bon choix, 
					//il m'affichait plus d'essais puisque le programme voyait que mon compteur etait depasser 5 avant de voir que choixUtilisateur != iRandom.
			{
				cout << "Bravo, " << choixUtilisateur << " est le bon choix! Rejouer avec nous quand vous voulez. =)";
				return 0;

			}
		}
		else
		{
			cout << "Bravo," << choixUtilisateur << " est le bon choix! Rejouer avec nous quand vous voulez. =)";
			return 0;
		}
		
	}

	


	cout << "Oh non! Vous n'avez plus d'essais. Le chiffre est: " << iRandom <<". "<<  "Meilleur chance la prochaine fois ;)";

	return 0;
}
/*
Plan de test 
iRandom    choixUtilisateur       +> ou +<				  résultat         
100            20               plus grand         recommence
100             -1									  ERREUR
9             10                  plus petit        recommence
9             0										  ERREUR
27             200									 ERREUR
100           100								  Félication
2              3                    plus petit     recommence
2				78					plus petit      recommence
2				99					plus petit		recommence
2				1					plus grand		recommence
2				2									Félicitation
*/