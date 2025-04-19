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

	return false;
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

LongNumber LongNumber::multiply_abs (const LongNumber& x, const LongNumber& y) const {
	int* result = new int[x.length + y.length]{0};
    int len = 0;

    for (int i = 0; i < x.length; ++i) {
        int carry = 0;
        for (int j = 0; j < y.length || carry; ++j) {
            int product = result[i + j] + x.numbers[i] * (j < y.length ? y.numbers[j] : 0) + carry;
            result[i + j] = product % 10;
            carry = product / 10;
            len = std::max(len, i + j + 1);
        }
    }

    // Удаление ведущих нулей
    while (len > 1 && result[len-1] == 0) len--;

    LongNumber num;
    delete[] num.numbers;
    num.numbers = result;
    num.length = len;
    num.sign = 1;
    return num;
}

// Если один из аргументов = 0, возвращаем другой
// Если одинаковые знаки - складываем модули и добавляем знак
// Если противоположные - идем в вычитание

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (sign == 0) return x; 					// 0 + x = x
	if (x.sign == 0) return *this;				// x + 0 = x

	// (+x) + (+y) = +(x+y)
	// (-x) + (-y) = -(x+y)
	// знак от x
	if (sign == x.sign) {
		return add_abs(*this, x, sign);
	}

	auto zero = LongNumber();
	if (compare_abs(x)) { // |this| > |x|
        LongNumber result = sub_abs(*this, x);
        if (result != zero) {
            result.sign = sign; // знак x (большего по модулю)
        }
        return result;
    } else {
        LongNumber result = sub_abs(x, *this);
        if (result != zero) {
            result.sign = x.sign; // знак текущего объекта (большего по модулю)
        }
        return result;
    }
}

// Если один из аргументов ноль - меняем знак
// 0 - x = -x, x - 0 = x
// Если знаки разные - идем в складывание
// Если одинаковые то вычитаем, знак определяется сравнением |this| |x|

LongNumber LongNumber::operator - (const LongNumber& x) const {

	// 0 - a = -a, меняем знак
	if (sign == 0) {
		LongNumber result = x;
		result.sign = -x.sign;
		return result;
	}
	if (x.sign == 0) return x; // a - 0 = a

	// (-x) - (+y) = -(x+y)
	// x - (-y) = x + y
	// знак от x (this)

	if (sign != x.sign) {
		return add_abs(*this, x, sign);
	}

	// знаки одинаковые, нужно вычесть из большего меньшее и взять нужный знак
	bool is_abs_bigger = compare_abs(x);

	LongNumber result;
	if (is_abs_bigger) {
		result = sub_abs(*this, x);
	} else {
		result = sub_abs(x, *this);
	}

	// здесь мог получится ноль, но он обработан в sub_abs
	// устанавливаем знак того, чей больше
	if (result != LongNumber()) {
		result.sign = (is_abs_bigger) ? sign : -sign;
	}
	
	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	if (sign == 0 || x.sign == 0) return LongNumber();

    int result_sign = (sign == x.sign) ? 1 : -1;
    LongNumber result = multiply_abs(*this, x);
    result.sign = result_sign;
    return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
    if (x.sign == 0) throw std::runtime_error("Division by zero");
    if (sign == 0) return LongNumber();

    // Работаем с абсолютными значениями
    LongNumber dividend = abs(*this);
    LongNumber divisor = abs(x);

    if (dividend < divisor) return LongNumber("0");

    LongNumber quotient;
    LongNumber current_dividend;
    quotient.numbers = new int[dividend.length]();
    quotient.length = 0;

    for (int i = dividend.length - 1; i >= 0; i--) {
        current_dividend = current_dividend * LongNumber("10") + LongNumber(std::to_string(dividend.numbers[i]).c_str());
        
        if (current_dividend < divisor) {
            quotient.numbers[quotient.length++] = 0;
            continue;
        }

        int count = 0;
        LongNumber temp = divisor;
        while (temp < current_dividend || temp == current_dividend) {
            temp = temp + divisor;
            count++;
        }
        
        quotient.numbers[quotient.length++] = count;
        current_dividend = current_dividend - (divisor * LongNumber(std::to_string(count).c_str()));
    }

    // Разворачиваем цифры частного (храним младшие разряды первыми)
    for (int i = 0; i < quotient.length / 2; ++i) {

		int temp = quotient.numbers[i];
		quotient.numbers[i] = quotient.numbers[quotient.length - 1 - i];
		quotient.numbers[quotient.length - 1 - i] = temp;
	}
    
    // Удаляем ведущие нули
    while (quotient.length > 1 && quotient.numbers[quotient.length - 1] == 0) {
        quotient.length--;
    }

    quotient.sign = (sign == x.sign) ? 1 : -1;
    return quotient;
}

LongNumber LongNumber::operator % ( const LongNumber& x) const {
    if (x.sign == 0) throw std::runtime_error("Division by zero");
    
    // Вычисляем частное и остаток
    LongNumber quotient = *this / x;
    LongNumber remainder = *this - (quotient * x);
    
    // Корректируем остаток в диапазон [0, |x|)
    if (remainder != LongNumber("0")) {
        LongNumber abs_x = abs(x);
        if (remainder.is_negative()) {
            remainder = remainder + abs_x;
        } else if (remainder > abs_x || remainder == abs(x)) {
            remainder = remainder - abs_x;
        }
        // Всегда устанавливаем положительный знак
        remainder.sign = 1;
    }
    
    return remainder;
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

// true если больше
bool LongNumber::compare_abs(const LongNumber& x) const {
	// смотрим по длине
	if (length != x.length) {
		return length > x.length;
	}

	// сравниваем разряды
	for (int i = length - 1; i >= 0; --i) {
		if (numbers[i] != x.numbers[i]) {
			return numbers[i] > x.numbers[i];
		}
	}

	// одинаковы по длине и одинаковые разряды => равны
	return false;
}

bool LongNumber::abs_equal(const LongNumber& x) const {
	if (length != x.length) {
		return false;
	} else {
		for (int i = 0; i < length; ++i) {
			if (numbers[i] != x.numbers[i]) {
				return false;
			}
		}
	}
	return true;
}

LongNumber LongNumber::abs(const LongNumber& x) const {
    LongNumber result = x;
    result.sign = 1;
    return result;
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