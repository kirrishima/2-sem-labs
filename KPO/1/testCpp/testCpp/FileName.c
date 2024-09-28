#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <codecvt>
struct BankClient {
	std::wstring fullName; // ��������, ��� ������ �����
	std::wstring accountType; // ��� ������
	int accountNumber = 0; // ����� �������
	long long accountBalance = 0; // ������
	std::wstring lastModifiedDate; // ������� ���� ����� ����������
};

const int MAX_CLIENTS = 10;
BankClient clients[MAX_CLIENTS];
int currentClientsCount = 0;

// ���� ������� ��� ������
void inputClientsData();

// ����� ������� ��� ��� ������
void displayClientsData();

// ��������� ������� 
void deleteClient(int accountNumberToDelete);

// ����� ������
void searchClient();

// ���� ���������� � ����
void writeToFile();

// ������� ���������� � �����
void readFromFile();

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	int choice;

	do {
		std::wcout << L"\nѳ����� �������� ������� �����\n";
		std::wcout << L"1. ���� �������� ������\n";
		std::wcout << L"2. ������������ �������� ������\n";
		std::wcout << L"3. ������� ������\n";
		std::wcout << L"4. ����� ������\n";
		std::wcout << L"5. ���� � ����\n";
		std::wcout << L"6. ������� � �����\n";
		std::wcout << L"0. �����\n";
		std::wcout << L"������� ���� �����: ";
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
			std::wcout << L"������� ����� ������� ������ ��� ���������: ";
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
			std::wcout << L"����� � ��������....\n";
			break;
		default:
			std::wcout << L"���������� �����\n";
		}
	} while (choice != 0);

	return 0;
}

void inputClientsData() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	BankClient newClient; // �������� ���� ��'��� ���������
	std::wcin.ignore(); // �������� ����� ������ ����� � ������, ��� getline �� �������� ����� ����� ������ ����� ������������
	// ���������� �� ������������ ��� ������ � �������� 
	std::wcout << L"������� ��������, ���: ";
	std::getline(std::wcin, newClient.fullName);

	std::wcout << L"������� ��� ������: ";
	std::getline(std::wcin, newClient.accountType);

	std::wcout << L"������� ����� �������: ";
	std::cin >> newClient.accountNumber;

	std::wcout << L"������� ������: ";
	std::cin >> newClient.accountBalance;

	std::wcout << L"������� ���� ������� �����: ";
	std::wcin.ignore();
	std::getline(std::wcin, newClient.lastModifiedDate);

	clients[currentClientsCount++] = newClient;
}

void readFromFile() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wifstream inFile("bank_clients.txt");
	inFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>)); // ������������ ������ ��� ����������� ��������� ����� � ��������� UTF-8
	if (!inFile) {
		std::wcerr << L"������� �������� ����� ��� �������.\n";
		return;
	}

	while (inFile.good() && currentClientsCount < MAX_CLIENTS) {
		BankClient newClient;
		std::getline(inFile, newClient.fullName, L',');
		std::getline(inFile, newClient.accountType, L',');
		inFile >> newClient.accountNumber;
		inFile.ignore(); // �������� ����� ',' � �����
		inFile >> newClient.accountBalance;
		inFile.ignore(); // �������� ����� ',' � �����

		std::getline(inFile, newClient.lastModifiedDate);
		//inFile.ignore();  // �������� ����� ������ ����� � ����� ��� ���������� ���������� ���������
		clients[currentClientsCount++] = newClient;
	}

	std::wcout << L"����� ��������� ��������� � �����.\n";
	inFile.close();
}

void writeToFile() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wofstream outFile("bank_clients.txt");
	outFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>)); // ������������ ������ ��� ����������� ����� ����� � ��������� UTF-8
	if (!outFile) {
		std::wcerr << L"������� �������� ����� ��� �����.\n";
		return;
	}

	for (int i = 0; i < currentClientsCount; ++i) {
		outFile << clients[i].fullName << L","
			<< clients[i].accountType << L","
			<< clients[i].accountNumber << L","
			<< clients[i].accountBalance << L","
			<< clients[i].lastModifiedDate << L"\n";
	}

	std::wcout << L"����� ��������� ������� � ����.\n";
	outFile.close();
}

void searchClient() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	int accountNumberToSearch;
	std::wcout << L"������� ����� ������� ��� ������: ";
	std::wcin >> accountNumberToSearch;

	for (int i = 0; i < currentClientsCount; i++) {
		if (clients[i].accountNumber == accountNumberToSearch) {
			std::wcout << L"��������� �����:\n";
			std::wcout << L"ϲ�: " << clients[i].fullName << L"\n";
			std::wcout << L"��� �������: " << clients[i].accountType << L"\n";
			std::wcout << L"����� �������: " << clients[i].accountNumber << L"\n";
			std::wcout << L"������: " << clients[i].accountBalance << L"\n";
			std::wcout << L"���� ������� �����: " << clients[i].lastModifiedDate << L"\n\n";
			return;
		}
	}

	std::wcout << L"����� � ������� ������� " << accountNumberToSearch << L" �� ���������.\n";
}

void displayClientsData() {
	std::wcout.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	for (int i = 0; i < currentClientsCount; i++) {
		std::wcout << L"\n�����: " << i + 1 << L":\n";
		std::wcout << L"ϲ�: " << clients[i].fullName << L"\n";
		std::wcout << L"��� �������: " << clients[i].accountType << L"\n";
		std::wcout << L"����� �������: " << clients[i].accountNumber << L"\n";
		std::wcout << L"������: " << clients[i].accountBalance << L"\n";
		std::wcout << L"���� ������� �����: " << clients[i].lastModifiedDate << L"\n\n";
	}
}

void deleteClient(int accountNumberToDelete) {
	int foundIndex = -1;

	// �������� ������ ������ � ��������� ������� �������, �� ����� ������� �� ���� ������ ������ � ���� �������� (�� �����, ��� ������� ���)
	for (int i = 0; i < currentClientsCount; i++) {
		if (clients[i].accountNumber == accountNumberToDelete) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {
		// �������� ��� �������� ����� ����������� ������ ������ �� 1 ������
		for (int i = foundIndex; i < currentClientsCount - 1; i++) {
			clients[i] = clients[i + 1];
		}

		// ��������� ������� ������� ��������� ������
		--currentClientsCount;

		std::wcout << L"����� � ������� ������� " << accountNumberToDelete << " ��������.\n";
	}
	else {
		std::wcout << L"����� � ������� ������� " << accountNumberToDelete << " �� ���������.\n";
	}
}