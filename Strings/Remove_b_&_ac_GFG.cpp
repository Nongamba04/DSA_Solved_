class Solution
{
  public:
    string stringFilter(string str) 
    { 
        int i = 0;

        while (i < str.length()) {
            if (str[i] == 'b') {
                str.erase(i, 1); // Remove character 'b'
            } else if (i + 1 < str.length() && str[i] == 'a' && str[i + 1] == 'c') {
                str.erase(i, 2); // Remove pattern 'ac'
            } else {
                i++;
            }
        }
        
        return str;
    } ;
    
};