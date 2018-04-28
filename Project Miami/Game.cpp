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
	
	Player* p3 = new Player();
	Player* p4 = new Player();
	Player* p5 = new Player();
	Player* p6 = new Player();
	Player* p7 = new Player();
	Player* p8 = new Player();
	Player* p9 = new Player();
	Player* p10 = new Player();
	p2->type=baddy;
	p2->moveL();
	p3->type=baddy;
	p3->moveL();
	p4->type=baddy;
	p4->moveL();
	p5->type=baddy;
	p5->moveL();
	p6->type=baddy;
	p6->moveL();
	p7->type=baddy;
	p7->moveL();
	p8->type=baddy;
	p8->moveL();
	p9->type=baddy;
	p9->moveL();
	p10->type=baddy;
	p10->moveL();

	std::vector<Entity*> walls;
	for(int i = 0; i <=20; i+=1){
		walls.push_back(new Entity(false));
		walls[i]->x = -1+double(i)/10;
		walls[i]->y = .8;
		walls[i]->type = environment;
	}

	for(int i = 0; i <=20; i+=1){
		walls.push_back(new Entity(false));
		walls[i+21]->x = -1+double(i)/10;
		walls[i+21]->y = -.8;
		walls[i+21]->type = environment;
	}	


}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
	
    Player* hero = dynamic_cast<Player*>(gp[0]);
  srand (time(NULL));
  

	for(int i = 0; i < gp.size(); i++){

		if(gp[i]-> type == baddy){
			Player* bad = dynamic_cast<Player*>(gp[i]);
			
			int random = rand() % 4;
			
			if (random == 0){
				bad->moveU();
			}
			if (random == 1 ){
				bad->moveD();
			}
			if (random == 2 ){
				bad->moveL();
			}
			if (random == 3 ){
				bad->moveR();
			}
		
		}
		
	}
	
	checkCollisions();

	
    

   
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
			
			
			if(collides(gp[i], gp[j])){
				if(gp[j]->type == environment){
					gp[i]->x=gp[i]->px;
					gp[i]->y=gp[i]->py;						
				}
				
				if(i != 0){
					if(gp[j]->type == bullet){
						if(gp[i]->type == baddy){
							removeGP(gp[i]);
						}
						if(gp[i]->type != bullet){
							removeGP(gp[j]);
						}
					}
				}
			}
			
			
			
			
		}
	}
 }
 

 bool Game::collides(Gamepiece* a, Gamepiece* b){
	double D = sqrt( pow(a->x - b->x,2.0)+pow(a->y - b->y,2.0));

	return (D<.08);

 }
	 
	 