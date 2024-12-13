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
        cout << "����������: " << name << ", ��������: " << material << endl;
    }
};

class StringInstrument : public MusicalInstrument {
private:
    int string_count;

public:
    StringInstrument(const string& instrument_name, const string& instrument_material, int strings): MusicalInstrument(instrument_name, instrument_material), string_count(strings) {}

    void display() const override {
        cout << "��������� ����������: " << name << ", ��������: " << material
            << ", ������: " << string_count << endl;
    }
};

class BrassInstrument : public MusicalInstrument {
private:
    string brass_type;

public:
    BrassInstrument(const string& instrument_name, const string& instrument_material, const string& type): MusicalInstrument(instrument_name, instrument_material), brass_type(type) {}

    void display() const override {
        cout << "������� ����������: " << name << ", ��������: " << material
            << ", ������� ���: " << brass_type << endl;
    }
};

void modifyInstrument(MusicalInstrument* instrument) {
    cout << "��������� �����������..." << endl;

    instrument->display();
    cout << "��������� ����������" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<unique_ptr<MusicalInstrument>> instruments;

    instruments.push_back(make_unique<StringInstrument>("������", "������", 6));
    instruments.push_back(make_unique<StringInstrument>("����������", "������", 4));

    instruments.push_back(make_unique<BrassInstrument>("�����", "�������", "�������"));
    instruments.push_back(make_unique<BrassInstrument>("���������)", "�������", "������"));

    cout << "��� �����������:\n";
    for (const auto& instrument : instruments) {
        instrument->display();
    }

    if (!instruments.empty()) {
        cout << "\n��������� �����������...\n";
        modifyInstrument(instruments.front().get());
    }

    return 0;
}
