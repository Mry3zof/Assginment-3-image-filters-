//####################################FCAI-CU CS112####################################
//################################Assignment 3 part 1 #################################
//#################################Dr.Mohamed Elramly##################################
//#####################################################################################

//Auhtor 1 ID: 20230511 section 21,22 Youssef Mohamed did flip filter and Black and white and Grayscale Conversion
//Author 2 ID: 20230504 section 21,22 Youssef Farid did resize filter and invert color filters






#include "Image_Class.h"
#include<cmath>
#include<string>
using namespace std;

void ResizeImage() {//procedure to resize the image
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image;
    image.loadNewImage(s);//load the image
    int wid;
    int hiet;
    cout << "Enter your new width and height as: \"1920 1080\"\n";
    cin >> wid >> hiet;//get the new dimension of the image
    Image potatos(wid, hiet);//create new image with new image
    for (int i = 0; i < potatos.width; ++i) {
        for (int j = 0; j < potatos.height; ++j) {
            for (int k = 0; k < potatos.channels; ++k) {
                potatos(i, j, k) = image(i * image.width / potatos.width, j * image.height / potatos.height, k);//take the pixels of original image the multiply it to the ration

            }
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    potatos.saveImage(s);
    cout << "Done!\n";
}
void InvertImage() {
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    cout << "Please wait a few seconds........\n";
    Image image(s);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

                image(i, j, k) = 255 - image(i, j, k);//invert the color by this algo if the pixel black will be white etc......
            }
        }
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    cout << "Please wait a few seconds........\n";
    image.saveImage(s);//save the image
    cout << "Done!\n";
}
void FlipHorizontal() {
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    int f = image.width - 1;
    Image image2(image.width, image.height);//make new image with same dimension

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;

            for (int k = 0; k < 3; ++k) {
                image2(f, j, k) = image(i, j, k);//take the first pixel from the original image and save it in the last pixel in the same height
            }
        }
        f--;//decrease the new width by 1;
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image2.saveImage(s);
    cout << "Done!\n";

}
void FlipVertical() {
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    Image image2(image.width, image.height);//create new image with same dimension
    int y;
    for (int i = 0; i < image.width; ++i) {
        y = 0;
        for (int j = image.height - 1; j >= 0; --j) {//this loop start from the last height
            for (int k = 0; k < 3; ++k) {
                image2(i, y, k) = image(i, j, k);
            }
            y++;//this y mean the first y in the new image then increase by 1
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image2.saveImage(s);
    cout << "Done!\n";
}
void GrayScaleConversion() {
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 1; j >= 0; --j) {
            unsigned avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);//summation of the 3 colors in the pixel
            }
            avg /= 3;//them divide it by 3 accordin to RGB
            image(i, j, 0) = avg;//the RGB in the pixel will be the same value
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;

        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    image.saveImage(s);
    cout << "Done!\n";
}
void BlackAndWhite() {
    string s;
    cout << "Pls enter the image name to import it\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    Image image(s);
    cout << "Please wait a few seconds........\n";

    for (int i = 0; i < image.width; ++i) {//GrayScale conversion
        for (int j = image.height - 1; j >= 0; --j) {
            unsigned avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;

        }
    }
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned x = 0;
            for (int k = 0; k < 3; k++) {
                x += image(i, j, k);
            }
            if (x / 3 > 112) {//if the pixel greate than the half of 255 the pixel turn black else turn blue
                for (int k = 0; k < 3; k++) {
                    image(i, j, k) = 255;
                }
            }
            else {
                for (int k = 0; k < 3; k++) {
                    image(i, j, k) = 0;
                }
            }
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
    cin >> s;
    cout << "Please wait a few seconds........\n";
    image.saveImage(s);
    cout << "Done!\n";
}


int main() {
    cout << "Welcome to our program\nThis is program were you choose the filter and type the image name\nand our role is to apply this filter on the image\n";
    char choice;
    while (true) {//loop to make the program dont close
        cout << "What filter do you wish to apply?\nA)Grayscale Conversion B)Black and white C)Invert Image D)Flip Image E)Resizing Images F)Exit\nPlease Enter a valid choise: ";
        while (true) {//this loop to make validation
            cin >> choice;
            if (choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'c' || choice == 'C' || choice == 'D' || choice == 'd' || choice == 'e' || choice == 'E' || choice == 'f' || choice == 'F')break;
            else { cout << "It's not valid choice\nPlease enter a valid one: "; }
        }
        if (choice == 'A' || choice == 'a') {
            GrayScaleConversion();
        }
        else if (choice == 'B' || choice == 'b') {
            BlackAndWhite();
        }
        else if (choice == 'C' || choice == 'c') {
            InvertImage();
        }
        else if (choice == 'D' || choice == 'd') {
            string choice2;
            cout << "1.Flip vertical\n2.Flip horizontal\nPlease enter valid choice: ";//make choice to flip vertical or horizontal
            while (true)
            {
                cin >> choice2;
                if (choice2 == "1" || choice2 == "2")break;
                else { cout << "Its not valid choice\nPlease enter a valid one: "; }
            }
            if (choice2 == "1") {
                FlipVertical();
            }
            else {
                FlipHorizontal();
            }
        }
        else if (choice == 'e' || choice == 'E') {
            ResizeImage();
        }
        else {
            return 0;
        }

    }
}