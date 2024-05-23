# Q06
- Questão 6
Para o desenvolvimento web, um descreva o framework MVC e a função dos seus 3 principais componentes ( Model - View - Controller ), das rotas, e como um request é processado por estes.
---
Design de arquitetura bastante utilizado para interface de usuários, de certa forma parecido com um *chain of responsability*, porém cíclico. Segmenta bastante e de forma bem definida o que cada módulo do serviço faz.

- Model
	- responsável pela manipulação de dado e logica de negócio
	- recebe de controller para iniciar suas tarefas
- View
	- basicamente o frontend
	- consome do model para ser atualizado
- Controller
	- recebe e processa os inputs de usuário
	- repassa os eventos processados para que o model realize as tarefas geradas.


> Henrique Mochida Peixoto, 23/05/2024