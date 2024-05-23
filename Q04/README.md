# Q04
- Questão 4 
Em Sistemas Operacionais, um grupo de mecanismos que permite aos processos transferir informação entre si é chamado de IPC (Inter-Process Communication). 
Cite um tipo de IPC e explique-o sucintamente.

---

Quando falamos em Linux, os IPCs são mais transparentes em seu uso, uma vez que são gerenciados pelo kernel e como a maioria dos kernels de Linux são de código aberto (e documentado), fica mais fácil de se compreender como eles funcionam. Existem alguns tipos bastante úteis, como **signals**, **shared memory**, **message queue**, **pipes** e **sockets**. Destes, provavelmente o menos utilizado é o message queue, que usa um arquivo como chave, e cuja mensageria é bastante simples de utilizar. Mas se o arquivo é deletado, a mensageria é comprometida. Então geralmente é tido como uma péssima opção - ainda mais quando temos IPCs como sockets, que apesar de serem um pouco mais complicados de se utilizar, funcionam para praticamente tudo e têm grande compatibilidade com outras linguagens. 

> Henrique Mochida Peixoto, 23/05/2024