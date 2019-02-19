
- N participantes se reúnem numa lista circular.
- A princesa escolhe se a fase, ou seja, se o número 1 será positivo ou negativo. Todos os outros vão alternar de sinal a partir daí.
- A princesa escolhe o número E que começa o jogo. 
- Se E for negativo ele mata o elemento à sua esquerda. A espada então anda E elementos à sua esquerda.
- Se E for positivo, ele mata o elemento à sua direita. A espada então anda E elementos à sua direita.

Entrada
    - N, E, FASE sendo N o número de participantes e E o escolhido para iniciar o jogo e FASE indicando se o elemento 1 será positivo ou negativo.
Saída
    - O estado do vetor, etapa a etapa, indicando quem está com a espada.
```
>>>>>>>>
3 1 -1
========
[-1E 2]
[1 2E]
[2E]
<<<<<<<<

>>>>>>>>
3 2 1
========
[1 -2E 3]
[-2E 3]
[-2E]
<<<<<<<<

>>>>>>>>
3 3 -1
========
[-1 2 -3E]
[-1E -3]
[-1E]
<<<<<<<<

>>>>>>>>
6 3 1
========
[1 -2 3E -4 5 -6]
[1E -2 3 5 -6]
[1 3E 5 -6]
[1 3E -6]
[1E 3]
[1E]
<<<<<<<<

>>>>>>>>
9 9 -1
========
[-1 2  -3 4  -5 6 -7 8 -9E]
[-1 2  -3 4  -5 6 -7E -9]
[-1 2  -3 4 -7E -9]
[-1 2E -3 -7 -9]
[-1 2 -7 -9E]
[-1 2 -9E]
[-1E -9]
[-1E]
<<<<<<<<
```