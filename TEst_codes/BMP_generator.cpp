#include <iostream>
#include <fstream>
#include <stdint.h>

using namespace std;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;

#pragma pack(push,1)

struct BitmapFileHeader {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};

#pragma pack(push,1)

struct BitmapInfoHeader {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};
//Cтворення.bmp файла, //задання параметрів полям заголовка .bmp файла і зображення. 

void CreateBmp(const char* fileName, unsigned int** colors, int height, int width) {
    BitmapFileHeader bfh = { 0 };
    BitmapInfoHeader bih = { 0 };
    bfh.bfType = 0x4D42; // 'BM'
    bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
    bfh.bfSize = bfh.bfOffBits + sizeof(colors[0][0]) * width * height;
    bih.biSize = sizeof(bih);
    bih.biBitCount = 32;
    bih.biHeight = height;
    bih.biWidth = width;
    bih.biPlanes = 1;
    ofstream f(fileName, ios::binary);
    f.write((char*)&bfh, sizeof(bfh));
    f.write((char*)&bih, sizeof(bih));
    for (int i = height - 1; i >= 0; i--) {
        f.write((char*)colors[i], sizeof(colors[0][0]) * width);
    }
    f.close();
}

uint32_t rgbToRGB888(uint8_t red, uint8_t green, uint8_t blue) {
    return (red << 16) | (green << 8) | blue;
}

#pragma pack (pop)
int main(){
    int w = 0, h = 0;
    cout << "Input height in px" << endl;
    cin >> h;
    cout << "Input width in px" << endl;
    cin >> w;
    unsigned int** color = new unsigned int* [h];
    for (int i = 0; i < h; i++)
        color[i] = new unsigned int[w];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {            
             // чорний
            
            if(i == j || (w-i) == (h-j)){
                color[i][j] == 0xAAAAAAaa;
            }else{
                color[i][j] = rgbToRGB888(i,j,i);
            }
        }
    }
    CreateBmp("test.bmp", color, h, w);
    for (int i = 0; i < h; i++)
        delete[]color[i];
    delete[] color;
    cout << "test.bmp has been successfully created; Press Enter to exit";
    cin.ignore(2);
    return 0;
}
