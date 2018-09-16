#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef struct			s_key
{
	unsigned char		key;		// Key code
	unsigned char		state;		// 1 Presed, 0 Released
	char				name[25];	// Key name
	struct tm			time;		// time
	struct keyboard_s	*next;		// next
}						t_key;

static const unsigned char	*key_name[] = {
	0, // undefined
	"escape", // escape
	"1","2","3","4","5","6","7","8","9","0","-","=",
	"backspace", // backspace
	"tab", // tab
	"q","w","e","r","t","y","u","i","o","p","[","]","enter",
	"left ctrl", // Ctrl
	"a","s","d","f","g","h","j","k","l",";","\"","`",
	"left shift", // Left shift
	"\\","z","x","c","v","b","n","m",",",".","/",
	"right shift",		// Right shift
	"*",	// (Keypad *)
	"left alt",		// left alt
	" ",
	"CapsLock",	// Caps lock
	"F1",		// <F1>
	"F2",		// <F2>
	"F3",		// <F3>
	"F4",		// <F4>
	"F5",		// <F5>
	"F6",		// <F6>
	"F7",		// <F7>
	"F8",		// <F8>
	"F9",		// <F9>
	"F10",		// <F10>
	"NumberLock",		// Num lock
	"ScrollLock",		// Scroll Lock
	"Home",		// Home key
	"cursor up",		// Up Arrow
	"page up",		// Page Up
	"-",
	"cursor left",		// Left Arrow
	"",
	"cursor right",		// Right Arrow
	"+",
	"end",		// End key
	"cursor down",		// Down Arrow
	"page down",		// Page Down
	"insert",		// Insert Key
	"delete",		// Delete Key
	"",		// ?
	"",		// ?
	"",		// ?
	"F11",		// <F11>
	"F12"		// <F12>
};
static const unsigned char	keyboard_map[] = {
	0, // undefined
	0, // escape
	'1','2','3','4','5','6','7','8','9','0','-','=',
	'\b', // backspace
	'\t', // tab
	'q','w','e','r','t','y','u','i','o','p','[',']','\n',
	0, // Ctrl
	'a','s','d','f','g','h','j','k','l',';','\'','`',
	0, // Left shift
	'\\','z','x','c','v','b','n','m',',','.','/',
	0,		// Right shift
	'*',	// (Keypad *)
	0,		// left alt
	' ',
	'0',	// Caps lock
	0,		// <F1>
	0,		// <F2>
	0,		// <F3>
	0,		// <F4>
	0,		// <F5>
	0,		// <F6>
	0,		// <F7>
	0,		// <F8>
	0,		// <F9>
	0,		// <F10>
	0,		// Num lock
	0,		// Scroll Lock
	0,		// Home key
	0,		// Up Arrow
	0,		// Page Up
	'-',
	0,		// Left Arrow
	0,
	0,		// Right Arrow
	'+',
	0,		// End key
	0,		// Down Arrow
	0,		// Page Down
	0,		// Insert Key
	0,		// Delete Key
	0,		// ?
	0,		// ?
	0,		// ?
	0,		// <F11>
	0		// <F12>
};

#endif
