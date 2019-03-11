#include "xpaint.h"



int main(){
    int largura = 600, altura = 600;
    x_open(largura, altura); 

    float ang = 90;
    int x = 50;
    int y = altura - 50;
    float tamanho = altura - 100;
    while(tamanho > 10){
        int xf = x + tamanho * xm_cos(ang);
        int yf = y - tamanho * xm_sin(ang);
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        xd_thick_line(x, y, xf, yf, 10);
        ang -= 90;
        tamanho -= 10;
        x = xf;
        y = yf;
        x_step("embua");
    }
    x_close();
    return 0;
}