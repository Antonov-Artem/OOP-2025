#include "Barge.h"

#include <cstring>
#include <iostream>
#include <ostream>

int Barge::cargo_capacity = 100;

Barge::Barge(const int imo_number, const char *home_port, const char *ship_owner)
    : _imo_number(imo_number), _current_cargo(0), _mileage(0), _state(DOCKED) {
    _home_port = new char[strlen(home_port) + 1];
    strcpy(_home_port, home_port);

    _ship_owner = new char[strlen(ship_owner) + 1];
    strcpy(_ship_owner, ship_owner);
}

Barge::Barge(const Barge &b, const int imo_number) {
    _imo_number = imo_number;
    _home_port = new char[strlen(b._home_port) + 1];
    strcpy(_home_port, b._home_port);
    _ship_owner = new char[strlen(b._ship_owner) + 1];
    strcpy(_ship_owner, b._ship_owner);
    _current_cargo = 0;
    _mileage = 0;
    _state = DOCKED;
}

Barge::~Barge() {
    delete[] _home_port;
    delete[] _ship_owner;
    std::cout << "Destructor for object " << _imo_number << " worked" << std::endl;
}

int Barge::get_cargo_capacity() { return cargo_capacity; }

void Barge::set_cargo_capacity(const int cargo_capacity) { Barge::cargo_capacity = cargo_capacity; }

bool Barge::operator>(const Barge &b) const { return _current_cargo > b._current_cargo; }

void Barge::start() {
    if (_state == UNDER_MAINTENANCE) return;

    _state = SAILING;
    std::cout << "Started sailing" << std::endl;

    _mileage += 50;
}

void Barge::stop() {
    if (_state == UNDER_MAINTENANCE) return;

    _state = DOCKED;
    std::cout << "Stopped sailing" << std::endl;
}

void Barge::load_cargo(const int cargo) {
    if (_current_cargo + cargo > cargo_capacity || _state == UNDER_MAINTENANCE) return;

    _state = LOADING;
    std::cout << "LOADING cargo " << std::endl;

    _current_cargo += cargo;

    _state = DOCKED;
    std::cout << "DOCKED cargo" << std::endl;
}

void Barge::unload_cargo(const int cargo) {
    if (cargo > _current_cargo || _state == UNDER_MAINTENANCE) return;

    _state = LOADING;
    std::cout << "UNLOADING cargo " << std::endl;

    _current_cargo -= cargo;

    _state = DOCKED;
    std::cout << "DOCKED cargo " << std::endl;
}

void Barge::check_barge_condition() {
    if (_mileage >= MAX_MILEAGE) {
        _state = UNDER_MAINTENANCE;
        std::cout << "Under maintenance" << std::endl;
    }
}

const char *Barge::state_to_string() const {
    switch (_state) {
        case SAILING:
            return "Sailing";
        case DOCKED:
            return "Docked";
        case LOADING:
            return "Loading";
        case UNDER_MAINTENANCE:
            return "Under maintenance";
        default:
            return "";
    }
}

void Barge::print_cargo() const {
    std::cout << "IMO Number: " << _imo_number << std::endl;
    std::cout << "Home Port: " << _home_port << std::endl;
    std::cout << "Ship Owner: " << _ship_owner << std::endl;
    std::cout << "Cargo Capacity: " << cargo_capacity << std::endl;
    std::cout << "Current Cargo: " << _current_cargo << std::endl;
    std::cout << "Mileage: " << _mileage << std::endl;
    std::cout << "State: " << state_to_string() << std::endl;
    std::cout << std::endl << std::string(30, '=') << std::endl;
}
