# include  < UnitTest ++ / UnitTest ++. h >
# include  " /home/alexeymarinin/Documents/lb1/131/AlphaCipher.h "
# включить  " /home/alexeymarinin/Documents/lb1/131/AlphaCipher.cpp "



используя  пространство имен  std ;
строка wst ( int k, wstring s1)
{
    AlphaCipher w (k);
    wstring s = w. CoderAlphaCipher (w, s1);
    const строка s2 (s. begin (), s. end ());
    return s2;
}
строка wst1 ( int k, wstring s1)
{
    AlphaCipher w (k);
    wstring s = w. DecoderAlphaCipher (k, s1);
    const строка s2 (s. begin (), s. end ());
    return s2;
}
SUITE (KeyTest)
{
    wstring test = L " ПРОГРАММИРОВАНИЕ " ;
    int k;
    TEST (ValidKey) {
        CHECK_EQUAL ( wst (k = 4 , test), « PRIARARNOMOIGMVE » );
    }
    TEST (EmptyKey) {
        CHECK_THROW ( wst (k = 0 , тест), cipher_error);
    }
    TEST (NegativeKey) {
        CHECK_THROW ( wst (k = - 5 , тест), cipher_error);
    }
    TEST (LargeKey) {
        CHECK_THROW ( wst (k = 12 , тест), cipher_error);
    }
    ТЕСТ (A_characters_in_the_key_instead_of_numbers) {
        CHECK_THROW ( wst (k = 12 , тест), cipher_error);
    }
}
SUITE (EncryptTest)
{
    TEST (ValidText) {
        CHECK_EQUAL ( wst ( 4 , L " ПРОГРАММИРОВАНИЕ " ), " ПРИАРНОМОИГМВЕ " );
    }
    TEST (LowText) {
        CHECK_EQUAL ( wst ( 4 , L " ПРОГРАММИРОВАНИЕ " ), " ПРИАРНОМОИГМВЕ " );
    }
    TEST (SpaceText) {
        CHECK_EQUAL ( wst ( 4 , Л « ПРОГРАММА МИРОВАНИЕ » ), « ПРИАРНОМОИГМВЕ » );
    }
    TEST (EmptyText) {
        CHECK_THROW ( wst ( 4 , L "  " ), cipher_error);
    }
    ТЕСТ (ValiDTextWithoutletters) {
        CHECK_THROW ( wst ( 4 , L " ! *> <? / ,. 123 " ), cipher_error);
    }
    TEST (TextWithNumber) {
        CHECK_EQUAL ( wst ( 4 , L " ПРОГРАМ123МИРОВАНИЕ " ), " ПРИАРНОМОИГМВЕ " );
    }
    TEST (TextWithSpaceAndPunct) {
        CHECK_EQUAL ( wst ( 6 , L « Программист идет! » ), « TGRHRWEAAPMLRMKOES » );
    }
}
SUITE (DecryptText)
{
    ТЕСТ (ValidTEXT) {
        CHECK_EQUAL ( wst1 ( 4 , L " ПРИАРНОМОИГМВЕ " ), " ПРОГРАММИРОВАНИЕ " );
    }
    ТЕСТ (LowTEXT) {
        CHECK_EQUAL ( wst1 ( 4 , L " PriaRARNomoIGMve " ), " ПРОГРАММИРОВАНИЕ " );
    }
    ТЕСТ (SpaceTEXT) {
        CHECK_EQUAL ( wst1 ( 4 , L " ПРИАРН ОМОИГМВЕ " ), " ПРОГРАММИРОВАНИЕ " );
    }
    ТЕСТ (EmptyTEXT) {
        CHECK_THROW ( wst1 ( 4 , L "  " ), cipher_error);
    }
    TEST (TextNumberText) {
        CHECK_EQUAL ( wst1 ( 4 , L " ПРИАРН123ОМОИГМВЕ " ), " ПРОГРАММИРОВАНИЕ " );
    }
    TEST (TextSymbolText) {
        CHECK_EQUAL ( wst1 ( 4 , L « ПРИАРН !!! ОМОИГМВЕ » ), « ПРОГРАММИРОВАНИЕ » );
    }

}

int  main ()
{
    return  UnitTest :: RunAllTests ();
}
