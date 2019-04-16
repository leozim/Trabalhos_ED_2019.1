#include "xpaint.h"

void tree(int x, int y, float ang, int tamanho){
    if(tamanho < 10){
        xs_color(VIOLET);
        //xs_color((XColor) {xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        xd_filled_circle(x + tamanho, y + tamanho, 10);
        return;
    }
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    int linha = 10;
    //xs_color((XColor) {xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});//struct
    if(tamanho >= 85 && tamanho <= 120){
        xs_color(MAGENTA);
        xd_thick_line(x, y, xf, yf, linha);
        x_step("tree");
    }
    else{
        linha--;
        xs_color(BLACK);
        xd_thick_line(x, y, xf, yf, linha);
        x_step("tree");
    }
    
    tree(xf, yf, ang - xm_rand(18, 30), tamanho - xm_rand(8, 12));
    tree(xf, yf, ang + xm_rand(20, 25), tamanho - xm_rand(8, 10));
    
}

int main(void)
{
    int largura = 1400, altura = 1000;
    x_open(largura, altura);
    x_clear(WHITE);
    float ang = 90;
    int x = largura / 2;
    int y = altura - 10;
    float tamanho = 120;
    tree(x, y, ang, tamanho);
    x_save("tree");
    x_close();

    return 0;
}