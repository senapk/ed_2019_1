#include "xpaint.h"

void embua(int x, int y, float ang, int tamanho){
    if(tamanho < 10)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
    xd_thick_line(x, y, xf, yf, 10);
    x_step("embua");
    embua(xf, yf, ang - 90, tamanho - 10);
    x_step("embua");
    xs_color(BLACK);
    xd_thick_line(x, y, xf, yf, 10);
    
}

int main(){
    int largura = 600, altura = 600;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 90;
    int x = 50;
    int y = altura - 50;
    float tamanho = altura - 100;
    embua(x, y, ang, tamanho);
    x_save("embua");
    x_close();
    return 0;
}