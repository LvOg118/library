#include "Biblioteca.h"

int Emprestimo::proximoNumero = 1; // inicializa a constante do primeiro empréstimo

Emprestimo::Emprestimo(const Date& data, Usuario& u){ // construtor
	Date Atual;
	DataAtual(Atual);
	int AtualDias = Atual.ano * 365 + Atual.mes * 30 + Atual.dia;
	int PenDias = u.getData().ano * 365 + u.getData().mes * 30 + u.getData().dia;
	if (PenDias > AtualDias) { // caso a data atual seja anterior a data que o usuário pode fazer um empréstimo, lança exceção
		throw Erro("O usuário não está apto a entrar em um emprestimo!!!"); // exceção
	}
	else { // caso contrário, construção normal
		numero = proximoNumero;
		dataPrevDevolucao = data;
		DataAtual(dataEmprestimo);
		proximoNumero++;
		user = &u;
	}
}

void Emprestimo::addLivro(Livro& l) { // adiciona um livro ao empréstimo
	l.decrement();
	ItemEmprestimo* i = new ItemEmprestimo(l); // cria item para adicionar ao empréstimo
	lista.push_back(i);
}

void Emprestimo::rmvLivro(Livro& l) {
	l.increment();
	unsigned int i = 0;
	for (; i < lista.size(); i++) { // remove um livro da lista
		if ((*lista[i]).retornaLivro() == l) {
			lista.erase(lista.begin() + i);
		}
	}
}

void Emprestimo::devolveLivro(Livro& l) {
	Date data, dataPen;
	DataAtual(data);
	for (unsigned int i = 0; i < lista.size(); i++) {
		if ((*lista[i]).retornaLivro() == l) {
			int Prevdias = dataPrevDevolucao.ano * 365 + dataPrevDevolucao.mes * 30 + dataPrevDevolucao.dia;
			int Atualdias = data.ano * 365 + data.mes * 30 + data.dia;
			l.increment(); // como o livro foi devolvido, sua quantidade é incrementada
			(*lista[i]).setData(data); // coloca a data atual na data de devolução do item
			if (Prevdias < Atualdias) { // caso a entrega esteja atrasada
				int temp = (Atualdias - Prevdias) * 3; //calcula-se a nova data que o usuário poderá pegar o livro
				dataPen.ano = int(temp/365);
				dataPen.mes = int((temp - dataPen.ano*365)/30);
				dataPen.dia = temp - dataPen.ano*365 - dataPen.mes*30 ;
				dataPen.ano = dataPen.ano + data.ano;
				dataPen.mes = dataPen.mes + data.mes;
				dataPen.dia = dataPen.dia + data.dia;
				if (dataPen.dia > 31) {
					dataPen.mes = dataPen.mes + int(dataPen.dia / 30);
					dataPen.dia = dataPen.dia - int(dataPen.dia / 30) * 30;
				}
				if (dataPen.mes > 12) {
					dataPen.ano = dataPen.ano + int(dataPen.mes / 12);
					dataPen.mes = dataPen.mes - int(dataPen.mes / 12) * 12;
				}
				user->setData(dataPen); // data de penalização atualizada
			}
		}
	}
}

void Emprestimo::devolveAll() {
	Date data, dataPen;
	DataAtual(data);
	for (unsigned int i = 0; i < lista.size(); i++) {
		(*lista[i]).retornaLivro().increment(); // aumenta a quantidade de todos os livros dos itens
		(*lista[i]).setData(data); // coloca a data atual na data de devolução de todos os itens
	}
	int Prevdias = dataPrevDevolucao.ano * 365 + dataPrevDevolucao.mes * 30 + dataPrevDevolucao.dia;
	int Atualdias = data.ano * 365 + data.mes * 30 + data.dia;
	if (Prevdias < Atualdias) { // caso a devolução esteja atrasada
		int temp = (Atualdias - Prevdias) * 3; //calcula-se a nova data que o usuário poderá pegar o livro
		dataPen.ano = int(temp / 365);
		dataPen.mes = int((temp - dataPen.ano * 365) / 30);
		dataPen.dia = temp - dataPen.ano * 365 - dataPen.mes * 30;
		dataPen.ano = dataPen.ano + data.ano;
		dataPen.mes = dataPen.mes + data.mes;
		dataPen.dia = dataPen.dia + data.dia;
		if (dataPen.dia > 31) {
			dataPen.mes = dataPen.mes + int(dataPen.dia / 30);
			dataPen.dia = dataPen.dia - int(dataPen.dia / 30) * 30;
		}
		if (dataPen.mes > 12) {
			dataPen.ano = dataPen.ano + int(dataPen.mes / 12);
			dataPen.mes = dataPen.mes - int(dataPen.mes / 12) * 12;
		}
		user->setData(dataPen); // data de penalização atualizada
	}
}

bool Emprestimo::operator== (const Emprestimo& empVerif) const { 
	if ((empVerif.numero == numero)) // como cada empréstimo tem um número único, verifica-se apenas o número
		return true;
	else
		return false;
}

Emprestimo::~Emprestimo() { // desaloca os objetos dinamicamente criados
	for (unsigned int i = 0; i < retornaLista().size(); i++) {
		delete retornaLista()[i];
	}
	retornaLista().clear();
}