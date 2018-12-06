#ifndef	INTER_H
#define INTER_H

#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include<time.h>
#include<clocale>
#include"Biblioteca.h"
#include<stdlib.h>
#include <stdio.h>

class Interface {
private:
	Biblioteca Biblio;
public:
	void cadUsuario(); // cadastra usuário
	void cadLivro(); // cadastra livro
	void cadPeriod(); // cadastra periódo
	void cadEmprest(); // cadastra empréstimo
	void addItemEmp();  // adiciona um item ao empréstimo
	void rmvUsuario(); // remove um usuário
	void rmvLivro();  // remove um livro
	void rmvPeriodico();  // remove um periódico
	void rmvEmp();  // remove um empréstimo
	void rmvItemEmp();  // remove um item de um empréstimo
	void devolverAll();  // devolve todos os itens de um empréstimo
	void devolverItemEmp();  // devolve um item de um empréstimo
	void findPubTit(); // encontra publicações por titulo
	void findLivroAutor();  // encontra livros por autor
	void listPub(); // imprime a lista de publicações
	void listEmp(); // imprime a lista de empréstimos
	void listUsuarios(); // imprime a lista de usuários
	void main(); // menu principal
	void addItens(Emprestimo&); // adiciona itens ao empréstimo
	void ImprimeEmp(); // imprime um empréstimo
	void listArquivo();
	void readArquivo();
	~Interface(); // destrutor
};

class ErroInterface : public Erro {
public:
	ErroInterface(const string& s) :Erro(s) {};
};

#endif // INTER_H
