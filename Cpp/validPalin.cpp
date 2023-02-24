bool isPalindrome(string s)
{

    string t;
    int i = 0;
    while (s[i] != '\0')
    {
        if (isalnum(s[i]))
        {
            t += tolower(s[i]);
        }
        i++;
    }

    string u;
    for (int j = t.length() - 1; j >= 0; j--)
    {
        u += t[j];
    }

    if (t == u)
    {
        return 1;
    }
    else
        return 0;
}