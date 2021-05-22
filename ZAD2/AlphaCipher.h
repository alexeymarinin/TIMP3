# pragma once
# include  < строка >
# include  < вектор >
# включить  < iostream >

используя  пространство имен  std ;
class  AlphaCipher
{
частный:
    int k;
    wstring getValidOpenText ( const std :: wstring & s);
    wstring getValidCipherText ( const std :: wstring & s);
    int  getValidKey ( const  int k, const std :: wstring & s);
общественность:
    AlphaCipher () = удалить ;
    ПерестанШифр ( int w);
    wstring CoderAlphaCipher (AlphaCipher w, wstring & s);
    wstring DecoderAlphaCipher (AlphaCipher w, wstring & s);
};
класс  cipher_error : общедоступный  std :: invalid_argument
{
общественность:
    явный  cipher_error ( const std :: string & what_arg):
        std :: invalid_argument (какой_арг) {}
    явный  cipher_error ( const  char * what_arg):
        std :: invalid_argument (какой_арг) {}
};
© 2021 GitHub, Inc.
