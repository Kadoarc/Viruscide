#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "GameContext.h"
#include "GameStates.h"

class StateManager;

class State : private sf::NonCopyable
{
public:
	using Ptr = std::unique_ptr<State>; // typedef std::unique_ptr<State> Ptr;

	explicit State(StateManager &stack, States::Context context);
	virtual ~State() = default;

	virtual bool handleEvent(const sf::Event &event) = 0;
	virtual bool update(sf::Time dt) = 0;
	virtual void draw() = 0;

protected:
	void pushState(States::ID state) const;
	void popState() const;
	void clearStates() const;

	States::Context getContext() const;

private:
	StateManager	 &stack;
	States::Context  context;
};