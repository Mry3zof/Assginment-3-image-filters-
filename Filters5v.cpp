#include <iostream>
#include "Image_Class.h"
#include <cmath>
using namespace std;


void Oilpaintfilter() {
    Image image("night3.jpg");
    Image resalt(image.width, image.height);
    int oilpaintnomber = 20;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int arrred[21] = {0};
            int arrgrn[21] = {0};
            int arrblu[21] = {0};
            int arrlvlcnt[21] = {0};
            for(int l = - 5; l <= 5; ++l){
                for (int k = - 5; k <= 5; ++k) {
                    int curX = i + l;
                    int curY = j + k;
                    if (curX > image.width - 1 or curX < 0 or curY > image.height - 1 or curY < 0) {
                        continue;
                    }
                    double (curIntensity) = ceil((int)((double)(image(curX,curY,0)+image(curX,curY,1)+image(curX,curY,2))/3*oilpaintnomber)/255.0f);
                    int curInrdsggfd = curIntensity;
                    arrlvlcnt[curInrdsggfd]++;
                    arrred[curInrdsggfd] += image(curX,curY,0);
                    arrgrn[curInrdsggfd] += image(curX,curY,1);
                    arrblu[curInrdsggfd] += image(curX,curY,2);
                }
            }
            int curmx=0;
            int maxindx=0;
            for (int k = 1; k <= oilpaintnomber; k++){
                if (arrlvlcnt[k] > curmx){
                    curmx = arrlvlcnt[k];
                    maxindx = k;
                }
            }
            resalt(i,j,0) = arrred[maxindx] / curmx;
            resalt(i,j,1) = arrgrn[maxindx] / curmx;
            resalt(i,j,2) = arrblu[maxindx] / curmx;
        }
    }
    resalt.saveImage("Done.png");
    cout << "Done!\n";
}

void Contrastfilter() {
    Image image("samurai.jpg");
    cout << "please enter the percentage you wish to change the contrast by" << endl << "Please make sure it's [-100,100]" << endl;
    int contrast;
    cin >> contrast;
    if(contrast > 100 or contrast < -100){
        return(Contrastfilter());
    }
    double factor = (double) (259 * (contrast + 255)) / (255 * (259 - contrast));
    int colour;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int red = factor * (image(i, j, 0) - 128) + 128;
            int green = factor * (image(i, j, 1) - 128) + 128;
            int blue = factor * (image(i, j, 2) - 128) + 128;

            image(i, j, 0) = max(0, min(red, 255));
            image(i, j, 1) = max(0, min(green, 255));
            image(i, j, 2) = max(0, min(blue, 255));
        }
    }
    image.saveImage("Done.png");
    cout << "Done!\n";
}

int main() {
    Oilpaintfilter();
}