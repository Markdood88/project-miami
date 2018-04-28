#ifndef Actor_hpp
#define Actor_hpp
#include "Entity.h"
#include "Projectile.h"
#define DIAG_VSPEED  0.70710678118; 

enum weapon { pistol, shotgun, mini };


class Actor: public Entity{

public:
    float vx; //keep this between 0 and 1 movement should be dx * speed * delta
    float vy;
    float speed;
    int health;
    weapon gun = pistol;
	
    Actor();
    ~Actor();
    
    virtual void init();
    //virtual void update(int delta);
	
	void shoot(float,float,float,float);
	void changeWeapon(weapon);
    

};

#endif