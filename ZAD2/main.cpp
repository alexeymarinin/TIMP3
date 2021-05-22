# включить  < stdio.h >
# включить  < iostream >
# включить  < cctype >
# включить  " AlphaCipher.h "
# include  < locale >
используя  пространство имен  std ;
 проверка недействительности ( const wstring & Text, const  int & key)
{
    wstring s = Текст;
    попробуйте {
        AlphaCipher SKEY (ключ);
        wcout << skey. CoderAlphaCipher (ключ, s) << endl;
        wstring g = skey. CoderAlphaCipher (ключ, s);
        wcout << skey. DecoderAlphaCipher (ключ, g) << endl;
    } catch ( const cipher_error & e) {
        cerr << " Ошибка: " << e. what () << endl;
    }
}
int  main ()
{
    локаль loc ( " ru_RU.UTF-8 " );
    locale :: global (место);
    check ( L " ПРИАРН !!! ОМОИГМВЕ " , 4 );
    чек ( Л " ПРОГРАММИРОВАНИЕ " , 10 );
    проверьте ( L " LDFHFEUFHWBCD " , 5 );
    возврат  0 ;
}
