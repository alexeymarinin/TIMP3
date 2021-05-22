# включить  " modAlphaCipher.h "

modAlphaCipher :: modAlphaCipher ( Const станд :: wstring & SKEY)
{
    for ( unsigned i = 0 ; i <numAlpha. size (); i ++) {
        alphaNum [numAlpha [i]] = i;
    }
    ключ = преобразовать ( getValidKey ( skey ));
}

std :: wstring modAlphaCipher :: encrypt ( const std :: wstring & open_text)
{
    std :: vector < int > work = convert ( getValidText (open_text));
    for ( unsigned i = 0 ; i <work. size (); i ++) {
        work [i] = (work [i] + key [i% key. size ()])% alphaNum. размер ();
    }
    return  convert (работа);
}

std :: wstring modAlphaCipher :: decrypt ( const std :: wstring & cipher_text)
{
    std :: vector < int > work = convert ( getValidText (cipher_text));
    for ( unsigned i = 0 ; i <work. size (); i ++) {
        work [i] = (work [i] + alphaNum. size () - key [i% key. size ()])% alphaNum. размер ();
    }
    return  convert (работа);
}

встроенный std :: vector < int > modAlphaCipher :: convert ( const std :: wstring & s)
{
    std :: vector < int > result;
    for ( auto c: s) {
        результат. push_back (alphaNum [c]);
    }
    вернуть результат;
}
встроенный std :: wstring modAlphaCipher :: convert ( const std :: vector < int > & v)
{
    std :: wstring result;
    for ( auto i: v) {
        результат. push_back (numAlpha [i]);
    }
    вернуть результат;
}
встроенный std :: wstring modAlphaCipher :: getValidKey ( const std :: wstring & s)
{
    локаль loc ( " ru_RU.UTF-8 " );
    locale :: global (место);
    если (s. size () == 0 )
        throw  cipher_error ( string ( " Вы ввели пустой текст " ));
    wstring wst = s;
    for ( size_t i = 0 ; i <wst. size (); i ++) {
        if ( iswalpha (wst [i]) == 0 ) {
            throw  cipher_error ( string ( " В вашем тексте присутствуют недопустимые символы " ));
            перерыв ;
        }
        если ( iswlower (wst [i]))
            wst [i] = буксир (wst [i]);
    }
    return wst;
}


встроенный wstring modAlphaCipher :: getValidText ( const wstring & s)
{
    локаль loc ( " ru_RU.UTF-8 " );
    locale :: global (место);
    если (s. size () == 0 )
        throw  cipher_error ( string ( " Вы ввели пустой текст " ));
    wstring wst = s;
    for ( size_t i = 0 ; i <wst. size (); i ++) {
        if ( iswalpha (wst [i]) == 0 ) {
            throw  cipher_error ( string ( " В вашем тексте присутствуют недопустимые символы " ));
            перерыв ;
        }
        если ( iswlower (wst [i]))
            wst [i] = буксир (wst [i]);
    }
    return wst;
}
