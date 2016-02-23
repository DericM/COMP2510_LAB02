/*
*    Created on: Jan 14, 2016
*        Author: Mccadden, Deric
* StudentNumber: A00751277
*/

#include <stdio.h>
#define CHECK(PRED) printf("%s ... %s\n",(PRED) ? "passed" : "FAILED", #PRED)

size_t str_replace_all(char s[], int oldc, int newc);
size_t str_replace_last(char s[], int oldc, int newc);
int    str_all_digits(const char s[]);
int    str_equal(const char s[], const char t[]);

int main(void) {

	char a[] = "2212u9u12";
	char b[] = { 2 };
	char c[] = { 2, 5, 0, 4, -1, 7 };

	printf("%d\n", str_replace_all(a, 2, 9));
	CHECK(str_replace_all(a, 2, 9) == 4);
	//printf("%d\n", str_replace_all(b, 2, 5));
	CHECK(str_replace_all(b, 2, 5) == 1);
	//printf("%d\n\n", str_replace_all(c, 4, 8));
	CHECK(str_replace_all(c, 4, 8) == 1);

	char d[] = { 2, 5, 0, 4, -1, 7, 4, 2 };
	char e[] = { 2 };
	char f[] = { 2, 5, 0, 4, -1, 7 };

	CHECK(str_replace_last(d, 2, 3) == 1);
	CHECK(str_replace_last(e, 7, 3) == 0);
	CHECK(str_replace_last(f, 2, 3) == 1);

	char g[] = { 2, 5, 0, 4, -1, 7, 4, 2 };
	char h[] = { 2 };
	char i[] = { 'A', 5, 0, 4, 3 ,2, 5 };

	CHECK(str_all_digits(g) == 1);
	CHECK(str_all_digits(h) == 1);
	CHECK(str_all_digits(i) == 0);

	char j[] = { 2, 5, 0, 4, -1, 7, 4, 2 };
	char k[] = { 2 };
	char l[] = { 2, 5, 0, 4, -1, 7 };
	char m[] = { 'A', 5, 0, 4, 3 ,2, 5 };
	char n[] = { 2 };
	char o[] = { 'A', 5, 0, 4, 3 ,2, 5 };

	CHECK(str_equal(m, o) == -1);
	CHECK(str_equal(k, n) == -1);
	CHECK(str_equal(j, l) == 0);

	getchar();
	return 0;
}

/*
* replace all occurrences of oldc in s with newc
* return the number of occurrences
*/
size_t str_replace_all(char s[], int oldc, int newc) {
	size_t i, n = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == oldc) {
			s[i] = newc;
			n++;
		}
	return n;
}

/*
* replaces the last occurance in of the character olc by new c in string s
*/
size_t str_replace_last(char s[], int oldc, int newc) {
	size_t i, n = 0;
	for (i = 1; s[i - 1] != '\0'; i++)
		if (s[i - 1] == oldc)
			n = i;
	if (n >= 0)
		s[n - 1] = newc;
	return (n == 0) ? 0 : 1;
}

/*
* return 1 if the string s consists entirely of digits otherwise return 0;
*/
int str_all_digits(const char s[]) {
	size_t i;
	for (i = 0; s[i] != '\0'; i++)
		if (!isdigit(s[i]))
			return 0;
	return 1;
}

/*
*return -1 if string s and t have the same characters; otherwise return 0.
*/
int str_equal(const char s[], const char t[]) {
	size_t i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] != t[i] || (s[i] == '\0' && t[i] != '\0') || (t[i] == '\0' && s[i] != '\0'))
			return 0;
	return -1;
}