# включить  < iostream >
# включить  < cctype >
# включить  " modAlphaCipher.h "
# include  < codecvt >
используя  пространство имен  std ;

int  main ( int argc, char ** argv) {
        локаль loc ( " ru_RU.UTF-8 " );
        locale :: global (место);
        bool isTrue = true ;
        wstring mode, NeMode, wstr, wstr_key;
        do {
            cout << " Укажите режим работы (Введите Encode / Decode / Exit): " ;
            wcin >> mode;
            if (mode == L " Кодировать " ) {
                cout << " Введите строку для шифрования: " ;
                wcin. получить ();
                getline (wcin, wstr);
                cout << " Введите ключ: " ;
                getline (wcin, wstr_key);
            }
            if (mode == L " Decode " ) {
                cout << " Введите для расшифрования: " ;
                wcin. получить ();
                getline (wcin, wstr);
                cout << " Введите ключ: " ;
                getline (wcin, wstr_key);
            }
            if (mode == L " Выход " ) {
                cout << " До свидания. " << endl;
                isTrue = false ;
                перерыв ;
            }
        } while (isTrue! = false );
        возврат  0 ;
    }
