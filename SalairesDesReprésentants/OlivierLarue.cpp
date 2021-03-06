// But :
/*
Une grosse soci�t� de produits chimiques r�mun�re ses repr�sentants commerciaux � la commission. Les
repr�sentants re�oivent 250 $ par semaine plus 7.5% de leurs ventes brutes par semaine. Par exemple, un
repr�sentant qui vend pour 5000 $ de produits chimiques en une semaine, per�oit un salaire de 250 $ plus 7.5 % de
5000$, soit un total de 625 $.
D�veloppez un programme qui entre les ventes brutes hebdomadaires de chaque repr�sentant et qui calcule et
affiche son salaire. Entrez -1 � la valeur des ventes pour quitter le programme.
*/
// Auteur : Olivier Larue
// Date : 2020 05 octobre

#include <iostream>
using namespace std;			// Pour all�ger le code et plus mettre std:: avant les cout, cin, endl, ...
/*
plan de  test 
valeurDesVentes        argentsemaine           commition                          salaire
 5000                     250                7.5 * 5000 /100 = 375               250+375=625
 2000                     250                7.5 * 2000 /100 = 150				250+150= 400
 -123      ERREUR: la valeur des ventes ne peut �tre negative ... return 0; on recommence
 0                        250                7.5 * 0 / 100 = 0                      250+0=250
 123456                   250               7.5 * 123 456/ 100 = 9 259.20          250+9259.20= 9 509.20
*/
int main()
{
	setlocale(LC_ALL, "");

	// D�claration des variables au d�but du programme
	const int argentSemaine = 250; // l'Argent donner � chaque semaine sans la commition de 7.5% mit dans une constante pour s'il change dans le future je n'aurais pas � changer tout mon code :)
	float valeurDesVentes; // initialis� par l'utilisateur.
	float salaire = 0; // le salaire = au 250 par semaine + 7.5% de la valeur des ventes (par exemple 5000)
	float commition = 0; // Initialis� avant la boucle, mais va changer de valeur � l'int�rieur, me permet de d�finir la commition obtenue par le repr�sentant des ventes
	// commition = 7.5% de la valeur des ventes
	cout << "Veuillez entrer la valeur des ventes obtenues cette semaine: ";
	cin >> valeurDesVentes;


	while (valeurDesVentes != -1)
	{
		if (valeurDesVentes < -1) // la valeur des ventes ne peut etre negative. Tu ne vends pas � la perte donc pas de chiffre n�gatif et l'utilisateur essai d'en rentrer le programme return 0.
		{
			cout << "ERREUR: Il est imposible d'entrer un nombre n�gatif pour rep�senter la valeur des ventes, veuillez r�essayer.";
			return 0;
		}
		
		
		commition = 7.5 * valeurDesVentes / 100; //Pour calculer la commition
		salaire = argentSemaine + commition; // Pour calculer le salaire
		cout << "Voici le montant re�u par semaine : " << argentSemaine << endl;

		cout << "Voici le montant de commition optenu par ce repr�sentant cette semaine: " << commition << endl;

		cout << "Voici le salaire pour ce rep�sentant cette semaine: " << salaire << endl;

		cout << endl; // � but d'am�liorer la clairet�, donne un espace entre les donn�es des repr�sentants j'aime mieux cela :)
		cout << "Veuillez entrer la valeur des ventes obtenues cette semaine: "; 
		cin >> valeurDesVentes;
		
	}

	cout << "Vous avez d�cid� de quitter le programme. � la prochain ! =D" << endl; 

	return 0;
}