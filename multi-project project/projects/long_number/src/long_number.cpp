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

LongNumber LongNumber::add_abs(const LongNumber& x, const LongNumber& y, const int sign) const {
	int max_len = std::max(x.length, y.length);
	// цифр результата на 1 больше чем максимум из-за возможного переноса
	int* result = new int[max_len + 1]{0};

	int carry = 0; // перенос
	int len = 0;

	for (int i = 0; i < max_len || carry; ++i) {
		int d1 = (i < x.length) ? x.numbers[i] : 0;
		int d2 = (i < y.length) ? y.numbers[i] : 0;
		int sum = d1 + d2 + carry;
		result[len++] = sum % 10;
		carry = sum / 10;
	}

	while (len > 1 && result[len-1] == 0) {
		--len;
	}

	LongNumber num;
	delete[] num.numbers;
	num.numbers = result;
	num.length = len;
	num.sign = (len == 1 && result[0] == 0) ? 0 : sign;
	return num;
}

LongNumber LongNumber::sub_abs(const LongNumber& x, const LongNumber& y) const {
	int* result = new int[x.length]{0};
	int borrow = 0;
	int len = 0;

	for (int i = 0; i < x.length; ++i) {
		// первая цифра с учетом занятого числа
		int d1 = x.numbers[i] - borrow;
		int d2 = (i < y.length) ? y.numbers[i] : 0;
		borrow = 0;

		// вычитаемая цифра больше - занимаем
		if (d1 < d2) {
			d1 += 10;
			borrow = 1;
		}

		result[len++] = d1 - d2;
	}

	while (len > 1 && result[len-1] == 0) {
		--len;
	}

	LongNumber num;
	delete[] num.numbers;
	num.numbers = result;
	num.length = len;
	// знак ставим +, потом определяем в самом операторе "минус"
	num.sign = (len == 1 && result[0] == 0) ? 0 : 1;
	return num;
}

// Если один из аргументов = 0, возвращаем другой
// Если одинаковые знаки - складываем модули и добавляем знак
// Если противоположные - идем в вычитание

LongNumber LongNumber::operator + (const LongNumber& x) const {
	
}

// Если один из аргументов ноль - меняем знак
// 0 - x = -x, x - 0 = x
// Если знаки разные - идем в складывание
// Если одинаковые то вычитаем, знак определяется сравнением |this| |x|

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