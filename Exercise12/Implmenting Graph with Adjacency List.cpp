#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream& operator<<(std::ostream& os, const city c);

enum class city : int {
	MOSCOW, LONDON, ISTANBUL, SEATTLE, DUBAI, MUMBAI, SINGAPORE
};

int main() {

}

ostream &operator<<(std::ostream& os, const city c)
{
	switch (c)
	{
	case city::MOSCOW:
		os << "MOSCOW";
		return os;
	case city::LONDON:
		os << "LONDON";
		return os;
	case city::ISTANBUL:
		os << "ISTANBUL";
		return os;
	case city::SEATTLE:
		os << "SEATTLE";
		return os;
	case city::DUBAI:
		os << "DUBAI";
		return os;
	case city::MUMBAI:
		os << "MUMBAI";
		return os;
	case city::SINGAPORE:
		os << "SINGAPORE";
		return os;
	default:
		return os;
	}
}