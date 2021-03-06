#include <iostream>
#include <cstdlib>
#include <sstream>

#include "io.h"

using namespace std;

bool
load_signal(istream & is, Vector<Complex<> > & input)
{
	Complex<> c;
	while (is >> c)
		input.push_back(c);
	if (is.bad())
		return false;
	return true;
}

bool
print_signal(ostream & os, Vector<Complex<> > const & output)
{
	for (size_t i = 0; i < output.size(); ++i)
		os << output[i] << ' ';
	os << endl;
	if (os.bad())
		return false;
	return true;
}

void
print_error_on_line(string line, size_t line_number)
{
	cerr << "Error processing \""
	     << line
	     << "\" (line "
	     << line_number
	     << ")."
	     << endl;
}
