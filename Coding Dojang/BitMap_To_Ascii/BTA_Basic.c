#include "BTA_Basic.h"
#include <stdio.h>

void ReadBitmapHeader(BitmapHeader* Target)
{
    FILE* fp_Bitmap = fopen("./Image.bitmap", "rb");
    if (fp_Bitmap == NULL)
    {
        perror("fopen");
        exit(1);
    }

    fread(Target, sizeof(*Target), 1, fp_Bitmap);
    if (Target->bfType != 'MB')

    fclose(fp_Bitmap);
}

