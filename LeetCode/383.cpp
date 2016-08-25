class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
        int mag[130], arr[130];
        for (int i = 0; i < 130; i++) {
            mag[i] = 0;
            arr[i] = 0;
        }
        for (int i = 0; i < magazine.length(); i++)
            mag[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.length(); i++) 
            arr[ransomNote[i]]++;
        }

        for (int i = 97; i < 130; i++) {
            if (arr[i] > mag[i])
                return false;
        }
        return true;
    }
};
