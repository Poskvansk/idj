#include "../include/TileMap.hpp"
#include <string>

TileMap::TileMap(GameObject& associated, const char* file, TileSet* tileSet) : Component(associated) {

    this->tileSet = tileSet;
    Load(file);
}

void TileMap::Load(const char* file) {

    std::ifstream mapfile (file);
    std::string temp;

    if(!mapfile.is_open()) {
        std::cout << "Error, mapfile not open" << std::endl;
    }
    else{
        std::getline(mapfile, temp, ',');
        mapWidth = std::stoi(temp);

        std::getline(mapfile, temp, ',');
        mapHeight = std::stoi(temp);

        std::getline(mapfile, temp, ',');
        mapDepth = std::stoi(temp);
        
        while(getline(mapfile, temp, ',')) {
                if(temp != "\n") {
                    this->tileMatrix.push_back(std::stoi(temp)-1);
                }
        } 
    }
}

void TileMap::SetTileSet(TileSet* tileSet) {
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z = 0) {
    
    int index;
    index = (y*mapWidth + x) + z*mapWidth*mapHeight;
    return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX = 0, int cameraY = 0) {

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            tileSet->RenderTile(At(i, j, layer), i, j);            
        }        
    }
}

void TileMap::Render() {
    for (int i = 0; i < mapDepth; i++) {
        RenderLayer(i,this->associated.box.x, this->associated.box.y);
    } 
}

void TileMap::Update(float dt) {
}

bool TileMap::Is(std::string type) {

    if(type == "TileMap") {
        return true;
    }    
    return false;
}

int TileMap::GetWidth() {
    return mapWidth;
}

int TileMap::GetHeight() {
    return mapHeight;
}

int TileMap::GetDepth() {
    return mapDepth;
}

TileMap::~TileMap() {
}

