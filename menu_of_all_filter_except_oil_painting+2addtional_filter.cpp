//####################################FCAI-CU CS112####################################
//################################Assignment 3 part 1 #################################
//#################################Dr.Mohamed ElRamly##################################
//#####################################################################################

//Author 1 ID: 20230511 section 21,22 Youssef Mohamed did flip filter and Black and white and Grayscale Conversion
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
void Sepiatonefilter(string s) {
    Image image("night3.jpg");
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image(i, j, 0) = min((image(i, j, 0) * .263) + (image(i, j, 1) * .729) + (image(i, j, 2) * .233), 255.0);
                image(i, j, 1) = min((image(i, j, 0) * .400) + (image(i, j, 1) * .466) + (image(i, j, 2) * .138), 255.0);
                image(i, j, 2) = min((image(i, j, 0) * .315) + (image(i, j, 1) * .414) + (image(i, j, 2) * .121), 255.0);
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
    };
}
void Frameimage(string s) {
    Image image;
    image.loadNewImage(s);
    Image potatos;
    potatos = image;
    int primarycolor, secondrycolor, frametype;
    cout << "please choose your frame type" << endl;
    cout << "1) Regular   2) Doubled regular   3) Fancy" << endl;
    cin >> frametype;
    //    cout << "please choose your primary frame color" << endl;
    //    cout <<"1) Red"<< endl<<"2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange" << endl << "6) Black" << endl ;
    //    cin  >> primarycolor;
    //    cout << "please choose your secondry frame color" << endl;
    //    cout <<"1) Red"<< endl<<"2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange" << endl << "6) Black" << endl;
    //    cin  >> secondrycolor;
    if (frametype == 3) {
        cout << "please choose your frame color" << endl;
        cout << "1) Red" << endl << "2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange"
            << endl << "6) Black" << endl;
        cin >> primarycolor;
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    if (primarycolor == 1) {
                        if (i < 5 && j < 5 || i >= image.width - 5 && j < 5 ||
                            j >= image.height - 5 && i >= image.width - 5 || j >= image.height - 5 && i < 5) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                        else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                            j >= image.height - 10 && i >= image.width - 10 ||
                            j >= image.height - 10 && i < 10) {
                        }
                        else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                            j >= image.height - 15 && i >= image.width - 15 ||
                            j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                        else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                    if (primarycolor == 2) {
                        if (i < 5 && j < 5 || i >= image.width - 5 && j < 5 ||
                            j >= image.height - 5 && i >= image.width - 5 || j >= image.height - 5 && i < 5) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                        else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                            j >= image.height - 10 && i >= image.width - 10 ||
                            j >= image.height - 10 && i < 10) {
                        }
                        else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                            j >= image.height - 15 && i >= image.width - 15 ||
                            j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                        else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    if (primarycolor == 3) {
                        if (i < 5 && j < 5 || i >= image.width - 5 && j < 5 ||
                            j >= image.height - 5 && i >= image.width - 5 || j >= image.height - 5 && i < 5) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                        else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                            j >= image.height - 10 && i >= image.width - 10 ||
                            j >= image.height - 10 && i < 10) {
                        }
                        else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                            j >= image.height - 15 && i >= image.width - 15 ||
                            j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                        else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    }
                    if (primarycolor == 4) {
                        if (i < 5 && j < 5 || i >= image.width - 5 && j < 5 ||
                            j >= image.height - 5 && i >= image.width - 5 || j >= image.height - 5 && i < 5) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                        else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                            j >= image.height - 10 && i >= image.width - 10 ||
                            j >= image.height - 10 && i < 10) {
                        }
                        else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                            j >= image.height - 15 && i >= image.width - 15 ||
                            j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                        else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    if (primarycolor == 5) {
                        if (i < 5 && j < 5 || i >= image.width - 5 && j < 5 ||
                            j >= image.height - 5 && i >= image.width - 5 || j >= image.height - 5 && i < 5) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                        else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                            j >= image.height - 10 && i >= image.width - 10 ||
                            j >= image.height - 10 && i < 10) {
                        }
                        else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                            j >= image.height - 15 && i >= image.width - 15 ||
                            j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                        else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    }
                    if (primarycolor == 6) {
                        if (i < 5 && j < 5 || i >= image.width - 5 && j < 5 ||
                            j >= image.height - 5 && i >= image.width - 5 || j >= image.height - 5 && i < 5) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                        else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                            j >= image.height - 10 && i >= image.width - 10 ||
                            j >= image.height - 10 && i < 10) {
                        }
                        else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                            j >= image.height - 15 && i >= image.width - 15 ||
                            j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                        else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                }
            }
        }
    }
    if (frametype == 2) {
        cout << "please choose your primary frame color" << endl;
        cout << "1) Red" << endl << "2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange"
            << endl << "6) Black" << endl;
        cin >> primarycolor;
        cout << "please choose your secondry frame color" << endl;
        cout << "1) Red" << endl << "2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange"
            << endl << "6) Black" << endl;
        cin >> secondrycolor;
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    if (primarycolor == 1) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (primarycolor == 2) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }

                    }
                    else if (primarycolor == 3) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    }
                    else if (primarycolor == 4) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (primarycolor == 5) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    }
                    else if (primarycolor == 6) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                    else {
                        cout << "invalid input please enter a valid number from the menu";
                    }

                    if (secondrycolor == 1) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (secondrycolor == 2) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (secondrycolor == 3) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    }
                    else if (secondrycolor == 4) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (secondrycolor == 5) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    }
                    else if (secondrycolor == 6) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                    else {
                        cout << "invalid input please enter a valid number from the menu";
                    }
                }
            }
        }
    }
    if (frametype == 1) {
        cout << "please choose your frame color" << endl;
        cout << "1) Red" << endl << "2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange"
            << endl << "6) Black" << endl;
        cin >> primarycolor;
        cout << "please choose your frame color (enter the number of the color)" << endl;
        cout << "1) Red" << endl << "2) Green" << endl << "3) Blue" << endl << "4) Yellow" << endl << "5) Orange"
            << endl;
        int color;
        cin >> color;
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    if (color == 1) {
                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (color == 2) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (color == 3) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    }
                    else if (color == 4) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    }
                    else if (color == 5) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    }
                    else {
                        cout << "invalid input please enter a valid number from the menu";
                    }
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
    };
}
void RotateImage(string s) {
    string angle;
    cout << "Enter the angle you wish to rotate the image by:(90 180 270)";
    cin >> angle;
    if (stoi(angle) == 270) {
        Image image;
        image.loadNewImage(s);
        Image potatos(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    potatos(j, i, k) = image(i, j, k);
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
    if (stoi(angle) == 90) {
        Image image;
        image.loadNewImage(s);
        Image potatos(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    potatos(image.height - j - 1, image.width - i - 1, k) = image(i, j, k);
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
    if (stoi(angle) == 180) {
        Image image;
        image.loadNewImage(s);
        Image potatos(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    potatos(image.width - i - 1, image.height - j - 1, k) = image(i, j, k);
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
}
void Inferredfilter(string s) {
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
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
            image(i, j, 0) += 255 - image(i, j, 0);
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
    };
}
void CropImage(string s) {
    Image image;
    image.loadNewImage(s);
    int wid;
    int hiet;
    int DWid;
    int DHiet;
    std::cout << "Enter your new width and height as: 1920 1080 ";
    std::cin >> wid >> hiet;
    std::cout << "Enter your X and Y of the starting point (upper left corner of the part to keep) as: 600 500 ";
    std::cin >> DWid >> DHiet;
    Image potatos(wid, hiet);
    for (int i = 0; i < potatos.width; ++i) {
        for (int j = 0; j < potatos.height; ++j) {
            for (int k = 0; k < potatos.channels; ++k) {
                potatos(i, j, k) = image(i + DWid, j + DHiet, k);

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
void BlurImage(string s) {
    Image image;
    string nameimage;
    image.loadNewImage(s);
    cout << "please choose the blur percentage" << endl << "1) 20%   2) 40%   3) 65%  4) 100%";
    int percent;
    cin >> percent;
    if (percent == 1 or percent == 2 or percent == 3 or percent == 4) {
        int di[25] = { -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2 };
        int dj[25] = { -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
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
                    }
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
    else {
        cout << "please choose a valid percent" << endl;
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
void cinematic(string s) {
    Image image(s);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int r = image(i, j, 0);
            int g = image(i, j, 1);
            int b = image(i, j, 2);
            int newR = (((r + 10 / 2) + ((r + 10 / 2) % 10) - 1));
            newR = (newR > 255) ? 255 : newR;
            newR = (newR < 0) ? 0 : newR;
            int newB = (((b + 10 / 2) + (b + 10 / 2) % 10) - 1);
            newB = (newB > 255) ? 255 : newB;
            newB = (newB < 0) ? 0 : newB;
            int newG = (((g + 10 / 2) + (g + 10 / 2) % 10) - 1);
            newG = (newG > 255) ? 255 : newG;
            newB = (newG < 0) ? 0 : newG;
            image(i, j, 0) = newR;
            image(i, j, 1) = newG;
            image(i, j, 2) = newB;
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
void DetectEdges(string s) {
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
void brightImage(string s) {
    Image image(s);
    int x;
    while (true) {
        cout << "please enter the percentage to increase the image brightnes by it: ";
        cin >> x;
        if (x >= 0 && x <= 100)break;
        else cout << "plesae enter the percentage from 0 to 100\n";
    }
    float y = 100.0 / x;
    y = 1 + y;
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 1; j >= 0; --j) {
            for (int k = 0; k < 3; ++k) {
                if (image(i, j, k) < (255 / y)) {
                    image(i, j, k) *= y;
                }
                else image(i, j, k) = 255;
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
void darkImage(string s) {
    Image image(s);
    int x;
    while (true) {
        cout << "please enter the percentage to decrease the image brightnes by it: ";
        cin >> x;
        if (x >= 0 && x <= 100)break;
        else cout << "plesae enter the percentage from 0 to 100\n";
    }
    float y = (100.0 / x);
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 1; j >= 0; --j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) /= y;
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
void merge(string s) {
    string z;
    bool x;
    while (true) {
        cout << "please enter the second image name you wish to apply filters on\nfollowed by a specify extension .jpg, .bmp, .png, .tga: ";
        cin >> z;
        x = false;
        try {
            ifstream file(z);
            if (!file) {
                throw "File not found!";
            }
            // File processing code here
            cout << "File '" << z << "' opened successfully.\n" << endl;
            break;
        }
        catch (const char* errorMessage) {
            cerr << "Error: " << errorMessage << endl;
        }
    }
    Image image(s);
    Image image2(z);
    Image ahahaha;
    char cc;
    while (true) {
        cout << "1)resize the smaller image to the bigger one\n2)resize the bigger image to the smaller one\n3)get the common area between them\nPlease enter a valid choice: ";
        cin >> cc;
        if (cc == '1' || cc == '2' || cc == '3')break;
        else {
            cout << "Its not a valid choice pleae eneter avalid one\n";
        }
    }
    if (cc == '1') {
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
        ahahaha = final;
    }
    else if (cc == '2') {
        int x = min(image.width, image2.width);
        int y = min(image.height, image2.height);
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
        ahahaha = final;
    }
    else {
        int x = min(image.width, image2.width);
        int y = min(image.height, image2.height);
        Image final(x, y);

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < 3; k++) {
                    final(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;

                }
            }
        }
        ahahaha = final;
    }
    char hh;
    while (true) {
        cout << "do you want to save same file?(Y/N): ";
        cin >> hh; hh = toupper(hh);
        if (hh == 'Y' || hh == 'N')break;
        else { cout << "Its not valid choice please enter valid one\n"; }
    }
    if (hh == 'Y') {
        ahahaha.saveImage(s);
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
        ahahaha.saveImage(neww);
    }
}
void dndnEffect(string s) {
    Image image(s);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                int x = rand() % 256 - 128;
                int y = image(i, j, k) + x;
                if (y < 0)
                    y = 0;
                else if (y > 255)
                    y = 255;
                image(i, j, k) = y;
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
void skew_Image(string s) {
    Image image(s);
    float xx;
    cout << "Please enter the angel : "; cin >> xx;
    double SkewAngleRAD = xx * 3.14 / 180.0;
    double tan_skew_angle = tan(SkewAngleRAD);
    int NewWidth = image.width + image.height * tan_skew_angle;

    Image newi(NewWidth, image.height);

    for (int y = 0; y < newi.height; ++y) {
        for (int x = 0; x < newi.width; ++x) {
            int source_x = x - tan_skew_angle * (newi.height - y);

            if (source_x >= 0 && source_x < image.width) {
                for (int c = 0; c < image.channels; ++c) {
                    newi(x, y, c) = image(source_x, y, c);
                }
            }
            else {
                for (int c = 0; c < image.channels; ++c) {
                    newi(x, y, c) = 0;
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
        newi.saveImage(s);
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
        newi.saveImage(neww);
        cout << "Done!\n";
    }
}
void sunlight(string s) {
    Image image(s);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 2; k++) {
                unsigned int z = 0;
                z = image(i, j, k);
                if (z >= 195) {
                    z = 255;
                }
                else {
                    z += 60;
                }
                image(i, j, k) = z;
            }
        }
    }
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) /= 1.2;
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
void purple(string s) {
    Image image(s);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int x = 0;
            for (int k = 0; k < 2; k++) {
                unsigned int z = 0;
                z = image(i, j, x);
                if (z >= 195) {
                    z = 255;
                }
                else {
                    z += 60;
                }
                image(i, j, x) = z;
                x += 2;
            }
        }
    }
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) /= 1.2;
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
            cout << "What filter do you wish to apply?\nA)Grayscale Conversion\nB)Black and white\nC)Invert Image\nD)Flip Image\nE)Resizing Images\nF)Merge image\nG)Rotate\nH)Image brightness\nI)Crop image\nJ)Adding frame\nK)Edge detection\nL)Blur\nM)sunlight\nN)Oil painting\nO)Old tv\nP)Purple\nQ)Infrared\nR)Skew image\nS)cinematic\nT)Sepiatone\nU)Load new image\nV)exit\nPlease Enter a valid choise: ";
            while (true) {//this loop to make validation
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'c' || choice == 'C' || choice == 'D' || choice == 'd' || choice == 'e' || choice == 'E' || choice == 'f' || choice == 'F' || choice == 'g' || choice == 'G' || choice == 'H' || choice == 'I' || choice == 'J' || choice == 'K' || choice == 'L' || choice == 'M' || choice == 'N' || choice == 'O' || choice == 'P' || choice == 'Q' || choice == 'R' || choice == 'S' || choice == 'T' || choice == 'U' || choice == 'V')break;
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
            else if (choice == 'u' || choice == 'U') {
                xf = true; break;
            }
            else if (choice == 'V' || choice == 'v') {
                xg = true; break;
            }
            else if (choice == 'F') {
                merge(name);
            }
            else if (choice == 'G') {
                RotateImage(name);
            }
            else if (choice == 'H') {
                string choice2;
                cout << "1.make image brighter\n2.make image darker\nPlease enter valid choice: ";//make choice to flip vertical or horizontal
                while (true)
                {
                    cin >> choice2;
                    if (choice2 == "1" || choice2 == "2")break;
                    else { cout << "Its not valid choice\nPlease enter a valid one: "; }
                }
                if (choice2 == "1") {
                    brightImage(name);
                }
                else {
                    darkImage(name);
                }
            }
            else if (choice == 'I') {
                CropImage(name);
            }
            else if (choice == 'J') {
                Frameimage(name);
            }
            else if (choice == 'K') {
                DetectEdges(name);
            }
            else if (choice == 'L') {
                BlurImage(name);
            }
            else if (choice == 'M') {
                sunlight(name);
            }
            else if (choice == 'N') {

            }
            else if (choice == 'O') {
                dndnEffect(name);
            }
            else if (choice == 'P') {
                purple(name);
            }
            else if (choice == 'Q') {
                Inferredfilter(name);
            }
            else if (choice == 'R') {
                skew_Image(name);
            }
            else if (choice == 'S') {
                cinematic(name);
            }
            else if (choice == 'T') {
                Sepiatonefilter(name);
            }
        }
        if (xf) continue;

        if (xg)return 0;
    }
}