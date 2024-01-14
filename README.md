## About
Simple edge detection program that uses fragment shaders to display edges in videos.

## Requirments
- [SFML](https://www.sfml-dev.org) (I used the latest version)
- [sfeMovie extension](http://sfemovie.yalir.org/latest/) for SFML
- C++ compiler

## How to use
1. Run the `make` command in the terminal to compile
2. Run the `main` executable created (you can also pass as an argument the video you want to process)
3. Use the `Space` key to pause/unpause the video, `Left\Right` arrows to change between the operations done per frame and `Up/Down` arrows to increase/decrease the threshold during binarization 

## Behind edge detection
The algorithm used is a simplified Canny Edge detector that does the following in order:
- makes the image black and white
- applies a simple gaussian convolution
- applies the Sobel operator to find edges in the blurred image (optionally highlighting the direction of the edge using colors)
- applies a simple threshold to highlight only strong edges

## Demo
For comparison, here is a sequence from [【東方】Bad Apple!! ＰＶ【影絵】](https://www.youtube.com/watch?v=FtutLA63Cp8):

![original](https://github.com/zkamper/edge-detector/assets/112496546/14cd78d2-558d-470f-b3be-da3513176d59)

...and that same part, but processed using the Sobel operator with color:

![processed](https://github.com/zkamper/edge-detector/assets/112496546/b95b03c0-ee5b-45e9-96c0-0d967f0e4024)
