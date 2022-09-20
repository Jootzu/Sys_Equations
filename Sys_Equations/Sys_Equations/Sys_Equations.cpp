#include <iostream>
#include <string>
#include<limits>
#define NOMINMAX
#include <windows.h>

using namespace std;

void couleurText(int c) { // méthode pour changer la couleur du texte au moment voulu dans la méthode résolution

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void resolution() {

	HWND hwnd = GetConsoleWindow(); // handle de la console
	SetConsoleTitleA("Solveur de systemes d equations par Ulysse/Jootzu"); //évident 
	MoveWindow(hwnd, 0, 0, 700, 400, TRUE); // modification de la taille de la fenêtre 

	couleurText(11); // couleur du texte qui change selon le paramètre d'entrée choisit

	cout << "Comment l utiliser ?\n";
	cout << "Saisissez vos coefficients en suivant ce schema : \n\n";
	cout << "| ax + by = c\n";
	cout << "| a'x + b'y = c'\n\n";
nouv_equa:

	// déclaration des variables utiles 
	double a = 0, b = 0, c = 0, a2 = 0, b2 = 0, c2 = 0, ta = 0, ta2 = 0, tb = 0, tb2 = 0, tc = 0, tc2 = 0, s1 = 0, s2 = 0, s3 = 0, y = 0, e = 0, x = 0;

	couleurText(15);

	cout << "\n----------------------------------1ere equation---------------------------------- \n";
	do { // tant que le frérot ne rentre pas un integer, on boule en retournant un message d'erreur
		couleurText(15); cout << "Entrez a = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //vide le buffer cin contenant la mauavaise saisie !
		cin >> a;
		if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; } // message d'erreur
	} while ((cin.fail()));
	cout << "\n";

	do {
		couleurText(15); cout << "Entrez b = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
		cin >> b;
		if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; }
	} while ((cin.fail()));
	cout << "\n";

	do {
		couleurText(15); cout << "Entrez c = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
		cin >> c;
		if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; }
	} while ((cin.fail()));


	cout << "\n----------------------------------2eme equation---------------------------------- \n";

	do {
		couleurText(15); cout << "Entrez a' = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
		cin >> a2;
		if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; }
	} while ((cin.fail()));
	cout << "\n";

	do {
		couleurText(15); cout << "Entrez b' = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
		cin >> b2;
		if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; }
	} while ((cin.fail()));
	cout << "\n";

	do {
		couleurText(15); cout << "Entrez c' = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
		cin >> c2;
		if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; }
	} while ((cin.fail()));

	couleurText(10);

	cout << "\nSysteme d equation :\n\n"; // Affichage du système d'équation avec qqs conditions : si b ou b2 sont positifs, on affiche un "+" devant le terme
	if (b > 0) { cout << "|" << a << "x + " << b << "y = " << c; }
	else { cout << "|" << a << "x " << b << "y = " << c; }

	cout << "\n";

	if (b2 > 0) { cout << "|" << a2 << "x + " << b2 << "y = " << c2; }
	else { cout << "|" << a2 << "x " << b2 << "y = " << c2; }
	cout << "\n\n";
	//if (c > 0) c* (-1); 
	// combinaisons linéaires simplement : 

	ta = a * a2; tb = b * a2; tc = c * a2;

	ta2 = a2 * a; tb2 = b2 * a; tc2 = c2 * a;

	s1 = ta - ta;

	s2 = tb - tb2;

	s3 = tc - tc2;

	y = s3 / s2;

	e = c - (b * y);

	x = e / a;

	couleurText(16);

	cout << "\n";
	cout << "(x ; y) = (" << x << " ; " << y << ")\n"; // Affichage des solutions x y

	goto nouv_equa; //mdrr tah l'époque 

}

int main() {

	resolution(); // appel de la fonction de résolutionc

}

/*conditions:
	if (b > 0)  b * (-1);
	//if (c > 0) c* (-1);
	//if (tb2 < 0) tb2 * (-1);
	//if (tc2 < 0) tc2 * (-1);
*/

/*do {
	couleurText(15);
	cout << "Entrez a = ";
	if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //vide le buffer cin contenant la mauavaise saisie !
	cin >> a;

	if (cin.fail()) {
		couleurText(12);
		cout << "[ERREUR] Pas un reel !\n\n";
	}

} while ((cin.fail()));*/


/*do { couleurText(15); cout << "Entrez a = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //vide le buffer cin contenant la mauavaise saisie !
	cin >> a;
	if (cin.fail()) { couleurText(12); cout << "[ERREUR] Pas un reel !\n\n"; }
} while ((cin.fail()));*/