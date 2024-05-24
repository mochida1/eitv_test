# Q02
- Questão 2
Desenvolva um conjunto de classes que representam pelo menos 3 tipos de pássaros (pato, bem-te-vi, pombo, ...). 

### Cada pássaro deve:
	- emitir um som diferente (o som é no sentido figurado! Imprimir "QUACK", por exemplo);
	- possuir hábitos alimentares diferentes;
	- possuir ou não a habilidade de voar.

### Faça com que cada pássaro existente execute as seguintes ações:
	- alimentar-se;
	- emitir som;
	- voar (se aplicável).

### Aplique os conceitos de:
	- Herança;
	- Polimorfismo;
	- Encapsulamento.

---

### Overview

Criação de classes com herança simples. Devido a simplicidade proposta, alguns conceitos pedidos, são explorados muito superficialmente: por exemplo, o polimorfismo e encapsulamente quase não são utilizados.O primeiro ocorre apenas em penguim quando utilizamos seu próprio método fly(). O segundo acontece somente por conta que utilizamos data criada (mas não inicializada) na classe base Birds e por que naturalmente declararamos variáveis membros não acessíveis por fora da própria classe.