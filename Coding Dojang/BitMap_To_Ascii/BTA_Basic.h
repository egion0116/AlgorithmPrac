#pragma once
#include <stdint.h>

#pragma pack(push, 2)
typedef struct tagBitmapHeader
{
    uint16_t bfType;        // BMP파일의 시그니쳐
    uint32_t bfSize;        // BMP 파일크기
    uint16_t bfReserved1;   // 예약공간 1
    uint16_t bfReserved2;   // 예약공간 2
    uint32_t bfOffBits;     // 비트맵 데이터 시작위치
}BitmapHeader;
#pragma pack(pop)

typedef struct tagBitMapInfoHeader
{
    uint32_t biSize;            // 비트맵 정보헤더 크기
    uint32_t biWidth;           // 비트맵 이미지 가로크기(픽셀)
    uint32_t biHeight;          // 비트맵 이미지 세로크기(픽셀)
    uint16_t biPlanes;          // 사용하는 색상판 수 : 보통 1
    uint16_t biBitCount;        // 픽셀 하나를 표현하는 비트 수
    uint32_t biCompression;     // 압축 방식, 보통 비트맵은 압축을 하지않으므로 0
    uint32_t biSizeImage;       // 비트맵 이미지의 픽셀 데이터 크기(압축되지 않은 크기)
    uint32_t biXPelsPerMeter;   // 그림의 가로 해상도
    uint32_t biYPelsPerMeter;   // 그림의 세로 해상도
    uint32_t biClrUsed;         // 색상 테이블에서 실제 사용되는 색상의 수
    uint32_t biClrImportant;    // 비트맵을 표현하기 위해 필요한 색상 인덱스의 수
}BitmapInfoHeader;

#pragma pack(push, 1)
typedef struct tagRGB
{
    uint8_t rgbRed;
    uint8_t rgbGreen;
    uint8_t rgbBlue;
}RGB;
#pragma pack(pop)