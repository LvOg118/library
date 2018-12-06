#include "Biblioteca.h"

void Biblioteca::removeUsuario(const Usuario& User) { // remove usu�rio
	for (unsigned int i = 0; i < Emprestimos.size(); i++) {
		if (Emprestimos[i]->retornaUsuario() == User) { // caso exista um emprestimo para o usu�rio
			throw Erro("O usu�rio n�o pode ser removido, uma vez que est� com um empr�stimo em aberto."); //exce��o
		}
	}
	for (unsigned int i = 0; i < Usuarios.size(); i++) { // caso contr�rio o usu�rio � removido
		if (*(Usuarios[i]) == User) {
			Usuarios.erase(Usuarios.begin() + i);
		}
	}
}

void Biblioteca::removePub(Publicacao& Pub) {
	Livro* temp = dynamic_cast<Livro*>(&Pub);
	if (temp != NULL) {
		for (unsigned int i = 0; i < Emprestimos.size(); i++) {
			for (unsigned int j = 0; j < Emprestimos[i]->retornaLista().size(); j++) {
				if (Emprestimos[i]->retornaLista()[j]->retornaLivro() == Pub) { // caso o livro esteja em algum empr�stimo
					throw Erro("O Livro n�o pode ser removido, uma vez que est� atrelado a um empr�stimo existente.");
				}
			}
		}
	}
	for (unsigned int i = 0; i < Publicacoes.size(); i++) {
		if (*(Publicacoes[i]) == Pub) {
			Publicacoes.erase((Publicacoes.begin() + i));
		}
	}
}

void Biblioteca::removeEmprest(const Emprestimo& Emp) { // remove um empr�stimo
	for (unsigned int i = 0; i < Emprestimos.size(); i++) {
		if (*(Emprestimos[i]) == Emp) {
			Emprestimos.erase(Emprestimos.begin() + i);
		}
	}
}

vector<Publicacao*> Biblioteca::FindTitulo(string& test) {
	vector<Publicacao*> Pub;
	for (unsigned int i = 0; i < getPub().size(); i++) {
		if (Find(getPub()[i]->getTitulo(), test)) { // usa a fun��o "find" para tentar descobrir se "test" esta contido no nome
			Pub.push_back(getPub()[i]); // caso esteja, adiciona a publica��o no vetor
		}
	}
	return Pub;
}

vector<Livro*> Biblioteca::FindAutor(string& test) {
	vector<Livro*> Livros;
	for (unsigned int i = 0; i < getPub().size(); i++) {
		Livro* temp = dynamic_cast<Livro*>(getPub()[i]);
		if (temp != NULL) { // encontra todos os livros do vetor de publica��es
			if (Find(temp->getAutores(), test)) { // usa a fun��o "find" para descobrir de "test" esta contida no nome
				Livros.push_back(temp); // caso verdadeiro, adiciona o livro no vetor
			}
		}
	}
	return Livros;
}

void Biblioteca::gravar(const string &s) {
	ofstream out(s);
	setlocale(LC_ALL, "Portuguese");
	out << "-----------------------------------------------------------------------" << endl;
	out << "                              USU�RIOS                                 " << endl;
	out << "-----------------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < getUsers().size(); i++) {
		out << " -----------------------------" << endl;
		out << "| Usu�rio " << i + 1 << endl;
		out << " -----------------------------" << endl;
		out << "| Nome: " << getUsers()[i]->getname() << endl;
		out << "| cpf: " << getUsers()[i]->getcpf() << endl;
		out << "| endere�o: " << getUsers()[i]->getendereco() << endl;
		out << "| telefone: " << getUsers()[i]->gettelefone() << endl;
		out << "| Data Penaliza��o: " << getUsers()[i]->getData().dia << "/" << getUsers()[i]->getData().mes << "/" << getUsers()[i]->getData().ano << endl;
		out << " -----------------------------" << endl << endl;
	}
	out << endl << endl;
	out << "-----------------------------------------------------------------------" << endl;
	out << "                             PUBLICA��ES                               " << endl;
	out << "-----------------------------------------------------------------------" << endl;
	Livro* temp;
	Periodico* temp2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	for (unsigned int i = 0; i < getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(getPub()[i]);
		if (temp != NULL) {
			out << " -----------------------" << endl;
			out << "| Livro" << endl;
			out << " -----------------------" << endl;
			out << "| T�tulo : " << temp->getTitulo() << endl;
			out << "| Autores : " << temp->getAutores() << endl;
			out << "| Editora : " << temp->getEditora() << endl;
			out << "| Ano : " << temp->getAno() << endl;
			out << "| C�digo : " << temp->getCod() << endl;
			out << "| Quantidade : " << temp->getQtd() << endl;
			out << " -----------------------" << endl << endl;
		}
		else {
			temp2 = dynamic_cast<Periodico*>(getPub()[i]);
			out << " -----------------------" << endl;
			out << "| Peri�dico" << endl;
			out << " -----------------------" << endl;
			out << "| T�tulo : " << temp2->getTitulo() << endl;
			out << "| M�s: " << temp2->getMes() << endl;
			out << "| Editora : " << temp2->getEditora() << endl;
			out << "| Ano : " << temp2->getAno() << endl;
			out << "| C�digo : " << temp2->getCod() << endl;
			out << "| N�mero da edi��o :" << temp2->getEdicao() << endl << endl;
			out << " -----------------------" << endl << endl;
		}
	}
	out << endl << endl;
	out << "-----------------------------------------------------------------------" << endl;
	out << "                             EMPR�STIMOS                               " << endl;
	out << "-----------------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < getEmp().size(); i++) {
		out << " --------------------------------" << endl;
		out << "|Emprestimo " << getEmp()[i]->getNum() << endl;
		out << " --------------------------------" << endl;
		out << "|Data do emprestimo: " << getEmp()[i]->getDataEmp().dia << "/" << getEmp()[i]->getDataEmp().mes << "/" << getEmp()[i]->getDataEmp().ano << endl;
		out << " --------------------------------" << endl;
		out << "|Data do devolu��o: " << getEmp()[i]->getDataDev().dia << "/" << getEmp()[i]->getDataDev().mes << "/" << getEmp()[i]->getDataDev().ano << endl;
		out << " --------------------------------" << endl;
		out << "|Usu�rio:              " << endl;
		out << "|Nome: " << getEmp()[i]->retornaUsuario().getname() << endl;
		out << "|cpf: " << getEmp()[i]->retornaUsuario().getcpf() << endl;
		out << "|endereco: " << getEmp()[i]->retornaUsuario().getendereco() << endl;
		out << "|telefone: " << getEmp()[i]->retornaUsuario().gettelefone() << endl;
		out << "|Data Penaliza��o: " << getEmp()[i]->retornaUsuario().getData().dia << "/" << getEmp()[i]->retornaUsuario().getData().mes << "/" << getEmp()[i]->retornaUsuario().getData().ano << endl;
		out << " --------------------------------" << endl;
		for (unsigned int j = 0; j < getEmp()[i]->retornaLista().size(); j++) {
			out << "|Item " << j << " : Livro" << endl;
			out << "|T�tulo: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getTitulo() << endl;
			out << "|Autores: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getAutores() << endl;
			out << "|Editora: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getEditora() << endl;
			out << "|Ano: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getAno() << endl;
			out << "|C�digo: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() << endl;
			out << "|Quantidade: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getQtd() << endl;
			out << "|Data de devolu��o: " << getEmp()[i]->retornaLista()[j]->getData().dia << "/" << getEmp()[i]->retornaLista()[j]->getData().mes << "/" << getEmp()[i]->retornaLista()[j]->getData().ano << endl;
			out << " --------------------------------" << endl;
		}
		out << endl;
	}
}

void Biblioteca::ler(const string &s) {
	ifstream in (s);
	string line, user = "Usuario:", livro = "Livro:" , per = "Periodico:";
	while (getline(in, line)) {
		if (Find(line, user)) {
			string nome ="", cpf = "", endereco = "", telefone = "";
			int i = 8;
			while (line[i] != ',') {
				nome = nome + line[i];
				i++;
			}
			i++;
			while (line[i] != ',') {
				cpf = cpf + line[i];
				i++;
			}
			i++;
			while (line[i] != ',') {
				endereco = endereco + line[i];
				i++;
			}
			i++;
			while (1) {
				telefone = telefone + line[i];
				i++;
				if (i == line.size())
					break;
			}
			Usuario* u = new Usuario(nome, cpf, endereco, telefone);
			getUsers().push_back(u);
		}
		if (Find(line, livro)) {
			string codS = "", anoS = "", titulo = "", editora = "", autores = "", qtdS="";
			int cod, ano, qtd, i = 6;
			while (line[i] != ',') {
				codS = codS + line[i];
				i++;
			}
			cod = stoi(codS);
			i++;
			while (line[i] != ',') {
				anoS = anoS + line[i];
				i++;
			}
			ano = stoi(anoS);
			i++;
			while (line[i] != ',') {
				titulo = titulo + line[i];
				i++;
			}
			i++;
			while (line[i] != ',') {
				editora = editora + line[i];
				i++;
			}
			i++;
			while (line[i] != ',') {
				autores = autores + line[i];
				i++;
			}
			i++;
			while (i) {
				qtdS = qtdS + line[i];
				i++;
				if (i == line.size())
					break;
			}
			qtd = stoi(qtdS);
			Livro* l = new Livro(cod, ano, titulo, editora, autores, qtd);
			getPub().push_back(l);
		}
		if (Find(line, per)) {
			string codS = "", anoS = "", titulo = "", editora = "", mes = "", nEdicaoS = "";
			int cod, ano, nEd, i = 10;
			while (line[i] != ',') {
				codS = codS+ line[i];
				i++;
			}
			cod = stoi(codS);
			i++;
			while (line[i] != ',') {
				anoS = anoS + line[i];
				i++;
			}
			ano = stoi(anoS);
			i++;
			while (line[i] != ',') {
				titulo = titulo + line[i];
				i++;
			}
			i++;
			while (line[i] != ',') {
				editora = editora + line[i];
				i++;
			}
			i++;
			while (line[i] != ',') {
				mes = mes + line[i];
				i++;
			}
			i++;
			while (1) {
				nEdicaoS = nEdicaoS + line[i];
				i++;
				if (i == line.size())
					break;
			}
			nEd = stoi(nEdicaoS);
			Periodico* p = new Periodico(cod, ano, titulo, editora, nEd, mes);
			getPub().push_back(p);
		}
	}
}

