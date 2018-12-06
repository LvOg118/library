#include "Biblioteca.h"
#include "Interface.h"

void Interface::ImprimeEmp() { // imprime os emprestimos da lista
	cout << "Lista de Emprestimos:" << endl << endl;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		cout << " --------------------------------" << endl;
		cout << "|Emprestimo " << Biblio.getEmp()[i]->getNum() << endl;
		cout << " --------------------------------" << endl;
		cout << "|Data do emprestimo: " << Biblio.getEmp()[i]->getDataEmp().dia << "/" << Biblio.getEmp()[i]->getDataEmp().mes << "/" << Biblio.getEmp()[i]->getDataEmp().ano << endl;
		cout << " --------------------------------" << endl;
		cout << "|Data do devolu��o: " << Biblio.getEmp()[i]->getDataDev().dia << "/" << Biblio.getEmp()[i]->getDataDev().mes << "/" << Biblio.getEmp()[i]->getDataDev().ano << endl;
		cout << " --------------------------------" << endl;
		cout << "|Usu�rio:              " << endl;
		cout << "|Nome: " << Biblio.getEmp()[i]->retornaUsuario().getname() << endl;
		cout << "|cpf: " << Biblio.getEmp()[i]->retornaUsuario().getcpf() << endl;
		cout << "|endereco: " << Biblio.getEmp()[i]->retornaUsuario().getendereco() << endl;
		cout << "|telefone: " << Biblio.getEmp()[i]->retornaUsuario().gettelefone() << endl;
		cout << "|Data Penaliza��o: " << Biblio.getEmp()[i]->retornaUsuario().getData().dia << "/" << Biblio.getEmp()[i]->retornaUsuario().getData().mes << "/" << Biblio.getEmp()[i]->retornaUsuario().getData().ano << endl;
		cout << " --------------------------------" << endl;
		for (unsigned int j = 0; j < Biblio.getEmp()[i]->retornaLista().size(); j++) {
			cout << "|Item " << j << " : Livro" << endl;
			cout << "|T�tulo: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getTitulo() << endl;
			cout << "|Autores: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getAutores() << endl;
			cout << "|Editora: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getEditora() << endl;
			cout << "|Ano: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getAno() << endl;
			cout << "|C�digo: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() << endl;
			cout << "|Quantidade: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getQtd() << endl;
			cout << "|Data de devolu��o: " << Biblio.getEmp()[i]->retornaLista()[j]->getData().dia << "/" << Biblio.getEmp()[i]->retornaLista()[j]->getData().mes << "/" << Biblio.getEmp()[i]->retornaLista()[j]->getData().ano << endl;
			cout << " --------------------------------" << endl;
		}
		cout << endl;
	}
}

void Interface::addItens(Emprestimo& emp) { // adiciona um item a um empr�stimo
	setlocale(LC_ALL, "Portuguese");
	string test;
	do {
		system("cls");
		cout << "Deseja adicionar um item ao empr�stimo? Digite s caso afirmativo. ";
		cin >> test;
		if ((test == "S") || (test == "s")) { // caso n�o se queira mais adicionar itens
			string test2;
			int tamanho, cod;
			cout << "O item j� est� cadastrado? Digite s caso afirmativo. ";
			cin >> test2;
			if ((test2 == "S") || (test2 == "s")) {  // caso o item j� esteja cadastrado
				system("cls");
				cout << "Lista de Livros: \n"; // imprime todos os livros para facilitar na identifica��o do usu�rio
				for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
					Livro* temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
					if (temp != NULL) { // caso seja realemnte um livro
						cout << " -----------------------" << endl;
						cout << "| Livro " << endl;
						cout << " -----------------------" << endl;
						cout << "| T�tulo : " << temp->getTitulo() << endl;
						cout << "| Autores : " << temp->getAutores() << endl;
						cout << "| Editora : " << temp->getEditora() << endl;
						cout << "| Ano : " << temp->getAno() << endl;
						cout << "| C�digo : " << temp->getCod() << endl;
						cout << "| Quantidade : " << temp->getQtd() << endl;
						cout << " -----------------------" << endl << endl;
					}
				}
				cout << "Digite o c�digo do livro que deseja adicionar ao emprestimo: ";
				cin >> cod; // usa o c�digo para identificar o livro (uma vez que a priori cada um tem um diferente)
				system("cls");
				for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
					Livro* temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
					if ((temp != NULL) && (temp->getCod() == cod)) { // encontra o livro
						ItemEmprestimo temp2(*temp);
						Biblio.addListEmprest(emp, temp2); // adiciona o livro ao empr�stimo
						system("cls");
						cout << "Item adicionado ao emprestimo!" << endl;
						system("PAUSE");
						system("cls");
					}
				}
			}
			else { // caso o livro nao esteja cadastrado
				cadLivro(); // cadastra-se o livro
				tamanho = Biblio.getPub().size();
				Livro* temp = dynamic_cast<Livro*>(Biblio.getPub()[tamanho - 1]);
				ItemEmprestimo temp2(*temp);
				Biblio.addListEmprest(emp ,temp2); // adiciona o livro ao empr�stimo
				system("cls");
				cout << "Item adicionado ao emprestimo!" << endl;
				system("PAUSE");
				system("cls");
			}
		}
	} while ((test == "s") || (test == "S")); // emquanto o usu�rio quiser adicionar itens
} 

void Interface::cadUsuario() { // cadastra um usu�rio
	system("cls");
	string nome, cpf, endereco, fone, lixo;
	setlocale(LC_ALL, "Portuguese");
	getline(cin, lixo);
	cout << "Digite o nome do usu�rio: ";
	getline(cin, nome);
	cout << "Digite o cpf do usu�rio: ";
	getline(cin, cpf);
	cout << "Digite o endereco do usu�rio: ";
	getline(cin, endereco);
	cout << "Digite o telefone do usu�rio: ";
	getline(cin, fone);
	cout << endl;
	Usuario* temp = new Usuario(nome, cpf, endereco, fone);
	Biblio.addUsuario(*temp);
	system("cls");
	cout << "Usu�rio cadastrado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::cadLivro() { // cadastra um livro
	system("cls");
	int codigo, ano, qtd;
	string titulo, editora, autores, lixo;
	setlocale(LC_ALL, "Portuguese");
	getline(cin, lixo);
	cout << "Digite o t�tulo do livro: ";
	getline(cin, titulo);
	cout << "Digite o nome dos autores do livro: ";
	getline(cin, autores);
	cout << "Digite a editora do livro: ";
	getline(cin, editora);
	cout << "Digite o c�digo do livro (n�merico): ";
	cin >> codigo;
	cout << "Digite o ano do livro (n�merico): ";
	cin >> ano;
	cout << "Digite a quantidade de exemplares do livro (n�merico): ";
	cin >> qtd;
	cout << endl;
	Livro* temp = new Livro(codigo, ano, titulo, editora, autores, qtd);
	Biblio.addPublicacao(*temp);
	system("cls");
	cout << "Livro cadastrado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::cadPeriod() { // cadastra um peri�dico
	system("cls");
	int codigo, ano, num_ed;
	string titulo, editora, mes, lixo;
	setlocale(LC_ALL, "Portuguese");
	getline(cin, lixo);
	cout << "Digite o t�tulo do Peri�dico: ";
	getline(cin, titulo);
	cout << "Digite a editora do Peri�dico: ";
	getline(cin, editora);
	cout << "Digite o m�s do Peri�dico (por extenso): ";
	getline(cin, mes);
	cout << "Digite o c�digo do Peri�dico (num�rico): ";
	cin >> codigo;
	cout << "Digite o n�mero de edi��o do Peri�dico (num�rico): ";
	cin >> num_ed;
	cout << "Digite o ano do Peri�dico (num�rico): ";
	cin >> ano;
	cout << endl;
	Periodico* temp = new Periodico(codigo, ano, titulo, editora, num_ed, mes);
	Biblio.addPublicacao(*temp);
	system("cls");
	cout << "Peri�dico cadastrado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::cadEmprest() { // cadastra um empr�stimo
	system("cls");
	string verif;
	setlocale(LC_ALL, "Portuguese");
	cout << "O usu�rio j� � cadastrado? Digite s caso afirmativo. ";
	cin >> verif;
	if ((verif == "s") or (verif == "S")) { // caso o usu�rio j� esteja cadastrado
		system("cls");
		Date dev;
		unsigned int id;
		for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) { // imprime para facilitar identifica��o
			cout << " -----------------------------" << endl;
			cout << "| Usu�rio " << i + 1 << endl;
			cout << " -----------------------------" << endl;
			cout << "| Nome: " << Biblio.getUsers()[i]->getname() << endl;
			cout << "| cpf: " << Biblio.getUsers()[i]->getcpf() << endl;
			cout << "| endereco: " << Biblio.getUsers()[i]->getendereco() << endl;
			cout << "| telefone: " << Biblio.getUsers()[i]->gettelefone() << endl;
			cout << "| Data Penaliza��o: " << Biblio.getUsers()[i]->getData().dia << "/" << Biblio.getUsers()[i]->getData().mes << "/" << Biblio.getUsers()[i]->getData().ano << endl << endl;
			cout << " -----------------------------" << endl;
		}
		cout << "Digite a identifica��o do usu�rio que deseja fazer o empr�stimo: ";
		cin >> id;
		if ((id < 0) || (id > Biblio.getUsers().size()))
			throw ErroInterface("Usu�rio inv�lido!");
		system("cls");
		cout << "Digite o dia de devolu��o do emprestimo (num�rico): ";
		cin >> dev.dia;
		cout << "Digite o m�s de devolu��o do emprestimo (num�rico): ";
		cin >> dev.mes;
		cout << "Digite o ano de devolu��o do emprestimo (num�rico): ";
		cin >> dev.ano;
		if ((dev.dia < 0) || (dev.dia > 31) || (dev.mes > 12) || (dev.mes < 12))
			throw ErroInterface("Data inv�lida!");
		Emprestimo* temp = new Emprestimo(dev, *(Biblio.getUsers()[id - 1]));
		addItens(*temp);
		Biblio.addEmprestimo(*temp);
		system("cls");
	}
	else {
		Date dev;
		int tamanho;
		system("cls");
		Interface::cadUsuario();
		cout << "Digite o dia de devolu��o do emprestimo (num�rico): ";
		cin >> dev.dia;
		cout << "Digite o m�s de devolu��o do emprestimo (num�rico): ";
		cin >> dev.mes;
		cout << "Digite o ano de devolu��o do emprestimo (num�rico): ";
		cin >> dev.ano;
		if ((dev.dia < 0) || (dev.dia > 31) || (dev.mes > 12) || (dev.mes < 12))
			throw ErroInterface("Data inv�lida!");
		tamanho = Biblio.getUsers().size();
		Emprestimo* temp = new Emprestimo(dev, *Biblio.getUsers()[tamanho - 1]);
		addItens(*temp);
		Biblio.addEmprestimo(*temp);
		system("cls");
	}
	system("cls");
	cout << "Emprestimo criado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::addItemEmp() { // adiciona um item ao emprestimo
	system("cls");
	int id;
	string id2;
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime os emprestimos para facilitar a identifica��o
	cout << "Digite o n�mero do emprestimo ao qual deseja adicionar um item: ";
	cin >> id; // usa-se o n�mero do empr�stimo para diferenciar, uma vez que ele � �nico
	system("cls");
	addItens(*Biblio.getEmp()[id - 1]); // adiciona item ao empr�stimo
	cout << "Item(s) adicionado(s) ao emprestimo!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::rmvUsuario() { // remove um usu�rio
	system("cls");
	unsigned int id;
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Usu�rios: " << endl << endl; // imprime os usu�rios para facilitar na identifica��o
	for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) {
		cout << " -----------------------------" << endl;
		cout << "| Usu�rio " << i + 1 << endl;
		cout << " -----------------------------" << endl;
		cout << "| Nome: " << Biblio.getUsers()[i]->getname() << endl;
		cout << "| cpf: " << Biblio.getUsers()[i]->getcpf() << endl;
		cout << "| endereco: " << Biblio.getUsers()[i]->getendereco() << endl;
		cout << "| telefone: " << Biblio.getUsers()[i]->gettelefone() << endl;
		cout << "| Data Penaliza��o: " << Biblio.getUsers()[i]->getData().dia << "/" << Biblio.getUsers()[i]->getData().mes << "/" << Biblio.getUsers()[i]->getData().ano << endl << endl;
		cout << " -----------------------------" << endl;
	}
	cout << "Digite a identifica��o do usu�rio que deseja apagar: " ;
	cin >> id; // usa-se a posi��o no vetor para apagar o usu�rio
	if ((id < 0) || (id > Biblio.getUsers().size()))
		throw ErroInterface("Usu�rio inv�lido!");
	Usuario* temp = Biblio.getUsers()[id - 1];
	Biblio.removeUsuario(*Biblio.getUsers()[id -1]);
	delete temp;
	system("cls");
	cout << "Usu�rio removido!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::rmvLivro() {
	int id;
	Livro* temp;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Livros: \n"; // imprime-se os livros para facilitar na identifica��o
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Livro " << endl;
			cout << " -----------------------" << endl;
			cout << "| T�tulo : " << temp->getTitulo() << endl;
			cout << "| Autores : " << temp->getAutores() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| C�digo : " << temp->getCod() << endl;
			cout << "| Quantidade : " << temp->getQtd() << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	cout << "Digite o c�digo do livro que deseja apagar: ";
	cin >> id; // usa-se os c�digos do livro, uma vez que s�o �nicos a priori
	unsigned int before = Biblio.getPub().size();
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
		if ((temp != NULL) && (Biblio.getPub()[i]->getCod() == id)){
			Biblio.removePub(*Biblio.getPub()[i]); // remove a publica��o
			delete temp;
			system("cls");
			cout << "Livro removido!" << endl;
		}
	}
	if (before == Biblio.getPub().size())
		throw ErroInterface("Livro n�o encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::rmvPeriodico() {
	int id;
	Periodico* temp;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Peri�dicos: \n"; // imprime-se os peri�dicos para facilitar na identifica��o
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Periodico*>(Biblio.getPub()[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Peri�dico" << endl;
			cout << " -----------------------" << endl;
			cout << "| T�tulo : " << temp->getTitulo() << endl;
			cout << "| M�s : " << temp->getMes() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| C�digo : " << temp->getCod() << endl;
			cout << "| N�mero da edi��o :" << temp->getEdicao() << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	cout << "Digite o c�digo do Peri�dico que deseja apagar: ";
	cin >> id; // usa-se os c�digos do peri�dico, uma vez que s�o �nicos a priori
	unsigned int before = Biblio.getPub().size();
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Periodico*>(Biblio.getPub()[i]);
		if ((temp != NULL) && (Biblio.getPub()[i]->getCod() == id)) {
			Biblio.removePub(*Biblio.getPub()[i]); // remove peri�dico
			delete temp;
			system("cls");
			cout << "Peri�dico removido!" << endl;
		}
	}
	if (before == Biblio.getPub().size())
		throw ErroInterface("Peri�dico n�o encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::rmvEmp() {
	int id;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime-se os empr�stimos para facilitar na identifica��o
	cout << "Digite o n�mero do emprestimo que deseja apagar: ";
	cin >> id;
	unsigned int before = Biblio.getEmp().size();
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id){
			Emprestimo* temp = Biblio.getEmp()[i];
			Biblio.removeEmprest(*Biblio.getEmp()[i]); // remove empr�stimo
			delete temp;
			//system("cls");
			cout << "Emprestimo removido!" << endl;
		}
	}
	if (before == Biblio.getEmp().size())
		throw ErroInterface("Emprestimo n�o encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::rmvItemEmp() {
	int id, id2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime-se os empr�stimos para facilitar na identifica��o
	cout << "Digite o n�mero do emprestimo do qual deseja remover um item: ";
	cin >> id;
	cout << "Digite o c�digo do Livro que deseja remover: ";
	cin >> id2; // usa-se a identifica��o do empr�stimo e o c�digo do livro para identifica-los 
	int test = 0, test2 = 0;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id) {
			for (unsigned int j = 0; j < Biblio.getEmp()[i]->retornaLista().size(); j++) {
				if (Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() == id2) {
					Biblio.rmvListEmprest(*Biblio.getEmp()[i], *Biblio.getEmp()[i]->retornaLista()[j]); // remove item do empr�stimo
					system("cls");
					cout << "Item removido do emprestimo!" << endl;
					test2 = 1;
				}
			}
			test = 1;
		}
	}
	if (test == 0)
		throw ErroInterface("Emprestimo n�o encontrado!");
	if (test2 == 0)
		throw ErroInterface("Item n�o encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::devolverAll() {
	int id;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime-se os empr�stimos para facilitar na identifica��o
	cout << "Digite o n�mero do emprestimo do qual deseja devolver todos os itens: ";
	cin >> id;
	int test = 0;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id) {
			Biblio.devolveAll(*Biblio.getEmp()[i]); // devolve-se todos itens do empr�stimo
			system("cls");
			cout << "Itens devolvidos!" << endl;
			test = 1;
		}
	}
	if (test == 0)
		throw ErroInterface("Emprestimo n�o encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::devolverItemEmp() {
	int id, id2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp();
	cout << "Digite o n�mero do emprestimo do qual deseja devolver um item: ";
	cin >> id;
	cout << "Digite o c�digo do Livro que deseja remover: ";
	cin >> id2;  // usa-se a identifica��o do empr�stimo e o c�digo do livro para identifica-los
	int test = 0, test2 = 0;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id) {
			for (unsigned int j = 0; j < Biblio.getEmp()[i]->retornaLista().size(); j++) {
				if (Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() == id2) {
					Biblio.devolveLivro(*Biblio.getEmp()[i], Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro());
					system("cls"); // remove-se o item espec�fico do empr�stimo
					cout << "Item devolvido!" << endl;
					test2 = 1;
				}
			}
			test = 1;
		}
	}
	if (test == 0)
		throw ErroInterface("Emprestimo n�o encontrado!");
	if (test2 == 0)
		throw ErroInterface("Item n�o encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::findPubTit() {
	system("cls");
	string verif;
	setlocale(LC_ALL, "Portuguese");
	cout << "Digite parte do t�tulo da publica��o: ";
	cin >> verif;
	vector <Publicacao*> Pub;
	Pub = Biblio.FindTitulo(verif); // recebe apenas as publica��es que possuem no nome
	if (Pub.size() == 0)
		throw ErroInterface("Nenhuma Publica��o encontrada!");
	for (unsigned int i = 0; i < Pub.size(); i++) {// varre todo vetor imprimindo livros e peri�dicos
		Livro* temp = dynamic_cast<Livro*>(Pub[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Livro" << endl;
			cout << " -----------------------" << endl;
			cout << "| T�tulo : " << temp->getTitulo() << endl;
			cout << "| Autores : " << temp->getAutores() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| C�digo : " << temp->getCod() << endl;
			cout << "| Quantidade : " << temp->getQtd() << endl;
			cout << " -----------------------" << endl << endl;
		}
		else {
			Periodico* temp2 = dynamic_cast<Periodico*>(Pub[i]);
			cout << " -----------------------" << endl;
			cout << "| Peri�dico" << endl;
			cout << " -----------------------" << endl;
			cout << "| T�tulo : " << temp2->getTitulo() << endl;
			cout << "| M�s: " << temp2->getMes() << endl;
			cout << "| Editora : " << temp2->getEditora() << endl;
			cout << "| Ano : " << temp2->getAno() << endl;
			cout << "| C�digo : " << temp2->getCod() << endl;
			cout << "| N�mero da edi��o :" << temp2->getEdicao() << endl << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	system("PAUSE");
	system("cls");
}

void Interface::findLivroAutor() {
	system("cls");
	string verif;
	setlocale(LC_ALL, "Portuguese");
	cout << "Digite parte do nome dos autores do Livro: ";
	cin >> verif;
	vector <Livro*> Livros;
	Livros = Biblio.FindAutor(verif); // recebe todos os livros que possuem a string no nome dos autores
	if (Livros.size() == 0)
		throw ErroInterface("Nenhum Livro encontrado!");
	for (unsigned int i = 0; i < Livros.size(); i++) { // imprime todos esses livros
		cout << " -----------------------" << endl;
		cout << "| Livro" << endl;
		cout << " -----------------------" << endl;
		cout << "| T�tulo : " << Livros[i]->getTitulo() << endl;
		cout << "| Autores : " << Livros[i]->getAutores() << endl;
		cout << "| Editora : " << Livros[i]->getEditora() << endl;
		cout << "| Ano : " << Livros[i]->getAno() << endl;
		cout << "| C�digo : " << Livros[i]->getCod() << endl;
		cout << "| Quantidade : " << Livros[i]->getQtd() << endl;
		cout << " -----------------------" << endl << endl;
	}
	system("PAUSE");
	system("cls");
}

void Interface::listPub() { // imprime todas as publica��es
	Livro* temp;
	Periodico* temp2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Publica��es:" << endl << endl;
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Livro" << endl;
			cout << " -----------------------" << endl;
			cout << "| T�tulo : " << temp->getTitulo() << endl;
			cout << "| Autores : " << temp->getAutores() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| C�digo : " << temp->getCod() << endl;
			cout << "| Quantidade : " << temp->getQtd() << endl;
			cout << " -----------------------" << endl << endl;
		}
		else {
			temp2 = dynamic_cast<Periodico*>(Biblio.getPub()[i]);
			cout << " -----------------------" << endl;
			cout << "| Peri�dico" << endl;
			cout << " -----------------------" << endl;
			cout << "| T�tulo : " << temp2->getTitulo() << endl;
			cout << "| M�s: " << temp2->getMes() << endl;
			cout << "| Editora : " << temp2->getEditora() << endl;
			cout << "| Ano : " << temp2->getAno() << endl;
			cout << "| C�digo : " << temp2->getCod() << endl;
			cout << "| N�mero da edi��o :" << temp2->getEdicao() << endl << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	system("PAUSE");
	system("cls");
}

void Interface::listEmp(){
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // lista os empr�stimos
	cout << endl;
	system("PAUSE");
	system("cls");
}

void Interface::listUsuarios() { // lista de usu�rios (opicional)
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Usu�rios: " << endl << endl;
	for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) {
		cout << " -----------------------------" << endl;
		cout << "| Usu�rio " << i + 1 << endl;
		cout << " -----------------------------" << endl;
		cout << "| Nome: " << Biblio.getUsers()[i]->getname() << endl;
		cout << "| cpf: " << Biblio.getUsers()[i]->getcpf() << endl;
		cout << "| endereco: " << Biblio.getUsers()[i]->getendereco() << endl;
		cout << "| telefone: " << Biblio.getUsers()[i]->gettelefone() << endl;
		cout << "| Data Penaliza��o: " << Biblio.getUsers()[i]->getData().dia << "/" << Biblio.getUsers()[i]->getData().mes << "/" << Biblio.getUsers()[i]->getData().ano << endl << endl;
		cout << " -----------------------------" << endl;
	}
	system("PAUSE");
	system("cls");
}

void Interface::listArquivo() {
	string s;
	system("cls");
	cout << "Digite o nome do arquivo (com a extens�o): ";
	cin >> s;
	Biblio.gravar(s);
	system("cls");
	cout << "Dados escritos em " << s << " !!"  << endl;
	system("PAUSE");
}

void Interface::readArquivo() {
	string s;
	system("cls");
	cout << "Digite o nome do arquivo que deseja ler (com a extens�o): ";
	cin >> s;
	Biblio.ler(s);
	system("cls");
	cout << "Dados de " << s << " lidos !!" << endl;
	system("PAUSE");
}

void Interface::main() { // menu principal
	setlocale(LC_ALL, "Portuguese");
	int entrada;
	do {
		cout << " ---------------------------------------------------------" << endl;
		cout << "|                     BIBLIOTECA                          |" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "| * Digite o n�mero da a��o desejada:                     |" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "| - Cadastrar usu�rio (1)                                 |" << endl;
		cout << "| - Cadastrar livro (2)                                   |" << endl;
		cout << "| - Cadastrar peri�dico (3)                               |" << endl;
		cout << "| - Criar novo empr�stimo(4)                              |" << endl;
		cout << "| - Inserir item a um empr�stimo(5)                       |" << endl;
		cout << "| - Remover usu�rio (6)                                   |" << endl;
		cout << "| - Remover livro (7)                                     |" << endl;
		cout << "| - Remover peri�dico (8)                                 |" << endl;
		cout << "| - Remover emprestimo (9)                                |" << endl;
		cout << "| - Remover item de um emprestimo (10)                    |" << endl;
		cout << "| - Devolver todos os itens de um emprestimo (11)         |" << endl;
		cout << "| - Devolver um item de um emprestimo (12)                |" << endl;
		cout << "| - Pesquisar publica��o por t�tulo (13)                  |" << endl;
		cout << "| - Pesquisar livro por autor (14)                        |" << endl;
		cout << "| - Lista de publica��es (15)                             |" << endl;
		cout << "| - Lista de emprestimos (16)                             |" << endl;
		cout << "| - Lista de usu�rios (17)                                |" << endl;
		cout << "| - Imprimir valores em um arquivo (18)                   |" << endl;
		cout << "| - Ler valores de um arquivo (19)                        |" << endl;
		cout << "| - Sair (20)                                             |" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cin >> entrada;
		switch (entrada)
		{
		case 1:
			cadUsuario();
			break;
		case 2:
			cadLivro();
			break;
		case 3:
			cadPeriod();
			break;
		case 4:
			try {
				cadEmprest();
				break;
			}
			catch(Erro& E){
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}

		case 5:
			try {
				addItemEmp();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 6:
			try {
				rmvUsuario();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 7:
			try {
				rmvLivro();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 8:
			try {
				rmvPeriodico();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 9:
			try {
				rmvEmp();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 10:
			try {
				rmvItemEmp();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 11:
			try {
				devolverAll();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 12:
			try {
				devolverItemEmp();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 13:
			try {
				findPubTit();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 14:
			try {
				findLivroAutor();
				break;
			}
			catch (Erro& E) {
				system("cls");
				cout << E.getTipo() << endl;
				system("PAUSE");
				system("cls");
				break;
			}
		case 15:
			listPub();
			break;
		case 16:
			listEmp();
			break;
		case 17:
			listUsuarios();
			break;
		case 18:
			listArquivo();
			break;
		case 19:
			readArquivo();
			break;
		case 20:
			break;
		default:
			system("cls");
			break;
		}
	} while (entrada != 20);
}

Interface::~Interface(){ // desloca os objetos dinamicamente criados criados
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		delete Biblio.getEmp()[i];
	}
	Biblio.getEmp().clear();
	for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) {
		delete Biblio.getUsers()[i];
	}
	Biblio.getUsers().clear();
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		delete Biblio.getPub()[i];
	}
	Biblio.getPub().clear();
}
