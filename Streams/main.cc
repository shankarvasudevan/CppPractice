#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

int main(int argc, char* argv[])
{
	std::cout << "Hello world" << std::endl;

    Tours tours
    {
        "Tour Ticket Prices from Miami",
        {
            {
                "Colombia",
                {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medelin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil",
                {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                }
            },
            {
                "Chile",
                {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
                }
            },
            {
                "Argentina",
                {
                    { "Buenos Aires", 3010000, 723.77 }
                }
            }
        }
    };

    std::cout << tours.title << std::endl;

    for (auto country : tours.countries)
    {
        std::cout << country.name << std::endl;

        for (auto city : country.cities)
        {
            std::cout << "\t" << city.name << "\t" << city.population << "\t" << city.cost << std::endl;
        }
    }

	return 0;
}
