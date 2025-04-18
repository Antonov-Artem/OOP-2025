#ifndef BARGE_H
#define BARGE_H

// Стани об'єкту "баржа"
enum BargeState {
    SAILING,           // в рейсі
    DOCKED,            // на стоянці
    LOADING,           // завантажується
    UNDER_MAINTENANCE  // на ремонті
};

class Barge {
    const int MAX_MILEAGE = 100; // максимально припустимий пробіг

    int _imo_number;    // унікальний ідентифікатор судна
    char *_home_port;   // порт приписки
    char *_ship_owner;  // власник судна

    static int cargo_capacity;  // максимальний вантаж (у тоннах)

    int _current_cargo;  // поточний вантаж (у тоннах)
    int _mileage;        // пробіг судна (км)

    BargeState _state;  // стан об'єкту "баржа"

public:
    Barge(int imo_number, const char *home_port, const char *ship_owner);
    Barge(const Barge &b, int imo_number);
    ~Barge();

    static int get_cargo_capacity();
    static void set_cargo_capacity(int cargo_capacity);

    bool operator>(const Barge &b) const;  // істинна якщо вантаж даної баржі більший ніж вантаж баржі "b"

    void start();                         // почати рух
    void stop();                          // припинити рух
    void load_cargo(int cargo);           // завантажити
    void unload_cargo(int cargo);         // розвантажити
    void check_barge_condition();         // перевірити стан судна
    const char *state_to_string() const;  // ковертує код стану об'єкту в строку
    void print_cargo() const;             // виводить інформацію про атрибути об'єкту
};

#endif
