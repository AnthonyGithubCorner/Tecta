/*This code was originally from Lazy Foo' Productions (http:://lazyfoo.net)
 Some Modifications were made*/

#include "TextureManager.hpp"

//on init of class
LTexture::LTexture(){
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

void LTexture::free()
{
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

//deallocate instance of class
LTexture::~LTexture(){
    free();
}

//set specific instance of class to specific img
bool LTexture::loadFromFile( SDL_Renderer *gRenderer, std::string path )
{
    //Get rid of preexisting texture
    free();
    //The texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}



//render to screen, can define clip (part of the image) to render

bool LTexture::render( SDL_Renderer *gRenderer, int x, int y, SDL_Rect* clip){
    bool sucess = false;
    SDL_Rect renderQuad = {x,y, mWidth, mHeight};
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
    sucess = true;
    return sucess;
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
