bool doesAliceWin(char* s) {
    int i = 0;
    int count = 0;
    while(*s != '\0'){
        count += (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u');
        s++;
    }
    return count > 0;
}