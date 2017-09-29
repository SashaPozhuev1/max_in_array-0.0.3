#include <iostream>
#include <sstream>

using namespace std;

bool proverka(int mass[10]) {

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	bool prav = true;

	for (int i = 0; i < 10; i++) {
		if (!(stream >> mass[i])) {
			prav = false;
			break;
		}
	}

	return prav;
}


int main() {

	int mass1[10];
	int mass2[10];
	int mass3[20];

	if ((proverka(mass1)) && (proverka(mass2))) {

		for (int i = 0; i < 20; i++) {
			if (i % 2 == 0) {
				mass3[i] = mass1[i / 2];
			}
			else {
				mass3[i] = mass2[i / 2];
			}
		}


		int max = mass3[0] + mass3[1];

		for (int i = 0; i < 19; i += 2) {
			if (max < (mass3[i] + mass3[i + 1])) {
				max = mass3[i] + mass3[i + 1];
			}
			if (max < (mass3[i] + mass3[i + 3])) {
				max = mass3[i] + mass3[i + 3];
			}
		}

		cout << max;

	}
	else {
		cout << "An error has occurred while reading numbers" << endl;
	}


	cin.get();
	return 0;
}
