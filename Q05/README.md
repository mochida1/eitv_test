# Q05

- Questão 5 
Sobre boas práticas de desenvolvimento de software, explique UM dos itens abaixo:
  - Explique o padrão GRASP
  - Explique o padrão SOLID
  - Cite e comente dois Design Pattern (como funciona e qual problema resolve), exceto o padrão Singleton
  - Explique conceitos como: Coesão, Acoplamento, Single Responsibility e outros que julgar importante

---

Os principios SOLID são provavelmente os mais confusos, e há ainda grande debate sobre o que são e como funcionam. Mas de forma resumida:
**S** - Single responsability principle: metodos e classes tem uma única responsabilidade. Se fazem muitas coisas ao mesmo tempo, acabam tendo alto acoplamento, tornando-as demasiadamente complexas e diminuindo sua manutenabilidade.
**O** - Open-Closed principle: Se a coisa funciona, deixa ela funcionando. Podemos expandí-la por outros meios. Melhor que quebrar os testes unitários e todas as coisas das quais dependem dela.
**L** - Liskov: Classes filhas podem ser substituidas pelas de seus pais. Em C++ esse é um princípio bastante difícil de se seguir. Mas fazendo as classes filhas se comportarem direitinho, como as dos pais, já ajuda bastante.
**I** - Interface Segregation: Separar as coisas grandes em coisas pequenas. Se tem classe e interface, é pra usar. Este princípio é bastante associado ao *"S"*. O lado ruim é que cria um bocado de arquivos, e não incomumente, é possível que se haja bastante retrabalhos por coisas que se perderam em meio aos fontes.
**D** - Inversão de Dependências: de forma simples e resumida: "use abstrações sempre que possível". Um jeito fácil de saber quando este princípio não é seguido, é quando vemos metodos grande e com poucas subrotinas. Também conhecido como código macarrônico.

Vale a pena lembrar no entanto, que estes são princípios, e devem ser ponderados também. Muito comumente são beneficiais, mas existem algumas ocasiões quando é melhor não seguí-los. De forma geral, utilizando metodos pequenos e deixando o código o mais simples possível, ajuda a todos. Felizmente hoje em dia, a não ser que muito necessário, podemos consumir alguns bytes de memória a mais ao invés de reutilizar a mesma variável para 30 coisas diferentes.

> Henrique Mochida Peixoto, 23/05/2024