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
	void cadUsuario(); // cadastra usu�rio
	void cadLivro(); // cadastra livro
	void cadPeriod(); // cadastra peri�do
	void cadEmprest(); // cadastra empr�stimo
	void addItemEmp();  // adiciona um item ao empr�stimo
	void rmvUsuario(); // remove um usu�rio
	void rmvLivro();  // remove um livro
	void rmvPeriodico();  // remove um peri�dico
	void rmvEmp();  // remove um empr�stimo
	void rmvItemEmp();  // remove um item de um empr�stimo
	void devolverAll();  // devolve todos os itens de um empr�stimo
	void devolverItemEmp();  // devolve um item de um empr�stimo
	void findPubTit(); // encontra publica��es por titulo
	void findLivroAutor();  // encontra livros por autor
	void listPub(); // imprime a lista de publica��es
	void listEmp(); // imprime a lista de empr�stimos
	void listUsuarios(); // imprime a lista de usu�rios
	void main(); // menu principal
	void addItens(Emprestimo&); // adiciona itens ao empr�stimo
	void ImprimeEmp(); // imprime um empr�stimo
	void listArquivo();
	void readArquivo();
	~Interface(); // destrutor
};

class ErroInterface : public Erro {
public:
	ErroInterface(const string& s) :Erro(s) {};
};

#endif // INTER_H
