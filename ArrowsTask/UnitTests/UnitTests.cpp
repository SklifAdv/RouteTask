#include "pch.h"
#include "CppUnitTest.h"
#include "../ArrowsTask/ArrowsTask.cpp"
#include "../ArrowsTask/Coordinate.cpp"
#include "../ArrowsTask/Arrow.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(Is_Victory_Work)
		{
			Coordinate coor1(0, 0), coor2;
            Assert::AreEqual(true, isVictory(coor1, coor2));

			coor2.setY(1);
			Assert::AreEqual(false, isVictory(coor1, coor2));
		}

        TEST_METHOD(Distance_Calculation_Work)
        {
            Coordinate coor1(0, 0), coor2(0, 3);
            Assert::AreEqual(true, (coor1.distanceTo(coor2) == 3));

			coor1.setX(1);
            coor2.setY(1);
            Assert::AreEqual(false, (coor1.distanceTo(coor2) == sqrt (pow ((coor2.x() - coor1.x()), 2) + pow ((coor2.y() - coor1.y()), 2) )));
        }

        TEST_METHOD(Arrow_Constructor_Direction_Work)
        {
            const Coordinate coor1(10, 10);
            Arrow arrowUp(coor1, Arrow::kUp);
            Coordinate testVal(10, 11);
            Assert::AreEqual(true, (arrowUp.getDestination() == testVal));

            Arrow arrowDown(coor1, Arrow::kDown);
            testVal.setY(9);
            Assert::AreEqual(true, (arrowDown.getDestination() == testVal));

            Arrow arrowLeft(coor1, Arrow::kLeft);
            testVal.setX(9);
            testVal.setY(10);
            Assert::AreEqual(true, (arrowLeft.getDestination() == testVal));

            Arrow arrowRight(coor1, Arrow::kRight);
            testVal.setX(11);
            Assert::AreEqual(true, (arrowRight.getDestination() == testVal));
        }
	
        TEST_METHOD(Is_Valid_Work)
        {
            std::vector<Arrow> arrowsVec;
            arrowsVec.push_back(Arrow(Coordinate(0, 0), Arrow::kUp));
            arrowsVec.push_back(Arrow(arrowsVec.at(0).getDestination(), Arrow::kLeft));
            arrowsVec.push_back(Arrow(arrowsVec.at(1).getDestination(), Arrow::kDown));

            Arrow movement(Coordinate(0,0), Arrow::kDown);

            Assert::IsTrue(isValidMovement(movement, arrowsVec));

            Arrow movement2(Coordinate(0, -1), Arrow::kRight);

            Assert::IsTrue(isValidMovement(movement2, arrowsVec));

            Arrow movement3(Coordinate(0, -1), Arrow::kDown);

            Assert::IsTrue(!isValidMovement(movement3, arrowsVec));
        }
    };
}
