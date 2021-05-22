# pragma once
# include  < вектор >
# include  < строка >
# include  < карта >
# include  < locale >
используя  пространство имен  std ;
класс  modAlphaCipher
{
частный:
    std :: wstring numAlpha = L " АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " ;
    std :: map < char , int > alphaNum;   // ассоциативный массив "номер по символу"
    std :: vector < int > key;          // ключ
    std :: vector < int > convert ( const std :: wstring & s); // преобразование строка-вектор
    std :: wstring convert ( const std :: vector < int > & v); // преобразование вектор-строка
    std :: wstring getValidKey ( const std :: wstring & s);
    std :: wstring getValidText ( const std :: wstring & s);
общественность:
    modAlphaCipher () = удалить ; // запретим конструктор без параметров
    modAlphaCipher ( const std :: wstring & skey);    // конструктор для установки ключа
    std :: wstring encrypt ( const std :: wstring & open_text);  // зашифрование
    std :: wstring decrypt ( const std :: wstring & cipher_text); // расшифрование
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
