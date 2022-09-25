#include "../inc/header.h"

wchar_t mx_random_char() {
	wchar_t jap[] = L"ඞヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヷヸヹヺ・ーヽヾ";
	return jap[rand() % 64];
}
