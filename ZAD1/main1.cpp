# include  < UnitTest ++ / UnitTest ++. h >
# include  " /home/alexeymarinin/Documents/lb1/lab1/modAlphaCipher.h "
# включить  " /home/alexeymarinin/Documents/lb1/lab1/modAlphaCipher.cpp


используя  пространство имен  std ;
SUITE (KeyTest)
{

    TEST (LargeLetters) {
тест         modAlphaCipher ( L " БОЛЬШАЯБУКВА " );
        ПРОВЕРИТЬ ( верно );
    }
    TEST (LargeAndSmallLetters) {
тест         modAlphaCipher ( L « МАЛбол » );
        ПРОВЕРИТЬ ( верно );
    }
    TEST (EmptyKey) {
        CHECK_THROW ( тест modAlphaCipher ( L " " ), cipher_error);
    }
    ТЕСТ (Key_with_a_space) {
        CHECK_THROW ( тест modAlphaCipher ( L " бол мал " ), cipher_error);
    }
    ТЕСТ (Key_with_invalid_characters_number) {
        CHECK_THROW ( тест modAlphaCipher ( L " бол1мал " ), cipher_error);
    }
    ТЕСТ (Key_with_invalid_characters_special_character) {
        CHECK_THROW (modAlphaCipher test ( L " БОЛ, мал " ), cipher_error);
    }
}

struct  KeyAB_fixture {
    modAlphaCipher * указатель;
    KeyAB_fixture ()
    {
        указатель = новый  modAlphaCipher ( L « АВ » );
    }
    ~ KeyAB_fixture ()
    {
        указатель удаления ;
    }
};

SUITE (EncryptTest)
{
    TEST_FIXTURE (KeyAB_fixture, LargeLetters) {
        wstring open_text = L " АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " ;
        wstring result_correct = L " АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ " ;
        CHECK_EQUAL ( true , result_correct == указатель-> зашифровать (open_text));
    }
    TEST_FIXTURE (KeyAB_fixture, SmallLetters) {
        wstring open_text = L " абвгдеёжзийклмнопрстуфхцчшщъыьэюя " ;
        wstring result_correct = L " АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ " ;
        CHECK_EQUAL ( true , result_correct == указатель-> зашифровать (open_text));
    }
    TEST_FIXTURE (KeyAB_fixture, NumberInText) {
        wstring open_text = L " ХУК23КУХ " ;
        CHECK_THROW (указатель-> зашифровать (open_text), cipher_error);
    }
    TEST_FIXTURE (KeyAB_fixture, TextWithSpecialSymbol) {
        wstring open_text = L " ХУК | КУХ " ;
        CHECK_THROW (указатель-> зашифровать (open_text), cipher_error);
    }
    TEST_FIXTURE (KeyAB_fixture, TextWithASpace) {
        wstring open_text = L " ХУК КУХ " ;
        CHECK_THROW (указатель-> зашифровать (open_text), cipher_error);
    }

}
SUITE (DecryptTest)
{
   TEST_FIXTURE (KeyAB_fixture, LargeLetters) {
        wstring cipher_text = L " АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ " ;
        wstring result_correct = L " АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " ;
        CHECK_EQUAL ( true , result_correct == указатель-> расшифровать (cipher_text));
    }
    TEST_FIXTURE (KeyAB_fixture, Smallletters) {
        wstring cipher_text = L " агведжёизкймлонрптсфуцхшчъщьыюэая " ;
        wstring result_correct = L " АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " ;
        CHECK_EQUAL ( true , result_correct == указатель-> расшифровать (cipher_text));
    }
    TEST_FIXTURE (KeyAB_fixture, LargeAndSmallLetters) {
        wstring cipher_text = L " ЗДраВстуЙТЕ " ;
        wstring result_correct = L " ЗВРЮВПТСЙРЕ " ;
        CHECK_EQUAL ( true , result_correct == указатель-> расшифровать (cipher_text));
    }

    TEST_FIXTURE (KeyAB_fixture, EmptyText) {
        wstring cipher_text = L " " ;
        CHECK_THROW (указатель-> расшифровать (cipher_text), cipher_error);
    }
    TEST_FIXTURE (KeyAB_fixture, TextWithNumber) {
        wstring cipher_text = L " ХУК23КУХ " ;
        CHECK_THROW (указатель-> расшифровать (cipher_text), cipher_error);
    }
    TEST_FIXTURE (KeyAB_fixture, TextWithSymbol) {
        wstring cipher_text = L " ЖУК + КУЖ " ;
        CHECK_THROW (указатель-> расшифровать (cipher_text), cipher_error);
    }
    TEST_FIXTURE (KeyAB_fixture, TextWithASpace) {
        wstring cipher_text = L " ЗДЕСЬ Пробел " ;
        CHECK_THROW (указатель-> расшифровать (cipher_text), cipher_error);
    }
}
int  main ()
{
    return  UnitTest :: RunAllTests ();
}
