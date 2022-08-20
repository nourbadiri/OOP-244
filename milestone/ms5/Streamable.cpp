
#include "Streamable.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Streamable& st) {
		if (st) {
			st.write(os);
		}
		return os;
	}
	std::istream& operator>>(std::istream& istr, Streamable& st) {
		st.read(istr);
		return istr;
	}
}