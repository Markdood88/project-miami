#include "Game.h"
#include <stdio.h>
Game* Game::instance = 0;

Game* Game::getGame(){
    if(instance == 0){
        instance = new Game();
    }

    return instance;
}

Game::Game(){
    Gamepiece::setGM(this);
    init();
}

Game::~Game(){}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see
    Player* p = new Player();
    Player* p2 = new Player();
	Entity* wall = new Entity(false);
	Entity* wall1 = new Entity(false);
	wall->type = environment;
	wall1->type = environment;
	wall->x = .5;
	wall->y = .5;
	wall1->x = .5;

}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
	
    Player* hero = dynamic_cast<Player*>(gp[0]);
    Player* example = dynamic_cast<Player*>(gp[1]);

	
	checkCollisions();

	
    example->moveL();

    
    if (hero->up ){
        hero->moveU();
    }
    if (hero->down ){
       hero->moveD();
    }
    if (hero->left ){
        hero->moveL();
    }
    if (hero->right ){
       hero->moveR();
    }

	
    for(int i = 0; i < gp.size(); i++)
        gp[i]->update(delta);
    

}

void Game::draw(){
    //  Calls draw function from every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->draw();

}

Player* Game::getPlayerObject(){
    Player* p = dynamic_cast<Player*>(gp[0]);
    return p;
}



void Game::addGP(Gamepiece* gamepiece){
    this->gp.push_back(gamepiece);
}

void Game::removeGP(Gamepiece* toErase){
   // std::cout << gp.size() << std::endl;
    for(int i = 0; i < gp.size(); i++){
        if (toErase == gp[i]){
            gp.erase(gp.begin() + i);
            //std::cout << gp.size() << std::endl;
        }
    }

    //delete toErase;
}

void Game::checkCollisions(){
    for(int i = 0; i < gp.size(); i++){
		for(int j = i+1; j <gp.size(); j++){
			
			//environment collision for players
			if(collides(gp[i], gp[j]) && gp[j]->type == environment  ){//this collides function should be one specifically for walls
				gp[i]->x=gp[i]->px;
				gp[i]->y=gp[i]->py;
			}	
			//remove bullets that hit things
			if(collides(gp[i], gp[j]) && i != j && i!=0 && (gp[i]->type != bullet && gp[i]->type != bullet)  ){
				removeGP(gp[j]);
			}
			
			
		}
	}
 }
 

 bool Game::collides(Gamepiece* a, Gamepiece* b){
	double D = sqrt( pow(a->x - b->x,2.0)+pow(a->y - b->y,2.0));

	return (D<.08);

 }
	 
	 