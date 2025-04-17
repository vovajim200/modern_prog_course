#include "long_number.hpp"

using oia::LongNumber;
		
LongNumber::LongNumber() {
	numbers = new int[1]{0};
	length = 1;
	sign = 0;
}

LongNumber::LongNumber(const char* const str) {
	if (str == nullptr || *str == '\0') {
		numbers = new int[1]{0};
		length = 1;
		sign = 0;
		return;
	}

	int start = 0;
	sign = 1;

	if (str[0] == '-'){
		sign = -1;
		start = 1;
	}

	// Мат. операции выполняются справа налево,
	// будем хранить числа с младшего разряда

	// Пропускаем ведущие нули

	while (str[start] == '0' && str[start] != '\0') {
		start++;
	}

	// Обрабатываем 0

	if (str[start] == '\0') {
		numbers = new int[1]{0};
		length = 1;
		sign = 0;
		return;
	}

	// Вычисление длины с учетом знака

	length = get_length(str+start);
	numbers = new int[length];

	// Заполняем в обратном порядке,
	// - '0' преобразует символ в цифру

	for (int i = 0; i < length; i++) {
		numbers[i] = str[start + length - 1 - i] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) 
	: length(x.length), sign(x.sign)	{
		numbers = new int[length];
		std::copy(x.numbers, x.numbers + length, numbers);
}

LongNumber::LongNumber(LongNumber&& x)
	: numbers(x.numbers), length(x.length), sign(x.sign) {
		x.numbers = nullptr;
		x.length = 0;
		x.sign = 0;
}

LongNumber::~LongNumber() {
	delete[] numbers;
}

LongNumber& LongNumber::operator = (const char* const str) {
	LongNumber temp(str);
	*this = std::move(temp);
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this != &x) {
		delete[] numbers;
		length = x.length;
		sign = x.sign;
		numbers = new int[length];
		std::copy(x.numbers, x.numbers + length, numbers);
	}
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this != &x) {
		delete[] numbers;
		numbers = x.numbers;
		length = x.length;
		sign = x.sign;
		
		x.numbers = nullptr;
		x.length = 0;
		x.sign = 0;
	}
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign || length != x.length) {
		return false;
	}
	for (int i = 0; i < length; i++){
		if (numbers[i] != x.numbers[i]) {
			return false;
		}
	}
	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign) {
		return sign > x.sign;
	}

	if (length != x.length) {
		return (length > x.length) ? (sign == 1) : (sign != 1);
	}

	for (int i = length - 1; i >= 0; i--) {
		if (numbers[i] != x.numbers[i]) {
			return (numbers[i] > x.numbers[i]) ? (sign == 1) : (sign != 1);
		}
	}
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this == x || *this > x);
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	return numbers[rank];
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int len = 0;
	while ( str[len] != '\0' && isdigit(str[len]) ) {
		len++;
	}
	return len == 0 ? 1 : len;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace oia {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.is_negative()) os << '-';
		for (int i = x.length - 1; i >= 0; i--)
			os << x.numbers[i];
		return os;
	}
}