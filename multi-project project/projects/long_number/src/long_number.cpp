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

LongNumber::LongNumber(const LongNumber& x) {
	// TODO
}

LongNumber::LongNumber(LongNumber&& x) {
	// TODO
}

LongNumber::~LongNumber() {
	// TODO
}

LongNumber& LongNumber::operator = (const char* const str) {
	// TODO
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	// TODO
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	// TODO
}

bool LongNumber::operator == (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator != (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator > (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator < (const LongNumber& x) const {
	// TODO
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
		for (int i = x.length - 1; i >=0; i--)
			os << x.numbers[i];
		return os;
	}
}