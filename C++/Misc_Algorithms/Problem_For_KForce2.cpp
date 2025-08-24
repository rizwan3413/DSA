
/*Pattern matching Problem:
=========================*/
//pattern "010" s = "amazing"

     "010"
 "amazing"
 
 
bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;
    
    return false;
}

int binaryPatternMatching(std::string pattern, std::string s) {
 if(pattern.size() == s.size())
    return 1;

    int var[pattern.size()];

    int temp =0;
    var[0] = 0;

    int i = 1 ;

    while(i < pattern.size())
    {
        if(pattern[i] == pattern[temp])
        {
            temp++;
            var[i] = temp;
            i++;
        }       
        else 
        {
            if(temp!=0)
            {
                temp = var[temp-1];
            }
            else {
                var[i] = 0;
                i++;
            }
        } 
    }
    i = 0;
    int j = 0;
    int count = 0;
    while(i< s.size())
    {
        if((pattern[j] == '0' && isVowel(s[i])) ||(pattern[j] == '1' && !isVowel(s[i])))
        {
            j++;
            i++;
        }
        if(j == pattern.size())
        {
            count++;
            j = var[j-1];
        }
        else if( i < s.size() && !((pattern[j] == '0' && isVowel(s[i])) ||(pattern[j] == '1' && !isVowel(s[i]))))
        {
            if(j!=0)
            j = var[j-1];

            else 
            i++;
        }
    }
    return count;
}
