#pragma once

#include <functional>

namespace Test {
const std::function<bool(const int&)> isTen {[](const int& element) {
	return element == 10;
}};

const std::function<bool(const int&)> isTwenty {[](const int& element) {
	return element == 20;
}};

const std::function<bool(const int&)> isThirty {[](const int& element) {
	return element == 30;
}};

const std::function<bool(const int&)> isForty {[](const int& element) {
	return element == 40;
}};

const std::function<bool(const int&)> isFifty {[](const int& element) {
	return element == 50;
}};

const std::function<bool(const int&)> isSixty {[](const int& element) {
	return element == 60;
}};

const std::function<bool(const int&)> isSeventy {[](const int& element) {
	return element == 70;
}};

const std::function<bool(const int&)> isEighty {[](const int& element) {
	return element == 80;
}};

const std::function<bool(const int&)> isNinety {[](const int& element) {
	return element == 90;
}};

const std::function<bool(const int&)> isOneHundred {[](const int& element) {
	return element == 100;
}};
}