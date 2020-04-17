#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct coord {
	double x;
	double y;
};

void main() {
	ifstream fin("firefly.in");

	int count = 1;
	int playerRange;
	coord caughtCoord;
	coord fireflyCoord;
	coord personStartCoord;
	coord personCurrentCoord;
	coord personNewCoord;
	double distanceToFirefly;

	if (fin.is_open()) {
		ofstream fout("firefly.out");

		fin >> playerRange >> personStartCoord.x >> personStartCoord.y;

		while (playerRange != 0 || personStartCoord.x > 0 || personStartCoord.y > 0)
		{
			personCurrentCoord.x = personStartCoord.x;
			personCurrentCoord.y = personStartCoord.y;
			caughtCoord.x = 0;
			caughtCoord.y = 0;

			fin >> fireflyCoord.x >> fireflyCoord.y;

			while (fireflyCoord.x != -1 && fireflyCoord.y != -1)
			{

				distanceToFirefly = sqrt((fireflyCoord.x - personCurrentCoord.x)*(fireflyCoord.x - personCurrentCoord.x)
										+ (fireflyCoord.y - personCurrentCoord.y)*(fireflyCoord.y - personCurrentCoord.y));


				if (distanceToFirefly <= 1 || distanceToFirefly <= (playerRange + 1) && caughtCoord.x == 0 && caughtCoord.y == 0) {
					caughtCoord.x = fireflyCoord.x;
					caughtCoord.y = fireflyCoord.y;

				}
				else if (distanceToFirefly > 1 && distanceToFirefly > (playerRange + 1)) {

					personNewCoord.x = ((playerRange / distanceToFirefly)*(fireflyCoord.x - personCurrentCoord.x)) + personCurrentCoord.x;
					personNewCoord.y = ((playerRange / distanceToFirefly)*(fireflyCoord.y - personCurrentCoord.y)) + personCurrentCoord.y;

					personCurrentCoord.x = personNewCoord.x;
					personCurrentCoord.y = personNewCoord.y;
				}
				
				

				fin >> fireflyCoord.x >> fireflyCoord.y;
				}

			if (caughtCoord.x == 0 && caughtCoord.y == 0) {

				fout << "Firefly " << count << " not caught" << endl;
			}
			else {
				fout << "Firefly " << count << " caught at (" << caughtCoord.x << "," << caughtCoord.y << ")" << endl;
			}

			count++;
			fin >> playerRange >> personStartCoord.x >> personStartCoord.y;
		}
		
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}