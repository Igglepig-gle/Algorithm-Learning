#pragma once
#include<iostream>
#include<cmath>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int stein_algorithm(int a, int b) {
	int count = 1;

	if (a == 0) return b;
	if (b == 0) return a;

	if (a < b) {
		std::swap(a, b);
	}

	while (a != 0 && b != 0) {
		while (a % 2 == 0 && b % 2 == 0) {
			a /= 2;
			b /= 2;
			count *= 2;
		}

		while(a % 2 == 0) {
			a /= 2;
		}
		
		while(b % 2 == 0) {
			b /= 2;
		}

		int temp = std::abs(a - b);
		b = std::min(a, b);
		a = temp;
	}

	return std::max(a, b) * count;
}