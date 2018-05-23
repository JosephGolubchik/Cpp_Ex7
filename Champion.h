#pragma once
#include "Player.h"

class Champion: public Player {
public:
	bool firstMove = false;

	const string name() const override { return "Champion"; }
	const Coordinate play(const Board& board) override;
};

