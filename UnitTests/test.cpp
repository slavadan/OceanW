#include "pch.h"
#include "../OceanW/Field/field.h"

TEST(SqareTest, sqare_plankton) 
{
	Plankton *plankton = new Plankton();

	Sqare sqare;

	EXPECT_EQ(Sqare::STATUS::EMPTY, sqare.GetStatus());

	sqare.GetIn(plankton);
	
	EXPECT_EQ(Sqare::STATUS::HALF, sqare.GetStatus());
	EXPECT_EQ(1, sqare.GetCitizenCount());
	EXPECT_EQ(1, sqare.GetPlantCount());

	Plankton *plankton2 = new Plankton();

	sqare.GetIn(plankton2);

	EXPECT_EQ(Sqare::STATUS::HALF, sqare.GetStatus());
	EXPECT_EQ(1, sqare.GetCitizenCount());
	EXPECT_EQ(1, sqare.GetPlantCount());

	sqare.GetOff(plankton);

	EXPECT_EQ(Sqare::STATUS::EMPTY, sqare.GetStatus());
	EXPECT_EQ(0, sqare.GetCitizenCount());
	EXPECT_EQ(0, sqare.GetPlantCount());
}