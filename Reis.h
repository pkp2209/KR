#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <algorithm>

#define SIZE 128
#define MAX 50

struct Rei
{
	char in[SIZE];
	char out[SIZE];
	int rest;
	int capacity;
	char dateout[SIZE];
	char datein[SIZE];
};

class Reis {
	Rei *list_;
	int count_;
public:

	Reis()
	{
		count_ = 0;
		list_ = nullptr;
	}

	Reis(const char *file)
	{
		count_ = 0;
		char buf[SIZE];
		auto i = 0;

		std::ifstream f1(file);

		if (!f1.is_open())
			throw std::exception("Error! Can't open file.");

		list_ = new Rei[MAX];

		while (f1.getline(buf, SIZE))
		{
			if (count_ == MAX)
				throw std::exception("Error! Too many members in your list");

			char *ptr, *ptr1;
			char *t = strtok_s(buf, ";", &ptr);
			strcpy_s(list_[i].out, SIZE, t);
			t = strtok_s(nullptr, ";", &ptr);
			strcpy_s(list_[i].dateout, SIZE, t);
			t = strtok_s(buf, ";", &ptr);
			strcpy_s(list_[i].in, SIZE, t);
			t = strtok_s(nullptr, ";", &ptr);
			strcpy_s(list_[i].datein, SIZE, t);
			t = strtok_s(nullptr, ";", &ptr);
			list_[i].capacity = strtol(t, &ptr1, 10);
			t = strtok_s(nullptr, ";", &ptr);
			list_[i].rest = strtol(t, &ptr1, 10);

			count_++;
			i++;
		}

		f1.close();
	}

	Reis(Reis const& l1)
	{
		count_ = l1.count_;
		list_ = new Rei[count_];

		for (auto i = 0; i < count_; i++)
		{
			strcpy_s(list_[i].dateout, SIZE, l1.list_[i].dateout);
			list_[i].capacity = l1.list_[i].capacity;
			list_[i].rest = l1.list_[i].rest;
			strcpy_s(list_[i].datein, SIZE, l1.list_[i].datein);
			strcpy_s(list_[i].in, SIZE, l1.list_[i].in);
			strcpy_s(list_[i].out, SIZE, l1.list_[i].out);
		}
	}

	Reis(Reis&& l1) noexcept
	{
		count_ = l1.count_;
		list_ = l1.list_;
	}

	virtual ~Reis()
	{
		delete[] list_;
	}

	void book_ticket(const int index) const;
	void append(const char* in, const char* out, const unsigned capacity, const unsigned rest, const char* datein, const char* dateout);
	void append(Rei &c);
	void book_ticket(const int index) const;
	void in_file(const char* file);
	Rei& operator[](const int index) const;

	friend std::istream& operator>>(std::istream& in, Reis& l1);
	friend std::ostream& operator<<(std::ostream& out, const Reis& l1);
};