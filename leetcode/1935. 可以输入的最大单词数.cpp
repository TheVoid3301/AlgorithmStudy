class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<int> s;
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] == ' ')
            {
                s.insert(i);
            }
        }
        int res = 0;
        s.insert(text.size());
        for (auto i : s)
        {
            for (int j = i - 1; j >= 0 && text[j] != ' '; --j)
            {
                if (brokenLetters.find(text[j]) != string::npos)
                {
                    res++;
                    break;
                }
            }
        }
        return s.size() - res;
    }
};