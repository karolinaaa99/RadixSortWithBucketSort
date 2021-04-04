#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void init(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 100 + 1;
	}
}

void print(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
}

void sortuj_pom(int tab[], int pom[], int n, int pot) 
{
	int liczniki[10] = { 0 }; //to sa chyba te kubelki, licznik=kubelek, 10, bo jest 10 cyfr od 0 do 9
	for (int i = 0; i < n; i++)
		liczniki[(tab[i] / pot) % 10]++;
	for (int i = 1; i < 10; i++)
		liczniki[i] += liczniki[i - 1];
	for (int i = n - 1; i >= 0; i--) 
	{
		int poz = (tab[i] / pot) % 10;
		pom[liczniki[poz] - 1] = tab[i];
		liczniki[poz]--;
	}
	for (int i = 0; i < n; i++)
		tab[i] = pom[i];
}

void sortuj(int tab[], int n) 
{
	int max = tab[0];
	for (int i = 1; i < n; i++)
		if (tab[i] > max)
			max = tab[i];
	int* pom = new int[n];
	for (int pot = 1; max / pot > 0; pot *= 10)
		sortuj_pom(tab, pom, n, pot);
	delete pom;
}

int main()
{
	cout << "Sortowanie pozycyjne z wykorzystaniem sortowania kubełkowego." << endl;
	cout << "*****************************************************************" << endl;

	int n;
	srand(time(NULL));
	clock_t poczatek;
	clock_t koniec;
	double wynik;
	poczatek = clock();

	cout << "Podaj ile liczb chcesz posortowac n = ";
	cin >> n;
	cout << endl;

	int* tab = new int[n];

	init(tab, n);

	cout << "Tablica przed sortowaniem:" << endl;
	print(tab, n);
	cout << endl;

	sortuj(tab, n);
	cout << endl;

	cout << "Tablica po sortowaniu:" << endl;
	print(tab, n);
	cout << endl;

	koniec = clock();

	wynik = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << endl;

	cout << "Czas dzialania algorytmu sortowania: " << wynik << " sec" << endl;
	
	return 0;
}