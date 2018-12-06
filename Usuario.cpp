#include "Biblioteca.h"

bool Usuario::operator== (const Usuario& UserVerif) const { // sobrecarga do operador
	if ((UserVerif.cpf == cpf) && (UserVerif.nome == nome) && (UserVerif.telefone == telefone) && (UserVerif.endereco == endereco))
		return true;
	else
		return false;
}