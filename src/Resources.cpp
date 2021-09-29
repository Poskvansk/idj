#include "../include/Resources.hpp"

std::unordered_map<const char*, SDL_Texture*> Resources::imageTable;
std::unordered_map<const char*, Mix_Chunk*> Resources::soundTable;
std::unordered_map<const char*, Mix_Music*> Resources::musicTable;

SDL_Texture* Resources::GetImage( const char* file) {
    
    auto none = imageTable.end();
    
    if(imageTable.find(file) != none) {
        auto aux = imageTable.find(file);
        return aux->second; 
    }

    SDL_Texture* tex = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file);

    if(tex != nullptr) {
        imageTable[file] = tex;
    }

    return tex;
}

void Resources::ClearImages() {

    for(auto img : imageTable) {
        SDL_DestroyTexture(img.second);  
    }
}



Mix_Music* Resources::GetMusic( const char* file) {
    
    auto none = musicTable.end();
    
    if(musicTable.find(file) != none) {
        auto aux = musicTable.find(file);
        return aux->second; 
    }

    Mix_Music* mus = Mix_LoadMUS(file);

    if(mus != nullptr) {
        musicTable[file] = mus;
    }

    return mus;
}

void Resources::ClearMusics() {

    for(auto mus : musicTable) {
        Mix_FreeMusic(mus.second);
    }
}


Mix_Chunk* Resources::GetSound( const char* file) {
    
    auto none = soundTable.end();
    
    if(soundTable.find(file) != none) {
        auto aux = soundTable.find(file);
        return aux->second; 
    }

    Mix_Chunk* sound = Mix_LoadWAV(file);

    if(sound != nullptr) {
        soundTable[file] = sound;
    }

    return sound;
}

void Resources::ClearSounds() {

    for(auto sound : soundTable) {
        Mix_FreeChunk(sound.second);
    }
}