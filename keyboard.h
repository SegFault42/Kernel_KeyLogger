#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/time.h>
#include <linux/time.h>
#include <asm/io.h>

#include "./misc.h"
#include "./log.h"

#define KBD_IRQ				0x01	/* IRQ number for keyboard (i8042) */
#define KBD_DATA_REG		0x60	/* I/O port for keyboard data */
#define KBD_SCANCODE_MASK	0x7f
#define KBD_STATUS_MASK		0x80

#define BUFF_SIZE			1024
#define MIN					0
#define MAJ					1


typedef struct			s_key
{
	unsigned char		key;	// Key code
	unsigned char		state;		// 1 Presed, 0 Released
	char				name[15];	// Key name
	struct timespec		time;		// time
	struct s_key		*next;		// next
}						t_key;

void	*add_tail(unsigned char scancode);
void	free_lst(void);

// array for explicit name key
static const unsigned char	*key_name[128] = {
	0,				// undefined
	"escape",		// escape
	"1","2","3","4","5","6","7","8","9","0","-","=",
	"backspace",	// backspace
	"tab",			// tab
	"q","w","e","r","t","y","u","i","o","p","[","]","enter",
	"left ctrl",	// Ctrl
	"a","s","d","f","g","h","j","k","l",";","\"","`",
	"left shift",	// Left shift
	"\\","z","x","c","v","b","n","m",",",".","/",
	"right shift",	// Right shift
	"*",			// (Keypad *)
	"left alt",		// left alt
	" ",
	"CapsLock",		// Caps lock
	"F1",			// <F1>
	"F2",			// <F2>
	"F3",			// <F3>
	"F4",			// <F4>
	"F5",			// <F5>
	"F6",			// <F6>
	"F7",			// <F7>
	"F8",			// <F8>
	"F9",			// <F9>
	"F10",			// <F10>
	"NumberLock",	// Num lock
	"ScrollLock",	// Scroll Lock
	"Home",			// Home key
	"cursor up",	// Up Arrow
	"page up",		// Page Up
	"-",
	"cursor left",	// Left Arrow
	"",
	"cursor right",	// Right Arrow
	"+",
	"end",			// End key
	"cursor down",	// Down Arrow
	"page down",	// Page Down
	"insert",		// Insert Key
	"delete",		// Delete Key
	"", "", "",		// ?
	"F11",			// <F11>
	"F12",			// <F12>
	"", "",			// ?
	"super",
	"","","","","","","","","","","","","","","","","","","","","","","","","",
	"","","","","","","","","","",""
};
// array for key
static const unsigned char	keyboard_map[2][128] = {
	{
	0,		// undefined
	0,		// escape
	'1','2','3','4','5','6','7','8','9','0','-','=',
	'\b',	// backspace
	'\t',	// tab
	'q','w','e','r','t','y','u','i','o','p','[',']','\n',
	0,		// Ctrl
	'a','s','d','f','g','h','j','k','l',';','\'','`',
	0,		// Left shift
	'\\','z','x','c','v','b','n','m',',','.','/',
	0,		// Right shift
	'*',	// (Keypad *)
	0,		// left alt
	' '
	},
	{
	0,		// undefined
	0,		// escape
	'!','@','#','$','%','^','&','*','(',')','_','+',
	'\b',	// backspace
	'\t',	// tab
	'Q','W','E','R','T','Y','U','I','O','P','{','}','\n',
	0,		// Ctrl
	'A','S','D','F','G','H','J','K','L',':','"','~',
	0,		// Left shift
	'|','Z','X','C','V','B','N','M','<','>','?',
	0,		// Right shift
	'*',	// (Keypad *)
	0,		// left alt
	' '
	}
};

#endif
