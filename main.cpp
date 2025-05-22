//Code to implement a simple Arnold Cat Map algorithm
//Based on the sample source code available at https://easybmp.sourceforge.net

#include <iostream>
#include "EasyBMP.cpp"

using namespace std;

void applyTransform(BMP,BMP);
void transformPixel(int[2], int[2]);

int main(int argc, char* argv[]) {
    
    if( argc != 2 ) {
        cout << "Usage: ArnoldCatMapBMP <input_filename>" << endl << endl;
        return 1; 
    }

    //Read from file
    BMP Input;
    if(Input.ReadFromFile( argv[1] ))
        printf("Success reading file!\n");

    //Resize the image
    Rescale( Input , 'f', 255 );
    cout<<"Image resized into 255x255"<<endl;

    BMP NewImage;
    NewImage.SetSize(255, 255);

    // apply the transformation
    int oldPos[2], newPos[2];
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            oldPos[0] = j;
            oldPos[1] = i;
            transformPixel(oldPos, newPos);
            PixelToPixelCopy(Input, j, i, NewImage, newPos[0], newPos[1]);
        } 
    }


    NewImage.WriteToFile("output/transformed.bmp");

    return 0;
}

void transformPixel(int oldPixel[], int newPixel[]){
    newPixel[0] = (oldPixel[0]*2 + oldPixel[1])%255; //New x position;
    newPixel[1] = (oldPixel[0] + oldPixel[1])%255; //New y position;
    return;
}