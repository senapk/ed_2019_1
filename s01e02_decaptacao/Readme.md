## Decaptação V2


- N participantes se reúnem numa lista circular.
- A princesa escolhe se a fase, ou seja, se o número 1 será positivo ou negativo. Todos os outros vão alternar de sinal a partir daí.
- A princesa escolhe o número E que começa o jogo. 
- Se E for negativo ele mata o elemento à sua esquerda. A espada então anda E elementos à sua esquerda.
- Se E for positivo, ele mata o elemento à sua direita. A espada então anda E elementos à sua direita.

Entrada
    - N, E, FASE sendo N o número de participantes e E o escolhido para iniciar o jogo e FASE indicando se o elemento 1 será positivo ou negativo.
Saída
    - O estado do vetor, etapa a etapa, indicando quem está com a espada. Se for um número positivo, coloque a espada à sua direita usando o sinal de >. Se for negativo, coloque a espada à sua esquerda utilizando o sinal de <.
```
>>>>>>>> 01
2 1 1
========
[1> -2]
[1>]
<<<<<<<<

>>>>>>>> 01
2 2 1
========
[1 <-2]
[<-2]
<<<<<<<<

>>>>>>>> 01
4 1 1
========
[1> -2 3 -4]
[1 3> -4]
[1> 3]
[1>]
<<<<<<<<

>>>>>>>> 01
4 2 1
========
[1 <-2 3 -4]
[-2 3> -4]
[<-2 3]
[<-2]
<<<<<<<<

>>>>>>>> 01
4 3 1
========
[1 -2 3> -4]
[1 -2 3>]
[<-2 3]
[<-2]
<<<<<<<<

>>>>>>>> 01
4 4 1
========
[1 -2 3 <-4]
[1 <-2 -4]
[<-2 -4]
[<-2]
<<<<<<<<

>>>>>>>> 01
3 1 -1
========
[<-1 2 -3]
[-1 2>]
[2>]
<<<<<<<<

>>>>>>>> 02
3 2 1
========
[1 <-2 3]
[<-2 3]
[<-2]
<<<<<<<<

>>>>>>>> 03
3 3 -1
========
[-1 2 <-3]
[<-1 -3]
[<-1]
<<<<<<<<

>>>>>>>> 04
6 3 1
========
[1 -2 3> -4 5 -6]
[1> -2 3 5 -6]
[1 3> 5 -6]
[1 3> -6]
[1> 3]
[1>]
<<<<<<<<

>>>>>>>> 05
9 9 -1
========
[-1 2 -3 4 -5 6 -7 8 <-9]
[-1 2 -3 4 -5 6 <-7 -9]
[-1 2 -3 4 -5 <-7 -9]
[-1 2 -3 4> -7 -9]
[-1 2 <-3 4 -9]
[-1 -3 4> -9]
[<-1 -3 4]
[-1 <-3]
[<-3]
<<<<<<<<


```