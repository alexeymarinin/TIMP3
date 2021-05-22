# включить  " AlphaCipher.h "
AlphaCipher :: AlphaCipher ( ключ int )
{
    это -> k = ключ;
}
wstring AlphaCipher :: CoderAlphaCipher (AlphaCipher w, wstring & s)
{
    код wstring;
    s = getValidOpenText (s);
    ш. k = getValidKey (w. k , s);
    int h;
    if (s. size ()% w. k ! = 0 ) {
        ч = с. размер () / ш. к + 1 ;
    } else {
        ч = с. размер () / ш. k ;
    }
    wchar_t a [h] [w. k ];
    int k = 0 ;
    for ( int i = 0 ; i <h; i ++) {
        for ( int j = 0 ; j <w. k ; j ++) {
            if (k <s. size ()) {
                a [i] [j] = s [k];
                k ++;
            } иначе a [i] [j] = '  ' ;
        }
    }
    for ( int i = 0 ; i <w. k ; i ++) {
        for ( int j = 0 ; j <h; j ++) {
            код + = a [j] [i];
        }
    }
    код возврата ;
}
wstring AlphaCipher :: DecoderAlphaCipher (AlphaCipher w, wstring & s)
{
    s = getValidOpenText (s);
    ш = getValidKey (ш. к , с);
    int h;
    if (s. size ()% w. k ! = 0 ) {
        ч = с. размер () / ш. к + 1 ;
    } else {
        ч = с. размер () / ш. k ;
    }
    wchar_t a [h] [w. k ];
    int k = 0 ;
    for ( int i = 0 ; i <w. k ; i ++) {
        for ( int j = 0 ; j <h; j ++) {
            a [j] [i] = s [k];
            k ++;
        }
    }
    wstring decode;
    for ( int i = 0 ; i <h; i ++) {
        for ( int j = 0 ; j <w. k ; j ++) {
            декодировать + = a [i] [j];
        }
    }
    вернуться декодировать;
}
встроенный  int  AlphaCipher :: getValidKey ( const  int k, const std :: wstring & s)
{
    если (k <= 0 )
        throw  cipher_error ( « Неверный ключ » );
    иначе,  если (k> (s. size () / 2 ))
        throw  cipher_error ( « Ключ длиннее, чем длина текста » );
    еще
        return k;
}
встроенный std :: wstring AlphaCipher :: getValidOpenText ( const std :: wstring & s)
{
    std :: wstring tmp;
    for ( auto c: s) {
        if ( isalpha (c)) {
            if ( islower (c)) {
                tmp. push_back ( toupper (c));
            } еще
                tmp. push_back (c);
        }
    }
    если (tmp. empty ())
        throw  cipher_error ( « Отсутствует вводимый текст » );
    return tmp;
}

встроенный std :: wstring AlphaCipher :: getValidCipherText ( const std :: wstring & s)
{
    std :: wstring tmp;
    for ( auto c: s) {
        if ( isalpha (c)) {
            if ( islower (c)) {
                tmp. push_back ( toupper (c));
            } еще
                tmp. push_back (c);
        }
    }
    если (tmp. empty ())
        throw  cipher_error ( « Отсутствует выводимый текст » );
    return tmp;
}
