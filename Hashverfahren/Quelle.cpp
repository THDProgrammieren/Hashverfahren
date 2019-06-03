#include <iostream>
#include <cmath>
#include <vector>
#include <string>

struct KFZ
{
	char Kennzeichen[11];
	char Haltername[31];
	char Adresse[31];
};

int Hashverfahren(const char *Kennzeichen)
{
	int sum = 0;
	for (unsigned int i = 0; i < 11; i++)
	{
		sum += Kennzeichen[i];
	}

	sum = static_cast<int>(((sum / 768.0) * 15) - 1);

	return sum;
}

int main()
{
	std::vector<KFZ> Fahrzeuge[15];

	while (1)
	{
		char auswahl;
		std::cout << "Fahrzeug hinzufuegen (a) | Fahrzeug suchen (b)" << std::endl;
		std::cin >> auswahl;

		if (auswahl == 'a')
		{

			KFZ neuesFahrzeug;

			std::cout << "Kennzeichen: ";
			std::cin >> neuesFahrzeug.Kennzeichen;

			std::cout << "Haltername: ";
			std::cin >> neuesFahrzeug.Haltername;

			std::cout << "Adresse: ";
			std::cin >> neuesFahrzeug.Adresse;

			std::cout << "Berechneter Hashwert: " << Hashverfahren(neuesFahrzeug.Kennzeichen) << std::endl;
			Fahrzeuge[Hashverfahren(neuesFahrzeug.Kennzeichen)].push_back(neuesFahrzeug);
			std::cout << std::endl;
		}
		if (auswahl == 'b')
		{
			std::string kennzeichen;
			std::cout << "Kennzeichen: ";
			std::cin >> kennzeichen;

			std::cout << "Suche in Arrayindex " << Hashverfahren(kennzeichen.c_str()) << std::endl;
			for (unsigned int i = 0; i < Fahrzeuge[Hashverfahren(kennzeichen.c_str())].size(); i++)
			{
				if (Fahrzeuge[Hashverfahren(kennzeichen.c_str())][i].Kennzeichen == kennzeichen)
				{
					std::cout << "Fahrzeug an Listenstelle " << i << " gefunden!" << std::endl;
					std::cout << "-----------------------" << std::endl;
					std::cout << "Kennzeichen: " << Fahrzeuge[Hashverfahren(kennzeichen.c_str())][i].Kennzeichen << std::endl;
					std::cout << "Halter: " << Fahrzeuge[Hashverfahren(kennzeichen.c_str())][i].Haltername << std::endl;
					std::cout << "Adresse: " << Fahrzeuge[Hashverfahren(kennzeichen.c_str())][i].Adresse << std::endl;
					std::cout << "-----------------------" << std::endl;
				}
			}
		}
	}

	system("pause");
	return 0;
}