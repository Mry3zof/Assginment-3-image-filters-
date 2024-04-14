#include <iostream>
#include "Image_Class.h"
#include <cmath>
using namespace std;

void Contrastfilter() {
    Image image("night3.jpg");
    int contrast;
    int newcontrast;
    cin >> newcontrast;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {


            contrast = (100.0+newcontrast)/100.0;
            contrast*=contrast;

            int avGRed = image(i,j,0)/255;
            avGRed -= 0.5;
            avGRed *= contrast;
            avGRed += 0.5;
            avGRed *= 255;
            int avGreen = image(i,j,1)/255;
            avGreen -= 0.5;
            avGreen *= contrast;
            avGreen += 0.5;
            avGreen *= 255;
            int avGblu = image(i,j,2)/255;
            avGblu -= 0.5;
            avGblu *= contrast;
            avGblu += 0.5;
            avGblu *= 255;

            image(i,j,0) = avGRed;
            image(i,j,1) = avGreen;
            image(i,j,2) = avGblu;
        }
    }


    image.saveImage("Done.png");
    cout << "Done!\n";
}

void Sepiatonefilter() {
    Image image("night3.jpg");
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image(i,j,0) = min((image(i,j,0)* .263) + (image(i,j,1)* .729) + (image(i,j,2)* .233),255.0);
                image(i,j,1) = min((image(i,j,0)* .400) + (image(i,j,1)* .466) + (image(i,j,2)* .138),255.0);
                image(i,j,2) = min((image(i,j,0)* .315) + (image(i,j,1)* .414) + (image(i,j,2)* .121),255.0);
            }
        }
    }

    image.saveImage("neww.png");
    cout << "Done!\n";
}


void Oilpaintfilter() {
    Image image("night3.jpg");
    int oilpaintnomber = 3;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int red = 0, blue = 0,grn = 0;
            for (int x = i - oilpaintnomber/2; x<= i + oilpaintnomber/2;x++){
                for (int y = j - oilpaintnomber/2; y<= j + oilpaintnomber/2;y++){
                    int Xlimit = max(0, min(image.width-1,x));
                    int Ylimit = max(0, min(image.height-1,y));
                    red += image(Xlimit, Ylimit, 0);
                    grn += image(Xlimit, Ylimit, 1);
                    blue += image(Xlimit, Ylimit, 2);
                }
            }
            unsigned int avGRed = red/(oilpaintnomber*oilpaintnomber);
            unsigned int avGreen = grn/(oilpaintnomber*oilpaintnomber);
            unsigned int avGblu = blue/(oilpaintnomber*oilpaintnomber);
            image(i,j,0)=avGRed;
            image(i,j,1)=avGreen;
            image(i,j,2)=avGblu;
        }
    }


    image.saveImage("Done.png");
    cout << "Done!\n";
}

void Frameimage() {
    Image image;
    image.loadNewImage("image1.jpg");
    Image potatos;
    potatos = image;
    int primarycolor, secondrycolor, frametype;
    cout << "please choose your frame type" << endl;
    cout << "1) Regular   2) Doubled regular   3) Fancy" << endl;
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
                        } else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                                   j >= image.height - 10 && i >= image.width - 10 ||
                                   j >= image.height - 10 && i < 10) {
                        } else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                                   j >= image.height - 15 && i >= image.width - 15 ||
                                   j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        } else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
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
                        } else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                                   j >= image.height - 10 && i >= image.width - 10 ||
                                   j >= image.height - 10 && i < 10) {
                        } else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                                   j >= image.height - 15 && i >= image.width - 15 ||
                                   j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        } else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
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
                        } else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                                   j >= image.height - 10 && i >= image.width - 10 ||
                                   j >= image.height - 10 && i < 10) {
                        } else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                                   j >= image.height - 15 && i >= image.width - 15 ||
                                   j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        } else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
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
                        } else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                                   j >= image.height - 10 && i >= image.width - 10 ||
                                   j >= image.height - 10 && i < 10) {
                        } else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                                   j >= image.height - 15 && i >= image.width - 15 ||
                                   j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        } else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
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
                        } else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                                   j >= image.height - 10 && i >= image.width - 10 ||
                                   j >= image.height - 10 && i < 10) {
                        } else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                                   j >= image.height - 15 && i >= image.width - 15 ||
                                   j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        } else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
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
                        } else if (i < 10 && j < 10 || i >= image.width - 10 && j < 10 ||
                                   j >= image.height - 10 && i >= image.width - 10 ||
                                   j >= image.height - 10 && i < 10) {
                        } else if (i < 15 && j < 15 || i >= image.width - 15 && j < 15 ||
                                   j >= image.height - 15 && i >= image.width - 15 ||
                                   j >= image.height - 15 && i < 15) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        } else if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {
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
                    } else if (primarycolor == 2) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }

                    } else if (primarycolor == 3) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    } else if (primarycolor == 4) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    } else if (primarycolor == 5) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    } else if (primarycolor == 6) {
                        if ((i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    } else {
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
                    } else if (secondrycolor == 2) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    } else if (secondrycolor == 3) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    } else if (secondrycolor == 4) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    } else if (secondrycolor == 5) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    } else if (secondrycolor == 6) {
                        if ((i < 10 || i >= image.width - 10 || j < 10 || j >= image.height - 10)) {
                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 0;
                        }
                    } else {
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
                    } else if (color == 2) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 0;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    } else if (color == 3) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 0;
                            image(i, j, 1) = 0;
                            image(i, j, 2) = 255;
                        }
                    } else if (color == 4) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 255;
                            image(i, j, 1) = 255;
                            image(i, j, 2) = 0;
                        }
                    } else if (color == 5) {

                        if ((i < 5 || i >= image.width - 5 || j < 5 || j >= image.height - 5)) {

                            image(i, j, 0) = 255;
                            image(i, j, 1) = 94;
                            image(i, j, 2) = 5;
                        }
                    } else {
                        cout << "invalid input please enter a valid number from the menu";
                    }
                }
            }
        }
        image.saveImage("Done.png");
        std::cout << "Done!";
    }
}

int main() {
    Contrastfilter();
}