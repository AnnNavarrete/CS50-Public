# Questions

## What's `stdint.h`?

If we want our program to work universally in any systems used, we cannot rely on utilising standard data types. stdint.h is a header file that enable us to include specific integer types i.e. width and length.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To specify the specific byte size and if it's an assigned or unassigned integer, i.e. uint8_t is an unassigned integer of 8 bits vs int32_t which is an assigned integer of 32 bits size. The point of these bytes is how to minimise the number of memory used in your code.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

a BYTE = 1 bytes or 8 bits
a DWORD = 4 bytes or 32 bits
a LONG = 4 bytes or 32 bits
a WORD = 2 bytes or 16 bits

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM in ASCII
0x42 0x4D in hexadecimal

## What's the difference between `bfSize` and `biSize`?

bfSize is the total size of file in bytes
biSize is the total size of image in bytes, it has to be smaller and fit inside the file

## What does it mean if `biHeight` is negative?

It means it starts reading the bitmap from top down, whereis if it's positive, it starts reading the bitmap from bottom up. 

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount determines the number of bits for each pixel

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

It will return a NULL value if you're trying to open a file that does not exist.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

1 is the number of elements in order for the file to be read.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?
int padding = (4 - (3 * 3 = 9) % 4) % 4 = 1

## What does `fseek` do?

fseek enables you to skip the reading of the file up to a certain point.

## What is `SEEK_CUR`?

SEEK_CUR it's a marker of your current position in the file. 
