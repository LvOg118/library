#include "Biblioteca.h"

bool Publicacao::operator== (Publicacao& PubVerif) const { // sobrecarga padrão de PUB
	if ((PubVerif.titulo == titulo) & (PubVerif.editora == editora) & (PubVerif.codPublicacao == codPublicacao) & (PubVerif.ano == ano))
		return true;
	else
		return false;
}

void Livro::decrement() {
	if (qtdeExemplares != 0)
		qtdeExemplares--; // decrementa a quantidade de exemplares do livro
	else
		throw Erro("Não existem mais exemplares do Livro!!"); // caso não possa ser decrementado gera uma exceção
}

bool Livro::operator== (Publicacao& livroVerif) const { // sobrecaraga polimórfica de ==
	Livro* temp = dynamic_cast<Livro*>(&livroVerif);
	if ((temp!=NULL) && (temp->getTitulo() == getTitulo()) && (temp->getEditora() == getEditora()) && (temp->getCod() == getCod()) && (temp->getAno() == getAno()) && (temp->getAutores() == getAutores()) && (temp->getQtd() == getQtd()))
		return true;
	else
		return false;
}

bool Periodico::operator== (Publicacao& PeriodVerif) const { // sobrecarga polimórfica de ==
	Periodico* temp = dynamic_cast<Periodico*>(&PeriodVerif);
	if ((temp != NULL) && (temp->getTitulo() == getTitulo()) && (temp->getEditora() == getEditora()) && (temp->getCod() == getCod()) & (temp->getAno() == getAno()) && (temp->getMes() == getMes()) && (temp->getEdicao() == getEdicao()))
		return true;
	else
		return false;
}