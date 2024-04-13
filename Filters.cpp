#include <iostream>
#include "Image_Class.h"
#include <cmath>
using namespace std;

void BlurImage() {
    Image image;
    string nameimage;
    image.loadNewImage("luffy.jpg");
    cout << "please choose the blur percentage" << endl << "1) 20%   2) 40%   3) 65%  4) 100%";
    int percent;
    cin >> percent;
    if(percent==1 or percent==2 or percent==3 or percent==4) {
        int di[25] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};
        int dj[25] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    int sum = 0;
                    int element = 0;
                    for (int l = 0; l < 25; l++) {


                        int x = i + di[l] * percent;
                        int y = j + dj[l] * percent;
                        if (x > image.width - 1 or x < 0 or y > image.height - 1 or y < 0) {
                            continue;
                        }

                        sum = sum + image(x, y, k);
                        element++;

                        sum = sum / element;
                        for (int l = 0; l < 25; l++) {
                            if (di[l] > image.width - 1 or di[l] < 0 or dj[l] > image.height - 1 or dj[l] < 0) {
                                continue;
                            }
                            image(i, j, k) = sum;
                        }

                    }
                }
            }
        }
    }
    else{
        cout<< "please enter a valid choice";
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

void Inferredfilter() {
    Image image("image1.jpg");
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 1; j >= 0; --j) {
            unsigned avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);//summation of the 3 colors in the pixel
            }
            avg /= 3;//them divide it by 3 according to RGB
            image(i, j, 0) = avg;//the RGB in the pixel will be the same value
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
            for (int k = 0; k < 3; ++k){
                image(i,j,k) = 255 - image(i,j,k);
            }
            image(i,j,0) += 255-image(i,j,0);
        }
    }


    image.saveImage("neww.png");
    cout << "Done!\n";
}