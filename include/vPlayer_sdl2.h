#include <iostream>
extern "C"{
#include <libavcodec/avcodec.h>
#include "SDL.h"
#
}
using namespace std;
namespace FFMPEG_TEST{
class Temp{
  public:
  unsigned codecVer;
  public:
  Temp(){
    codecVer = avcodec_version();
  }
  public:
  void output();
};
}
