# Q03
- Questão 3 
Explique como a memória em Java (C#/Python/Ruby) é gerenciada comparando com C++. 
Como fazer para alocar? E como fazer um objeto ser deletado?
Você pode garantir que a memória alocada por um objeto em Java seja liberada?

---

Em C++, o uso de *"new"* e *"delete"* geralmente levanta cheiros de código estranho. Nas versões mais modernas de C++ podemos muito bem utilizar smartpointers para evitar os temidos leaks. Note que é sempre uma boa prática rodar o valgrind ou algum outro memory sanitizer quando possível.
O garbage collector utilizado por linguagens como as citadas, basicamente cria tabelas de uso de memória dinamicamente alocada. Quando estas não são mais utilizadas o GC, que roda em background se encarrega de liberá-la.
Em java e C# podemos usar a keyword *"new"* para alocar memória, e setar para null para quando o garbage collector estiver disposto, liberá-la para nós.

Quando falamos de C, no entanto, aí é praticamente impossível de escapar de usar mallocs manualmente.

> Henrique Mochida Peixoto, 23/05/2024