#include "Reis.h"


std::ostream& operator<<(std::ostream& out, const Reis& l1)
{
	for (auto i = 0; i < l1.count_; i++)
		out << l1.list_[i].in << ": " << l1.list_[i].capacity << "; " << l1.list_[i].rest << "; " << l1.list_[i].datein << ";" << l1.list_[i].dateout << ";" << l1.list_[i].out << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Reis& l1)
{
	Rei c;
	char s = 'c';
	while (s != 'q')
	{
		std::cout << "Enter the name of the town to: ";
		in.getline(c.in, SIZE);
		std::cout << "Enter the name of the town from: ";
		in.getline(c.out, SIZE);
		std::cout << "Enter the capacity: ";
		in >> c.capacity;
		std::cout << "Enter the amount of remaining tickets: ";
		in >> c.rest;
		std::cout << "Enter the date and the time of to(y-m-d h:m): ";
		in.ignore();
		in.getline(c.dateout, SIZE);
		std::cout << "Enter the date and the time of from(y-m-d h:m): ";
		in.ignore();
		in.getline(c.datein, SIZE);

		l1.append(c);

		std::cout << "Press 'q' to quit or something else to continue ";
		in >> s;
		in.ignore();
	}

	return in;
}

void Reis::append(Rei& c)
{
	if (count_ == MAX)
		throw std::exception("Error! Too many members in your list");

	count_++;

	list_[count_ - 1].capacity = c.capacity;
	list_[count_ - 1].rest = c.rest;
	strcpy_s(list_[count_ - 1].in, SIZE, c.in);
	strcpy_s(list_[count_ - 1].out, SIZE, c.out);
	strcpy_s(list_[count_ - 1].datein, SIZE, c.datein);
	strcpy_s(list_[count_ - 1].dateout, SIZE, c.dateout);
}

Rei& Reis::operator[](const int index) const
{
	if (index >= count_ || index < 0)
		throw std::exception("Error! The index is not included in the values area ");

	return list_[index];
}

void Reis::book_ticket(const int index) const
{
	if (list_[index].rest == 0)
		throw std::exception("Sorry, no more tickets left");
	else
		list_[index].rest--;
}
