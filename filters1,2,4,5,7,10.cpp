using namespace std;
#include "Image_Class.h"
#include<cmath>
void FlipHorizontal(){
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    int f=image.width-1;
    Image image2(image.width,image.height);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;

            for (int k = 0; k < 3; ++k) {
                image2(f,j,k)=image(i,j,k);
            }
        }
        f--;
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image2.saveImage(s);

}
void FlidVertical(){
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    Image image2(image.width,image.height);
    int y;
    for (int i = 0; i < image.width; ++i) {
        y=0;
        for (int j = image.height-1; j >=0; --j) {
            for (int k = 0; k < 3; ++k) {
                image2(i,y,k)=image(i,j,k);
            }
            y++;
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image2.saveImage(s);
}
void GrayScaleConversion(){
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height-1; j >=0; --j) {
            unsigned avg=0;
            for (int k = 0; k < 3; ++k) {
                avg+=image(i,j,k);
            }
            avg/=3;
            image(i,j,0)=avg;
            image(i,j,1)=avg;
            image(i,j,2)=avg;

        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image.saveImage(s);
}
void DarkenImage(){
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height-1; j >=0; --j) {
            unsigned avg=0;
            for (int k = 0; k < 3; ++k) {
                if(image(i,j,k)<=124){
                    image(i,j,k)*=2;
                }
                else{
                    image(i,j,k)=255;
                }
            }
        }   
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image.saveImage(s);
}
void BrightenImage(){
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height-1; j >=0; --j) {
            unsigned avg=0;
            for (int k = 0; k < 3; ++k) {
                if(image(i,j,k)<=124){
                    image(i,j,k)*=2;
                }
                else{
                    image(i,j,k)=255;
                }
            }
        }   
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image.saveImage(s);
}
void BlackAndWhite(){
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    
   for (int i = 0; i < image.width; ++i) {
        for (int j = image.height-1; j >=0; --j) {
            unsigned avg=0;
            for (int k = 0; k < 3; ++k) {
                avg+=image(i,j,k);
            }
            avg/=3;
            image(i,j,0)=avg;
            image(i,j,1)=avg;
            image(i,j,2)=avg;

        }
    }
    for (int i =0 ; i<image.width;i++){
        for(int j=0;j<image.height;j++){
            unsigned x=0;
            for(int k=0;k<3;k++){
                x+=image(i,j,k);
            }
            if(x/3>128){
                for(int k=0;k<3;k++){
                    image(i,j,k)=255;
                }
            }
            else {
            for(int k=0;k<3;k++){
                image(i,j,k)=0;
            }
            }
        }
    }
    
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;

    image.saveImage(s);
}
void DetectImageEdges() {
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    Image image2(image.width, image.height);
    for (int i = 0; i < image.width; ++i) {
        int pixel1 = 0;
        int pixel2 = 0;
        unsigned count = 0;
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; k++) {
                pixel2 += image(i, j, k);
            }
            count++;
            if (count == 1) {
                pixel1 = pixel2;
                pixel2 = 0;
            }
            else if ((count == 2) && (abs(pixel2 - pixel1) > 30)) {
                image2(i, j, 0) = 0;
                image2(i, j, 1) = 0;
                image2(i, j, 2) = 0;
                image2(i, j - 1, 0) = 255;
                image2(i, j - 1, 1) = 255;
                image2(i, j - 1, 2) = 255;
                count = 0;
                pixel1 = 0;
                pixel2 = 0;
            }
            else {
                image2(i, j, 0) = 255;
                image2(i, j, 1) = 255;
                image2(i, j, 2) = 255;
                image2(i, j - 1, 0) = 255;
                image2(i, j - 1, 1) = 255;
                image2(i, j - 1, 2) = 255;
                count = 0;
                pixel1 = 0;
                pixel2 = 0;
            }
        }
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image2.saveImage(s);
}
void MergeImages() {
    string s, z;
    cout << "Pls enter the first image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    cout << "Pls enter the second image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> z;
    Image image(s);
    Image image2(z);
    int x = max(image.width, image2.width);
    int y = max(image.height, image2.height);
    Image potatos(x, y);
    for (int i = 0; i < potatos.width; ++i) {
        for (int j = 0; j < potatos.height; ++j) {
            for (int k = 0; k < potatos.channels; ++k) {
                potatos(i, j, k) = image(i * image.width / potatos.width, j * image.height / potatos.height, k);

            }
        }
    }
    Image potatos2(x, y);
    for (int i = 0; i < potatos2.width; ++i) {
        for (int j = 0; j < potatos2.height; ++j) {
            for (int k = 0; k < potatos2.channels; ++k) {
                potatos2(i, j, k) = image2(i * image2.width / potatos.width, j * image2.height / potatos.height, k);

            }
        }
    }
    Image final(x, y);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < 3; k++) {
                final(i, j, k) = (potatos(i, j, k) + potatos2(i, j, k)) / 2;

            }
        }
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    final.saveImage(s);
    
}

int main() {
    
}
