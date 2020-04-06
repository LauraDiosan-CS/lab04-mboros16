
#include "UI.h"

bool Sort_Tip(Cheltuiala * cheltuiala_c, Cheltuiala * cheltuiala_n)
{
	if (cheltuiala_c->getZiua() > cheltuiala_n->getZiua())
		return true;
	return false;
}

int main()
{
	/*List<Cheltuiala> list;

	Cheltuiala * x = new Cheltuiala(29, 2, "Mancare");
	Cheltuiala * y = new Cheltuiala(29, 1, "Caca");

	list.Add(x);
	list.Add(y);

	list[0]->print();
	list[1]->print();

	list.Sort(Sort_Tip);

	list[0]->print();
	list[1]->print();

	List<Cheltuiala> copyList = list.Copy();
	copyList[0]->print();
	copyList[1]->print();
	system("pause");*/
	UI ui;
	while (true)
	{
		ui.Meniu();
	}
}