#include "Automata.h"

int main()
{
	Automata machine;
	machine.on();
	machine.coin(90);
	machine.coin(5);
	machine.choice(1);
	machine.off();
}
