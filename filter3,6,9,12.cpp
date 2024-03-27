#include <iostream>
#include "Image_Class.h"
#include <cmath>
using namespace std;

void BlurImage() {
    Image image;
    string nameimage;
    image.loadNewImage(nameimage);

    int di[8] = {-1, 0 , 1,  -1, -1, 1, 0, 1};
    int dj[8] = {-1, -1, -1, 0, 1 ,  0, 1, 1};

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                int sum = 0;
                int element = 0;
                for (int l = 0; l < 8; ++l) {
                    int x = i + di[l];
                    int y = j + dj[l];
                    if ( x > image.width-1 or x < 0 or y > image.height-1 or y < 0 ){
                        continue;
                    }
                    sum = sum + image(x,y,k);
                    element++;
                }
                sum = sum/element;
                image(i,j,k) = sum;

            }
        }
    }


    image.saveImage("Done.png");
    std::cout<< "Done!";
}

void ResizeImage(){
    Image image;
    image.loadNewImage("image1.jpg");
    int wid;
    int hiet;
    std::cout << "Enter your new width and height as: 1920 1080 ";
    std::cin >> wid >>hiet;
    Image potatos(wid,hiet);
    for (int i = 0; i < potatos.width ; ++i) {
        for (int j = 0; j < potatos.height ; ++j) {
            for (int k = 0; k < potatos.channels; ++k) {
                potatos(i, j,k) = image(i*image.width/potatos.width,j*image.height/potatos.height,k);

            }
        }
    }




    potatos.saveImage("Done.png");
    std::cout<< "Done!";
}

void CropImage() {
    Image image;
    image.loadNewImage("toy1.jpg");
    int wid;
    int hiet;
    int DWid;
    int DHiet;
    std::cout << "Enter your new width and height as: 1920 1080 ";
    std::cin >> wid >>hiet;
    std::cout << "Enter your X and Y of the starting point (upper left corner of the part to keep) as: 600 500 ";
    std::cin >> DWid >> DHiet;
    Image potatos(wid,hiet);
    for (int i = 0; i < potatos.width; ++i) {
        for (int j = 0; j < potatos.height; ++j) {
            for (int k = 0; k < potatos.channels; ++k) {
                potatos(i, j, k) = image(i+DWid, j+DHiet, k);

            }
        }
    }


    potatos.saveImage("Done.png");
    std::cout << "Done!";
}



void RotateImage(){
    string angle;
    cout<<"Enter the angle you wish to rotate the image by:(90 180 270)";
    cin>> angle;
    if (stoi(angle)==270) {
        Image image;
        image.loadNewImage("image1.jpg");
        Image potatos(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    potatos(j, i, k) = image(i, j, k);
                }
            }
        }
        potatos.saveImage("Done.png");
        std::cout<< "Done!";
    }
    if (stoi(angle)==90) {
        Image image;
        image.loadNewImage("image1.jpg");
        Image potatos(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    potatos(image.height - j - 1, image.width - i - 1, k) = image(i, j, k);
                }
            }
        }
        potatos.saveImage("Done.png");
        std::cout<< "Done!";
    }
    if (stoi(angle)==180) {
        Image image;
        image.loadNewImage("image1.jpg");
        Image potatos(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    potatos(image.width - i - 1, image.height - j - 1, k) = image(i, j, k);
                }
            }
        }
        potatos.saveImage("Done.png");
        std::cout<< "Done!";
    }
}

void InvertImage() {
    Image image("image1.jpg");
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

                image(i,j,k) = 255 - image(i,j,k) ;
            }
        }
    }
    image.saveImage("Done.png");
    std::cout<< "Done!";
}

int main() {
    string enter;
    cin >> enter;
    BlurImage();
}