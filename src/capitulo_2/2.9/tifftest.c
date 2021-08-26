#include<stdio.h>
#include<tiffio.h>


int main(int argc, char **argv)
{
  TIFF* tif;
  TIFF* out=TIFFOpen( "filename.tif" , "w"); 
  // #define uint32 unsigned long
TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);           // uint32 width;
TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);        // uint32 height;
  int sampleperpixel = 4;
  char *image = char [width*height*sampleperpixel];
  TIFFSetField (out, TIFFTAG_IMAGEWIDTH, width);  // set the width of the image
TIFFSetField(out, TIFFTAG_IMAGELENGTH, height);    // set the height of the image
TIFFSetField(out, TIFFTAG_SAMPLESPERPIXEL, sampleperpixel);   // set number of channels per pixel
TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, 8);    // set the size of the channels
TIFFSetField(out, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);    // set the origin of the image.
//   Some other essential fields to set that you do not have to understand for now.
TIFFSetField(out, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
tsize_t linebytes = sampleperpixel * width;     // length in memory of one row of pixel in the image.

unsigned char *buf = NULL;        // buffer used to store the row of pixel information for writing to file
//    Allocating memory to store the pixels of current row
if (TIFFScanlineSize(out)linebytes)
    buf =(unsigned char *)_TIFFmalloc(linebytes);
else
    buf = (unsigned char *)_TIFFmalloc(TIFFScanlineSize(out));

// We set the strip size of the file to be size of one row of pixels
TIFFSetField(out, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(out, width*sampleperpixel));

//Now writing image to the file one strip at a time
for (uint32 row = 0; row < h; row++)
{
    memcpy(buf, &image[(h-row-1)*linebytes], linebytes);    // check the index here, and figure out why not using h*linebytes
    if (TIFFWriteScanline(out, buf, row, 0) < 0)
    break;
}
(void) TIFFClose(out);

if (buf)
    _TIFFfree(buf);
  tiff= TIFFOpen( "filename.tif" , "r");
  TIFFClose(tiff);
  return 0;
   
}

