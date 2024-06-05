#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Определение класса Train
class Train {
public:
    std::string destination;
    int train_number;
    int departure_hour;
    int departure_minute;

    Train(std::string dest, int num, int hour, int minute)
        : destination(dest),
          train_number(num),
          departure_hour(hour),
          departure_minute(minute)
    {
    }

    void display() const
    {
        std::cout << "Destination: " << destination
                  << ", Train Number: " << train_number
                  << ", Departure Time: " << departure_hour << ":"
                  << (departure_minute < 10 ? "0" : "") << departure_minute
                  << "\n";
    }

    bool operator<(const Train& other) const
    {
        // Сортировка по времени отправления
        if (departure_hour != other.departure_hour)
            return departure_hour < other.departure_hour;
        return departure_minute < other.departure_minute;
    }
};

int main()
{
    int n;
    std::cout << "Enter the number of trains: ";
    std::cin >> n;

    std::vector<Train> trains;
    for (int i = 0; i < n; ++i) {
        std::string dest;
        int num, hour, minute;
        std::cout << "Enter destination: ";
        std::cin >> dest;
        std::cout << "Enter train number: ";
        std::cin >> num;
        std::cout << "Enter departure hour and minute: ";
        std::cin >> hour >> minute;
        trains.emplace_back(dest, num, hour, minute);
    }

    // Критерий для перезаписи: поезд с номером больше 100
    std::vector<Train> filtered_trains;
    std::copy_if(
            trains.begin(),
            trains.end(),
            std::back_inserter(filtered_trains),
            [](const Train& t) { return t.train_number > 100; });

    if (filtered_trains.empty()) {
        std::cout << "No trains matched the criteria.\n";
    } else {
        std::sort(filtered_trains.begin(), filtered_trains.end());

        std::cout << "Filtered and sorted trains:\n";
        for (const auto& train : filtered_trains) {
            train.display();
        }
    }

    return 0;
}
