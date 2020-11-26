#include "pch.h"
#include "../OceanW/game.h"

TEST(SqareTest, sqare_plankton) 
{
	Plankton *plankton = new Plankton();

	Square square;

	EXPECT_EQ(Square::STATUS::EMPTY, square.GetStatus());

	square.GetIn(plankton);
	
	EXPECT_EQ(Square::STATUS::HALF, square.GetStatus());
	EXPECT_EQ(1, square.GetCitizenCount());
	EXPECT_EQ(1, square.GetPlantCount());

	Plankton *plankton2 = new Plankton();

	square.GetIn(plankton2);

	EXPECT_EQ(Square::STATUS::HALF, square.GetStatus());
	EXPECT_EQ(1, square.GetCitizenCount());
	EXPECT_EQ(1, square.GetPlantCount());

	square.GetOff(plankton);

	EXPECT_EQ(Square::STATUS::EMPTY, square.GetStatus());
	EXPECT_EQ(0, square.GetCitizenCount());
	EXPECT_EQ(0, square.GetPlantCount());
}

TEST(SqareTest, SqarePlanktonAndPredator)
{
	Plankton* plankton = new Plankton();
	Plankton* plankton1 = new Plankton();

	Shark* predator = new Shark(0, Predator::Gender::FEMALE);
	Shark* predator2 = new Shark(0, Predator::Gender::FEMALE);
	Shark* predator3 = new Shark(0, Predator::Gender::MALE);
	Shark* predator4 = new Shark(0, Predator::Gender::MALE);

	Square square;

	EXPECT_EQ(Square::STATUS::EMPTY, square.GetStatus());

	square.GetIn(plankton);
	square.GetIn(plankton1);

	EXPECT_EQ(Square::STATUS::HALF, square.GetStatus());
	EXPECT_EQ(1, square.GetCitizenCount());
	EXPECT_EQ(1, square.GetPlantCount());

	square.GetIn(predator);
	square.GetIn(predator2);
	square.GetIn(predator3);
	square.GetIn(predator4);

	EXPECT_EQ(Square::STATUS::FULL, square.GetStatus());
	EXPECT_EQ(4, square.GetCitizenCount());
	EXPECT_EQ(1, square.GetPlantCount());
	EXPECT_EQ(3, square.GetPredatorCount());

	square.GetOff(square[0]);
	square.GetOff(square[1]);
	square.GetOff(square[2]);
	square.GetOff(square[3]);

	EXPECT_EQ(Square::STATUS::EMPTY, square.GetStatus());
	EXPECT_EQ(0, square.GetCitizenCount());
	EXPECT_EQ(0, square.GetPlantCount());
	EXPECT_EQ(0, square.GetPredatorCount());
}

TEST(sdf, sdf1)
{
	Game game(4, 4, 6);
	
	game.SelectCitizen();
	
	game.selectedCitizen->Move(Citizen::Direction::RIGHT);
}