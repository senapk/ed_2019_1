#include "xpaint.h"


void draw_square(int xc, int yc, int side, float thick){
    if(thick < 1)
        thick = 1;
    xs_color(make_xcolor(xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)));
    xd_thick_line(xc - side/2, yc - side/2, xc + side/2, yc - side/2, thick);
    xd_thick_line(xc - side/2, yc + side/2, xc + side/2, yc + side/2, thick);
    xd_thick_line(xc - side/2, yc - side/2, xc - side/2, yc + side/2, thick);
    xd_thick_line(xc + side/2, yc - side/2, xc + side/2, yc + side/2, thick);
}

void fractal(int xc, int yc, int side, float thick){
    if(side < 2)
        return;
    draw_square(xc, yc, side, thick);
    float ratio = 0.475;
    thick *= 0.7;
    fractal(xc - side/2, yc - side/2, ratio * side, thick);
    fractal(xc + side/2, yc - side/2, ratio * side, thick);
    fractal(xc - side/2, yc + side/2, ratio * side, thick);
    fractal(xc + side/2, yc + side/2, ratio * side, thick);
}

int main(){
    x_open(2000, 2000);
    fractal(1000, 1000, 1000, 4);
    x_save("quadrado");
}