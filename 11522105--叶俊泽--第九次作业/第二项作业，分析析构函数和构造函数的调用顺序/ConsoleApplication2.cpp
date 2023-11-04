#include"No2.h"
int main() 
{
	Brother bro("ZX", 'M', "ZF", 'M', "FQ", 'M', "Bro", 'M');
	Sister  sis("ZX", 'M', "ZF", 'M', "FQ", 'M', "Sis", 'F');
	Me me("ZX", 'M', "ZF", 'M', "FQ", 'M', "Me", 'M', bro, sis);
	me.displayMe();
}