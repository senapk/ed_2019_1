## Construindo labirinto recursivamente

```
void create_lab_rec(mat, posicao){
    se posicao esta fora da matriz
        retorne
    se posicao nao eh parede
        retorne
    se nessa posicao existe mais de um vizinho aberto
        retorne
    
    derruba parede em posicao
    chama a recursao aleatoriamente para todos os vizinhos
}
```


## Criando um labirinto com pilha
```
void create_lab_pilha(mat){
    inicie uma pilha de pares
    fure o primeiro elemento e coloque na pilha

    enquanto a pilha nao estiver fazia faca {
        'topo' eh o par do topo da pilha
        pegue os vizinhos de 'topo' que podem ser furados
            voce soh pode pegar os vizinhos que tem no máximo um lado aberto
        se existe pelo menos um vizinho valido pra furar
            selecione aleatoriamente um desses vizinhos
            fure e empilhe
        se nao existe
            desempilhe o topo
    }
}
```