## About
Simple edge detection program that uses fragment shaders to display edges in videos.

## Requirments
- [SFML](https://www.sfml-dev.org) (I used the latest version)
- [sfeMovie extension](http://sfemovie.yalir.org/latest/) for SFML
- C++ compiler

## How to use
1. Run the `make` command in the terminal to compile
2. Run the `main` executable created (you can also pass as an argument the video you want to process)

## Demo
For comparison, here is a sequence from [【東方】Bad Apple!! ＰＶ【影絵】](https://www.youtube.com/watch?v=FtutLA63Cp8):

![original](https://github.com/zkamper/edge-detector/assets/112496546/14cd78d2-558d-470f-b3be-da3513176d59)

...and that same part, but processed:

![processed](https://github.com/zkamper/edge-detector/assets/112496546/b95b03c0-ee5b-45e9-96c0-0d967f0e4024)
