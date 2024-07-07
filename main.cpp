#include "vPlayer_sdl2.h"
#undef main 
int main()
{
    char filePath[]= "F:/C++Pro/Git/FFMPEG/demo/test.mpg";
    vPlayer_sdl2(filePath);
    getchar();
}