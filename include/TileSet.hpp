#ifndef TILE_SET_HPP
#define TILE_SET_HPP

#include "Sprite.hpp"
#include "GameObject.hpp"


class TileSet {

    private:
        Sprite* tileSet;
        int rows, columns, tileWidth, tileHeight;
        
    public:
        TileSet(int tileWidth, int tileHeight, const char* file);
        ~TileSet();

        void RenderTile(unsigned index, float x, float y);

        int GetTileWidth();
        int GetTileHeight();
};

#endif