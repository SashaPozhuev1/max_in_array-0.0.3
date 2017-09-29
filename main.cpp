#include <iostream>
#include <sstream>

using namespace std;

bool proverka( int mass[ 10 ] ) {
	string stroka;
	getline( cin, stroka );
	istringstream stream( stroka );

	bool prav = true;

	for ( int i = 0; i < 10; i++ ) {
		if ( !( stream >> mass[ i ] ) ) {
			prav = false;
			break;
		}
	}

	return prav;
}


int main() {

	int mass1[ 10 ];
	int mass2[ 10 ];

	if ( ( proverka( mass1 ) ) && ( proverka( mass2 ) ) ) {
		int max = mass1[ 0 ] + mass2[ 0 ];
		for ( int i = 0; i < 10; i ++ ) {
			for ( int j = i; j < 10; j ++ ) {
				if ( max < mass1[ i ] + mass2[ j ] ) {
					max = mass1[ i ] + mass2[ j ];
				}
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
