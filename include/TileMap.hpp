#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include "GameObject.hpp"
#include "TileSet.hpp"
#include <iostream>
#include <fstream>

class TileMap : public Component {

    private:
        std::vector<int> tileMatrix;
        TileSet* tileSet;
        int mapWidth, mapHeight, mapDepth;
        
    public:

        TileMap(GameObject& associated, const char* file, TileSet* tileSet);
        ~TileMap();

        void Load(const char* file);
        void SetTileSet(TileSet* tileSet);
        int& At(int x, int y, int z);

        void Render() override;
        void Update(float dt) override;
        bool Is(std::string type) override;

        void RenderLayer(int layer, int cameraX, int cameraY);

        int GetWidth();
        int GetHeight();
        int GetDepth();     
};

#endif