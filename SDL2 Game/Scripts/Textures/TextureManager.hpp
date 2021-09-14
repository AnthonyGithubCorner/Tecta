/*This code was originally from Lazy Foo' Productions (http:://lazyfoo.net)
 Some Modifications were made*/

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>

class LTexture{
public:
    LTexture();
    ~LTexture();
    bool loadFromFile( SDL_Renderer *gRenderer, std::string path );
    void free();
    
    //Creates image from font used in UI and Faction text
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
    
    //Renders texture at given point
    bool render( SDL_Renderer *gRenderer, int x, int y , SDL_Rect* clip = NULL );
    
    int getWidth();
    
    int getHeight();
    
private:
    SDL_Texture *mTexture;
    int mWidth;
    int mHeight;
    
};

#endif /* TextureManager_hpp */
