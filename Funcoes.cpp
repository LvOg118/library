#include "Biblioteca.h"

void DataAtual(Date& d) { // função que calcula a data atual
	time_t rawtime;
	struct tm dat;
	time(&rawtime);
	localtime_s(&dat, &rawtime);
	d.dia = dat.tm_mday;
	d.mes = dat.tm_mon + 1;
	d.ano = dat.tm_year + 1900;
}

bool Find(string total, string& parte) { // função que pesquisa se uma string está contida na outra
	if ((parte.size()) > (total.size()))
		return false;
	for (unsigned int i = 0; i < total.size(); i++) { // varre toda a string
		unsigned int j = 0;
		if (total[i] == parte[j]) { // caso encontre um match
			unsigned int k = i; // temp
			while ((total[i] == parte[j]) && (j < parte.size())) { // segue a ordem dos caracteres
				j++;
				i++;
			}
			if (j == parte.size()) // nesse caso, ele percorreu todos os caracteres da parte, logo está contido
				return true;
			else 
				i = k; // caso contrário recomeça
		}
	}
	return false;
}