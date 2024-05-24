# Q01
- Questão 1

Uma Fila de prioridades é uma fila de ítens na qual cada item possui obrigatoriamente um valor de prioridade.

Obviamente, cada item pode possuir outros campos que descrevem tal ítem (um identificador, por exemplo).

A lista deve manter seus itens ordenados por prioridade (ordem crescente).

Dentre ítens de mesma prioridade, a ordem de inserção deve ser mantida.
Exemplo conceitual:
1 - Inserir Item1 com prioridade 3;
2 - Inserir Item2 com prioridade 4;
3 - Inserir Item3 com prioridade 2;

Estado parcial da fila: Item3 (P=2), Item1 (P=3), Item2 (P=4)

4 - Inserir Item4 com prioridade 3;
5 - Inserir Item5 com prioridade 2;

Estado parcial da fila: Item3 (P=2), Item5 (P=2), Item1 (P=3), Item4 (P=3), Item2 (P=4)

6 - Remover Item1 da fila;
7 - Remover da fila item com prioridade 2;

Estado parcial da fila: Item5 (P=2), Item4 (P=3), Item2 (P=4)

8 - Inserir Item6 com prioridade 4;
9 - Inserir Item7 com prioridade 1;

Estado final da fila: Item7 (P=1), Item5 (P=2), Item4 (P=3), Item2 (P=4), Item6 (P=4)

Escreva um programa em qualquer linguagem ou pseudo código que implemente uma fila de prioridades.

As prioridades devem ser números inteiros positivos de 1 a 20.

O programa deve aceitar comandos do tipo:

**Comando1: A \<identificador\> \<prioridade\>**
Insere um item na fila, com identificador \<identificador\> e prioridade \<prioridade\>.
Exibe uma mensagem informando o item inserido na lista.

**Comando2: R \<identificador\>**
Remove da fila o item com identificador \<identificador\>.
Se o item não existir, exiba uma mensagem de notificação e continue o programa.
Caso exista, exiba uma mensagem informando o item removido.

**Comando3: X \<prioridade\>**
Remove da fila um item com prioridade \<prioridade\>.
Se não existir itens com tal prioridade, exiba uma mensagem de notificação e continue o programa.
Caso exista, exiba uma mensagem informando o item removido.

**Comando4: P**
Exibe o estado atual da lista, com o identificador e a prioridade de cada item (veja exemplo acima).

**Comando4: Q**
Exibe o estado final da lista, com o identificador e a prioridade de cada item (veja exemplo acima).
Finaliza o programa.
Os comandos devem ser lidos diretamente da entrada padrão e executados em seguida, um após o outro.

A leitura dos comandos pode ser simplificada. É permitido o uso de pseudo código como:

LER codigo_do_comando; // Ler o código do comando.
LER identificador; // Ler o identificador de um item.
LER prioridade; // Ler a prioridade de um item.

Exemplo de execução:
Entrada: A 1 3
Saida:   Item 1 inserido.
Entrada: A 2 4
Saida:   Item 2 inserido.
Entrada: A 3 2
Saida:   Item 3 inserido.
Entrada: A 4 3
Saida:   Item 4 inserido.
Entrada: A 5 2
Saida:   Item 5 inserido.
Entrada: R 1
Saida:   Item 1 removido.
Entrada: X 2
Saida:   Item 3 removido.
Entrada: P
Saida:   5(P=2), 4(P=3), 2(P=4)
Entrada: A 6 4
Saida:   Item 6 inserido.
Entrada: A 7 1
Saida:   Item 7 inserido.
Entrada: Q
Saida:   7(P=1), 5(P=2), 4(P=3), 2(P=4), 6(P=4)
