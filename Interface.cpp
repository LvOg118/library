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
		cout << "|Data do devolução: " << Biblio.getEmp()[i]->getDataDev().dia << "/" << Biblio.getEmp()[i]->getDataDev().mes << "/" << Biblio.getEmp()[i]->getDataDev().ano << endl;
		cout << " --------------------------------" << endl;
		cout << "|Usuário:              " << endl;
		cout << "|Nome: " << Biblio.getEmp()[i]->retornaUsuario().getname() << endl;
		cout << "|cpf: " << Biblio.getEmp()[i]->retornaUsuario().getcpf() << endl;
		cout << "|endereco: " << Biblio.getEmp()[i]->retornaUsuario().getendereco() << endl;
		cout << "|telefone: " << Biblio.getEmp()[i]->retornaUsuario().gettelefone() << endl;
		cout << "|Data Penalização: " << Biblio.getEmp()[i]->retornaUsuario().getData().dia << "/" << Biblio.getEmp()[i]->retornaUsuario().getData().mes << "/" << Biblio.getEmp()[i]->retornaUsuario().getData().ano << endl;
		cout << " --------------------------------" << endl;
		for (unsigned int j = 0; j < Biblio.getEmp()[i]->retornaLista().size(); j++) {
			cout << "|Item " << j << " : Livro" << endl;
			cout << "|Título: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getTitulo() << endl;
			cout << "|Autores: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getAutores() << endl;
			cout << "|Editora: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getEditora() << endl;
			cout << "|Ano: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getAno() << endl;
			cout << "|Código: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() << endl;
			cout << "|Quantidade: " << Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getQtd() << endl;
			cout << "|Data de devolução: " << Biblio.getEmp()[i]->retornaLista()[j]->getData().dia << "/" << Biblio.getEmp()[i]->retornaLista()[j]->getData().mes << "/" << Biblio.getEmp()[i]->retornaLista()[j]->getData().ano << endl;
			cout << " --------------------------------" << endl;
		}
		cout << endl;
	}
}

void Interface::addItens(Emprestimo& emp) { // adiciona um item a um empréstimo
	setlocale(LC_ALL, "Portuguese");
	string test;
	do {
		system("cls");
		cout << "Deseja adicionar um item ao empréstimo? Digite s caso afirmativo. ";
		cin >> test;
		if ((test == "S") || (test == "s")) { // caso não se queira mais adicionar itens
			string test2;
			int tamanho, cod;
			cout << "O item já está cadastrado? Digite s caso afirmativo. ";
			cin >> test2;
			if ((test2 == "S") || (test2 == "s")) {  // caso o item já esteja cadastrado
				system("cls");
				cout << "Lista de Livros: \n"; // imprime todos os livros para facilitar na identificação do usuário
				for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
					Livro* temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
					if (temp != NULL) { // caso seja realemnte um livro
						cout << " -----------------------" << endl;
						cout << "| Livro " << endl;
						cout << " -----------------------" << endl;
						cout << "| Título : " << temp->getTitulo() << endl;
						cout << "| Autores : " << temp->getAutores() << endl;
						cout << "| Editora : " << temp->getEditora() << endl;
						cout << "| Ano : " << temp->getAno() << endl;
						cout << "| Código : " << temp->getCod() << endl;
						cout << "| Quantidade : " << temp->getQtd() << endl;
						cout << " -----------------------" << endl << endl;
					}
				}
				cout << "Digite o código do livro que deseja adicionar ao emprestimo: ";
				cin >> cod; // usa o código para identificar o livro (uma vez que a priori cada um tem um diferente)
				system("cls");
				for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
					Livro* temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
					if ((temp != NULL) && (temp->getCod() == cod)) { // encontra o livro
						ItemEmprestimo temp2(*temp);
						Biblio.addListEmprest(emp, temp2); // adiciona o livro ao empréstimo
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
				Biblio.addListEmprest(emp ,temp2); // adiciona o livro ao empréstimo
				system("cls");
				cout << "Item adicionado ao emprestimo!" << endl;
				system("PAUSE");
				system("cls");
			}
		}
	} while ((test == "s") || (test == "S")); // emquanto o usuário quiser adicionar itens
} 

void Interface::cadUsuario() { // cadastra um usuário
	system("cls");
	string nome, cpf, endereco, fone, lixo;
	setlocale(LC_ALL, "Portuguese");
	getline(cin, lixo);
	cout << "Digite o nome do usuário: ";
	getline(cin, nome);
	cout << "Digite o cpf do usuário: ";
	getline(cin, cpf);
	cout << "Digite o endereco do usuário: ";
	getline(cin, endereco);
	cout << "Digite o telefone do usuário: ";
	getline(cin, fone);
	cout << endl;
	Usuario* temp = new Usuario(nome, cpf, endereco, fone);
	Biblio.addUsuario(*temp);
	system("cls");
	cout << "Usuário cadastrado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::cadLivro() { // cadastra um livro
	system("cls");
	int codigo, ano, qtd;
	string titulo, editora, autores, lixo;
	setlocale(LC_ALL, "Portuguese");
	getline(cin, lixo);
	cout << "Digite o título do livro: ";
	getline(cin, titulo);
	cout << "Digite o nome dos autores do livro: ";
	getline(cin, autores);
	cout << "Digite a editora do livro: ";
	getline(cin, editora);
	cout << "Digite o código do livro (númerico): ";
	cin >> codigo;
	cout << "Digite o ano do livro (númerico): ";
	cin >> ano;
	cout << "Digite a quantidade de exemplares do livro (númerico): ";
	cin >> qtd;
	cout << endl;
	Livro* temp = new Livro(codigo, ano, titulo, editora, autores, qtd);
	Biblio.addPublicacao(*temp);
	system("cls");
	cout << "Livro cadastrado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::cadPeriod() { // cadastra um periódico
	system("cls");
	int codigo, ano, num_ed;
	string titulo, editora, mes, lixo;
	setlocale(LC_ALL, "Portuguese");
	getline(cin, lixo);
	cout << "Digite o título do Periódico: ";
	getline(cin, titulo);
	cout << "Digite a editora do Periódico: ";
	getline(cin, editora);
	cout << "Digite o mês do Periódico (por extenso): ";
	getline(cin, mes);
	cout << "Digite o código do Periódico (numérico): ";
	cin >> codigo;
	cout << "Digite o número de edição do Periódico (numérico): ";
	cin >> num_ed;
	cout << "Digite o ano do Periódico (numérico): ";
	cin >> ano;
	cout << endl;
	Periodico* temp = new Periodico(codigo, ano, titulo, editora, num_ed, mes);
	Biblio.addPublicacao(*temp);
	system("cls");
	cout << "Periódico cadastrado!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::cadEmprest() { // cadastra um empréstimo
	system("cls");
	string verif;
	setlocale(LC_ALL, "Portuguese");
	cout << "O usuário já é cadastrado? Digite s caso afirmativo. ";
	cin >> verif;
	if ((verif == "s") or (verif == "S")) { // caso o usuário já esteja cadastrado
		system("cls");
		Date dev;
		unsigned int id;
		for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) { // imprime para facilitar identificação
			cout << " -----------------------------" << endl;
			cout << "| Usuário " << i + 1 << endl;
			cout << " -----------------------------" << endl;
			cout << "| Nome: " << Biblio.getUsers()[i]->getname() << endl;
			cout << "| cpf: " << Biblio.getUsers()[i]->getcpf() << endl;
			cout << "| endereco: " << Biblio.getUsers()[i]->getendereco() << endl;
			cout << "| telefone: " << Biblio.getUsers()[i]->gettelefone() << endl;
			cout << "| Data Penalização: " << Biblio.getUsers()[i]->getData().dia << "/" << Biblio.getUsers()[i]->getData().mes << "/" << Biblio.getUsers()[i]->getData().ano << endl << endl;
			cout << " -----------------------------" << endl;
		}
		cout << "Digite a identificação do usuário que deseja fazer o empréstimo: ";
		cin >> id;
		if ((id < 0) || (id > Biblio.getUsers().size()))
			throw ErroInterface("Usuário inválido!");
		system("cls");
		cout << "Digite o dia de devolução do emprestimo (numérico): ";
		cin >> dev.dia;
		cout << "Digite o mês de devolução do emprestimo (numérico): ";
		cin >> dev.mes;
		cout << "Digite o ano de devolução do emprestimo (numérico): ";
		cin >> dev.ano;
		if ((dev.dia < 0) || (dev.dia > 31) || (dev.mes > 12) || (dev.mes < 12))
			throw ErroInterface("Data inválida!");
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
		cout << "Digite o dia de devolução do emprestimo (numérico): ";
		cin >> dev.dia;
		cout << "Digite o mês de devolução do emprestimo (numérico): ";
		cin >> dev.mes;
		cout << "Digite o ano de devolução do emprestimo (numérico): ";
		cin >> dev.ano;
		if ((dev.dia < 0) || (dev.dia > 31) || (dev.mes > 12) || (dev.mes < 12))
			throw ErroInterface("Data inválida!");
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
	ImprimeEmp(); // imprime os emprestimos para facilitar a identificação
	cout << "Digite o número do emprestimo ao qual deseja adicionar um item: ";
	cin >> id; // usa-se o número do empréstimo para diferenciar, uma vez que ele é único
	system("cls");
	addItens(*Biblio.getEmp()[id - 1]); // adiciona item ao empréstimo
	cout << "Item(s) adicionado(s) ao emprestimo!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::rmvUsuario() { // remove um usuário
	system("cls");
	unsigned int id;
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Usuários: " << endl << endl; // imprime os usuários para facilitar na identificação
	for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) {
		cout << " -----------------------------" << endl;
		cout << "| Usuário " << i + 1 << endl;
		cout << " -----------------------------" << endl;
		cout << "| Nome: " << Biblio.getUsers()[i]->getname() << endl;
		cout << "| cpf: " << Biblio.getUsers()[i]->getcpf() << endl;
		cout << "| endereco: " << Biblio.getUsers()[i]->getendereco() << endl;
		cout << "| telefone: " << Biblio.getUsers()[i]->gettelefone() << endl;
		cout << "| Data Penalização: " << Biblio.getUsers()[i]->getData().dia << "/" << Biblio.getUsers()[i]->getData().mes << "/" << Biblio.getUsers()[i]->getData().ano << endl << endl;
		cout << " -----------------------------" << endl;
	}
	cout << "Digite a identificação do usuário que deseja apagar: " ;
	cin >> id; // usa-se a posição no vetor para apagar o usuário
	if ((id < 0) || (id > Biblio.getUsers().size()))
		throw ErroInterface("Usuário inválido!");
	Usuario* temp = Biblio.getUsers()[id - 1];
	Biblio.removeUsuario(*Biblio.getUsers()[id -1]);
	delete temp;
	system("cls");
	cout << "Usuário removido!" << endl;
	system("PAUSE");
	system("cls");
}

void Interface::rmvLivro() {
	int id;
	Livro* temp;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Livros: \n"; // imprime-se os livros para facilitar na identificação
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Livro " << endl;
			cout << " -----------------------" << endl;
			cout << "| Título : " << temp->getTitulo() << endl;
			cout << "| Autores : " << temp->getAutores() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| Código : " << temp->getCod() << endl;
			cout << "| Quantidade : " << temp->getQtd() << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	cout << "Digite o código do livro que deseja apagar: ";
	cin >> id; // usa-se os códigos do livro, uma vez que são únicos a priori
	unsigned int before = Biblio.getPub().size();
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
		if ((temp != NULL) && (Biblio.getPub()[i]->getCod() == id)){
			Biblio.removePub(*Biblio.getPub()[i]); // remove a publicação
			delete temp;
			system("cls");
			cout << "Livro removido!" << endl;
		}
	}
	if (before == Biblio.getPub().size())
		throw ErroInterface("Livro não encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::rmvPeriodico() {
	int id;
	Periodico* temp;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Periódicos: \n"; // imprime-se os periódicos para facilitar na identificação
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Periodico*>(Biblio.getPub()[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Periódico" << endl;
			cout << " -----------------------" << endl;
			cout << "| Título : " << temp->getTitulo() << endl;
			cout << "| Mês : " << temp->getMes() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| Código : " << temp->getCod() << endl;
			cout << "| Número da edição :" << temp->getEdicao() << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	cout << "Digite o código do Periódico que deseja apagar: ";
	cin >> id; // usa-se os códigos do periódico, uma vez que são únicos a priori
	unsigned int before = Biblio.getPub().size();
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Periodico*>(Biblio.getPub()[i]);
		if ((temp != NULL) && (Biblio.getPub()[i]->getCod() == id)) {
			Biblio.removePub(*Biblio.getPub()[i]); // remove periódico
			delete temp;
			system("cls");
			cout << "Periódico removido!" << endl;
		}
	}
	if (before == Biblio.getPub().size())
		throw ErroInterface("Periódico não encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::rmvEmp() {
	int id;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime-se os empréstimos para facilitar na identificação
	cout << "Digite o número do emprestimo que deseja apagar: ";
	cin >> id;
	unsigned int before = Biblio.getEmp().size();
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id){
			Emprestimo* temp = Biblio.getEmp()[i];
			Biblio.removeEmprest(*Biblio.getEmp()[i]); // remove empréstimo
			delete temp;
			//system("cls");
			cout << "Emprestimo removido!" << endl;
		}
	}
	if (before == Biblio.getEmp().size())
		throw ErroInterface("Emprestimo não encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::rmvItemEmp() {
	int id, id2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime-se os empréstimos para facilitar na identificação
	cout << "Digite o número do emprestimo do qual deseja remover um item: ";
	cin >> id;
	cout << "Digite o código do Livro que deseja remover: ";
	cin >> id2; // usa-se a identificação do empréstimo e o código do livro para identifica-los 
	int test = 0, test2 = 0;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id) {
			for (unsigned int j = 0; j < Biblio.getEmp()[i]->retornaLista().size(); j++) {
				if (Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() == id2) {
					Biblio.rmvListEmprest(*Biblio.getEmp()[i], *Biblio.getEmp()[i]->retornaLista()[j]); // remove item do empréstimo
					system("cls");
					cout << "Item removido do emprestimo!" << endl;
					test2 = 1;
				}
			}
			test = 1;
		}
	}
	if (test == 0)
		throw ErroInterface("Emprestimo não encontrado!");
	if (test2 == 0)
		throw ErroInterface("Item não encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::devolverAll() {
	int id;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // imprime-se os empréstimos para facilitar na identificação
	cout << "Digite o número do emprestimo do qual deseja devolver todos os itens: ";
	cin >> id;
	int test = 0;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id) {
			Biblio.devolveAll(*Biblio.getEmp()[i]); // devolve-se todos itens do empréstimo
			system("cls");
			cout << "Itens devolvidos!" << endl;
			test = 1;
		}
	}
	if (test == 0)
		throw ErroInterface("Emprestimo não encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::devolverItemEmp() {
	int id, id2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp();
	cout << "Digite o número do emprestimo do qual deseja devolver um item: ";
	cin >> id;
	cout << "Digite o código do Livro que deseja remover: ";
	cin >> id2;  // usa-se a identificação do empréstimo e o código do livro para identifica-los
	int test = 0, test2 = 0;
	for (unsigned int i = 0; i < Biblio.getEmp().size(); i++) {
		if (Biblio.getEmp()[i]->getNum() == id) {
			for (unsigned int j = 0; j < Biblio.getEmp()[i]->retornaLista().size(); j++) {
				if (Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro().getCod() == id2) {
					Biblio.devolveLivro(*Biblio.getEmp()[i], Biblio.getEmp()[i]->retornaLista()[j]->retornaLivro());
					system("cls"); // remove-se o item específico do empréstimo
					cout << "Item devolvido!" << endl;
					test2 = 1;
				}
			}
			test = 1;
		}
	}
	if (test == 0)
		throw ErroInterface("Emprestimo não encontrado!");
	if (test2 == 0)
		throw ErroInterface("Item não encontrado!");
	system("PAUSE");
	system("cls");
}

void Interface::findPubTit() {
	system("cls");
	string verif;
	setlocale(LC_ALL, "Portuguese");
	cout << "Digite parte do título da publicação: ";
	cin >> verif;
	vector <Publicacao*> Pub;
	Pub = Biblio.FindTitulo(verif); // recebe apenas as publicações que possuem no nome
	if (Pub.size() == 0)
		throw ErroInterface("Nenhuma Publicação encontrada!");
	for (unsigned int i = 0; i < Pub.size(); i++) {// varre todo vetor imprimindo livros e periódicos
		Livro* temp = dynamic_cast<Livro*>(Pub[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Livro" << endl;
			cout << " -----------------------" << endl;
			cout << "| Título : " << temp->getTitulo() << endl;
			cout << "| Autores : " << temp->getAutores() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| Código : " << temp->getCod() << endl;
			cout << "| Quantidade : " << temp->getQtd() << endl;
			cout << " -----------------------" << endl << endl;
		}
		else {
			Periodico* temp2 = dynamic_cast<Periodico*>(Pub[i]);
			cout << " -----------------------" << endl;
			cout << "| Periódico" << endl;
			cout << " -----------------------" << endl;
			cout << "| Título : " << temp2->getTitulo() << endl;
			cout << "| Mês: " << temp2->getMes() << endl;
			cout << "| Editora : " << temp2->getEditora() << endl;
			cout << "| Ano : " << temp2->getAno() << endl;
			cout << "| Código : " << temp2->getCod() << endl;
			cout << "| Número da edição :" << temp2->getEdicao() << endl << endl;
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
		cout << "| Título : " << Livros[i]->getTitulo() << endl;
		cout << "| Autores : " << Livros[i]->getAutores() << endl;
		cout << "| Editora : " << Livros[i]->getEditora() << endl;
		cout << "| Ano : " << Livros[i]->getAno() << endl;
		cout << "| Código : " << Livros[i]->getCod() << endl;
		cout << "| Quantidade : " << Livros[i]->getQtd() << endl;
		cout << " -----------------------" << endl << endl;
	}
	system("PAUSE");
	system("cls");
}

void Interface::listPub() { // imprime todas as publicações
	Livro* temp;
	Periodico* temp2;
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Publicações:" << endl << endl;
	for (unsigned int i = 0; i < Biblio.getPub().size(); i++) {
		temp = dynamic_cast<Livro*>(Biblio.getPub()[i]);
		if (temp != NULL) {
			cout << " -----------------------" << endl;
			cout << "| Livro" << endl;
			cout << " -----------------------" << endl;
			cout << "| Título : " << temp->getTitulo() << endl;
			cout << "| Autores : " << temp->getAutores() << endl;
			cout << "| Editora : " << temp->getEditora() << endl;
			cout << "| Ano : " << temp->getAno() << endl;
			cout << "| Código : " << temp->getCod() << endl;
			cout << "| Quantidade : " << temp->getQtd() << endl;
			cout << " -----------------------" << endl << endl;
		}
		else {
			temp2 = dynamic_cast<Periodico*>(Biblio.getPub()[i]);
			cout << " -----------------------" << endl;
			cout << "| Periódico" << endl;
			cout << " -----------------------" << endl;
			cout << "| Título : " << temp2->getTitulo() << endl;
			cout << "| Mês: " << temp2->getMes() << endl;
			cout << "| Editora : " << temp2->getEditora() << endl;
			cout << "| Ano : " << temp2->getAno() << endl;
			cout << "| Código : " << temp2->getCod() << endl;
			cout << "| Número da edição :" << temp2->getEdicao() << endl << endl;
			cout << " -----------------------" << endl << endl;
		}
	}
	system("PAUSE");
	system("cls");
}

void Interface::listEmp(){
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	ImprimeEmp(); // lista os empréstimos
	cout << endl;
	system("PAUSE");
	system("cls");
}

void Interface::listUsuarios() { // lista de usuários (opicional)
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	cout << "Lista de Usuários: " << endl << endl;
	for (unsigned int i = 0; i < Biblio.getUsers().size(); i++) {
		cout << " -----------------------------" << endl;
		cout << "| Usuário " << i + 1 << endl;
		cout << " -----------------------------" << endl;
		cout << "| Nome: " << Biblio.getUsers()[i]->getname() << endl;
		cout << "| cpf: " << Biblio.getUsers()[i]->getcpf() << endl;
		cout << "| endereco: " << Biblio.getUsers()[i]->getendereco() << endl;
		cout << "| telefone: " << Biblio.getUsers()[i]->gettelefone() << endl;
		cout << "| Data Penalização: " << Biblio.getUsers()[i]->getData().dia << "/" << Biblio.getUsers()[i]->getData().mes << "/" << Biblio.getUsers()[i]->getData().ano << endl << endl;
		cout << " -----------------------------" << endl;
	}
	system("PAUSE");
	system("cls");
}

void Interface::listArquivo() {
	string s;
	system("cls");
	cout << "Digite o nome do arquivo (com a extensão): ";
	cin >> s;
	Biblio.gravar(s);
	system("cls");
	cout << "Dados escritos em " << s << " !!"  << endl;
	system("PAUSE");
}

void Interface::readArquivo() {
	string s;
	system("cls");
	cout << "Digite o nome do arquivo que deseja ler (com a extensão): ";
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
		cout << "| * Digite o número da ação desejada:                     |" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "| - Cadastrar usuário (1)                                 |" << endl;
		cout << "| - Cadastrar livro (2)                                   |" << endl;
		cout << "| - Cadastrar periódico (3)                               |" << endl;
		cout << "| - Criar novo empréstimo(4)                              |" << endl;
		cout << "| - Inserir item a um empréstimo(5)                       |" << endl;
		cout << "| - Remover usuário (6)                                   |" << endl;
		cout << "| - Remover livro (7)                                     |" << endl;
		cout << "| - Remover periódico (8)                                 |" << endl;
		cout << "| - Remover emprestimo (9)                                |" << endl;
		cout << "| - Remover item de um emprestimo (10)                    |" << endl;
		cout << "| - Devolver todos os itens de um emprestimo (11)         |" << endl;
		cout << "| - Devolver um item de um emprestimo (12)                |" << endl;
		cout << "| - Pesquisar publicação por título (13)                  |" << endl;
		cout << "| - Pesquisar livro por autor (14)                        |" << endl;
		cout << "| - Lista de publicações (15)                             |" << endl;
		cout << "| - Lista de emprestimos (16)                             |" << endl;
		cout << "| - Lista de usuários (17)                                |" << endl;
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
