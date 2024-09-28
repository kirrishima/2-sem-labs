#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <codecvt>
struct BankClient {
	std::wstring fullName; // Прозвішча, імя кліента банка
	std::wstring accountType; // Тып акаўнта
	int accountNumber = 0; // Нумар рахунку
	long long accountBalance = 0; // Баланс
	std::wstring lastModifiedDate; // Апошняя дата змены інфармацыі
};

const int MAX_CLIENTS = 10;
BankClient clients[MAX_CLIENTS];
int currentClientsCount = 0;

// Увод звестак пра кліента
void inputClientsData();

// Вывад звестак пра ўсіх кліентаў
void displayClientsData();

// Выдаленне звестак 
void deleteClient(int accountNumberToDelete);

// Пошук кліента
void searchClient();

// Запіс інфармацыі ў файл
void writeToFile();

// Чытанне інфармацыі з файла
void readFromFile();

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	int choice;

	do {
		std::wcout << L"\nСістэма кіравання кліентамі банка\n";
		std::wcout << L"1. Увод дадзеных кліентаў\n";
		std::wcout << L"2. Адлюстраваць дадзеныя кліентаў\n";
		std::wcout << L"3. Выдаліць кліента\n";
		std::wcout << L"4. Пошук кліента\n";
		std::wcout << L"5. Запіс у файл\n";
		std::wcout << L"6. Чытанне з файла\n";
		std::wcout << L"0. Выхад\n";
		std::wcout << L"Увядзіце свой выбар: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			inputClientsData();
			break;
		case 2:
			displayClientsData();
			break;
		case 3: {
			int accountNumberToDelete;
			std::wcout << L"Увядзіце нумар рахунку кліента для выдалення: ";
			std::cin >> accountNumberToDelete;
			deleteClient(accountNumberToDelete);
			break;
		}
		case 4:
			searchClient();
			break;
		case 5:
			writeToFile();
			break;
		case 6:
			readFromFile();
			break;
		case 0:
			std::wcout << L"Выхад з праграмы....\n";
			break;
		default:
			std::wcout << L"Некарэктны выбар\n";
		}
	} while (choice != 0);

	return 0;
}

void inputClientsData() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	BankClient newClient; // Ствараем новы аб'ект структуры
	std::wcin.ignore(); // Выдяляем сімвал новага радку з буфера, каб getline не атрымліваў пусты радок замест уводу карыстальніка
	// Атрымліваем ад карыстальніка ўсе звесткі і захоўваем 
	std::wcout << L"Увядзіце Прозвішча, імя: ";
	std::getline(std::wcin, newClient.fullName);

	std::wcout << L"Увядзіце тып акаўнта: ";
	std::getline(std::wcin, newClient.accountType);

	std::wcout << L"Увядзіце нумар рахунку: ";
	std::cin >> newClient.accountNumber;

	std::wcout << L"Увядзіце баланс: ";
	std::cin >> newClient.accountBalance;

	std::wcout << L"Увядзіце дату апошняй змены: ";
	std::wcin.ignore();
	std::getline(std::wcin, newClient.lastModifiedDate);

	clients[currentClientsCount++] = newClient;
}

void readFromFile() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wifstream inFile("bank_clients.txt");
	inFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>)); // Устанавліваем лакаль для корректнага счытвання файла ў кодаванцы UTF-8
	if (!inFile) {
		std::wcerr << L"Памылка адкрыцця файла для чытання.\n";
		return;
	}

	while (inFile.good() && currentClientsCount < MAX_CLIENTS) {
		BankClient newClient;
		std::getline(inFile, newClient.fullName, L',');
		std::getline(inFile, newClient.accountType, L',');
		inFile >> newClient.accountNumber;
		inFile.ignore(); // ігнаруем сімвал ',' у файле
		inFile >> newClient.accountBalance;
		inFile.ignore(); // ігнаруем сімвал ',' у файле

		std::getline(inFile, newClient.lastModifiedDate);
		//inFile.ignore();  // ігнаруем сімвал новага радка ў файле для правільнага наступнага счытвання
		clients[currentClientsCount++] = newClient;
	}

	std::wcout << L"Даныя паспяхова прачытаны з файла.\n";
	inFile.close();
}

void writeToFile() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wofstream outFile("bank_clients.txt");
	outFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>)); // Устанавліваем лакаль для корректнага запісу файла ў кодаванцы UTF-8
	if (!outFile) {
		std::wcerr << L"Памылка адкрыцця файла для запісу.\n";
		return;
	}

	for (int i = 0; i < currentClientsCount; ++i) {
		outFile << clients[i].fullName << L","
			<< clients[i].accountType << L","
			<< clients[i].accountNumber << L","
			<< clients[i].accountBalance << L","
			<< clients[i].lastModifiedDate << L"\n";
	}

	std::wcout << L"Даныя паспяхова запісаны ў файл.\n";
	outFile.close();
}

void searchClient() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	int accountNumberToSearch;
	std::wcout << L"Увядзіце нумар рахунку для пошуку: ";
	std::wcin >> accountNumberToSearch;

	for (int i = 0; i < currentClientsCount; i++) {
		if (clients[i].accountNumber == accountNumberToSearch) {
			std::wcout << L"Знойдзены кліент:\n";
			std::wcout << L"ПІБ: " << clients[i].fullName << L"\n";
			std::wcout << L"Тып рахунку: " << clients[i].accountType << L"\n";
			std::wcout << L"Нумар рахунку: " << clients[i].accountNumber << L"\n";
			std::wcout << L"Баланс: " << clients[i].accountBalance << L"\n";
			std::wcout << L"Дата апошняй змены: " << clients[i].lastModifiedDate << L"\n\n";
			return;
		}
	}

	std::wcout << L"Кліент з нумарам рахунку " << accountNumberToSearch << L" не знойдзены.\n";
}

void displayClientsData() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	for (int i = 0; i < currentClientsCount; i++) {
		std::wcout << L"\nКліент: " << i + 1 << L":\n";
		std::wcout << L"ПІБ: " << clients[i].fullName << L"\n";
		std::wcout << L"Тып рахунку: " << clients[i].accountType << L"\n";
		std::wcout << L"Нумар рахунку: " << clients[i].accountNumber << L"\n";
		std::wcout << L"Баланс: " << clients[i].accountBalance << L"\n";
		std::wcout << L"Дата апошняй змены: " << clients[i].lastModifiedDate << L"\n\n";
	}
}

void deleteClient(int accountNumberToDelete) {
	int foundIndex = -1;

	// Знаходзім індэкс кліента з паказаным нумарам рахунку, бо нумар рахунку не роўны нумару кліента ў базе дадзеных (ну мусіць, мне здаецца так)
	for (int i = 0; i < currentClientsCount; i++) {
		if (clients[i].accountNumber == accountNumberToDelete) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {
		// Зрушваем усе элементы пасля знойдзенага кліента налева на 1 пазіцыю
		for (int i = foundIndex; i < currentClientsCount - 1; i++) {
			clients[i] = clients[i + 1];
		}

		// Памяншаем лічыльнік бягучай колькасці кліентаў
		--currentClientsCount;

		std::wcout << L"Кліент з нумарам рахунку " << accountNumberToDelete << " выдалены.\n";
	}
	else {
		std::wcout << L"Кліент з нумарам рахунку " << accountNumberToDelete << " не знойдзены.\n";
	}
}