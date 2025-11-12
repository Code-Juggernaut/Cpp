// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<stdint.h>
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
#pragma pack (pop)
uint32_t rgbToRGB888(uint8_t red, uint8_t green, uint8_t blue) {
    return (red << 16) | (green << 8) | blue;
}
int main()
{
    int canvasSize = 128;
    int squareSize = 32;
    int frameCount = 10;

    for (int f = 0; f < frameCount; f++) {
        unsigned int** color = new unsigned int* [canvasSize];
        for (int i = 0; i < canvasSize; i++)
            color[i] = new unsigned int[canvasSize];

        // ���������� ���� ���
        for (int i = 0; i < canvasSize; i++)
            for (int j = 0; j < canvasSize; j++)
                color[i][j] = 0xFFFFFF;

        // ��� ������� �������� �� �������
        int offset = f * 8;
        for (int i = 0; i < squareSize; i++)
            for (int j = 0; j < squareSize; j++) {
                int y = i + offset;
                int x = j + offset;
                if (y < canvasSize && x < canvasSize)
                    color[y][x] = rgbToRGB888(x,y,x);
            }

        // �������� ���� � ����
        char fileName[64];
        sprintf(fileName, "frame_%02d.bmp", f);
        CreateBmp(fileName, color, canvasSize, canvasSize);

        // ��������
        for (int i = 0; i < canvasSize; i++)
            delete[] color[i];
        delete[] color;
    }

    cout << "Frames created. Use them to assemble a GIF!" << endl;
    return 0;
    
}

