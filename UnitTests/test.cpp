#include "pch.h"
#include "../OceanW/Field/field.h"

TEST(SqareTest, sqare_plankton) 
{
	Plankton plankton();

	Sqare sqare;

	EXPECT_EQ(Sqare::STATUS::EMPTY, sqare.GetStatus());
}