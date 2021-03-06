#include <iostream>
using namespace std;
void init_field(char** field, int size);
void print_field(char** field, int size);
void player_turn(char** field, int size);
bool check_win(char** field, int size,char sign);
bool check_draw(char** field, int size);
//main
int main() {
	//русск яз
	setlocale(LC_ALL, "rus");
	//Выделение памяти под поле
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	//заполняем поле пробелами
	init_field(field, size);
	print_field(field, size);
	while (true) {
		//ход крестиков или ноликов
		player_turn(field, size);
		print_field(field, size);
		if (check_win(field, size, 'x')) {
			cout << "Выиграли крестики"<<endl;
			break;
		}
		if (check_draw(field, size)) {
			cout << "Ничья" << endl;
		}
		if (check_win(field, size, 'o')) {
			cout << "Выиграли нолики " << endl;
			break;
		}
		//выигрыш крестиков или ноликов
		//ничья
	}
	return 0;
	//функции
}
void init_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = ' ';
		}
	}
}
void print_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < size; j++) {
			cout<< "| "<< field[i][j]<<' ';
		}
		cout << '|' << endl;
	}
	cout << "|---|---|---|" << endl;
}
void player_turn(char** field, int size) {
	int row, col;
	char sign;
	//защита
	do {
		do {
			cout << "Введите номер строки";
			cin >> row;
		} while (row < 0 || row>size - 1);
		do {
			cout << "Введите номер столбца";
			cin >> col;
		} while (row < 0 || row>size - 1);
	} while (field[row][col] != ' ');
	do {
		cout << "Введите значок";
		cin >> sign;
		field[row][col] = sign;
	} while (sign != 'x' && sign != 'o');
	field[row][col] = sign;
}
bool check_win(char** field, int size, char sign) {
	//проверка что в строках три sign
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) {
		return true;
	}
	if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) {
		return true;
	}
	if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) {
		return true;
	}
	if (field[0][0] == sign && field[1][0] == sign && field[2][0] == sign) {
		return true;
	}
	if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) {
		return true;
	}
	if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) {
		return true;
	}
	if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) {
		return true;
	}
	if (field[0][2] == sign && field[1][1] == sign && field[2][0] == sign) {
		return true;
	}
	return false;
}
bool check_draw(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (field[i][j] == ' ')return false;
		}
	}
	return true;
}
