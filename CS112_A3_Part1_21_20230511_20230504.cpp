//####################################FCAI-CU CS112####################################
//################################Assignment 3 part 1 #################################
//#################################Dr.Mohamed Elramly##################################
//#####################################################################################

//Authhor 1 ID: 20230511 section 21,22 Youssef Mohamed did flip filter and Black and white and Grayscale Conversion
//Author 2 ID: 20230504 section 21,22 Youssef Farid did resize filter and invert color filters






#include "Image_Class.h"
#include<cmath>
#include<string>
#include <fstream>
using namespace std;

bool checktheextension(string s) {
    int ccc = s.size();
    string newCharacter = string(1, (tolower(s[ccc - 3]))) + string(1, tolower(s[ccc - 2])) + string(1, tolower(s[ccc - 1]));
    cout << newCharacter;
    if (newCharacter == "jpg" || newCharacter == "bmp" || newCharacter == "png" || newCharacter == "tga") {
        return true;
    }
    else { return false; }
}
void ResizeImage(string& s) {//procedure to resize the image
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

    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        potatos.saveImage(s);
    }
    else {
        string neww;
        while (true) {
            cout << "Pls enter image name to store new image\n";
            cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> neww;
            if (checktheextension(neww))break;
            else {
                cout << "its not valid extension\n";
            }
        }

        cout << "Please wait a few seconds........\n";
        s = neww;
        potatos.saveImage(neww);
        cout << "Done!\n";
    }
}
void InvertImage(string& s) {
    cout << "Please wait a few seconds........\n";
    Image image(s);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

                image(i, j, k) = 255 - image(i, j, k);//invert the color by this algo if the pixel black will be white etc......
            }
        }
    }
    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        image.saveImage(s);
    }
    else {
        string neww;
        while (true) {
            cout << "Pls enter image name to store new image\n";
            cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> neww;
            if (checktheextension(neww))break;
            else {
                cout << "its not valid extension\n";
            }
        }

        cout << "Please wait a few seconds........\n";
        s = neww;
        image.saveImage(neww);
        cout << "Done!\n";
    }
}
void FlipHorizontal(string& s) {
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

    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);;
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        image2.saveImage(s);
    }
    else {
        string neww;
        while (true) {
            cout << "Pls enter image name to store new image\n";
            cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> neww;
            if (checktheextension(neww))break;
            else {
                cout << "its not valid extension\n";
            }
        }

        cout << "Please wait a few seconds........\n";
        s = neww;
        image2.saveImage(neww);
        cout << "Done!\n";
    }

}
void FlipVertical(string& s) {
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

    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        image2.saveImage(s);
    }
    else {
        string neww;
        while (true) {
            cout << "Pls enter image name to store new image\n";
            cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> neww;
            if (checktheextension(neww))break;
            else {
                cout << "its not valid extension\n";
            }
        }

        cout << "Please wait a few seconds........\n";
        s = neww;
        image2.saveImage(neww);
        cout << "Done!\n";
    }
}
void GrayScaleConversion(string& s) {
    Image image(s);
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

        }
    }

    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        image.saveImage(s);
    }
    else {
        string neww;
        while (true) {
            cout << "Pls enter image name to store new image\n";
            cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> neww;
            if (checktheextension(neww))break;
            else {
                cout << "its not valid extension\n";
            }
        }

        cout << "Please wait a few seconds........\n";
        s = neww;
        image.saveImage(neww);
        cout << "Done!\n";
    }
}
void BlackAndWhite(string& s) {
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
            if (x / 3 > 112) {//if the pixel greater than the half of 255 the pixel turn black else turn blue
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
    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        image.saveImage(s);
    }
    else {
        string neww;
        while (true) {
            cout << "Pls enter image name to store new image\n";
            cout << "and follow it with a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> neww;
            if (checktheextension(neww))break;
            else {
                cout << "its not valid extension\n";
            }
        }

        cout << "Please wait a few seconds........\n";
        s = neww;
        image.saveImage(neww);
        cout << "Done!\n";
    }
}
int main() {
    cout << "Welcome to our program\nThis is program were you choose the filter and type the image name\nand our role is to apply this filter on the image\n";
    while (true) {
        bool x = false;
        string name;
        char gg;
        while (true) {
            cout << "please enter the image name you wish to apply filters on\nfollowed by a specify extension .jpg, .bmp, .png, .tga: ";
            cin >> name;
            x = false;
            try {
                ifstream file(name);
                if (!file) {
                    throw "File not found!";
                }
                // File processing code here
                cout << "File '" << name << "' opened successfully.\n" << endl;
                break;
            }
            catch (const char* errorMessage) {
                cerr << "Error: " << errorMessage << endl;
            }
        }
        char choice;
        bool xf = false;
        bool xg = false;
        while (true) {//loop to make the program dont close
            cout << "What filter do you wish to apply?\nA)Grayscale Conversion\nB)Black and white\nC)Invert Image\nD)Flip Image\nE)Resizing Images\nF)Load another image\nG)Exit\nPlease Enter a valid choise: ";
            while (true) {//this loop to make validation
                cin >> choice;
                if (choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'c' || choice == 'C' || choice == 'D' || choice == 'd' || choice == 'e' || choice == 'E' || choice == 'f' || choice == 'F' || choice == 'g' || choice == 'G')break;
                else { cout << "It's not valid choice\nPlease enter a valid one: "; }
            }
            if (choice == 'A' || choice == 'a') {
                GrayScaleConversion(name);
            }
            else if (choice == 'B' || choice == 'b') {
                BlackAndWhite(name);
            }
            else if (choice == 'C' || choice == 'c') {
                InvertImage(name);
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
                    FlipVertical(name);
                }
                else {
                    FlipHorizontal(name);
                }
            }
            else if (choice == 'e' || choice == 'E') {
                ResizeImage(name);
            }
            else if (choice == 'f' || choice == 'F') {
                xf = true; break;
            }
            else {
                xg = true; break;
            }
        }
        if (xf) continue;

        if (xg)return 0;
    }
}