#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class MusicalInstrument {
protected:
    string name;
    string material;

public:
    MusicalInstrument(const string& instrument_name, const string& instrument_material): name(instrument_name), material(instrument_material) {}

    virtual ~MusicalInstrument() = default;

    virtual void display() const {
        cout << "Инструмент: " << name << ", Материал: " << material << endl;
    }
};

class StringInstrument : public MusicalInstrument {
private:
    int string_count;

public:
    StringInstrument(const string& instrument_name, const string& instrument_material, int strings): MusicalInstrument(instrument_name, instrument_material), string_count(strings) {}

    void display() const override {
        cout << "Стьрунный инструмент: " << name << ", Маетриал: " << material
            << ", Струны: " << string_count << endl;
    }
};

class BrassInstrument : public MusicalInstrument {
private:
    string brass_type;

public:
    BrassInstrument(const string& instrument_name, const string& instrument_material, const string& type): MusicalInstrument(instrument_name, instrument_material), brass_type(type) {}

    void display() const override {
        cout << "Духовой инструмент: " << name << ", Материал: " << material
            << ", Духовой тип: " << brass_type << endl;
    }
};

void modifyInstrument(MusicalInstrument* instrument) {
    cout << "Изменение инструмента..." << endl;

    instrument->display();
    cout << "Изменение завершенно" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<unique_ptr<MusicalInstrument>> instruments;

    instruments.push_back(make_unique<StringInstrument>("Гитара", "Дерево", 6));
    instruments.push_back(make_unique<StringInstrument>("Виолончель", "Дерево", 4));

    instruments.push_back(make_unique<BrassInstrument>("Труба", "Духовой", "Высокий"));
    instruments.push_back(make_unique<BrassInstrument>("Тромболон)", "Духовой", "Низкий"));

    cout << "Все инструменты:\n";
    for (const auto& instrument : instruments) {
        instrument->display();
    }

    if (!instruments.empty()) {
        cout << "\nИзменение инструмента...\n";
        modifyInstrument(instruments.front().get());
    }

    return 0;
}
