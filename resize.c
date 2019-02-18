#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // converting string to integers
    int n = atoi(argv[1]);

    // ensure user provides an n value between 1 to 100
    if (n < 1 || n > 100)
    {
        printf("Please enter an n value between 1-100\n");

        return 1;
    }


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfResize;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfResize = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, biResize;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    biResize = bi;

    // set the value n for the changes in resize dimension
    biResize.biWidth = bi.biWidth * n;
    biResize.biHeight = bi.biHeight * n;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPadding = (4 - (biResize.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //determine new size image
    biResize.biSizeImage = ((sizeof(RGBTRIPLE)  * biResize.biWidth) + newPadding) * abs(biResize.biHeight);
    bfResize.bfSize = biResize.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bfResize, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biResize, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile n times
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // add new padding
            for (int m = 0; m < newPadding; m++)
            {
                fputc(0x00, outptr);
            }
            if (j < n - 1)
            {
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
