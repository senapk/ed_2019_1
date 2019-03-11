#include "xpaint.h"

void linha(int x, int y, float ang, int tamanho){
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    xd_thick_line(x, y, xf, yf, 4);
}


int main(){
    int largura = 600, altura = 600;
    x_open(largura, altura); 
    int step = 360 / 12;
    float ang = 90;
    for(int i = 0; i < 12; i++){
        x_clear(BLACK);
        xs_color(WHITE);
        linha(largura/2, altura/2, ang - i * step, 250);
        x_step("relogio");
    }
    x_save("relogio");
    x_close();
    return 0;
}