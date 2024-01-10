// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/

int minOperations(string s)
{
    // there only 2 types
    // 1 - "01010101..." -> even index = 0
    // 2 - "10101010..." -> even index = 1

    // check minimum out of these 2

    int startWithZero = 0, startWithOne = 0, n = s.length();

    // Case 1 - "01010101..." -> even index = 0
    // for(int i = 0 ; i < n ; i++){
    //     if( i % 2 == 0){
    //         if(s[i] != '0'){
    //             startWithZero++;
    //         }
    //     }
    //     else{
    //         if(s[i] != '1'){
    //             startWithZero++;
    //         }
    //     }
    // }

    // // Case 2 - "10101010..." -> even index = 1
    // for(int i = 0 ; i < n ; i++){
    //     if( i % 2 == 0){
    //         if(s[i] != '1'){
    //             startWithOne++;
    //         }
    //     }
    //     else{
    //         if(s[i] != '0'){
    //             startWithOne++;
    //         }
    //     }
    // }

    // Doing above 2 cases in single loop
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            // Case 2
            if (s[i] != '1')
            {
                startWithOne++;
            }
            // Case 1
            else
            {
                startWithZero++;
            }
        }
        else
        {
            // Case 2
            if (s[i] != '0')
            {
                startWithOne++;
            }
            // Case 1
            else
            {
                startWithZero++;
            }
        }
    }

    return min(startWithZero, startWithOne);
}