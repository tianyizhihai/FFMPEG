#include <iostream>

extern "C"{
#include <libavcodec/avcodec.h>
#include <SDL.h>
#undef main 
}
using namespace std;
int main()
{
    // cout <<"Hello SDL2"<< endl;
     //创建一个SDL_VIDEO窗口
    SDL_Window* window = NULL;
    SDL_Renderer *renderer = NULL;//渲染器
    SDL_Texture *texture = NULL;//纹理
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Title",
                              SDL_WINDOWPOS_UNDEFINED, // 默认x y 显示到窗口中间
                              SDL_WINDOWPOS_UNDEFINED,
                              640,
                              480,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);// 设置窗口属性
    if(!window){
        printf("不能创建window,%s",SDL_GetError());
    }
    //创建渲染器（一个窗口可以有多个渲染器）
    renderer = SDL_CreateRenderer(window,-1,0);
    if(NULL==renderer){
        printf("渲染器创建失败:%s",SDL_GetError());
        //销毁窗口释放资源
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    //基于渲染器创建纹理
    texture = SDL_CreateTexture(renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    640,
    480);
    if(NULL==texture){
        printf("纹理创建失败:%s",SDL_GetError());
        //销毁窗口释放资源
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
 
    int showCnt = 0;//显示次数
    int run = 1;//循环退出条件
    SDL_Rect rect;//定义一个SDL举行
    rect.w = 50;
    rect.h = 50;
 
    while(run){
        //碎甲rect的位置
        rect.x = rand()%600;
        rect.y = rand() % 400;
        // 设置渲染目标为纹理
        SDL_SetRenderTarget(renderer, texture);
        // 设置渲染绘制颜色
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        // 刷新渲染
        SDL_RenderClear(renderer);
  
        // 设置渲染绘制颜色
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        // 绘制矩形
        SDL_RenderDrawRect(renderer, &rect);
        // 绘制填充矩形
        SDL_RenderFillRect(renderer, &rect);
  
        // 恢复渲染目标为窗口
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
  
        // 显示纹理
        SDL_RenderPresent(renderer);
        SDL_Delay(300);
  
        if(showCnt++ >= 30)
            run = 0;
    }
 
 
    SDL_Delay(5000);//延迟5000毫秒
    SDL_DestroyWindow(window);//销毁窗口
    SDL_Quit();//释放资源
     
    // 引入ffmpeg并打印版本号
    unsigned codecVer = avcodec_version();
    cout << "codec版本号:" <<codecVer<<endl;
    // return 0;
    // string filepath = "F:\\C++Pro\\Git\\tianyizhihai\\C++_FFMPEG\\demo\\test.mpg";

}