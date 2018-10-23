#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{

  
  cout << argc << " arguments!" << endl;
  cout << "second argument: " << argv[1] << endl;

  if (argc !=2)
  {

    cout<< "Please specify one imige file!\n";

  } 

  string filename = argv [1];
  Bitmap image;
  image.open(filename);

  if (image.isImage()==false)
  {
    cout<< "Image file must be a bitmap with 24-bit color.\n";
  }

  if (image.isImage()==true)
  {
    vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
    for (int row = 0; row < imagePixels.size(); row++) 
    {
      for (int column =0; column < imagePixels [row].size(); column ++) 
      {
        Pixel color; 
        color = imagePixels [row] [column];

        color.green = 0;
        color.blue = 0;

        imagePixels [row] [column] = color;

      }
    }

    cout<< filename << " is " << filename << " is " << imagePixels.size() << " pixels hight and " << imagePixels[0].size() << " pixels wide\n" ;

    image.fromPixelMatrix(imagePixels);
    image.save("redness.bmp");
  }  

  return 0; 
}
