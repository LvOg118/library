#include "Biblioteca.h"

void Biblioteca::removeUsuario(const Usuario& User) { // remove usuário
	for (unsigned int i = 0; i < Emprestimos.size(); i++) {
		if (Emprestimos[i]->retornaUsuario() == User) { // caso exista um emprestimo para o usuário
			throw Erro("O usuário não pode ser removido, uma vez que está com um empréstimo em aberto."); //exceção
		}
	}
	for (unsigned int i = 0; i < Usuarios.size(); i++) { // caso contrário o usuário é removido
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
				if (Emprestimos[i]->retornaLista()[j]->retornaLivro() == Pub) { // caso o livro esteja em algum empréstimo
					throw Erro("O Livro não pode ser removido, uma vez que está atrelado a um empréstimo existente.");
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

void Biblioteca::removeEmprest(const Emprestimo& Emp) { // remove um empréstimo
	for (unsigned int i = 0; i < Emprestimos.size(); i++) {
		if (*(Emprestimos[i]) == Emp) {
			Emprestimos.erase(Emprestimos.begin() + i);
		}
	}
}

vector<Publicacao*> Biblioteca::FindTitulo(string& test) {
	vector<Publicacao*> Pub;
	for (unsigned int i = 0; i < getPub().size(); i++) {
		if (Find(getPub()[i]->getTitulo(), test)) { // usa a função "find" para tentar descobrir se "test" esta contido no nome
			Pub.push_back(getPub()[i]); // caso esteja, adiciona a publicação no vetor
		}
	}
	return Pub;
}

vector<Livro*> Biblioteca::FindAutor(string& test) {
	vector<Livro*> Livros;
	for (unsigned int i = 0; i < getPub().size(); i++) {
		Livro* temp = dynamic_cast<Livro*>(getPub()[i]);
		if (temp != NULL) { // encontra todos os livros do vetor de publicações
			if (Find(temp->getAutores(), test)) { // usa a função "find" para descobrir de "test" esta contida no nome
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
	out << "                              USUÁRIOS                                 " << endl;
	out << "-----------------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < getUsers().size(); i++) {
		out << " -----------------------------" << endl;
		out << "| Usuário " << i + 1 << endl;
		out << " -----------------------------" << endl;
		out << "| Nome: " << getUsers()[i]->getname() << endl;
		out << "| cpf: " << getUsers()[i]->getcpf() << endl;
		out << "| endereço: " << getUsers()[i]->getendereco() << endl;
		out << "| telefone: " << getUsers()[i]->gettelefone() << endl;
		out << "| Data Penalização: " << getUsers()[i]->getData().dia << "/" << getUsers()[i]->getData().mes << "/" << getUsers()[i]->getData().ano << endl;
		out << " -----------------------------" << endl << endl;
	}
	out << endl << endl;
	out << "-----------------------------------------------------------------------" << endl;
	out << "                             PUBLICAÇÕES                               " << endl;
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
			out << "| Título : " << temp->getTitulo() << endl;
			out << "| Autores : " << temp->getAutores() << endl;
			out << "| Editora : " << temp->getEditora() << endl;
			out << "| Ano : " << temp->getAno() << endl;
			out << "| Código : " << temp->getCod() << endl;
			out << "| Quantidade : " << temp->getQtd() << endl;
			out << " -----------------------" << endl << endl;
		}
		else {
			temp2 = dynamic_cast<Periodico*>(getPub()[i]);
			out << " -----------------------" << endl;
			out << "| Periódico" << endl;
			out << " -----------------------" << endl;
			out << "| Título : " << temp2->getTitulo() << endl;
			out << "| Mês: " << temp2->getMes() << endl;
			out << "| Editora : " << temp2->getEditora() << endl;
			out << "| Ano : " << temp2->getAno() << endl;
			out << "| Código : " << temp2->getCod() << endl;
			out << "| Número da edição :" << temp2->getEdicao() << endl << endl;
			out << " -----------------------" << endl << endl;
		}
	}
	out << endl << endl;
	out << "-----------------------------------------------------------------------" << endl;
	out << "                             EMPRÉSTIMOS                               " << endl;
	out << "-----------------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < getEmp().size(); i++) {
		out << " --------------------------------" << endl;
		out << "|Emprestimo " << getEmp()[i]->getNum() << endl;
		out << " --------------------------------" << endl;
		out << "|Data do emprestimo: " << getEmp()[i]->getDataEmp().dia << "/" << getEmp()[i]->getDataEmp().mes << "/" << getEmp()[i]->getDataEmp().ano << endl;
		out << " --------------------------------" << endl;
		out << "|Data do devolução: " << getEmp()[i]->getDataDev().dia << "/" << getEmp()[i]->getDataDev().mes << "/" << getEmp()[i]->getDataDev().ano << endl;
		out << " --------------------------------" << endl;
		out << "|Usuário:              " << endl;
		out << "|Nome: " << getEmp()[i]->retornaUsuario().getname() << endl;
		out << "|cpf: " << getEmp()[i]->retornaUsuario().getcpf() << endl;
		out << "|endereco: " << getEmp()[i]->retornaUsuario().getendereco() << endl;
		out << "|telefone: " << getEmp()[i]->retornaUsuario().gettelefone() << endl;
		out << "|Data Penalização: " << getEmp()[i]->retornaUsuario().getData().dia << "/" << getEmp()[i]->retornaUsuario().getData().mes << "/" << getEmp()[i]->retornaUsuario().getData().ano << endl;
		out << " --------------------------------" << endl;
		for (unsigned int j = 0; j < getEmp()[i]->retornaLista().size(); j++) {
			out << "|Item " << j << " : Livro" << endl;
			out << "|Título: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getTitulo() << endl;
			out << "|Autores: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getAutores() << endl;
			out << "|Editora: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getEditora() << endl;
			out << "|Ano: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getAno() << endl;
			out << "|Código: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() << endl;
			out << "|Quantidade: " << getEmp()[i]->retornaLista()[j]->retornaLivro().getQtd() << endl;
			out << "|Data de devolução: " << getEmp()[i]->retornaLista()[j]->getData().dia << "/" << getEmp()[i]->retornaLista()[j]->getData().mes << "/" << getEmp()[i]->retornaLista()[j]->getData().ano << endl;
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

