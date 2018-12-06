#ifndef BIBLIO_H
#define BIBLIO_H

#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include<time.h>
#include<clocale>

using namespace std;

struct { /// revised
	int dia, mes, ano;
}typedef Date;

void DataAtual(Date&); /// revised

bool Find(string, string&); /// revised

class Erro { // OK
private:	
	string tipo;
public:
	Erro(const string& s) :tipo(s) {};
	virtual string getTipo() { return tipo; };
	virtual ~Erro() {};
};

class Usuario { /// revised
private:
	string nome, cpf, endereco, telefone;
	Date dataPenalizacao;
public:
	Usuario(const string& nom, const string& c, const string& end, const string& telef) : nome(nom), cpf(c), endereco(end), telefone(telef) { 
		DataAtual(dataPenalizacao);
	}; // Construtor
	bool operator== (const Usuario&) const; // sobrecarga de ==
	string getname() const { return nome; }; // retorna o nome
	string getcpf() const { return cpf; }; // retorna o cpf
	string getendereco() const { return endereco; }; // retorna o endereço
	string gettelefone() const { return telefone; }; // retorna o telefone
	Date getData() const { return dataPenalizacao; }; // retorna a daat de penalização
	void setData(const Date& D) {dataPenalizacao = D; }; // altera a data de penalização
};

class Publicacao { /// revised
private:
	int codPublicacao, ano;
	string titulo, editora;
public:
	Publicacao(int cod, int a, const string& tit, const string& edit) : codPublicacao(cod), ano(a), titulo(tit), editora(edit) {}; // construtor
	virtual bool operator== (Publicacao&) const; // sobrecarga do operador ==
	virtual string getTitulo() const { return titulo; }; // retorna titulo (virtual devido ao dynamic cast)
	virtual string getEditora() const { return editora; }; // retorna editora (virtual devido ao dynamic cast)
	virtual int getCod() const { return codPublicacao; }; // retorna codigo (virtual devido ao dynamic cast)
	virtual int getAno() const { return ano; }; // retorna ano (virtual devido ao dynamic cast)
	virtual ~Publicacao() {}; // destrutor virtual
};

class Livro : public Publicacao { /// revised
private:
	string autores;
	int qtdeExemplares;
public:
	Livro(int cod1, int a1, const string& tit1, const string& edit1, const string &aut, int qtde = 0) : Publicacao(cod1, a1, tit1, edit1), autores(aut), qtdeExemplares(qtde) {}; //construtor
	void increment() { qtdeExemplares++; }; // incermeta a quantidade
	void decrement(); // decrementa a quantidade
	bool operator== (Publicacao&) const; // sobrecarga do operador==, polimórfica
	string getAutores() const { return autores; }; // retorna autores
	int getQtd() const { return qtdeExemplares; }; // retorna Qtd
};

class Periodico : public Publicacao { /// revised
private:
	int numEdicao;
	string mes;
public:
	Periodico(int cod1, int a1, const string& tit1, const string& edit1, int num, const string& m) : Publicacao(cod1, a1, tit1, edit1), numEdicao(num), mes(m) {}; // Construtor
	bool operator== (Publicacao&) const; // sobrecarga de ==, polimórfica
	string getMes() const { return mes; }; //retorna mes
	int getEdicao() const { return numEdicao; }; // retorna num
};

class ItemEmprestimo { ///revised
private:
	Date dataDevolucao;
	Livro* livro; // aponta para um livro
public:
	ItemEmprestimo(Livro& l){ 
		dataDevolucao.dia = 0; 
		dataDevolucao.mes = 0; 
		dataDevolucao.ano = 0; 
		livro = &l;
	}; // construtor
	Livro& retornaLivro() const { return *livro; }; // retorna livro
	Date& getData() { return dataDevolucao; }; // retorna data de devolução
	void setData(Date& dat) { dataDevolucao = dat; }; // altera data de devolução
};

class Emprestimo { ///revised
private:
	int numero;
	Date dataEmprestimo, dataPrevDevolucao;
	Usuario* user; // ponteiro para um usuário
	vector<ItemEmprestimo*> lista; // lista de ponteiros de Itens
	static int proximoNumero;
public:
	Emprestimo(const Date&, Usuario&); // construtor do Emprestimo
	void addLivro(Livro&); // adiciona um livro ao emprestimo 
	void rmvLivro(Livro&); // remove um livro do emprestimo
	void devolveLivro(Livro&); // devolve um livro do emprestimo
	void devolveAll(); // devolve todos os livros do emprestimo
	Usuario& retornaUsuario() const { return *user; }; // retorna o usuário
	int getNum() const { return numero; }; // retorna o numero do emprestimo
	vector<ItemEmprestimo*>& retornaLista() { return (lista); }; // retorna a lista de ponteiros para itens
	bool operator== (const Emprestimo&) const; // sobrecarga do operador ==
	Date getDataEmp() const { return dataEmprestimo; }; //retorna data que o emprestimo foi feito
	Date getDataDev() const { return dataPrevDevolucao; }; // retorna a data em que deve ser devolvido os itens
	~Emprestimo();
};

class Biblioteca { /// revised
private:	
	vector<Usuario*> Usuarios; // vetor que aponta para usuários
	vector<Publicacao*> Publicacoes; // vetor que aponta para publicações
	vector<Emprestimo*> Emprestimos; // vetor que aponta para emprestimos
public:
	Biblioteca() { Usuarios.clear();  Publicacoes.clear(); Emprestimos.clear(); }; // Construtor 
	void addUsuario(Usuario& User) { Usuarios.push_back(&User); }; // adiciona um usuário
	void addPublicacao (Publicacao& Pub) { Publicacoes.push_back(&Pub); }; // adiciona uma pub
	void addEmprestimo(Emprestimo& Emp) { Emprestimos.push_back(&Emp); }; // adiciona um emprestimo
	void addListEmprest(Emprestimo& Emp, ItemEmprestimo& Item) { Emp.addLivro(Item.retornaLivro()); } //adiciona um item a um emprestimo
	void removeUsuario(const Usuario&); //remove um usuário
	void removePub(Publicacao&); // remove uma publicação
	void removeEmprest(const Emprestimo&); // remove um emprestimo
	void rmvListEmprest(Emprestimo& Emp, ItemEmprestimo& Item) { Emp.rmvLivro(Item.retornaLivro()); }; // remove um item de um empréstimo
	void devolveLivro(Emprestimo& Emp, Livro& L) { Emp.devolveLivro(L); }; // devolve um livro de um emprestimo
	void devolveAll(Emprestimo& Emp) { Emp.devolveAll(); }; // devolve todos os livros de um emprestimo
	vector<Publicacao*> FindTitulo(string&); // Encontra publicações que contenha uma string específica no título
	vector<Livro*> FindAutor(string &); // Encontra Livros que contenha uma string específica no nome dos autores
	vector<Usuario*>& getUsers() { return Usuarios; } // retorna o vetor de ponteiros de usuários
	vector<Publicacao*>& getPub() { return Publicacoes; } // retorna o vetor de ponteiros de Publicações
	vector<Emprestimo*>& getEmp() { return Emprestimos; } // retorna o vetor de ponteiros de Emprestimos
	void gravar(const string &s);
	void ler(const string &s);
};

#endif // BIBLIO_H
