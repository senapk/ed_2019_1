int procurar_vivo(vet, size, inicio, direcao){
    if(direcao == 1)
        pos = (inicio + direcao) % size
    else
        pos = (inicio + size - 1) % size
    while(vet[pos] == MORTO)
    if(direcao == 1)
        pos = (inicio + direcao) % size
    else
        pos = (inicio + size - 1) % size



int main(){

    int N, E, fase;
    int size = N;
    int vet[size];
    for(int i = 0; i < size; i++){
        vet[i] = (i + 1) * fase;
        fase *= -1
    }
    vao_morrer = N - 1
    while(vao_morrer--){
        dir = vet[E] > 0 ? 1 : -1
        saltos = vet[E] > 0 ? vet[E] : -vet[E]
        morrer = procurar_vivo(vet, size, E, dir)
        vet[morrer] = 0
        pos = morrer
        for(int i = 0; i < saltos; i++)
            pos = procurar_vivo(vet, size, pos, dir)
        E = pos
    }


}