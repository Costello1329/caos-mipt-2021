#include <stdio.h>
#include <stdbool.h>



bool get_bit (const long long number, const long long bit_index) {
        return (number >> bit_index) & 1ull == 1ull;
}

char char_at (int index) {
	if (index < 10) // number
		return '0' + index;
	else if (index < 10 + 26)
		return 'a' + index - 10;
	else if (index < 10 + 26 + 26)
		return 'A' + index - 10 - 26;
	else if (index == 62)
		return '+';
	else
		return '-';
}

int char_index (char ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else if (ch >= 'a' && ch <= 'z')
		return (ch - 'a') + 10;
	else if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A') + 10 + 26;
	else if (ch == '+')
		return 62;
	else if (ch == '-')
		return 63;
	else
		return -1;
}

void add_char_to_set (long long* bitset, char ch) {
        *bitset |= (1ull << (unsigned long long)char_index(ch));
}

long long input () {
	long long bitset = 0;

	while (true) {
		char ch = getchar();

		if (char_index(ch) != -1)
			break;
		
		add_char_to_set(&bitset, ch);
	}
	return bitset;
}

void output (long long bitset) {
	for (int i = 0; i < 64; i ++)
		if (get_bit(bitset, i))
			putchar(char_at(i));
}

long long bitset_union (long long first, long long second) {
        long long res = 0;

        for (int i = 0; i < 64; i ++)
                if (get_bit(first, i) || get_bit(second, i))
                        res |= (1ull << i);

        return res;
}

int main (int argc, char** argv) {
	long long first_set = input();
	long long second_set = input();
	long long united_set = bitset_union(first_set, second_set);
	output(united_set);
	printf("\n");
}

