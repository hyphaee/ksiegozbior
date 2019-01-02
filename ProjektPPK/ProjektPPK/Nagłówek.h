#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Autor
{
	std::string autor;
	std::string tytul;
	Autor *nastepny;
	Autor();
};

struct Etykieta
{
	std::string etykieta;
	Autor *autor;
	Etykieta *nastepna;
	Etykieta();
};

Etykieta::Etykieta():etykieta("brak"){
	autor = nullptr;
	nastepna = nullptr;
}

Autor::Autor():autor("brak"),tytul("brak") {
	nastepny = nullptr;
}

int load_etykiety_from_file(Etykieta * & pHead);
void dodaj_etykiete(std::string autor, std::string tytul, std::vector < std::string >&etykiety, Etykieta * & pHead);
bool czy_etykieta_istnieje(std::vector < std::string >&etykiety, Etykieta *  pHead, int it);
bool czy_pozycja_juz_istnieje(std::string autor, std::string tytul, Etykieta *  pHead);
void zapisz_do_pilku(std::string file_path, Etykieta * & pHead);
void dodaj_na_poczatek(std::vector < std::string >&etykiety, int it, std::string autor, std::string tytul, Etykieta * & pHead);
void dodaj_pierwszy_element(std::vector < std::string >&etykiety, int it, std::string autor, std::string tytul, Etykieta * & pHead);
void dodaj_autora(std::string autor, std::string tytul, Autor *pHead);