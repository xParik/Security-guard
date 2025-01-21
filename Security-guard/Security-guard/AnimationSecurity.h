#pragma once
#include "SDL.h"
#include <string>
#include <vector>
using namespace std;
class Animation {
public:
    Animation(SDL_Renderer* renderer, const std::string& path, int frameCount, double speed, bool loop)
        : renderer(renderer), path(path), frameCount(frameCount), speed(speed), loop(loop), currentFrame(0), frameTimer(0) {
        for (int i = 0; i < frameCount; ++i) {
            string framePath = path + std::to_string(i) + "Security.bmp";
            SDL_Texture* texture = loadTexture(framePath);
            if (texture) {
                textures.push_back(texture);
            }
        }
    }

private:
    SDL_Renderer* renderer;
    vector<SDL_Texture*> textures;
    string path;
    int frameCount;
    int speed;
    int loop;
    int currentFrame;
    int frameTimer;

    SDL_Texture* loadTexture(const string& path) {
        SDL_Surface* surface = SDL_LoadBMP(path.c_str());
        if (!surface) {
            std::cerr << "Error loading BMP: " << SDL_GetError() << std::endl;
            return nullptr;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        return texture;
    }
};

class AnimationSecurity {
private:
    SDL_Renderer* renderer;
    vector<Animation> sprites;
    SDL_Window* window;
    SDL_Texture* texture;


    string name;
    int x, y, width, height;

    SDL_Texture* loadTexture(const string& path);

public:
    AnimationSecurity(const string& name, int x, int y, int width, int height);
    ~AnimationSecurity();
    AnimationSecurity(SDL_Renderer* renderer)
        : renderer(renderer),
        sprites{ Animation(renderer, "StudentRest.bmp", 256, 1.0, true),
                Animation(renderer, "StudentTakeoff.bmp", 256, 0.3, false),
                Animation(renderer, "StudentFlight.bmp", 256, 1.3, false),
                Animation(renderer, "StudentLanding.bmp", 256, 0.3, false),
                Animation(renderer, "StudentWalk.bmp", 256, 1.0, true),
                Animation(renderer, "StudentFall.bmp", 256, 1.0, true) } {
    }
    void draw();
    void update();


};

