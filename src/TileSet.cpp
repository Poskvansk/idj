#include "../include/TileSet.hpp"
#include <iostream>

TileSet::TileSet(int tileWidth, int tileHeight, const char* file) {

    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    GameObject* go = new GameObject;
    this->tileSet = new Sprite(*go, file);

    if (tileSet != nullptr) {
        rows = tileSet->GetHeight()/this->GetTileHeight();
        columns = tileSet->GetWidth()/this->GetTileWidth();
    }
    else {
        std::cout << "Error, tileSet nil" << std::endl;
    }
}

void TileSet::RenderTile(unsigned index, float x, float y) {
    
    x*=GetTileWidth();
    y*=GetTileHeight();

    if (index >= 0 && index < (columns*rows)) {
        int p1, p2;
        p1 = (index%columns)*tileWidth;
        p2 = (int)(index/columns)*tileHeight;

        tileSet->SetClip(p1, p2, this->GetTileWidth(), this->GetTileHeight());
        tileSet->Render(x, y);
    }
}

int TileSet::GetTileWidth() {
    return tileWidth;
}

int TileSet::GetTileHeight() {
    return tileHeight;
}

TileSet::~TileSet() {
}

