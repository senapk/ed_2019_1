- Leia a string que representa a árvore serializada e mostre a árvore.
- Para apresentar a árvore utilize a sequência em pré-ordem.
- Utilize um . para cada nível do nó.

Você pode entender a lógica de serialização no seguinte [link](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/).

```
>>>>>>>> um
4 # # 
========
4
<<<<<<<<

>>>>>>>> dois
1 # 0 # # 
========
1
.#
.0
<<<<<<<<

>>>>>>>> tres
4 # 8 2 # # # 
========
4
.#
.8
..2
..#
<<<<<<<<

>>>>>>>> quatro
0 9 4 # # # 5 # # 
========
0
.9
..4
..#
.5
<<<<<<<<

>>>>>>>> cinco
0 4 # # 2 0 # # 3 # # 
========
0
.4
.2
..0
..3
<<<<<<<<

>>>>>>>> seis
2 0 0 # # # 3 # 7 # 7 # # 
========
2
.0
..0
..#
.3
..#
..7
...#
...7
<<<<<<<<

>>>>>>>> dez
3 4 3 # # 4 # 0 # # 5 0 # # 9 # 3 2 # # # 
========
3
.4
..3
..4
...#
...0
.5
..0
..9
...#
...3
....2
....#
<<<<<<<<

```