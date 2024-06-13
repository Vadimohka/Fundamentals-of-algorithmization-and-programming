#ifndef ROULETTE_GAMESTATE_H 
#define ROULETTE_GAMESTATE_H 
#include <SFML/Graphics.hpp> 
//#include "../objects/visible-object-manager.h" 
class GameState {
public:
	virtual ~GameState();
	virtual void init() = 0;
	virtual void handleInput(sf::Event* event) = 0;
	virtual void update(float elapsedTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void endLoopLogic() {};
	
protected:
	//VisibleObjectManager _visibleObjectManager;
};
#endif //ROULETTE_GAMESTATE_H 