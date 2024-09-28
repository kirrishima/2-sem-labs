#include "stdafx.h"

#if( defined(TEST_CREATE_01) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) + defined(TEST_CREATE_02)) > 1
#error "Only one macro from the list can be defined at a time."
#endif

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try {
#ifdef TEST_DICTIONARY
    Dictionary::Instance students = Dictionary::Create("Students", 7);
    Dictionary::Instance teachers = Dictionary::Create("Teachers", 7);

    Dictionary::Entry studentEntries[] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"},
        {4, "David"},
        {5, "Eva"},
        {6, "Frank"},
        {7, "Grace"}
    };

    Dictionary::Entry teacherEntries[] = {
        {101, "Ms. Smith"},
        {102, "Mr. Johnson"},
        {103, "Dr. Lee"},
        {104, "Prof. Brown"},
        {105, "Ms. Wilson"},
        {106, "Mr. Clark"},
        {107, "Dr. Baker"}
    };

    for (int i = 0; i < 7; ++i) {
        Dictionary::AddEntry(students, studentEntries[i]);
        Dictionary::AddEntry(teachers, teacherEntries[i]);
    }

    // Printing dictionaries
    std::cout << "Students: ";
    Dictionary::Print(students);
    std::cout << "Teachers: ";
    Dictionary::Print(teachers);

    // Freeing memory
    Dictionary::Delete(students);
    Dictionary::Delete(teachers);
#endif

#ifdef TEST_CREATE_01

        Dictionary::Instance test = Dictionary::Create("TestDictfdhsfkhdkjjhfdkjsjhfkjdsjhkd", -1);


#endif

#ifdef TEST_CREATE_02

        Dictionary::Instance test = Dictionary::Create("TestDict", 1000);
    
#endif

#ifdef TEST_ADDENTRY_03
    Dictionary::Instance test = Dictionary::Create("TestDict", 3);

        Dictionary::AddEntry(test, { 1, "Entry1" });
        Dictionary::AddEntry(test, { 2, "Entry2" });
        Dictionary::AddEntry(test, { 3, "Entry3" });
        Dictionary::AddEntry(test, { 4, "Entry4" });
    }

#endif

#ifdef TEST_ADDENTRY_04
    Dictionary::Instance test = Dictionary::Create("TestDict", 3);

        Dictionary::AddEntry(test, { 1, "Entry1" });
        Dictionary::AddEntry(test, { 2, "Entry2" });
        Dictionary::AddEntry(test, { 2, "DuplicateEntry" }); // Duplicate entry ID

#endif

#ifdef TEST_GETENTRY_05
    Dictionary::Instance test = Dictionary::Create("TestDict", 3);

        Dictionary::AddEntry(test, { 1, "Entry1" });
        Dictionary::Entry* entry = Dictionary::GetEntry(test, 2);
        if (entry != nullptr) {
            std::cout << "Found entry: " << entry->name << std::endl;
        }

#endif

#ifdef TEST_DELENTRY_06
    Dictionary::Instance test = Dictionary::Create("TestDict", 3);

        Dictionary::DelEntry(test, 1); // Trying to delete from an empty dictionary

#endif

#ifdef TEST_UPDENTRY_07
    Dictionary::Instance test = Dictionary::Create("TestDict", 3);

        Dictionary::AddEntry(test, { 1, "Entry1" });
        Dictionary::UpdEntry(test, 2, { 2, "UpdatedEntry" }); // Updating non-existent entry
 
#endif

#ifdef TEST_UPDENTRY_08
    Dictionary::Instance test = Dictionary::Create("TestDict", 3);

        Dictionary::AddEntry(test, { 1, "Entry1" });
        Dictionary::AddEntry(test, { 2, "Entry2" });
        Dictionary::UpdEntry(test, 2, { 1, "DuplicateIDEntry" }); // Trying to update with duplicate ID
    

#endif
        }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const char* what) {
        std::cout << what;
    }
	return 0;
}
