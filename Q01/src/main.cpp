#include "Cli.hpp"
#include "PriorityQueue.tpp"
#include <string>

void print_help(void){
	std::cout << "Comando1: A <identificador> <prioridade>\n";
	std::cout << "Insere um item na fila, com identificador <identificador> e prioridade <prioridade>.\n";
	std::cout << "Exibe uma mensagem informando o item inserido na lista.\n";
	std::cout << "\n";
	std::cout << "Comando2: R <identificador>\n";
	std::cout << "Remove da fila o item com identificador <identificador>.\n";
	std::cout << "Se o item não existir, exiba uma mensagem de notificação e continue o programa.\n";
	std::cout << "Caso exista, exiba uma mensagem informando o item removido.\n";
	std::cout << "\n";
	std::cout << "Comando3: X <prioridade>\n";
	std::cout << "Remove da fila um item com prioridade <prioridade>.\n";
	std::cout << "Se não existir itens com tal prioridade, exiba uma mensagem de notificação e continue o programa.\n";
	std::cout << "Caso exista, exiba uma mensagem informando o item removido.\n";
	std::cout << "\n";
	std::cout << "Comando4: P\n";
	std::cout << "Exibe o estado atual da lista, com o identificador e a prioridade de cada item (veja exemplo acima).\n";
	std::cout << "\n";
	std::cout << "Comando4: Q\n";
	std::cout << "Exibe o estado final da lista, com o identificador e a prioridade de cada item (veja exemplo acima).\n";
	std::cout << "Finaliza o programa.\n";
	std::cout << "Os comandos devem ser lidos diretamente da entrada padrão e executados em seguida, um após o outro." << std::endl;
}

int main(int argc, char *argv[]){
	if (argc > 1 && argv[1]){
		const std::string helpArg = "--help";
		if (helpArg.compare(argv[1]) == 0){
			print_help();
			return 0;
		}
	}
	Cli program;
	int rc = program.loopStart();
	return rc;
}