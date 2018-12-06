#include "Biblioteca.h"

bool Publicacao::operator== (Publicacao& PubVerif) const { // sobrecarga padr�o de PUB
	if ((PubVerif.titulo == titulo) & (PubVerif.editora == editora) & (PubVerif.codPublicacao == codPublicacao) & (PubVerif.ano == ano))
		return true;
	else
		return false;
}

void Livro::decrement() {
	if (qtdeExemplares != 0)
		qtdeExemplares--; // decrementa a quantidade de exemplares do livro
	else
		throw Erro("N�o existem mais exemplares do Livro!!"); // caso n�o possa ser decrementado gera uma exce��o
}

bool Livro::operator== (Publicacao& livroVerif) const { // sobrecaraga polim�rfica de ==
	Livro* temp = dynamic_cast<Livro*>(&livroVerif);
	if ((temp!=NULL) && (temp->getTitulo() == getTitulo()) && (temp->getEditora() == getEditora()) && (temp->getCod() == getCod()) && (temp->getAno() == getAno()) && (temp->getAutores() == getAutores()) && (temp->getQtd() == getQtd()))
		return true;
	else
		return false;
}

bool Periodico::operator== (Publicacao& PeriodVerif) const { // sobrecarga polim�rfica de ==
	Periodico* temp = dynamic_cast<Periodico*>(&PeriodVerif);
	if ((temp != NULL) && (temp->getTitulo() == getTitulo()) && (temp->getEditora() == getEditora()) && (temp->getCod() == getCod()) & (temp->getAno() == getAno()) && (temp->getMes() == getMes()) && (temp->getEdicao() == getEdicao()))
		return true;
	else
		return false;
}