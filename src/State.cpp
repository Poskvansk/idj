#include "../include/State.hpp"
#include <iostream>

State::State() {
    quitRequested = false;

	GameObject* go = new GameObject();
	bg = new Sprite(*go, "./assets/img/ocean.jpg");
	go->AddComponent(bg);

	go->box.x=0;
	go->box.y=0;
	
	objectArray.emplace_back(go);

	music = new Music("./assets/audio/stageState.ogg");
    music->Play(-1);
}

State::~State() {
    objectArray.clear();
}

void State::Update(float dt) {

    Input();

	for (size_t i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Update(dt);
	}
	
	for (int i = objectArray.size() - 1; i >= 0; i--)	{

		if (objectArray[i]->IsDead() ) {

			// para a musica tocar corretamente primeiro removeu-se o sprite e a face
			// mas só apaga o objeto depois q o som terminar de tocar

			objectArray[i]->RemoveComponent(objectArray[i]->GetComponent("Sprite"));
			objectArray[i]->RemoveComponent(objectArray[i]->GetComponent("Face"));

			Sound* sound = (Sound*)objectArray[i]->GetComponent("Sound");

        	if(!sound->IsPlaying()) {
				objectArray.erase((objectArray.begin()+i));
			}
		}
	}
}

void State::LoadAssets() {
    // bg = new Sprite("assets/img/ocean.jpg");
    // music = new Music("assets/audio/stageState.ogg");
}

void State::Render() {
	
	for (size_t i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Render();
	}
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::AddObject(int mouseX, int mouseY) {

	GameObject* go = new GameObject;

	Sprite* sprite = new Sprite(*go, "./assets/img/penguinface.png");
	go->AddComponent(sprite);
	go->box.x = mouseX;
	go->box.y = mouseY;

	Sound* sound = new Sound(*go, "./assets/audio/boom.wav");
	go->AddComponent(sound);
	
	Face* face = new Face(*go);
	go->AddComponent(face);

	objectArray.emplace_back(go);
}

//////////////////////////  Codigo disponibilizado pelos monitores
void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contr�rio
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para termina��o
		if (event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de tr�s pra frente pra sempre clicar no objeto mais de cima
			for (int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro � algo que devemos evitar ao m�ximo.
				// O prop�sito do unique_ptr � manter apenas uma c�pia daquele ponteiro,
				// ao usar get(), violamos esse princ�pio e estamos menos seguros.
				// Esse c�digo, assim como a classe Face, � provis�rio. Futuramente, para
				// chamar fun��es de GameObjects, use objectArray[i]->fun��o() direto.

				if (go->box.Contains({ (float)mouseX, (float)mouseY })) {
					Face* face = (Face*)go->GetComponent("Face");
					if (nullptr != face) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (s� queremos acertar um)
						break;
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}
			// Se n�o, crie um objeto
			else {
				Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}